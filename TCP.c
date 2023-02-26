#include "TCP.h"

void ParseTCP(uchar* base, uint len)
{
    TCPHeader *th = (TCPHeader*)base;
    printf(">>>>>>>>>>  TCP Header  <<<<<<<<<<\n");
    printf("\t src port: %u\n", ntohs(th->src_port));
    printf("\t dst port: %u\n", ntohs(th->dst_port));
    printf("\t seq no: %u\n", ntohl(th->seqno));
    printf("\t ack no: %u\n", ntohl(th->ackno));
    printf("\t ");
    if(th->syn) printf("SYN ");
    if(th->ack) printf("ACK ");
    if(th->fin) printf("FIN ");
    if(th->rst) printf("RST ");
    if(th->psh) printf("PSH ");
    if(th->urg) printf("URG ");
    printf("\n");
    printf("\t window size: %u\n", ntohs(th->winsize));
    printf("\t urg pointer: %u\n", ntohs(th->upoint));
}