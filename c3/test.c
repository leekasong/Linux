#include <unistd.h>
#include <signal.h>

void sig_handler(int signo){
	if(signo == SIGINT){
		printf("INT signal received\n");
	}else if(signo == SIGUSR1){
		printf("SIGUSR1 signal received\n");
	}else{
		printf("signal no = %d\n", signo);
	}
	return;
}

void main(){
	if(signal(SIGINT, sig_handler) == SIG_ERR){
		perror("SIGINT");
	}
	if(signal(SIGUSR1, sig_handler) == SIG_ERR){
		perror("SIGUSR1");
	}
	while(1){
		pause();
	}
}
