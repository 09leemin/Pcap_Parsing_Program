#include "pcapfile.h"
#include "EHEther.h"

char buffer[0x100000];

void ViewPCapFile(FILE *fp, PFHeader *pfh);
void ViewPacketHeaderInfo(PackHeader *ph, int pno);

void ParseEthers(FILE *fp)
{
	PackHeader ph = {0};
	int pno = 0;
	while(fread(&ph, sizeof(PackHeader), 1, fp) == 1)
	{
		pno++;
		ViewPacketHeaderInfo(&ph, pno);
		fread(buffer, sizeof(uchar), ph.caplen, fp);
		ParseEther(buffer, ph.caplen);
	}
}

int ParsePCapFile(FILE *fp, PFHeader *pfh)
{
	fread(pfh, sizeof(PFHeader), 1, fp);
	if(pfh->magic != PF_MAGIC)
	{
		return 0;
	}
	ViewPCapFile(fp, pfh);

	return 1;
}

void ViewPCapFile(FILE *fp, PFHeader *pfh)
{
	printf("======================= PCAP File 헤더 정보 ========================\n");
	printf("\t 버전 : %d.%d\n", pfh->major, pfh->minor);
	printf("\t 최대 캡쳐 길이 : %d bytes\n", pfh->max_caplen);
}


void ViewPacketHeaderInfo(PackHeader *ph, int pno)
{
	printf("\n!!! <%4d th> 프레임 !!!\n", pno);
	printf("패킷:%6d bytes 캡쳐:%6d\n", ph->packlen, ph->caplen);
}
