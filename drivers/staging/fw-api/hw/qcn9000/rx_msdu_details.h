/*
 * Copyright (c) 2019, The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _RX_MSDU_DETAILS_H_
#define _RX_MSDU_DETAILS_H_
#if !defined(__ASSEMBLER__)
#endif

#include "buffer_addr_info.h"
#include "rx_msdu_desc_info.h"

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0-1	struct buffer_addr_info buffer_addr_info_details;
//	2-3	struct rx_msdu_desc_info rx_msdu_desc_info_details;
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_RX_MSDU_DETAILS 4

struct rx_msdu_details {
    struct            buffer_addr_info                       buffer_addr_info_details;
    struct            rx_msdu_desc_info                       rx_msdu_desc_info_details;
};

/*

struct buffer_addr_info buffer_addr_info_details
			
			Consumer: REO/SW
			
			Producer: RXDMA
			
			
			
			Details of the physical address of the buffer containing
			an MSDU (or entire MPDU)

struct rx_msdu_desc_info rx_msdu_desc_info_details
			
			Consumer: REO/SW
			
			Producer: RXDMA
			
			
			
			General information related to the MSDU that should be
			passed on from RXDMA all the way to to the REO destination
			ring.
*/


 /* EXTERNAL REFERENCE : struct buffer_addr_info buffer_addr_info_details */ 


/* Description		RX_MSDU_DETAILS_0_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_31_0
			
			Address (lower 32 bits) of the MSDU buffer OR
			MSDU_EXTENSION descriptor OR Link Descriptor
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			<legal all>
*/
#define RX_MSDU_DETAILS_0_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_31_0_OFFSET 0x00000000
#define RX_MSDU_DETAILS_0_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_31_0_LSB 0
#define RX_MSDU_DETAILS_0_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_31_0_MASK 0xffffffff

/* Description		RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_39_32
			
			Address (upper 8 bits) of the MSDU buffer OR
			MSDU_EXTENSION descriptor OR Link Descriptor
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			<legal all>
*/
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_39_32_OFFSET 0x00000004
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_39_32_LSB 0
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_BUFFER_ADDR_39_32_MASK 0x000000ff

/* Description		RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_RETURN_BUFFER_MANAGER
			
			Consumer: WBM
			
			Producer: SW/FW
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			
			
			Indicates to which buffer manager the buffer OR
			MSDU_EXTENSION descriptor OR link descriptor that is being
			pointed to shall be returned after the frame has been
			processed. It is used by WBM for routing purposes.
			
			
			
			<enum 0 WBM_IDLE_BUF_LIST> This buffer shall be returned
			to the WMB buffer idle list
			
			<enum 1 WBM_IDLE_DESC_LIST> This buffer shall be
			returned to the WMB idle link descriptor idle list
			
			<enum 2 FW_BM> This buffer shall be returned to the FW
			
			<enum 3 SW0_BM> This buffer shall be returned to the SW,
			ring 0
			
			<enum 4 SW1_BM> This buffer shall be returned to the SW,
			ring 1
			
			<enum 5 SW2_BM> This buffer shall be returned to the SW,
			ring 2
			
			<enum 6 SW3_BM> This buffer shall be returned to the SW,
			ring 3
			
			<enum 7 SW4_BM> This buffer shall be returned to the SW,
			ring 4
			
			
			
			<legal all>
*/
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_RETURN_BUFFER_MANAGER_OFFSET 0x00000004
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_RETURN_BUFFER_MANAGER_LSB 8
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_RETURN_BUFFER_MANAGER_MASK 0x00000700

/* Description		RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_SW_BUFFER_COOKIE
			
			Cookie field exclusively used by SW. 
			
			
			
			In case of 'NULL' pointer, this field is set to 0
			
			
			
			HW ignores the contents, accept that it passes the
			programmed value on to other descriptors together with the
			physical address 
			
			
			
			Field can be used by SW to for example associate the
			buffers physical address with the virtual address
			
			The bit definitions as used by SW are within SW HLD
			specification
			
			
			
			NOTE:
			
			The three most significant bits can have a special
			meaning in case this struct is embedded in a TX_MPDU_DETAILS
			STRUCT, and field transmit_bw_restriction is set
			
			
			
			In case of NON punctured transmission:
			
			Sw_buffer_cookie[20:19] = 2'b00: 20 MHz TX only
			
			Sw_buffer_cookie[20:19] = 2'b01: 40 MHz TX only
			
			Sw_buffer_cookie[20:19] = 2'b10: 80 MHz TX only
			
			Sw_buffer_cookie[20:19] = 2'b11: 160 MHz TX only
			
			
			
			In case of punctured transmission:
			
			Sw_buffer_cookie[20:18] = 3'b000: pattern 0 only
			
			Sw_buffer_cookie[20:18] = 3'b001: pattern 1 only
			
			Sw_buffer_cookie[20:18] = 3'b010: pattern 2 only
			
			Sw_buffer_cookie[20:18] = 3'b011: pattern 3 only
			
			Sw_buffer_cookie[20:18] = 3'b100: pattern 4 only
			
			Sw_buffer_cookie[20:18] = 3'b101: pattern 5 only
			
			Sw_buffer_cookie[20:18] = 3'b110: pattern 6 only
			
			Sw_buffer_cookie[20:18] = 3'b111: pattern 7 only
			
			
			
			Note: a punctured transmission is indicated by the
			presence of TLV TX_PUNCTURE_SETUP embedded in the scheduler
			TLV
			
			
			
			<legal all>
*/
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_SW_BUFFER_COOKIE_OFFSET 0x00000004
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_SW_BUFFER_COOKIE_LSB 11
#define RX_MSDU_DETAILS_1_BUFFER_ADDR_INFO_DETAILS_SW_BUFFER_COOKIE_MASK 0xfffff800

 /* EXTERNAL REFERENCE : struct rx_msdu_desc_info rx_msdu_desc_info_details */ 


/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_FIRST_MSDU_IN_MPDU_FLAG
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU 
			
			
			
			<enum 0 Not_first_msdu> This is not the first MSDU in
			the MPDU. 
			
			<enum 1 first_msdu> This MSDU is the first one in the
			MPDU.
			
			
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_FIRST_MSDU_IN_MPDU_FLAG_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_FIRST_MSDU_IN_MPDU_FLAG_LSB 0
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_FIRST_MSDU_IN_MPDU_FLAG_MASK 0x00000001

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_LAST_MSDU_IN_MPDU_FLAG
			
			Consumer: WBM/REO/SW/FW
			
			Producer: RXDMA
			
			
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU
			
			
			
			<enum 0 Not_last_msdu> There are more MSDUs linked to
			this MSDU that belongs to this MPDU 
			
			<enum 1 Last_msdu> this MSDU is the last one in the
			MPDU. This setting is only allowed in combination with
			'Msdu_continuation' set to 0. This implies that when an msdu
			is spread out over multiple buffers and thus
			msdu_continuation is set, only for the very last buffer of
			the msdu, can the 'last_msdu_in_mpdu_flag' be set.
			
			
			
			When both first_msdu_in_mpdu_flag and
			last_msdu_in_mpdu_flag are set, the MPDU that this MSDU
			belongs to only contains a single MSDU.
			
			
			
			
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_LAST_MSDU_IN_MPDU_FLAG_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_LAST_MSDU_IN_MPDU_FLAG_LSB 1
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_LAST_MSDU_IN_MPDU_FLAG_MASK 0x00000002

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_CONTINUATION
			
			When set, this MSDU buffer was not able to hold the
			entire MSDU. The next buffer will therefor contain
			additional information related to this MSDU.
			
			
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_CONTINUATION_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_CONTINUATION_LSB 2
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_CONTINUATION_MASK 0x00000004

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_LENGTH
			
			Parsed from RX_MSDU_START TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the First
			buffer used by MSDU.
			
			 
			
			Full MSDU length in bytes after decapsulation. 
			
			
			
			This field is still valid for MPDU frames without
			A-MSDU.  It still represents MSDU length after decapsulation
			
			
			
			Or in case of RAW MPDUs, it indicates the length of the
			entire MPDU (without FCS field)
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_LENGTH_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_LENGTH_LSB  3
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_LENGTH_MASK 0x0001fff8

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_REO_DESTINATION_INDICATION
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU
			
			 
			
			The ID of the REO exit ring where the MSDU frame shall
			push after (MPDU level) reordering has finished.
			
			
			
			<enum 0 reo_destination_tcl> Reo will push the frame
			into the REO2TCL ring
			
			<enum 1 reo_destination_sw1> Reo will push the frame
			into the REO2SW1 ring
			
			<enum 2 reo_destination_sw2> Reo will push the frame
			into the REO2SW2 ring
			
			<enum 3 reo_destination_sw3> Reo will push the frame
			into the REO2SW3 ring
			
			<enum 4 reo_destination_sw4> Reo will push the frame
			into the REO2SW4 ring
			
			<enum 5 reo_destination_release> Reo will push the frame
			into the REO_release ring
			
			<enum 6 reo_destination_fw> Reo will push the frame into
			the REO2FW ring
			
			<enum 7 reo_destination_sw5> Reo will push the frame
			into the REO2SW5 ring (REO remaps this in chips without
			REO2SW5 ring, e.g. Pine) 
			
			<enum 8 reo_destination_sw6> Reo will push the frame
			into the REO2SW6 ring (REO remaps this in chips without
			REO2SW6 ring, e.g. Pine)
			
			 <enum 9 reo_destination_9> REO remaps this <enum 10
			reo_destination_10> REO remaps this 
			
			<enum 11 reo_destination_11> REO remaps this 
			
			<enum 12 reo_destination_12> REO remaps this <enum 13
			reo_destination_13> REO remaps this 
			
			<enum 14 reo_destination_14> REO remaps this 
			
			<enum 15 reo_destination_15> REO remaps this 
			
			<enum 16 reo_destination_16> REO remaps this 
			
			<enum 17 reo_destination_17> REO remaps this 
			
			<enum 18 reo_destination_18> REO remaps this 
			
			<enum 19 reo_destination_19> REO remaps this 
			
			<enum 20 reo_destination_20> REO remaps this 
			
			<enum 21 reo_destination_21> REO remaps this 
			
			<enum 22 reo_destination_22> REO remaps this 
			
			<enum 23 reo_destination_23> REO remaps this 
			
			<enum 24 reo_destination_24> REO remaps this 
			
			<enum 25 reo_destination_25> REO remaps this 
			
			<enum 26 reo_destination_26> REO remaps this 
			
			<enum 27 reo_destination_27> REO remaps this 
			
			<enum 28 reo_destination_28> REO remaps this 
			
			<enum 29 reo_destination_29> REO remaps this 
			
			<enum 30 reo_destination_30> REO remaps this 
			
			<enum 31 reo_destination_31> REO remaps this 
			
			
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_REO_DESTINATION_INDICATION_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_REO_DESTINATION_INDICATION_LSB 17
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_REO_DESTINATION_INDICATION_MASK 0x003e0000

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_DROP
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU
			
			 
			
			When set, REO shall drop this MSDU and not forward it to
			any other ring...
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_DROP_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_DROP_LSB    22
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_MSDU_DROP_MASK   0x00400000

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IS_VALID
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU
			
			 
			
			Indicates that OLE found a valid SA entry for this MSDU
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IS_VALID_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IS_VALID_LSB  23
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IS_VALID_MASK 0x00800000

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU
			
			 
			
			Indicates an unsuccessful MAC source address search due
			to the expiring of the search timer for this MSDU
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT_LSB 24
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_SA_IDX_TIMEOUT_MASK 0x01000000

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_VALID
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU
			
			 
			
			Indicates that OLE found a valid DA entry for this MSDU
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_VALID_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_VALID_LSB  25
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_VALID_MASK 0x02000000

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_MCBC
			
			Field Only valid if da_is_valid is set
			
			
			
			Indicates the DA address was a Multicast of Broadcast
			address for this MSDU
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_MCBC_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_MCBC_LSB   26
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IS_MCBC_MASK  0x04000000

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT
			
			Parsed from RX_MSDU_END TLV . In the case MSDU spans
			over multiple buffers, this field will be valid in the Last
			buffer used by the MSDU
			
			 
			
			Indicates an unsuccessful MAC destination address search
			due to the expiring of the search timer for this MSDU
			
			<legal all>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT_LSB 27
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_DA_IDX_TIMEOUT_MASK 0x08000000

/* Description		RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_RESERVED_0A
			
			<legal 0>
*/
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_RESERVED_0A_OFFSET 0x00000008
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_RESERVED_0A_LSB  28
#define RX_MSDU_DETAILS_2_RX_MSDU_DESC_INFO_DETAILS_RESERVED_0A_MASK 0xf0000000

/* Description		RX_MSDU_DETAILS_3_RX_MSDU_DESC_INFO_DETAILS_RESERVED_1A
			
			<legal 0>
*/
#define RX_MSDU_DETAILS_3_RX_MSDU_DESC_INFO_DETAILS_RESERVED_1A_OFFSET 0x0000000c
#define RX_MSDU_DETAILS_3_RX_MSDU_DESC_INFO_DETAILS_RESERVED_1A_LSB  0
#define RX_MSDU_DETAILS_3_RX_MSDU_DESC_INFO_DETAILS_RESERVED_1A_MASK 0xffffffff


#endif // _RX_MSDU_DETAILS_H_
