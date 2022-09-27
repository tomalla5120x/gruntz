#include <cmath>

#include "harry_potter.h"
#include "../common.h"

int UnknownClassCGruntzMgrHarryPotter::staticUnknown1 = 0;
int UnknownClassCGruntzMgrHarryPotter::staticUnknown2 = 0;

UnknownClassCGruntzMgrHarryPotter::UnknownClassCGruntzMgrHarryPotter()
{
	//@address: 00555b20
	fieldUnknownDraco = nullptr;
	fieldUnknownHermiona = nullptr;
	fieldUnknownHagrid = nullptr;
	fieldUnknownSeverus = nullptr;
	fieldUnknownSirius = nullptr;
	fieldUnknownAlbus = nullptr;
	fieldUnknownFilch = nullptr;
	fieldUnknownVoldemort = nullptr;
	fieldUnknownRemus = nullptr;
	fieldUnknownMinerva = nullptr;
	fieldUnknownPettigrew = nullptr;
	m_flagsUnknown = 0;
	fieldUnknown38 = 0;
	fieldUnknown3C = 0;

	staticUnknown1 = 0;
	staticUnknown2 = 0;
}

UnknownClassCGruntzMgrHarryPotter::~UnknownClassCGruntzMgrHarryPotter()
{
	//@address: 00555b90
	UnknownVirtualMethod1C();
}

void UnknownClassCGruntzMgrHarryPotter::UnknownVirtualMethod14()
{
	//@address: 005561e0
	//@todo:
	throw NotImplemented();
}

bool UnknownClassCGruntzMgrHarryPotter::UnknownVirtualMethod18(HWND hWnd, int unknown1, int unknown2, int unknown3, int flagsUnknown)
{
	//@address: 00555be0
	m_hWnd = hWnd;
	m_flagsUnknown = flagsUnknown;

	fieldUnknownDraco = new UnknownDraco(this, 0, 0);
	fieldUnknownHermiona = new UnknownHermiona(this, 0, 0);
	fieldUnknownHagrid = new UnknownHagrid(this, 0, 0);
	fieldUnknownSeverus = new UnknownSeverus(this, 0, 0);
	fieldUnknownSirius = new UnknownSirius(this, 0, 0);
	fieldUnknownAlbus = new UnknownAlbus(this, 0, 0);
	fieldUnknownRemus = new UnknownRemus(this, 0, 0);
	fieldUnknownMinerva = new UnknownMinerva(this, 0, 0);
	fieldUnknownPettigrew = new UnknownPettigrew(this, 0, 0);

	fieldUnknownFilch = new UnknownFilch();
	fieldUnknownVoldemort = new UnknownVoldemort();
	
	//@address: 00555f1d
	if (!fieldUnknownHermiona->VirtualMethodUnknown18())
	{
		if(fieldUnknown38 == 0)
			fieldUnknown38 = 1001;
		return false;
	}

	if (!fieldUnknownHagrid->VirtualMethodUnknown18())
	{
		if (fieldUnknown38 == 0)
			fieldUnknown38 = 1002;
		return false;
	}

	if (!fieldUnknownSeverus->VirtualMethodUnknown18())
	{
		if (fieldUnknown38 == 0)
			fieldUnknown38 = 1003;
		return false;
	}
	
	if (!fieldUnknownSirius->VirtualMethodUnknown18())
	{
		if (fieldUnknown38 == 0)
			fieldUnknown38 = 1004;
		return false;
	}

	if (!fieldUnknownAlbus->VirtualMethodUnknown18())
	{
		if (fieldUnknown38 == 0)
			fieldUnknown38 = 1005;
		return false;
	}

	if (!fieldUnknownPettigrew->VirtualMethodUnknown18())
	{
		if (fieldUnknown38 == 0)
			fieldUnknown38 = 1006;
		return false;
	}

	//@address: 00555ff6


	//m_pGameWnd->m_hWnd, 0x280, 0x1e0, 0x10, flagUnknown
	// 
	//@todo:
	throw NotImplemented();
}

void UnknownClassCGruntzMgrHarryPotter::UnknownVirtualMethod1C()
{
	//@address: 00556100
	//@todo:
	throw NotImplemented();
	// free field pointers?
}

// ======================== LUCIUS ======================================

UnknownCGruntzMgrLucius::UnknownCGruntzMgrLucius(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrHogwarts(unknown2)
{
	//@address: 00556f90
	fieldUnknown8 = unknown3;
	m_pUnknownHarryPotter = pUnknownHarryPotter;
}

UnknownCGruntzMgrLucius::~UnknownCGruntzMgrLucius()
{
	//@address: 00555a00
	m_fieldBaseUnknown = -1;
	fieldUnknown8 = 0;
	m_pUnknownHarryPotter = nullptr;
}

void UnknownCGruntzMgrLucius::VirtualMethodUnknown14()
{
	//@address: 005559e0
	//@todo:
	throw NotImplemented();
}

bool UnknownCGruntzMgrLucius::VirtualMethodUnknown18()
{
	//@address: 00401c03
	return true;
}

void UnknownCGruntzMgrLucius::VirtualMethodUnknown1C()
{
	//@address: 00555a20
	//@todo:
	throw NotImplemented();
}

void UnknownCGruntzMgrLucius::VirtualMethodUnknown20()
{
	//@address: 00554ce0
	//@todo:
	throw NotImplemented();
}

// ======================================= DRACO ==========================================

UnknownDraco::UnknownDraco(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3): UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
	fieldUnknown10 = 0;
	fieldUnknown14 = 0;
	fieldUnknown18 = 0;
}

UnknownDraco::~UnknownDraco()
{
	//@address: 00557790
	VirtualMethodUnknown1C();
}

void UnknownDraco::VirtualMethodUnknown14()
{
	//@address: 00557760
	//@todo:
	throw NotImplemented();
}

void UnknownDraco::VirtualMethodUnknown1C()
{
	//@address: 00558da0
	//@todo:
	throw NotImplemented();
	// free resources
}

void UnknownDraco::VirtualMethodUnknown20()
{
	//@address: 00557780
	//@todo:
	throw NotImplemented();
}

void UnknownDraco::VirtualMethodUnknown24()
{
	//@address: 00558bd0
	//@todo:
	throw NotImplemented();
}

// ================================================ HERMIONA ===========================================================

UnknownHermiona::UnknownHermiona(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
	fieldUnknown64 = 0;
	fieldUnknown68 = 0;
}

UnknownHermiona::~UnknownHermiona()
{
	//@address: 005578f0
	VirtualMethodUnknown1C();
}

void UnknownHermiona::VirtualMethodUnknown14()
{
	//@address: 005578c0
	//@todo:
	throw NotImplemented();
}

bool UnknownHermiona::VirtualMethodUnknown18()
{
	//@address: 005579a0
	return true;
}

void UnknownHermiona::VirtualMethodUnknown1C()
{
	//@address: 005594c0
	// call to the VirtualMethodUnknown3C? Or is it an array of function pointers instead?
	// MOV  EAX,dword ptr [ECX]
	// JMP  dword ptr[EAX + 0x3c]
	// 
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown20()
{
	//@address: 005578e0
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown24()
{
	//@address: 00559d50
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown28()
{
	//@address: 00559f70
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown2C()
{
	//@address: 00559fa0
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown30()
{
	//@address: 00559fd0
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown34()
{
	//@address: 0055a020
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown38()
{
	//@address: 0055a070
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown3C()
{
	//@address: 005594d0
	//@todo:
	throw NotImplemented();
}

void UnknownHermiona::VirtualMethodUnknown40()
{
	//@address: 0055a1e0
	//@todo:
	throw NotImplemented();
}

// ================================================= HAGRID ====================================================

UnknownHagrid::UnknownHagrid(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
}

UnknownHagrid::~UnknownHagrid()
{
	//@address: 00557230
	VirtualMethodUnknown1C();
}

void UnknownHagrid::VirtualMethodUnknown14()
{
	//@address: 005571e0
	//@todo:
	throw NotImplemented();
}

bool UnknownHagrid::VirtualMethodUnknown18()
{
	//@address: 005572a0
	return true;
}

void UnknownHagrid::VirtualMethodUnknown1C()
{
	//@address: 00563ea0

	POSITION pos = m_unknownObList.GetHeadPosition();
	while (pos != nullptr)
	{
		CObject* pData = m_unknownObList.GetNext(pos);
		if(pData != nullptr)
			delete pData;
	}

	m_unknownObList.RemoveAll();
}

void UnknownHagrid::VirtualMethodUnknown20()
{
	//@address: 00557200
	//@todo:
	throw NotImplemented();
}

void UnknownHagrid::VirtualMethodUnknown24()
{
	//@address: 005572b0
	//@todo:
	throw NotImplemented();
}

void UnknownHagrid::VirtualMethodUnknown28()
{
	//@address: 005576c0
	//@todo:
	throw NotImplemented();
}

void UnknownHagrid::VirtualMethodUnknown2C()
{
	//@address: 00557610
	//@todo:
	throw NotImplemented();
}

void UnknownHagrid::VirtualMethodUnknown30()
{
	//@address: 00557430
	//@todo:
	throw NotImplemented();
}

void UnknownHagrid::VirtualMethodUnknown34()
{
	//@address: 00563ed0
	//@todo:
	throw NotImplemented();
}

// ======================================== SEVERUS ====================================================

int UnknownSeverus::staticUnknown1 = 0;
int UnknownSeverus::staticUnknown2 = 0;

UnknownSeverus::UnknownSeverus(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
}

UnknownSeverus::~UnknownSeverus()
{
	//@address: 005570d0
	VirtualMethodUnknown1C();
}

void UnknownSeverus::VirtualMethodUnknown14()
{
	//@address: 005570a0
	//@todo:
	throw NotImplemented();
}

bool UnknownSeverus::VirtualMethodUnknown18()
{
	//@address: 00554d80
	memset(&staticUnknownDirectDrawStructure, 0, sizeof(UnknownDirectDrawStructure));
	staticUnknownDirectDrawStructure.dwSize = sizeof(UnknownDirectDrawStructure);
	return true;
}

void UnknownSeverus::VirtualMethodUnknown1C()
{
	//@address: 00554da0
	VirtualMethodUnknown58();
	staticUnknown1 = 0;
	staticUnknown2 = 0;
}

void UnknownSeverus::VirtualMethodUnknown20()
{
	//@address: 005570c0
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown24()
{
	//@address: 005550d0
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown28()
{
	//@address: 00555240
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown2C()
{
	//@address: 00555220
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown30()
{
	//@address: 00554fc0
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown34()
{
	//@address: 00555200
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown38()
{
	//@address: 00554dc0
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown3C()
{
	//@address: 005551e0
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown40()
{
	//@address: 00554ec0
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown44()
{
	//@address: 00557160
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown48()
{
	//@address: 00555260
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown4C()
{
	//@address: 00555440
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown50()
{
	//@address: 00555560
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown54()
{
	//@address: 005571a0
	//@todo:
	throw NotImplemented();
}

void UnknownSeverus::VirtualMethodUnknown58()
{
	//@address: 00555590
	CString strKey;
	CObject* pObject;
	POSITION position = m_unknownMap.GetStartPosition();

	while (position != nullptr)
	{
		m_unknownMap.GetNextAssoc(position, strKey, pObject);

		if(pObject != nullptr)
			delete pObject;
	}

	m_unknownMap.RemoveAll();
}

// ================================================== SIRIUS ===================================================

UnknownSirius::UnknownSirius(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
}

UnknownSirius::~UnknownSirius()
{
	//@address: 005579e0
	VirtualMethodUnknown1C();
}

void UnknownSirius::VirtualMethodUnknown14()
{
	//@address: 005579b0
	//@todo:
	throw NotImplemented();
}

bool UnknownSirius::VirtualMethodUnknown18()
{
	//@address: 00557a70
	return true;
}

void UnknownSirius::VirtualMethodUnknown1C()
{
	//@address: 005654f0
	CString strKey;
	CObject* pObject;
	POSITION position = m_unknownMap.GetStartPosition();

	while (position != nullptr)
	{
		m_unknownMap.GetNextAssoc(position, strKey, pObject);

		if (pObject != nullptr)
			delete pObject;
	}

	m_unknownMap.RemoveAll();
}

void UnknownSirius::VirtualMethodUnknown20()
{
	//@address: 005579d0
	//@todo:
	throw NotImplemented();
}

void UnknownSirius::VirtualMethodUnknown24()
{
	//@address: 005655a0
	//@todo:
	throw NotImplemented();
}

// ============================================================== ALBUS ==========================================================

UnknownAlbus::UnknownAlbus(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
	fieldUnknown64 = 0;
}

UnknownAlbus::~UnknownAlbus()
{
	//@address: 00556fe0
	VirtualMethodUnknown1C();
}

void UnknownAlbus::VirtualMethodUnknown14()
{
	//@address: 00556fb0
	//@todo:
	throw NotImplemented();
}

bool UnknownAlbus::VirtualMethodUnknown18()
{
	//@address: 00557090
	return true;
}

void UnknownAlbus::VirtualMethodUnknown1C()
{
	//@address: 00565af0
	CString strKey;
	CObject* pObject;
	POSITION position = m_unknownMap1.GetStartPosition();

	while (position != nullptr)
	{
		m_unknownMap1.GetNextAssoc(position, strKey, pObject);

		if (pObject != nullptr)
			delete pObject;
	}

	m_unknownMap1.RemoveAll();
	fieldUnknown64 = 0;
}

void UnknownAlbus::VirtualMethodUnknown20()
{
	//@address: 00556fd0
	//@todo:
	throw NotImplemented();
}

void UnknownAlbus::VirtualMethodUnknown24()
{
	//@address: 00565ba0
	//@todo:
	throw NotImplemented();
}

void UnknownAlbus::VirtualMethodUnknown28()
{
	//@address: 00565c70
	//@todo:
	throw NotImplemented();
}

void UnknownAlbus::VirtualMethodUnknown2C()
{
	//@address: 00565cf0
	//@todo:
	throw NotImplemented();
}

void UnknownAlbus::VirtualMethodUnknown30()
{
	//@address: 00565d70
	//@todo:
	throw NotImplemented();
}

// ======================================================== REMUS ==============================================================

UnknownRemus::UnknownRemus(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: 0055cfb0
	fieldUnknown10 = INT_MIN;
	fieldUnknown5C = 0;
	fieldUnknown60 = -1;
	fieldUnknown64 = 64;
	fieldUnknown68 = 64;
	fieldUnknownAC = 0;
	fieldUnknownB0 = 500;
	fieldUnknownB4 = 250;
	fieldUnknownB8 = 1000;
	fieldUnknownBC = 1000;
	fieldUnknownC0 = 250;
	fieldUnknownC4 = 125;
	fieldUnknownC8 = 1600;
	fieldUnknownCC = 1200;
	fieldUnknownD0 = 2560;
	fieldUnknownD4 = 1920;
	fieldUnknownD8 = 768;
	fieldUnknownDC = 576;
}

UnknownRemus::~UnknownRemus()
{
	//@address: 005614a0
	VirtualMethodUnknown1C();
}

void UnknownRemus::VirtualMethodUnknown14()
{
	//@address: 00561470
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown1C()
{
	//@address: 0055d4d0
	for(int i=0; i<m_unknownObArray2.GetSize(); ++i)
		if(m_unknownObArray2[i] != nullptr)
			delete m_unknownObArray2[i];

	m_unknownObArray2.SetSize(0);

	for (int i = 0; i < m_unknownObArray3.GetSize(); ++i)
		if (m_unknownObArray3[i] != nullptr)
			delete m_unknownObArray3[i];

	m_unknownObArray3.SetSize(0);

	memset(_unknown_buffer, 0, sizeof(_unknown_buffer));

	fieldUnknown10 = INT_MIN;
	fieldUnknown5C = 0;
	fieldUnknown60 = -1;
}

void UnknownRemus::VirtualMethodUnknown20()
{
	//@address: 00561490
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown24()
{
	//@address: 0055d250
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown28()
{
	//@address: 0055d190
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown2C()
{
	//@address: 0055d0d0
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown30()
{
	//@address: 0055d3b0
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown34()
{
	//@address: 0055d310
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown38()
{
	//@address: 0055d560
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown3C()
{
	//@address: 0055d910
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown40()
{
	//@address: 0055d7e0
	//@todo:
	throw NotImplemented();
}

void UnknownRemus::VirtualMethodUnknown44()
{
	//@address: 0055d960
	//@todo:
	throw NotImplemented();
}

// ======================================================== MINERVA ==========================================================

UnknownMinerva::UnknownMinerva(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
	fieldUnknown2C = 0;
	fieldUnknown34 = 0;
}

UnknownMinerva::~UnknownMinerva()
{
	//@address: 00557830
	VirtualMethodUnknown1C();
}

void UnknownMinerva::VirtualMethodUnknown14()
{
	//@address: 00557810
	//@todo:
	throw NotImplemented();
}

void UnknownMinerva::VirtualMethodUnknown1C()
{
	//@address: 00557dc0
	ClearUnknownMap();
	fieldUnknown2C = 0;
}

void UnknownMinerva::ClearUnknownMap()
{
	//@address: 00557ea0
	CString strKey;
	void* pPtr;
	POSITION position = m_unknownMap.GetStartPosition();

	while (position != nullptr)
	{
		m_unknownMap.GetNextAssoc(position, strKey, pPtr);

		if (pPtr != nullptr)
		{
			// instead of calling the free operator, it's calling the virtual method +0x4 (as if it was a vector deleting destructor)
			// hence it's probably interpreted as the CObject pointer anyways
			CObject* pObject = (CObject*) pPtr;
			delete pObject;
		}
	}

	m_unknownMap.RemoveAll();
}

// ========================================= PETTIGREW ====================================================

UnknownPettigrew::UnknownPettigrew(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3) : UnknownCGruntzMgrLucius(pUnknownHarryPotter, unknown2, unknown3)
{
	//@address: inlined
}

UnknownPettigrew::~UnknownPettigrew()
{
	//@address: 00557aa0
	VirtualMethodUnknown1C();
}

void UnknownPettigrew::VirtualMethodUnknown14()
{
	//@address: 00557a80
	//@todo:
	throw NotImplemented();
}

bool UnknownPettigrew::VirtualMethodUnknown18()
{
	//@address: 00552920
	return true;
}

void UnknownPettigrew::VirtualMethodUnknown1C()
{
	//@address: 00552930
	CString strKey;
	void* pPtr;
	POSITION position = m_unknownMap.GetStartPosition();

	while (position != nullptr)
	{
		m_unknownMap.GetNextAssoc(position, strKey, pPtr);

		if (pPtr != nullptr)
		{
			// instead of calling the free operator, it's calling the virtual method +0x4 (as if it was a vector deleting destructor)
			// hence it's probably interpreted as the CObject pointer anyways
			CObject* pObject = (CObject*)pPtr;
			delete pObject;
		}
	}

	m_unknownMap.RemoveAll();
}

// ============================================= FILCH ================================================

UnknownFilch::UnknownFilch()
{
	//@address: 00541fa0
	fieldUnknown000 = 0;
	fieldUnknown004 = 0;
	fieldUnknown534 = 0;
	fieldUnknown538 = 0;
	fieldUnknown93C = 0;
	fieldUnknown940 = 0;
	fieldUnknown944 = 0;
}

// ============================================ SALAZAR ================================================

int UnknownSalazar::unknownLookupTable[101] = {0};

UnknownSalazar::UnknownSalazar()
{
	//@address: 00536650
	fieldUnknown04 = 0;
	fieldUnknown08 = 0;
	fieldUnknown0C = 0;
	fieldUnknown10 = 0;
	fieldUnknown78 = 0;
	fieldUnknown80 = 0;
	fieldUnknown84 = 0;
	fieldUnknown88 = 0;
	fieldUnknown8C = 0;
	fieldUnknown90 = 0;

	initializeUnknownLookupTable();
}

UnknownSalazar::~UnknownSalazar()
{
	//@address: 005366d0
	if (fieldUnknown78 != NULL)
	{
		//@todo:
		throw NotImplemented();
	}
}

void UnknownSalazar::initializeUnknownLookupTable()
{
	//@address: 005353b0
	for (int nIndex = 0; nIndex <= 100; ++nIndex)
		unknownLookupTable[nIndex] = getLookupTableValue(nIndex);
}

int UnknownSalazar::getLookupTableValue(int index)
{
	//@address: 005352c0
	if(index == 0)
		return -10000;
	else if(index == 100)
		return 0;
	else
	{
		//@note: I've experimentally double checked that the generated values are the same on my build as they are in the game
		// however just in case, here are the exact 101 values generated by the game binary:
		// -10000;-6643;-5643;-5058;-4643;-4321;-4058;-3836;-3643;-3473;-3321;-3184;-3058;-2943;-2836;-2736;-2643;-2556;-2473;-2395;-2321;-2251;-2184;-2120;-2058;-2000;-1943;-1888;-1836;-1785;-1736;-1689;-1643;-1599;-1556;-1514;-1473;-1434;-1395;-1358;-1321;-1286;-1251;-1217;-1184;-1152;-1120;-1089;-1058;-1029;-1000;-971;-943;-915;-888;-862;-836;-810;-785;-761;-736;-713;-689;-666;-643;-621;-599;-577;-556;-535;-514;-494;-473;-454;-434;-415;-395;-377;-358;-340;-321;-304;-286;-268;-251;-234;-217;-200;-184;-168;-152;-136;-120;-104;-89;-74;-58;-43;-29;-14;0
		return static_cast<int>(-1000.0 * std::log2(100.0 / index));
	}
}

// ================================================================ VOLDEMORT ===========================================================

UnknownVoldemort::UnknownVoldemort()
{
	//@address: 005378e0
	fieldUnknown94 = 0;
	fieldUnknown98 = 0;
}

UnknownVoldemort::~UnknownVoldemort()
{
	//@address: 00537900
	//@note: empty
}
