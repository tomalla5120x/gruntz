#ifndef __UTILS_MEMORY_POOL__
#define __UTILS_MEMORY_POOL__

#include <cassert>
#include <new>

namespace Utils
{
	// Memory pool which uses nodes stored in a contiguous block of memory.
	// I couldn't find any matching ATL class. The closest match would be CFixedAllocNoSync class, but:
	// * the fields and method signatures don't match
	// * it operates on CPlex instances, which represent allocated memory blocks for nodes -
	//   they form a linked-list with each block starting with the pointer to the next CPlex instance.
	//   Here we have only one block of memory which has to suffice.
	// * its usage is overly complicated
	// That's why I whipped up this simple utility class with matching functionality and fields.
	//
	// Note: the class is not designed well and contains no checks - it's not safe by all means but it seems like the game
	// handles it well. I've added some custom asserts throughout the code in case the memory is allocated twice or
	// the memory pool runs out of free space. They're not a part of the original binary and are merely there to signal something went wrong.
	template<typename T>
	class MemoryPool
	{
	private:
		struct Node
		{
			Node* pNext;
			T data;
		};

	public:
		MemoryPool(): m_pBlock(nullptr), m_pNextFreeNode(nullptr), m_nodesCount(0), m_dataOffset(0) {
			//@address: inlined
		}
		
		~MemoryPool()
		{
			//@address: inlined
			if(m_pBlock != nullptr)
				delete m_pBlock;

			m_pBlock = nullptr;
			m_pNextFreeNode = nullptr;
			m_nodesCount = m_dataOffset = 0;
		}

		bool AllocateBlock(unsigned int nodesCount)
		{
			//@address: inlined	
			//@bug: the initialization and allocation should be redesigned - now they're not particularly safe
			assert(m_pBlock == nullptr);

			m_dataOffset = sizeof(Node::pNext);
			m_nodesCount = nodesCount;
			m_pBlock = new char[nodesCount * sizeof(Node)];

			//@bug: the check will never evaluate to true
			if(m_pBlock == nullptr)
				return false;

			m_pNextFreeNode = (Node*)m_pBlock;

			// initializing the linked list of free nodes in the allocated block of memory
			Node* pCurrentNode = (Node*)m_pBlock;
			for(int i = 0; i < nodesCount - 1; ++i, ++pCurrentNode)
				pCurrentNode->pNext = pCurrentNode + 1;
			pCurrentNode->pNext = nullptr;

			return true;
		}

		T* Get()
		{
			//gets the next free from the memory pool
			//@address: inlined
			assert(m_pNextFreeNode != nullptr);

			// always leaves the last node free
			if(m_pNextFreeNode->pNext == nullptr)
				return nullptr;

			Node* pNode = m_pNextFreeNode;
			m_pNextFreeNode = m_pNextFreeNode->pNext;
			return &(pNode->data);
		}

		void Free(T* pData)
		{
			//returns the node to the memory pool
			//@address: inlined
			Node* pNode = (Node*)((char*)pData - m_dataOffset);
			pNode->pNext = m_pNextFreeNode;
			m_pNextFreeNode = pNode;
		}

	private:
		//@offset: 0
		char* m_pBlock;
		//@offset: 4
		Node* m_pNextFreeNode;
		//@offset: 8
		unsigned int m_nodesCount;
		//@offset: c
		//offset from the beginning of the node to data
		unsigned int m_dataOffset;
	};
}

#endif