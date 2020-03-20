//
// Created by derrick on 3/19/20.
//

#ifndef SE_VALGRIND_SE_DEFS_H
#define SE_VALGRIND_SE_DEFS_H

#include "../VEX/priv/guest_generic_bb_to_IR.h"
//#include "../VEX/priv/main_util.h"
#include "../coregrind/pub_core_machine.h"

/**
 * @brief Architecture specific macros. The offB* and szB_GUEST_IP are from
 * VEX/priv/main_main.c
 */

extern void vexSetAllocModeTEMP_and_clear(void);

#if defined(VGA_x86)
#include "../VEX/priv/guest_x86_defs.h"
#define SE_DISASM_TO_IR disInstr_X86
#define SE_offB_CMSTART offsetof(VexGuestX86State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestX86State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestX86State, guest_EIP)
#define SE_szB_GUEST_IP sizeof(((VexGuestX86State *)0)->guest_EIP)
#define SE_GUEST_WORD_TYPE Ity_I32
#elif defined(VGA_amd64)
#include "../VEX/priv/guest_amd64_defs.h"
#define SE_DISASM_TO_IR disInstr_AMD64
#define SE_offB_CMSTART offsetof(VexGuestAMD64State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestAMD64State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestAMD64State, guest_RIP)
#define SE_szB_GUEST_IP sizeof(((VexGuestAMD64State *)0)->guest_RIP)
#define SE_GUEST_WORD_TYPE Ity_I64
#elif defined(VGA_ppc32)
#include "../VEX/priv/guest_ppc_defs.h"
#define SE_DISASM_TO_IR disInstr_PPC
#define SE_offB_CMSTART offsetof(VexGuestPPC32State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestPPC32State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestPPC32State, guest_CIA)
#define SE_szB_GUEST_IP sizeof(((VexGuestPPC32State *)0)->guest_CIA)
#define SE_GUEST_WORD_TYPE Ity_I32
#elif defined(VGA_ppc64be) || defined(VGA_ppc64le)
#include "../VEX/priv/guest_ppc_defs.h"
#define SE_DISASM_TO_IR disInstr_PPC
#define SE_offB_CMSTART offsetof(VexGuestPPC64State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestPPC64State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestPPC64State, guest_CIA)
#define sSE_zB_GUEST_IP sizeof(((VexGuestPPC64State *)0)->guest_CIA)
#define SE_GUEST_WORD_TYPE Ity_I64
#elif defined(VGA_arm)
#include "../VEX/priv/guest_arm_defs.h"
#define SE_DISASM_TO_IR disInstr_ARM
#define SE_offB_CMSTART offsetof(VexGuestARMState, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestARMState, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestARMState, guest_R15T)
#define SE_szB_GUEST_IP sizeof(((VexGuestARMState *)0)->guest_R15T)
#define SE_GUEST_WORD_TYPE Ity_I32
#elif defined(VGA_arm64)
#include "../VEX/priv/guest_arm64_defs.h"
#define SE_DISASM_TO_IR disInstr_ARM64
#define SE_offB_CMSTART offsetof(VexGuestARM64State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestARM64State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestARM64State, guest_PC)
#define SE_szB_GUEST_IP sizeof(((VexGuestARM64State *)0)->guest_PC)
#define SE_GUEST_WORD_TYPE Ity_I64
#elif defined(VGA_s390x)
#include "../VEX/priv/guest_s390_defs.h"
#define SE_DISASM_TO_IR disInstr_S390
#define SE_offB_CMSTART = offsetof(VexGuestS390XState, guest_CMSTART)
#define SE_offB_CMLEN = offsetof(VexGuestS390XState, guest_CMLEN)
#define SE_offB_GUEST_IP = offsetof(VexGuestS390XState, guest_IA)
#define SE_szB_GUEST_IP = sizeof(((VexGuestS390XState *)0)->guest_IA)
#define SE_GUEST_WORD_TYPE Ity_I32
#elif defined(VGA_mips32)
#include "../VEX/priv/guest_mips_defs.h"
#define SE_DISASM_TO_IR disInstr_MIPS
#define SE_offB_CMSTART offsetof(VexGuestMIPS32State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestMIPS32State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestMIPS32State, guest_PC)
#define szB_GUEST_IP sizeof(((VexGuestMIPS32State *)0)->guest_PC)
#define SE_GUEST_WORD_TYPE Ity_I64
#elif defined(VGA_mips64)
#include "../VEX/priv/guest_mips_defs.h"
#define SE_DISASM_TO_IR disInstr_MIPS
#define SE_offB_CMSTART offsetof(VexGuestMIPS64State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestMIPS64State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestMIPS64State, guest_PC)
#define szB_GUEST_IP sizeof(((VexGuestMIPS64State *)0)->guest_PC)
#define SE_GUEST_WORD_TYPE Ity_I64
#elif defined(VGA_nanomips)
#include "../VEX/priv/guest_nanomips_defs.h"
#define SE_DISASM_TO_IR disInstr_nanoMIPS
#define SE_offB_CMSTART offsetof(VexGuestMIPS32State, guest_CMSTART)
#define SE_offB_CMLEN offsetof(VexGuestMIPS32State, guest_CMLEN)
#define SE_offB_GUEST_IP offsetof(VexGuestMIPS32State, guest_PC)
#define szB_GUEST_IP sizeof(((VexGuestMIPS32State *)0)->guest_PC)
#define SE_GUEST_WORD_TYPE Ity_I32
#else
#error Unknown arch
#endif

#endif // SE_VALGRIND_SE_DEFS_H
