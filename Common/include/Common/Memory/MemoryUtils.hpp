#pragma once
#include "Core/core.hpp"
#include "LoadMemory.hpp"


// Bytes that dont represent a type (typeless)
typedef u8 TL8;
typedef u16 TL16;
typedef u32 TL32;
typedef u64 TL64;

class WindowsMemory {

private:
	HANDLE Hproc = INVALID_HANDLE_VALUE;
	HMODULE Hmod = NULL;

public:
	DLL_PUBLIC void Initialise(HANDLE ProcessHandle, HMODULE ModuleHandle);

	// Returns offset
	DLL_PUBLIC inline u32 OffsetFromMod(u32 offset);
	DLL_PUBLIC inline u64 OffsetFromMod(u64 offset);

	// Returns dereffed offset.
	DLL_PUBLIC inline u32 PtrFromMod(u32 offset);
	DLL_PUBLIC inline u64 PtrFromMod(u64 offset);

	// Buffer must be allocated before calling
	DLL_PUBLIC void ReadMemory(u64 Offset, u8* Buffer, u64 Len);

	DLL_PUBLIC void WriteMemory(u64 Offset, u8* Bytes, u64 Len);

	DLL_PUBLIC inline void Read(u32 Addr, u32* Ret);
	DLL_PUBLIC inline void Read(u64 Addr, u64* Ret);

	DLL_PUBLIC inline void Write(u32 Addr, u32* Ret);
	DLL_PUBLIC inline void Write(u64 Addr, u64* Ret);

	DLL_PUBLIC inline u32 Deref(u32 Addr);
	DLL_PUBLIC inline u32 Deref(u32* Addr);
	DLL_PUBLIC inline u64 Deref(u64 Addr);
	DLL_PUBLIC inline u64 Deref(u64* Addr);


	DLL_PUBLIC TL32 MultiLevelPtr(u32 BaseAddr, std::vector<u32> Offsets);
	DLL_PUBLIC TL64 MultiLevelPtr(u64 BaseAddr, std::vector<u64> Offsets);

	

};