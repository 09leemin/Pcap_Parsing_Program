#include "IPv4.h"

void PrintIPv4(uint addr)
{
    uchar *up = (uchar*)&addr;
    int i = 0;
    for(i=0; i<3; i++)
    {
        printf("%d.", up[i]);
    }
    printf("%d", up[i]);
}

void ParseIPv4(uchar *base, uint len)
{
    IPv4Header *iph = (IPv4Header*)base;
    printf(">>>>>>>>>>  IPv4 Header  <<<<<<<<<<\n");
    printf("\t version: %d\n", iph->version);
    printf("\t hlen: %d bytes\n", iph->hlen * 4);
    printf("\t total length: %d bytes\n", ntohs(iph->tlen));
    printf("\t id: %d\n", ntohs(iph->id));

    if(DONT_FRAG(iph->fl_off))
    {
        printf("\t Don't Fragment\n");
    }
    if(MORE_FRAG(iph->fl_off))
    {
        printf("\t More Fragment\n");
    }
    printf("\t offset: %d bytes\n", FRAG_OFF(iph->fl_off));
    printf("\t Time To Live: %d\n", iph->ttl);
    printf("\t Protocol: %d\n", iph->protocol);
    printf("\t ICMP: %d, IGMP: %d, TCP: %d, UDP: %d, OSPF: %d\n", PRO_ICMPv4, PRO_IGMP, PRO_TCP, PRO_UDP, PRO_OSPF);
    printf("\t src:");
    PrintIPv4(iph->srcaddr);
    printf("\t dst:");
    PrintIPv4(iph->dstaddr);
    printf("\n");
    uchar *next = base + (iph->hlen * 4);
    len = len - (iph->hlen * 4);

    switch(iph->protocol)
    {
        case PRO_ICMPv4 : printf("to be defined\n"); break;
        case PRO_TCP : printf("to be defined\n"); break;
        default: printf("\t Not supported\n");
            break;
    }


}
