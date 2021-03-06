/******************************************************************************

  Copyright (c) 2001-2012, Intel Corporation 
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:
  
   1. Redistributions of source code must retain the above copyright notice, 
      this list of conditions and the following disclaimer.
  
   2. Redistributions in binary form must reproduce the above copyright 
      notice, this list of conditions and the following disclaimer in the 
      documentation and/or other materials provided with the distribution.
  
   3. Neither the name of the Intel Corporation nor the names of its 
      contributors may be used to endorse or promote products derived from 
      this software without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/
/*$FreeBSD$*/

#ifndef _IXGBE_OS_H_
#define _IXGBE_OS_H_

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <rte_common.h>
#include <rte_debug.h>
#include <rte_cycles.h>
#include <rte_log.h>
#include <rte_byteorder.h>

#include "../ixgbe_logs.h"

#define ASSERT(x) if(!(x)) rte_panic("IXGBE: x")

#define DELAY(x) rte_delay_us(x)
#define usec_delay(x) DELAY(x)
#define msec_delay(x) DELAY(1000*(x))

#define DEBUGFUNC(F)            DEBUGOUT(F);
#define DEBUGOUT(S, args...)    PMD_DRV_LOG(DEBUG, S, ##args)
#define DEBUGOUT1(S, args...)   DEBUGOUT(S, ##args)
#define DEBUGOUT2(S, args...)   DEBUGOUT(S, ##args)
#define DEBUGOUT3(S, args...)   DEBUGOUT(S, ##args)
#define DEBUGOUT6(S, args...)   DEBUGOUT(S, ##args)
#define DEBUGOUT7(S, args...)   DEBUGOUT(S, ##args)

#define FALSE               0
#define TRUE                1

#define false               0
#define true                1
#define min(a,b)	RTE_MIN(a,b) 

#define EWARN(hw, S, args...)     DEBUGOUT1(S, ##args)

/* Bunch of defines for shared code bogosity */
#define UNREFERENCED_PARAMETER(_p)  
#define UNREFERENCED_1PARAMETER(_p) 
#define UNREFERENCED_2PARAMETER(_p, _q)
#define UNREFERENCED_3PARAMETER(_p, _q, _r) 
#define UNREFERENCED_4PARAMETER(_p, _q, _r, _s) 

#define STATIC static
#define IXGBE_NTOHL(_i)	rte_be_to_cpu_32(_i)
#define IXGBE_NTOHS(_i)	rte_be_to_cpu_16(_i)
#define IXGBE_CPU_TO_LE32(_i)  rte_cpu_to_le_32(_i)
#define IXGBE_LE32_TO_CPUS(_i) rte_le_to_cpu_32(_i)

typedef uint8_t		u8;
typedef int8_t		s8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef int32_t		s32;
typedef uint64_t	u64;
typedef int		bool;

#define mb()	rte_mb()
#define wmb()	rte_wmb()
#define rmb()	rte_rmb()

#define prefetch(x) rte_prefetch0(x)

#define IXGBE_PCI_REG(reg) (*((volatile uint32_t *)(reg)))

static inline uint32_t ixgbe_read_addr(volatile void* addr)
{
	return IXGBE_PCI_REG(addr);
}

#define IXGBE_PCI_REG_WRITE(reg, value) do { \
	IXGBE_PCI_REG((reg)) = (value); \
} while(0)

#define IXGBE_PCI_REG_ADDR(hw, reg) \
	((volatile uint32_t *)((char *)(hw)->hw_addr + (reg)))

#define IXGBE_PCI_REG_ARRAY_ADDR(hw, reg, index) \
	IXGBE_PCI_REG_ADDR((hw), (reg) + ((index) << 2))

/* Not implemented !! */
#define IXGBE_READ_PCIE_WORD(hw, reg) 0	
#define IXGBE_WRITE_PCIE_WORD(hw, reg, value) do { } while(0)

#define IXGBE_WRITE_FLUSH(a) IXGBE_READ_REG(a, IXGBE_STATUS)

#define IXGBE_READ_REG(hw, reg) \
	ixgbe_read_addr(IXGBE_PCI_REG_ADDR((hw), (reg)))

#define IXGBE_WRITE_REG(hw, reg, value) \
	IXGBE_PCI_REG_WRITE(IXGBE_PCI_REG_ADDR((hw), (reg)), (value))

#define IXGBE_READ_REG_ARRAY(hw, reg, index) \
	IXGBE_PCI_REG(IXGBE_PCI_REG_ARRAY_ADDR((hw), (reg), (index)))

#define IXGBE_WRITE_REG_ARRAY(hw, reg, index, value) \
	IXGBE_PCI_REG_WRITE(IXGBE_PCI_REG_ARRAY_ADDR((hw), (reg), (index)), (value))

#endif /* _IXGBE_OS_H_ */
