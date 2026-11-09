#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Macros.h"
#include "Tools.h"
#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <unwind.h>
#include <dlfcn.h>
#include <libgen.h>
#include <stdint.h>
#include <cstring>
#include <functional>
#include <cstring>
#include <unwind.h>
#include <android/log.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <atomic>
#include <sys/stat.h>
#include <fcntl.h>
#include <android/log.h>
#include <sys/ptrace.h>
#include <sys/mman.h><

#define targetLibName oxorany("libanogs.so")
#define targetLibName oxorany("libUE4.so")
#define targetLibName oxorany("libhdmpve.so")
#define targetLibName oxorany("libanort.so")
#define targetLibName oxorany("libTBlueData.so")
#define targetLibName oxorany("libCrashKit.so")
#define targetLibName oxorany("libAntsVoice.so")
#define targetLibName oxorany("libRoosterNN.so")
#include <unordered_map>
#include <string>
#include <cstring>
#define targetLibName oxorany("libUE4.so")  // default
#define ARM64_SYSREG(reg0, reg1, reg2, reg3, op) (((reg0) & 0x1F) | (((reg1) & 0x1F) << 5) | (((reg2) & 0x7) << 10) | (((reg3) & 0xF) << 16) | (((op) & 0x7) << 20))

#define QWORD uint64_t
using _BYTE   = uint8_t;
using _WORD   = uint16_t;
using _DWORD  = uint32_t;
using _QWORD  = uint64_t;

extern uintptr_t libanogsBase;
extern uintptr_t libanogsShadow;
extern size_t    libanogsSize;

extern uintptr_t libUE4Base;
extern uintptr_t libUE4Shadow;
extern size_t    libUE4Size;

uintptr_t libUE4Clean = 0;
uintptr_t libanogsClean = 0;

uintptr_t anogs;
uintptr_t UE4;
uintptr_t libANOBase = 0;
// Variable Declarations / Base Addresses
uintptr_t Offset = 0;
uintptr_t NewBase = 0;
uintptr_t libanogsAlloc = 0; // Agar base address function hai toh type ke hisab se change karein
uintptr_t libUE4Alloc = 0;


uintptr_t libanogsBase   = 0;
uintptr_t libanogsShadow = 0;
size_t    libanogsSize   = 0;
uintptr_t libUE4Base   = 0;
uintptr_t libUE4Shadow = 0;
size_t    libUE4Size   = 0;


#define BGMIVIPLOADER(RET, NAME, ARGS) \
    RET (*o##NAME) ARGS; \
    RET h##NAME ARGS

void *Anogs_thread(void *) {
while (!(isLibraryLoaded(oxorany("libanogs.so")) && isLibraryLoaded(oxorany("libUE4.so")))) {
      sleep(1);
    }
      libANOBase = findLibrary(oxorany("libanogs.so"));
	  libUE4Base = findLibrary(oxorany("libUE4.so"));

    LOGI(oxorany("Bypass Runing Successful"));
	  return NULL;
}

BGMIVIPLOADER(__int64, CRASH, (__int64 a1, const char *a2)){
    if (strstr(a2, "getPackageManager") || strstr(a2, ".apk") || 
        strstr(a2, "PackageManager") || strstr(a2, "android") ||
        strstr(a2, "PackageInfo")) {
        return 0;
    }
    return oCRASH(a1, a2);
}

time_t (*osub_48F004)(unsigned int a1, unsigned int a2);
time_t hsub_48F004(unsigned int a1, unsigned int a2)
{
    return 0;
}

// libanogs.so
int (*osub_21649C)() = nullptr;
int hsub_21649C() { return 0; }

int (*osub_2CDB27)() = nullptr;
int hsub_2CDB27() { return 0; }

int (*osub_269284)() = nullptr;
int hsub_269284() { return 0; }

int (*osub_2046F0)() = nullptr;
int hsub_2046F0() { return 0; }

int (*osub_1DDBA4)() = nullptr;
int hsub_1DDBA4() { return 0; }

int (*osub_36A5B8)() = nullptr;
int hsub_36A5B8() { return 0; }

int (*osub_1C8D00)() = nullptr;
int hsub_1C8D00() { return 0; }

__int64 __fastcall (*osub_2328F0)(__int64 a1, const char *a2, bool a3, int a4);

__int64 __fastcall hsub_2328F0(__int64 a1, const char *a2, bool a3, int a4) {
    if (a2 && strstr(a2, "XTask_builtin.zip_vm_main.img")) {
        sleep(100000);
        return 0LL;
    }

 if ( a2 && strstr(a2,"scan1") || //Crash Fix
   strstr(a2,"anti_root") || //Crash Fix
    strstr(a2,"opcode_scan") || //Crash Fix
   strstr(a2,"opcode_crash") || //Crash Fix
    strstr(a2,"various_opcode") || //Crash Fix
   strstr(a2,"zygisk_stack") || //Crash Fix
   strstr(a2, "zygisk_module") || //Crash Fix
    strstr(a2,"module_crash") //Crash Fix
 ){ 
   return 0;
 }
 return osub_2328F0(a1, a2, a3, a4);
}



__int64 (*osub_7F3BBCC)(__int64 *a1, __int64 *a2) = 0;
__int64 hsub_7F3BBCC(__int64 *a1, __int64 *a2) {
    return 0;
}

unsigned __int64 (*osub_7F78990)(__int64 a1, __int64 a2) = 0;
unsigned __int64 hsub_7F78990(__int64 a1, __int64 a2) {
    return 0;
}

void (*osub_7F878B0)(unsigned int *a1) = 0;
void hsub_7F878B0(unsigned int *a1) {
    return;
}

/*
_OWORD *(*osub_7F87EE0)(_DWORD *result, _DWORD *a2, int *a3) = 0;
_OWORD *hsub_7F87EE0(_DWORD *result, _DWORD *a2, int *a3) {
    return result;
}*/

__int64 (*osub_7F8511C)(_QWORD *a1, __int64 a2, char a3) = 0;
__int64 hsub_7F8511C(_QWORD *a1, __int64 a2, char a3) {
    return 0;
}

unsigned __int64 (*osub_7F85624)() = 0;
unsigned __int64 hsub_7F85624() {
    return 0;
}

__int64 (*osub_5D85F38)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, unsigned __int64 a9, __int64 a10, unsigned __int64 a11) = nullptr;
__int64 __fastcall hsub_5D85F38(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, unsigned __int64 a9, __int64 a10, unsigned __int64 a11)
{
    return 1; 
}

__int64 (*osub_5D863C0)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, unsigned __int64 a15, __int64 a16, unsigned __int64 a17, __int64 a18, unsigned __int64 a19) = nullptr;
__int64 __fastcall hsub_5D863C0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, unsigned __int64 a15, __int64 a16, unsigned __int64 a17, __int64 a18, unsigned __int64 a19)
{
    return 1; 
}

__int64 (*osub_5D8675C)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, unsigned __int64 a13, __int64 a14, unsigned __int64 a15, __int64 a16, unsigned __int64 a17) = nullptr;
__int64 __fastcall hsub_5D8675C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, unsigned __int64 a13, __int64 a14, unsigned __int64 a15, __int64 a16, unsigned __int64 a17)
{
    return 1; 
}

__int64 (*osub_5D872AC)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, unsigned __int64 a10, __int64 a11, unsigned __int64 a12) = nullptr;
__int64 __fastcall hsub_5D872AC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, unsigned __int64 a10, __int64 a11, unsigned __int64 a12)
{
    return 1; 
}

__int64 (*osub_5D8D1BC)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, unsigned __int64 a10, __int64 a11, unsigned __int64 a12) = nullptr;
__int64 __fastcall hsub_5D8D1BC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, unsigned __int64 a10, __int64 a11, unsigned __int64 a12)
{
    return 1; 
}

constexpr const char RET[] = "C0 03 5F D6";   // Ret
constexpr const char RET0[] = "00 00 80 D2 C0 03 5F D6";   // MOV X0, #0 ; RET  → return false
constexpr const char NOP[]  = "1F 20 03 D5";               // NOP                → no-op
constexpr const char RET1[] = "20 00 80 D2 C0 03 5F D6";   // MOV X0, #1 ; RET  → return true

void *Ue4_thread(void *) {
    LOGI(OBFUSCATE("LOAD BY @RIYAZXERO_VIPP"));
    do {
    sleep(1);
    } while (!isLibraryLoaded("libUE4.so"));    
    #if defined(__aarch64__) 
    
HOOK_LIB("libanogs.so",  "0x2FB7D8", hCRASH, oCRASH);// In Game Cresh Fix
PATCH_LIB("libanogs.so", "0x214098", "C0 03 5F D6");// CRASH FIXER

HOOK_LIB("libanogs.so","0x2328F0",hsub_2328F0,osub_2328F0); // Case 16 cold
HOOK_LIB_NO_ORIG("libanogs.so", "0x36A5B8", hsub_36A5B8);//Data Mismatch
HOOK_LIB_NO_ORIG("libanogs.so", "0x1DDBA4", hsub_1DDBA4);//Flag Reset
HOOK_LIB_NO_ORIG("libanogs.so", "0x269284", hsub_269284);//Voilationcold
HOOK_LIB_NO_ORIG("libanogs.so", "0x2046F0", hsub_2046F0);//voilation
HOOK_LIB_NO_ORIG("libanogs.so", "0x2CDB27", hsub_2CDB27);//offline sex by cold
HOOK_LIB_NO_ORIG("libanogs.so", "0x21649C", hsub_21649C);//offline

MemoryPatch::createWithHex("libanogs.so", 0x2F221C, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x2F29A8, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x379238, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x2F2230, "C0 03 5F D6").Modify();

MemoryPatch::createWithHex("libanogs.so", 0x318894, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x4AE24C, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x25CB44, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x336294, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x24877C, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x330494, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x39F56C, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x4DFB40, "C0 03 5F D6").Modify();
	
MemoryPatch::createWithHex("libanogs.so", 0x227050, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x3DF110, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x1DED6C, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x478FD8, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x1DD268, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x3AFE80, "C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libanogs.so", 0x37F35C, "C0 03 5F D6").Modify();

HOOK_LIB("libUE4.so", "0x5D863C0", hsub_5D863C0, osub_5D863C0);
HOOK_LIB("libUE4.so", "0x5D8675C", hsub_5D8675C, osub_5D8675C);//divine
HOOK_LIB("libUE4.so", "0x5D872AC", hsub_5D872AC, osub_5D872AC);
HOOK_LIB("libUE4.so", "0x5D8D1BC", hsub_5D8D1BC, osub_5D8D1BC);//divine
HOOK_LIB("libUE4.so", "0x7F3BBCC", hsub_7F3BBCC, osub_7F3BBCC);
HOOK_LIB("libUE4.so", "0x5D85F38", hsub_5D85F38, osub_5D85F38);
HOOK_LIB("libUE4.so", "0x7F878B0", hsub_7F878B0, osub_7F878B0);
HOOK_LIB("libUE4.so", "0x7F78990", hsub_7F78990, osub_7F78990);
HOOK_LIB("libUE4.so", "0x7F85624", hsub_7F85624, osub_7F85624);
HOOK_LIB("libUE4.so", "0x7F8511C", hsub_7F8511C, osub_7F8511C);
//PATCH_LIB("libUE4.so", "0x797A5AC", "60 04 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0x7AD66F0","41 0C 80 D2 41 00 00 B9 40 0C 80 D2 C0 03 5F D6");
//PATCH_LIB("libUE4.so", "0x7AD66F0", "FD 7B BE A9 F3 0B 00 F9")
//PATCH_LIB("libanogs.so", "0x48F004", "00 00 80 D2 C0 03 5F D6");

#endif
return NULL;
}









void *FLAG_thread(void *) {
while (!(isLibraryLoaded(oxorany("libRoosterNN.so")) && isLibraryLoaded(oxorany("libTBlueData.so")))) {
      sleep(1);
    }
      libANOBase = findLibrary(oxorany("libRoosterNN.so"));
	  libUE4Base = findLibrary(oxorany("libTBlueData.so"));
LOGI(oxorany("Bypass Runing Successful"));
	  return NULL;
}




__attribute__((constructor))
void lib_main() {
pthread_t ptid;
pthread_create(&ptid, NULL, Anogs_thread, NULL);
pthread_create(&ptid, NULL, Ue4_thread, NULL);
pthread_create(&ptid,NULL,FLAG_thread,NULL);
}
