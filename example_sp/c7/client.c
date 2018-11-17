#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

void main(int argc, char *argv[]){
	int sock;
	char msg[1024];
	int str_len;
	struct sockaddr_in serv_addr;

	if(argc != 3){
		perror("Usage");
		return;
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1){
		perror("socket()");
		return;
	}
	
	memset(msg, 0, sizeof(msg));
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
	if(connect(sock, &serv_addr, sizeof(serv_addr)) == -1){
		perror("connect()");
		return;
	}

	while(1){
		printf("what's your msg sending for : ");
		scanf("%s", msg);
		printf("msg : %s\n",msg); 
		if(!strcmp(msg, "q")) break;
		write(sock, msg, strlen(msg));

		str_len = read(sock, msg, 1023);
		msg[str_len] =0;
		printf("msg from server : %s \n", msg);
		memset(msg, 0, sizeof(msg));

	}

	close(sock);
}
