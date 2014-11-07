/*
 * Copyright (c) 2014, Allwinner Technology Co., Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PLATFORM_H
#define PLATFORM_H

/*
 * Function specified by SMC Calling convention.
 *
 * SiP Service Calls
 *
 * Call register usage:
 * r0	SMC Function ID, TEESMC_OPTEE_FUNCID_SIP_SUNXI
 * r1	TEESMC_OPTEE_SIP_SUNXI_SET_SMP_BOOTENTRY set smp bootup entry
 */
#define TEESMC_OPTEE_SIP_SUNXI_SET_SMP_BOOTENTRY	(0xFFFF0000)

#define TEESMC_OPTEE_FUNCID_SIP_SUNXI			0x8000
#define TEESMC32_OPTEE_FAST_CALL_SIP_SUNXI \
	TEESMC_CALL_VAL(TEESMC_32, TEESMC_FAST_CALL, TEESMC_OWNER_SIP, \
			TEESMC_OPTEE_FUNCID_SIP_SUNXI)


/*
 * Function specified by SMC Calling convention.
 *
 * SiP Service Call Count
 *
 * This call returns a 32-bit count of the available
 * Service Calls. A return value of zero means no
 * services are available.
 */
#define TEESMC32_FUNCID_SIP_CALLS_COUNT	0xFF00
#define TEESMC32_SIP_SUNXI_CALLS_COUNT \
	TEESMC_CALL_VAL(TEESMC_32, TEESMC_FAST_CALL, \
			TEESMC_OWNER_SIP, \
			TEESMC32_FUNCID_CALLS_COUNT)

/*
 * Function specified by SMC Calling convention
 *
 * SiP Service Call UID
 *
 * Return the implementation of SiP Service Calls UID.
 *
 */
#define TEESMC_SIP_SUNXI_UID_R0			0xa5d5c51b
#define TEESMC_SIP_SUNXI_UID_R1			0x8d6c0002
#define TEESMC_SIP_SUNXI_UID_R2			0x6f8611e4
#define TEESMC_SIP_SUNXI_UID_R3			0x12b7e560
#define TEESMC32_FUNCID_SIP_SUNXI_CALLS_UID	0xFF01
#define TEESMC32_SIP_SUNXI_CALLS_UID \
	TEESMC_CALL_VAL(TEESMC_32, TEESMC_FAST_CALL, \
			TEESMC_OWNER_SIP, \
			TEESMC32_FUNCID_SIP_SUNXI_CALLS_UID)

void platform_init(void);
uint32_t platform_smc_handle(struct thread_smc_args *smc_args);

#endif /*PLATFORM_H*/
