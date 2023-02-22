#ifndef EHETHER_H
#define EHETHER_H

#include "pcapfile.h"

#define L3_IPv4 0x0800
#define L3_ARP  0x0806

typedef struct _EtherHeader EtherHeader;
struct _EtherHeader
{
    uchar dst_mac[6];
    uchar src_mac[6];
    ushort l3type;
};

void ParseEther(uchar *buffer, uint len);

#endif