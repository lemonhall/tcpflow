/* $Id: ieee802_11.h,v 1.1.1.1 2006/12/14 01:22:11 jpang Exp $ */
/* @(#) $Header: /home/cvs/wifitools/wifipcap/ieee802_11.h,v 1.1.1.1 2006/12/14 01:22:11 jpang Exp $ (LBL) */
/*
 * Copyright (c) 2001
 *	Fortress Technologies
 *      Charlie Lenahan ( clenahan@fortresstech.com )
 * 2013-03-15 - Simson Garfinkel - Updated for compiling on a modern compiler.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: (1) source code distributions
 * retain the above copyright notice and this paragraph in its entirety, (2)
 * distributions including binary code include the above copyright notice and
 * this paragraph in its entirety in the documentation or other materials
 * provided with the distribution, and (3) all advertising materials mentioning
 * features or use of this software display the following acknowledgement:
 * ``This product includes software developed by the University of California,
 * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
 * the University nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef _WLANSEC_IEEE802_11_H
#define _WLANSEC_IEEE802_11_H 1

typedef WifipcapCallbacks::MAC MAC;

//static const char *charlie_lenahan_copyright="Portions Copyright (C) 2001 Fortress Technologies";

/* Lengths of 802.11 header components. */
#define	IEEE802_11_FC_LEN		2
#define	IEEE802_11_DUR_LEN		2
#define	IEEE802_11_DA_LEN		6
#define	IEEE802_11_SA_LEN		6
#define	IEEE802_11_BSSID_LEN		6
#define	IEEE802_11_RA_LEN		6
#define	IEEE802_11_TA_LEN		6
#define	IEEE802_11_SEQ_LEN		2
#define	IEEE802_11_IV_LEN		3
#define	IEEE802_11_KID_LEN		1

/* Frame check sequence length. */
#define	IEEE802_11_FCS_LEN		4

/* Lengths of beacon components. */
#define	IEEE802_11_TSTAMP_LEN		8
#define	IEEE802_11_BCNINT_LEN		2
#define	IEEE802_11_CAPINFO_LEN		2
#define	IEEE802_11_LISTENINT_LEN	2

#define	IEEE802_11_AID_LEN		2
#define	IEEE802_11_STATUS_LEN		2
#define	IEEE802_11_REASON_LEN		2

/* Length of previous AP in reassocation frame */
#define	IEEE802_11_AP_LEN		6

#define	T_MGMT 0x0		/* management */
#define	T_CTRL 0x1		/* control */
#define	T_DATA 0x2		/* data */
#define	T_RESV 0x3		/* reserved */

#define	ST_ASSOC_REQUEST   	0x0
#define	ST_ASSOC_RESPONSE 	0x1
#define	ST_REASSOC_REQUEST   	0x2
#define	ST_REASSOC_RESPONSE  	0x3
#define	ST_PROBE_REQUEST   	0x4
#define	ST_PROBE_RESPONSE   	0x5
/* RESERVED 			0x6  */
/* RESERVED 			0x7  */
#define	ST_BEACON   		0x8
#define	ST_ATIM			0x9
#define	ST_DISASSOC		0xA
#define	ST_AUTH			0xB
#define	ST_DEAUTH		0xC
/* RESERVED 			0xD  */
/* RESERVED 			0xE  */
/* RESERVED 			0xF  */


#define	CTRL_PS_POLL	0xA
#define	CTRL_RTS	0xB
#define	CTRL_CTS	0xC
#define	CTRL_ACK	0xD
#define	CTRL_CF_END	0xE
#define	CTRL_END_ACK	0xF

#define	DATA_DATA		0x0
#define	DATA_DATA_CF_ACK	0x1
#define	DATA_DATA_CF_POLL	0x2
#define	DATA_DATA_CF_ACK_POLL	0x3
#define	DATA_NODATA		0x4
#define	DATA_NODATA_CF_ACK	0x5
#define	DATA_NODATA_CF_POLL	0x6
#define	DATA_NODATA_CF_ACK_POLL	0x7

/*
 * Bits in the frame control field.
 */
#define	FC_VERSION(fc)		((fc) & 0x3)
#define	FC_TYPE(fc)		(((fc) >> 2) & 0x3)
#define	FC_SUBTYPE(fc)		(((fc) >> 4) & 0xF)
#define	FC_TO_DS(fc)		((fc) & 0x0100)
#define	FC_FROM_DS(fc)		((fc) & 0x0200)
#define	FC_MORE_FLAG(fc)	((fc) & 0x0400)
#define	FC_RETRY(fc)		((fc) & 0x0800)
#define	FC_POWER_MGMT(fc)	((fc) & 0x1000)
#define	FC_MORE_DATA(fc)	((fc) & 0x2000)
#define	FC_WEP(fc)		((fc) & 0x4000)
#define	FC_ORDER(fc)		((fc) & 0x8000)

struct mgmt_header_t {
    mgmt_header_t():fc(),duration(),da(),sa(),bssid(),seq(),frag(){};
    u_int16_t fc;
    u_int16_t duration;
    MAC da;
    MAC sa;
    MAC bssid;
    u_int16_t seq;
    u_int8_t  frag;
};

#define	MGMT_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+          \
			 IEEE802_11_DA_LEN+IEEE802_11_SA_LEN+           \
			 IEEE802_11_BSSID_LEN+IEEE802_11_SEQ_LEN)

#define	CAPABILITY_ESS(cap)	((cap) & 0x0001)
#define	CAPABILITY_IBSS(cap)	((cap) & 0x0002)
#define	CAPABILITY_CFP(cap)	((cap) & 0x0004)
#define	CAPABILITY_CFP_REQ(cap)	((cap) & 0x0008)
#define	CAPABILITY_PRIVACY(cap)	((cap) & 0x0010)

typedef enum {
    NOT_PRESENT,
    PRESENT,
    TRUNCATED
} elem_status_t;


struct ssid_t {
    ssid_t():element_id(),length(),ssid(){};
    u_int8_t	element_id;
    u_int8_t	length;
    char	ssid[33];  /* 32 + 1 for null */
};

struct rates_t {
    rates_t():element_id(),length(),rate(){};
    u_int8_t	element_id;
    u_int8_t	length;
    u_int8_t	rate[16];
};

struct challenge_t {
    challenge_t():element_id(),length(),text(){};
    u_int8_t	element_id;
    u_int8_t	length;
    u_int8_t	text[254]; /* 1-253 + 1 for null */
};

struct fh_t {
    fh_t():element_id(),length(),dwell_time(),hop_set(),hop_pattern(),hop_index(){};
    u_int8_t	element_id;
    u_int8_t	length;
    u_int16_t	dwell_time;
    u_int8_t	hop_set;
    u_int8_t 	hop_pattern;
    u_int8_t	hop_index;
};

struct ds_t {
    u_int8_t	element_id;
    u_int8_t	length;
    u_int8_t	channel;
};

struct cf_t {
    u_int8_t	element_id;
    u_int8_t	length;
    u_int8_t	count;
    u_int8_t	period;
    u_int16_t	max_duration;
    u_int16_t	dur_remaing;
};

struct tim_t {
    u_int8_t	element_id;
    u_int8_t	length;
    u_int8_t	count;
    u_int8_t	period;
    u_int8_t	bitmap_control;
    u_int8_t	bitmap[251];
};

#define	E_SSID 		0
#define	E_RATES 	1
#define	E_FH	 	2
#define	E_DS 		3
#define	E_CF	 	4
#define	E_TIM	 	5
#define	E_IBSS 		6
/* reserved 		7 */
/* reserved 		8 */
/* reserved 		9 */
/* reserved 		10 */
/* reserved 		11 */
/* reserved 		12 */
/* reserved 		13 */
/* reserved 		14 */
/* reserved 		15 */
/* reserved 		16 */

#define	E_CHALLENGE 	16
/* reserved 		17 */
/* reserved 		18 */
/* reserved 		19 */
/* reserved 		16 */
/* reserved 		16 */

struct mgmt_body_t {
    mgmt_body_t():timestamp(),beacon_interval(),listen_interval(),status_code(),aid(),ap(),reason_code(),auth_alg(),
                  auth_trans_seq_num(),challenge_status(),challenge(),capability_info(),ssid_status(),ssid(),
                  rates_status(),rates(),ds_status(),ds(),cf_status(),cf(),fh_status(),fh(),tim_status(),tim(){};
    u_int8_t   	timestamp[IEEE802_11_TSTAMP_LEN];
    u_int16_t  	beacon_interval;
    u_int16_t 	listen_interval;
    u_int16_t 	status_code;
    u_int16_t 	aid;
    u_char		ap[IEEE802_11_AP_LEN];
    u_int16_t	reason_code;
    u_int16_t	auth_alg;
    u_int16_t	auth_trans_seq_num;
    elem_status_t	challenge_status;
    struct challenge_t  challenge;
    u_int16_t	capability_info;
    elem_status_t	ssid_status;
    struct ssid_t	ssid;
    elem_status_t	rates_status;
    struct rates_t 	rates;
    elem_status_t	ds_status;
    struct ds_t	ds;
    elem_status_t	cf_status;
    struct cf_t	cf;
    elem_status_t	fh_status;
    struct fh_t	fh;
    elem_status_t	tim_status;
    struct tim_t	tim;
};

// XXX Jeff: no FCS fields are filled in right now

struct ctrl_rts_t {
    ctrl_rts_t():fc(),duration(),ra(),ta(),fcs(){}
    u_int16_t fc;
    u_int16_t duration;
    MAC ra;
    MAC ta;
    u_int8_t fcs[4];
};

#define	CTRL_RTS_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+  \
			 IEEE802_11_RA_LEN+IEEE802_11_TA_LEN)

struct ctrl_cts_t {
    ctrl_cts_t():fc(),duration(),ra(),fcs(){};
    u_int16_t fc;
    u_int16_t duration;
    MAC ra;
    u_int8_t fcs[4];
};

#define	CTRL_CTS_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+IEEE802_11_RA_LEN)

struct ctrl_ack_t {
    ctrl_ack_t():fc(),duration(),ra(),fcs(){};
    u_int16_t fc;
    u_int16_t duration;
    MAC ra;
    u_int8_t fcs[4];
};

#define	CTRL_ACK_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+IEEE802_11_RA_LEN)

struct ctrl_ps_poll_t {
    ctrl_ps_poll_t():fc(),aid(),bssid(),ta(),fcs(){};
    u_int16_t fc;
    u_int16_t aid;
    MAC bssid;
    MAC ta;
    u_int8_t fcs[4];
};

#define	CTRL_PS_POLL_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_AID_LEN+  \
				 IEEE802_11_BSSID_LEN+IEEE802_11_TA_LEN)

struct ctrl_end_t {
    ctrl_end_t():fc(),duration(),ra(),bssid(),fcs(){}
    u_int16_t fc;
    u_int16_t duration;
    MAC ra;
    MAC bssid;
    u_int8_t fcs[4];
};

#define	CTRL_END_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+          \
			 IEEE802_11_RA_LEN+IEEE802_11_BSSID_LEN)

struct ctrl_end_ack_t {
    ctrl_end_ack_t():fc(),duration(),ra(),bssid(),fcs(){};
    u_int16_t fc;
    u_int16_t duration;
    MAC ra;
    MAC bssid;
    u_int8_t fcs[4];
};

#define	CTRL_END_ACK_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+  \
				 IEEE802_11_RA_LEN+IEEE802_11_BSSID_LEN)

#define	IV_IV(iv)	((iv) & 0xFFFFFF)
#define	IV_PAD(iv)	(((iv) >> 24) & 0x3F)
#define	IV_KEYID(iv)	(((iv) >> 30) & 0x03)

struct data_hdr_ibss_t {
    data_hdr_ibss_t():fc(),duration(),seq(),frag(),fcs(){};
    u_int16_t fc;
    u_int16_t duration;
    u_int16_t seq;
    u_int8_t frag;
    u_int8_t fcs[4];
};

struct data_hdr_t {
    data_hdr_t():fc(),duration(),seq(),frag(),sa(),da(),bssid(),fcs(){}
    u_int16_t fc;
    u_int16_t duration;
    u_int16_t seq;
    u_int8_t frag;
    MAC sa;
    MAC da;
    MAC bssid;
    u_int8_t fcs[4];
};

struct data_hdr_wds_t {
    data_hdr_wds_t():fc(),duration(),seq(),frag(),ra(),ta(),sa(),da(),fcs(){}
    u_int16_t fc;
    u_int16_t duration;
    u_int16_t seq;
    u_int8_t frag;
    MAC ra;
    MAC ta;
    MAC sa;
    MAC da;
    u_int8_t fcs[4];
};

#define	DATA_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+          \
			 IEEE802_11_SA_LEN+IEEE802_11_DA_LEN+           \
			 IEEE802_11_BSSID_LEN+IEEE802_11_SEQ_LEN)

#define	DATA_WDS_HDRLEN	(IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+          \
			 IEEE802_11_RA_LEN+IEEE802_11_TA_LEN+           \
			 IEEE802_11_SA_LEN+IEEE802_11_DA_LEN+IEEE802_11_SEQ_LEN)

/* Jeff: added for fully-decoded wep info */
struct wep_hdr_t {
    wep_hdr_t():iv(),pad(),keyid(){};
    u_int32_t iv;
    u_int32_t pad;
    u_int32_t keyid;
};

// XXX TKIP/CCMP ?

#endif /* _WLANSEC_IEEE802_11_H */
