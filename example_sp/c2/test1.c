#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void main(int argc, char *argv[]){
	
	FILE *fs1, *fs2;
	struct stat filestat;
	int nRet = 0;
	char *pFile;

	if(argc < 2){
		perror("Usage : more command needed");
		exit(1);
	}
	if((fs1 = fopen(argv[1], "rb")) != NULL){
		fstat(fileno(fs1), &filestat);
		pFile = (char *)malloc(filestat.st_size);
		memset(pFile, 0, filestat.st_size);
		nRet = fread(pFile, 1, filestat.st_size, fs1);

		fclose(fs1);

		if((fs2 = fopen("Copied", "wb")) != NULL){
			nRet = fwrite(pFile, filestat.st_size, 1, fs2);
			fclose(fs2);
		}
		free(pFile);
	}


	


}
