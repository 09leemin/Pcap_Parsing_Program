#include "EHEther.h"
#include "IPv4.h"

void ViewEther(EtherHeader *eh);
void ParseEther(uchar *buffer, uint len)
{
    EtherHeader *eh = (EtherHeader *)buffer;
    uchar *next = buffer + sizeof(EtherHeader);
    len = len - sizeof(EtherHeader);

    ViewEther(eh);
    switch(ntohs(eh->l3type))
    {
        case L3_IPv4 : ParseIPv4(next, len); break;
        case L3_ARP : printf("ARP: to be defined\n"); break;
        default : printf("Not support\n");
            break;
    }
}

void ViewMac(const char *msg, uchar *base);
void ViewEther(EtherHeader *eh)
{
    printf(">>>>>>>>>>  ethernet header  <<<<<<<<<<\n");
    ViewMac("dest  ", eh->dst_mac);
    ViewMac("source", eh->src_mac);
    printf("\tL3Type:%#x\n", ntohs(eh->l3type));     // ntohs, ntohl : 인자는 네트워크에서 받은 2, 4바이트 데이터 ,, 반환값은 호스트 엔디안에 맞게 변환된 빅/리틀 엔디안 값

    printf("\t(IPv4:0x0800 ARP:0x0806)\n");
}

void ViewMac(const char *msg, uchar *base)
{
    printf("\t%s   ", msg);
    printf("%02x", base[0]);
    for(int i=1; i<6; i++)
    {
        printf(":%02x", base[i]);
    }
    printf("\n");
}