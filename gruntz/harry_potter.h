#ifndef __GRUNTZ_HARRY_POTTER__
#define __GRUNTZ_HARRY_POTTER__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>

class UnknownClassCGruntzMgrHarryPotter;

class UnknownCGruntzMgrHogwarts : public CObject
{
protected:
	//@size: 8
	UnknownCGruntzMgrHogwarts() {}
	UnknownCGruntzMgrHogwarts(int unknown)
	{
		//@address: inlined
		m_fieldBaseUnknown = unknown;
	}

	virtual ~UnknownCGruntzMgrHogwarts()
	{
		// ?
	}

	//@offset: 4
	int m_fieldBaseUnknown;
};

class UnknownCGruntzMgrLucius : public UnknownCGruntzMgrHogwarts
{
public:
	//@size: 10
	UnknownCGruntzMgrLucius(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownCGruntzMgrLucius();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14();
	//@vftable: 18
	virtual bool VirtualMethodUnknown18();
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C();
	//@vftable: 20
	virtual void VirtualMethodUnknown20();

	//@offset: 0
	// base
	//@offset: 8
	int fieldUnknown8;
	//@offset: c
	UnknownClassCGruntzMgrHarryPotter* m_pUnknownHarryPotter;
};

class UnknownDraco: public UnknownCGruntzMgrLucius
{
public:
	//@size: 1c
	UnknownDraco(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownDraco();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	//skipped
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	virtual void VirtualMethodUnknown20() override;
	//@vftable: 24
	virtual void VirtualMethodUnknown24();

	//@offset: 0
	// base
	//@offset: 10
	int fieldUnknown10;
	//@offset: 14
	int fieldUnknown14;
	//@offset: 18
	int fieldUnknown18;
};


class UnknownHermiona: public UnknownCGruntzMgrLucius
{
public:
	//@size: 6c
	UnknownHermiona(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownHermiona();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	virtual bool VirtualMethodUnknown18() override;
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	virtual void VirtualMethodUnknown20() override;
	//@vftable: 24
	virtual void VirtualMethodUnknown24();
	//@vftable: 28
	virtual void VirtualMethodUnknown28();
	//@vftable: 2c
	virtual void VirtualMethodUnknown2C();
	//@vftable: 30
	virtual void VirtualMethodUnknown30();
	//@vftable: 34
	virtual void VirtualMethodUnknown34();
	//@vftable: 38
	virtual void VirtualMethodUnknown38();
	//@vftable: 3c
	virtual void VirtualMethodUnknown3C();
	//@vftable: 40
	virtual void VirtualMethodUnknown40();

	//@offset: 0
	// base
	//@offset: 10
	CObList m_unknownObList;
	//@offset: 2c
	CMapPtrToPtr m_unknownPtrMap1;
	//@offset: 48
	CMapPtrToPtr m_unknownPtrMap2;
	//@offset: 64
	int fieldUnknown64;
	//@offset: 68
	int fieldUnknown68;
};

class UnknownHagrid: public UnknownCGruntzMgrLucius
{
public:
	//@size: 2c
	UnknownHagrid(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownHagrid();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	virtual bool VirtualMethodUnknown18() override;
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	virtual void VirtualMethodUnknown20() override;
	//@vftable: 24
	virtual void VirtualMethodUnknown24();
	//@vftable: 28
	virtual void VirtualMethodUnknown28();
	//@vftable: 2c
	virtual void VirtualMethodUnknown2C();
	//@vftable: 30
	virtual void VirtualMethodUnknown30();
	//@vftable: 34
	virtual void VirtualMethodUnknown34();

	//@offset: 0
	// base
	//@offset: 10
	CObList m_unknownObList;
};

//@todo: replace with the correct structure from ddraw.h
struct UnknownDirectDrawStructure
{
	//@size: 64

	//@offset: 0
	DWORD dwSize;
	//@offset: 4
	char _padding04[96];
};

class UnknownSeverus : public UnknownCGruntzMgrLucius
{
public:
	//@size: 2c
	UnknownSeverus(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownSeverus();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	virtual bool VirtualMethodUnknown18() override;
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	virtual void VirtualMethodUnknown20() override;
	//@vftable: 24
	virtual void VirtualMethodUnknown24();
	//@vftable: 28
	virtual void VirtualMethodUnknown28();
	//@vftable: 2c
	virtual void VirtualMethodUnknown2C();
	//@vftable: 30
	virtual void VirtualMethodUnknown30();
	//@vftable: 34
	virtual void VirtualMethodUnknown34();
	//@vftable: 38
	virtual void VirtualMethodUnknown38();
	//@vftable: 3c
	virtual void VirtualMethodUnknown3C();
	//@vftable: 40
	virtual void VirtualMethodUnknown40();
	//@vftable: 44
	virtual void VirtualMethodUnknown44();
	//@vftable: 48
	virtual void VirtualMethodUnknown48();
	//@vftable: 4c
	virtual void VirtualMethodUnknown4C();
	//@vftable: 50
	virtual void VirtualMethodUnknown50();
	//@vftable: 54
	virtual void VirtualMethodUnknown54();
	//@vftable: 58
	virtual void VirtualMethodUnknown58();

	//@offset: 0
	//base
	//@offset: 10
	CMapStringToOb m_unknownMap;

	//@address: 006c0270
	static UnknownDirectDrawStructure staticUnknownDirectDrawStructure;
	//@address: 006c02d4
	static int staticUnknown1;
	//@address: 006c02d8
	static int staticUnknown2;
};

class UnknownSirius : public UnknownCGruntzMgrLucius
{
public:
	//@size: 2c
	UnknownSirius(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownSirius();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	virtual bool VirtualMethodUnknown18() override;
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	virtual void VirtualMethodUnknown20() override;
	//@vftable: 24
	virtual void VirtualMethodUnknown24();

	//@offset: 0
	//base
	//@offset: 10
	CMapStringToOb m_unknownMap;
};

class UnknownAlbus : public UnknownCGruntzMgrLucius
{
public:
	//@size: 68
	UnknownAlbus(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownAlbus();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	virtual bool VirtualMethodUnknown18() override;
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	virtual void VirtualMethodUnknown20() override;
	//@vftable: 24
	virtual void VirtualMethodUnknown24();
	//@vftable: 28
	virtual void VirtualMethodUnknown28();
	//@vftable: 2c
	virtual void VirtualMethodUnknown2C();
	//@vftable: 30
	virtual void VirtualMethodUnknown30();

	//@offset: 0
	// base
	//@offset: 10
	CMapStringToOb m_unknownMap1;
	//@offset: 2c
	CMapStringToOb m_unknownMap2;
	//@offset: 48
	CMapStringToOb m_unknownMap3;
	//@offset: 64
	int fieldUnknown64;
};

class UnknownRemus : public UnknownCGruntzMgrLucius
{
public:
	//@size: 6d4
	UnknownRemus(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownRemus();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	//skipped
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	virtual void VirtualMethodUnknown20() override;
	//@vftable: 24
	virtual void VirtualMethodUnknown24();
	//@vftable: 28
	virtual void VirtualMethodUnknown28();
	//@vftable: 2c
	virtual void VirtualMethodUnknown2C();
	//@vftable: 30
	virtual void VirtualMethodUnknown30();
	//@vftable: 34
	virtual void VirtualMethodUnknown34();
	//@vftable: 38
	virtual void VirtualMethodUnknown38();
	//@vftable: 3c
	virtual void VirtualMethodUnknown3C();
	//@vftable: 40
	virtual void VirtualMethodUnknown40();
	//@vftable: 44
	virtual void VirtualMethodUnknown44();

	//@offset: 0
	// base
	//@offset: 10
	int fieldUnknown10;
	//@offset: 14
	char _padding14[4];
	//@offset: 18
	char _padding18[4];
	//@offset: 1c
	char _padding1C[4];
	//@offset: 20
	CObArray m_unknownObArray1;
	//@offset: 34
	CObArray m_unknownObArray2;
	//@offset: 48
	CObArray m_unknownObArray3;
	//@offset: 5c
	int fieldUnknown5C;
	//@offset: 60
	int fieldUnknown60;
	//@offset: 64
	int fieldUnknown64;
	//@offset: 68
	int fieldUnknown68;
	//@offset: 6c
	char _padding6C[4];
	//@offset: 70
	char _padding70[4];
	//@offset: 74
	char _padding74[4];
	//@offset: 78
	char _padding78[4];
	//@offset: 7c
	char _padding7C[4];
	//@offset: 80
	char _padding80[4];
	//@offset: 84
	char _padding84[4];
	//@offset: 88
	char _padding88[4];
	//@offset: 8c
	char _padding8C[4];
	//@offset: 90
	char _padding90[4];
	//@offset: 94
	char _padding94[4];
	//@offset: 98
	char _padding98[4];
	//@offset: 9c
	char _padding9C[4];
	//@offset: a0
	char _paddingA0[4];
	//@offset: a4
	char _paddingA4[4];
	//@offset: a8
	char _paddingA8[4];
	//@offset: ac
	int fieldUnknownAC;
	//@offset: b0
	int fieldUnknownB0;
	//@offset: b4
	int fieldUnknownB4;
	//@offset: b8
	int fieldUnknownB8;
	//@offset: bc
	int fieldUnknownBC;
	//@offset: c0
	int fieldUnknownC0;
	//@offset: c4
	int fieldUnknownC4;
	//@offset: c8
	int fieldUnknownC8;
	//@offset: cc
	int fieldUnknownCC;
	//@offset: d0
	int fieldUnknownD0;
	//@offset: d4
	int fieldUnknownD4;
	//@offset: d8
	int fieldUnknownD8;
	//@offset: dc
	int fieldUnknownDC;
	//@offset: e0
	char _unknown_buffer[1524];
};

class UnknownMinerva : public UnknownCGruntzMgrLucius
{
public:
	//@size: 38
	UnknownMinerva(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownMinerva();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	//skipped
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	//skipped

	void ClearUnknownMap();

	//@offset: 0
	// base
	//@offset: 10
	CMapStringToPtr m_unknownMap;
	//@offset: 2c
	int fieldUnknown2C;
	//@offset: 30
	char _padding30[4];
	//@offset: 34
	int fieldUnknown34;
};

class UnknownPettigrew : public UnknownCGruntzMgrLucius
{
public:
	//@size: 2c
	UnknownPettigrew(UnknownClassCGruntzMgrHarryPotter* pUnknownHarryPotter, int unknown2, int unknown3);

	//@vftable: 0
	//skipped
	//@vftable: 4
	virtual ~UnknownPettigrew();
	//@vftable: 8
	//skipped
	//@vftable: c
	//skipped
	//@vftable: 10
	//skipped
	//@vftable: 14
	virtual void VirtualMethodUnknown14() override;
	//@vftable: 18
	virtual bool VirtualMethodUnknown18() override;
	//@vftable: 1c
	virtual void VirtualMethodUnknown1C() override;
	//@vftable: 20
	//skipped

	//@offset: 0
	//base
	//@offset: 10
	CMapStringToPtr m_unknownMap;
};

class UnknownFilch
{
public:
	//@size: 948
	UnknownFilch();

	//@offset: 0
	int fieldUnknown000;
	//@offset: 4
	int fieldUnknown004;
//@offset: 8
char _padding008[1140];
	//@offset: 47c
	CPtrList m_unknownPtrList1;
	//@offset: 498
	CPtrList m_unknownPtrList2;
	//@offset: 4b4
	CPtrArray m_unknownPtrArray;
//@offset: 4c8
char _padding4C8[108];
	//@offset: 534
	int fieldUnknown534;
	//@offset: 538
	int fieldUnknown538;
//@offset: 53c
char _padding53C[1024];
	//@offset: 93c
	int fieldUnknown93C;
	//@offset: 940
	int fieldUnknown940;
	//@offset: 944
	int fieldUnknown944;
};

class UnknownSalazar
{
public:
	//@size: 94
	UnknownSalazar();

	//@vftable: 0
	virtual ~UnknownSalazar();

	//@offset: 0
	//vft pointer
	//@offset: 4
	int fieldUnknown04;
	//@offset: 8
	int fieldUnknown08;
	//@offset: c
	int fieldUnknown0C;
	//@offset: 10
	int fieldUnknown10;
//@offset: 14
char _padding14[100];
	//@offset: 78
	int fieldUnknown78;
//@offset: 7c
char _padding7C[4];
	//@offset: 80
	int fieldUnknown80;
	//@offset: 84
	int fieldUnknown84;
	//@offset: 88
	int fieldUnknown88;
	//@offset: 8c
	int fieldUnknown8C;
	//@offset: 90
	int fieldUnknown90;

	static int unknownLookupTable[101];
	static void initializeUnknownLookupTable();
	static int getLookupTableValue(int index);
};

class UnknownVoldemort: public UnknownSalazar
{
public:
	//@size: 9c
	UnknownVoldemort();

	//@vftable: 0
	virtual ~UnknownVoldemort();

	//@offset: 0
	//base
	//@offset: 94
	int fieldUnknown94;
	//@offset: 98
	int fieldUnknown98;
};

class UnknownClassCGruntzMgrHarryPotter : public CObject
{
public:
	//@size: 0x40
	UnknownClassCGruntzMgrHarryPotter();
	virtual ~UnknownClassCGruntzMgrHarryPotter();

	//@vftable: 14
	virtual void UnknownVirtualMethod14();
	//@vftable: 18
	virtual bool UnknownVirtualMethod18(HWND hWnd, int unknown1, int unknown2, int unknown3, int flagsUnknown);
	//@vftable: 1c
	virtual void UnknownVirtualMethod1C();

	//@offset: 4
	UnknownCGruntzMgrLucius* fieldUnknownDraco;
	//@offset: 8
	UnknownCGruntzMgrLucius* fieldUnknownHermiona;
	//@offset: c
	UnknownCGruntzMgrLucius* fieldUnknownHagrid;
	//@offset: 10
	UnknownCGruntzMgrLucius* fieldUnknownSeverus;
	//@offset: 14
	UnknownCGruntzMgrLucius* fieldUnknownSirius;
	//@offset: 18
	UnknownCGruntzMgrLucius* fieldUnknownAlbus;
	//@offset: 1c
	UnknownFilch* fieldUnknownFilch;
	//@offset: 20
	UnknownVoldemort* fieldUnknownVoldemort;
	//@offset: 24
	UnknownCGruntzMgrLucius* fieldUnknownRemus;
	//@offset: 28
	UnknownMinerva* fieldUnknownMinerva;
	//@offset: 2c
	UnknownCGruntzMgrLucius* fieldUnknownPettigrew;
	//@offset: 30
	HWND m_hWnd;
	//@offset: 34
	int m_flagsUnknown;
	//@offset: 38
	int fieldUnknown38;
	//@offset: 3c
	int fieldUnknown3C;

	//@address: 006c0314
	static int staticUnknown1;
	//@address: 006c0318
	static int staticUnknown2;
};

#endif