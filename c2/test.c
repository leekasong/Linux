#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main(int argc, char *argv[]){
	
	if(argc < 2){
		perror("Usage 1");
		return;
	}

	int ret = execl("/usr/bin/gcc", "gcc", "-o", "test1", argv[1], NULL);
	if(ret == -1) {
		perror("Usage 2");
		return;
	}
	char buf[256] = {0,};
	getcwd(buf, sizeof(buf));
	sprintf(buf, "%s/test1", buf);
	ret = execl(buf, "test1", NULL);


	if(ret == -1) {
		perror("Usage 3");
		return;
	}

}

