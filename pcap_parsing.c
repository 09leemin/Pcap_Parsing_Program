#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pcapfile.h"

int main(int argc, char **argv)
{
	char fname[256 + 1] = "";
	printf("분석할 pcap 파일명:");
	scanf("%s", fname);

	FILE *fp = 0;
	fp = fopen(fname, "r");
	if(fp == NULL) {
		perror("fopen error\n");
		return -1;
	}
	
	PFHeader pfh = {0, };
	if(ParsePCapFile(fp, &pfh) == 0) {
		printf("PCAP 파일이 아닙니다.\n");
		fclose(fp);
		return 0;
	}

	switch(pfh.linktype)
	{
	case LT_ETHER : ParseEther(fp); break;
	default : printf("Not Support\n"); break;
		break;
	}

	sleep(600);
	return 0;
}

