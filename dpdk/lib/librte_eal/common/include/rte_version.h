/*-
 *   BSD LICENSE
 * 
 *   Copyright(c) 2010-2013 Intel Corporation. All rights reserved.
 *   All rights reserved.
 * 
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 * 
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * Definitions of Intel(R) DPDK version numbers
 */

#ifndef _RTE_VERSION_H_
#define _RTE_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <rte_common.h>

/**
 * String that appears before the version number
 */
#define RTE_VER_PREFIX "RTE"

/**
 * Major version number i.e. the x in x.y.z
 */
#define RTE_VER_MAJOR 1

/**
 * Minor version number i.e. the y in x.y.z
 */
#define RTE_VER_MINOR 5

/**
 * Patch level number i.e. the z in x.y.z
 */
#define RTE_VER_PATCH_LEVEL 0

/**
 * Extra string to be appended to version number,
 * for example: pre1, EAR, final etc.
 */
#define RTE_VER_SUFFIX "pre-release"

/**
 * Function returning string of version number: "RTE x.y.z"
 * @return
 *     string
 */
static inline const char *
rte_version(void) {
	if (sizeof(RTE_VER_SUFFIX) > sizeof(""))
		return RTE_VER_PREFIX" "
				RTE_STR(RTE_VER_MAJOR)"."
				RTE_STR(RTE_VER_MINOR)"."
				RTE_STR(RTE_VER_PATCH_LEVEL)
				"-"RTE_VER_SUFFIX;
	else
		return RTE_VER_PREFIX" "
				RTE_STR(RTE_VER_MAJOR)"."
				RTE_STR(RTE_VER_MINOR)"."
				RTE_STR(RTE_VER_PATCH_LEVEL);
}

#ifdef __cplusplus
}
#endif

#endif /* RTE_VERSION_H */
