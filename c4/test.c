#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
	pid_t pid;
	int fd[2];

	if((pipe(fd) == -1) || ((pid = fork()) == -1)){
		perror("pipe()");
		return;
	}

	if(pid == 0){
		if(dup2(fd[1], STDOUT_FILENO) == -1)
			perror("dup2()");
		else if(close(fd[0]) == -1 || close(fd[1]) == -1)
			perror("close()");
		else{
			execl("/bin/ls", "ls", "-l", NULL);
			perror("execli()");
		}
		return;	
	}

	if(dup2(fd[0], STDIN_FILENO) == -1)
		perror("dup2()");
	else if(close(fd[0]) == -1 || close(fd[1]) == -1)
		perror("close()");
	else{
		execl("/usr/bin/sort", "sort", "-k", "+4", NULL);
		perror("execl()");
	}

	return;

}
