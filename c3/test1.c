#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
void func(){
	printf("handler\n");
}

void main(){

	struct sigaction oact, act;
	sigemptyset(&(act.sa_mask));
	act.sa_flags = 0;
	printf("flags : %d\n", act.sa_flags);
	act.sa_handler = func;
	if(sigaction(SIGINT, &act, &oact) < 0){
		perror("sigaction() error");
		return;
	}
	
	while(1){}

	if(sigaction(SIGINT, &oact, NULL) < 0){
		perror("sigaction() error");
		return;
	}
}
