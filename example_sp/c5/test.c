#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

void main(){
	if(mkfifo("myfifo", 0644) == -1){
		perror("mkfifo()");
		return;
	}	
	
	FILE *fp = fopen("myfifo", "w");
	if(fp == NULL){
		perror("fopen()");
		return;
	}
	
	char buf[80] = {0,};	
	strcpy(buf, "fifo!!!");
	int ret = fwrite(buf, 1, strlen(buf)+1, fp);
	if(ret < 0){
		perror("fwrite()");
		return;
	}

	printf("snd : %s , size : %d\n", buf, ret);


}
