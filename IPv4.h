#ifndef IPV4_H
#define IPV4_H

#include "pcapfile.h"

#define PRO_ICMPv4  0x01
#define PRO_IGMP    0x02
#define PRO_TCP     0x06
#define PRO_UDP     0x11
#define PRO_OSPF    0x59

typedef struct _IPv4Header IPv4Header;
struct _IPv4Header
{
    uchar hlen : 4;
    uchar version : 4;
    uchar tos;
    ushort tlen; 
    ushort id;
    ushort fl_off;
#define DONT_FRAG(x)    (x&0x40)
#define MORE_FRAG(x)    (x&0x20)
#define FRAG_OFF(x)     ntohs(x&0xFF1F)
    uchar ttl;
    uchar protocol;
    ushort checksum;
    uint srcaddr;
    uint dstaddr;
};

void ParseIPv4(uchar *base, uint len);

#endif