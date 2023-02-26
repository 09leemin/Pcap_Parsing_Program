#ifndef TCP_H
#define TCP_H

#include "pcapfile.h"

typedef struct _TCPHeader TCPHeader;
struct _TCPHeader
{
    ushort src_port;
    ushort dst_port;
    uint seqno;
    uint ackno;
    uchar hdlen;
    uchar fin : 1;
    uchar syn : 1;
    uchar rst : 1;
    uchar psh : 1;
    uchar ack : 1;
    uchar urg : 1;
    uchar reserved : 2;
    ushort winsize;
    ushort checksum;
    ushort upoint;
};

void ParseTCP(uchar *base, uint len);

#endif