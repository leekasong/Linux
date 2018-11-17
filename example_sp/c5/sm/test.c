#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

void main(){
	int shmid = shmget(451332, 50, IPC_EXCL|IPC_CREAT|0660);
	if(shmid < 0){
		perror("shmget()");
		return;
	}

	char *ptr = shmat(shmid, NULL, 0);
	if(ptr == NULL){
		perror("shmat()");
		return;
	}

	strcpy(ptr, "Linux is best!");
	printf("text : %s\n", ptr);

	if(shmdt(ptr) <0){
		perror("shmdt()");
		return;
	}

	if(shmctl(shmid, IPC_RMID, 0) < 0){
		perror("shmctl()");
		return;
	}
	printf("gracefully finished!!\n");
}
