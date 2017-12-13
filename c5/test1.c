#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

void main(){
	
	FILE *fp = fopen("myfifo", "r");
	if(fp == NULL){
		perror("fopen()");
		return;
	}
	
	char buf[80];
	int ret = fread(buf, 1, sizeof(buf), fp);
	printf("ret : %d\n", ret);
	if(ret < 0){
		perror("fread()");
		return;
	}
	buf[ret] = 0;

	printf("%s\n", buf);


}
