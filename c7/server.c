#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void main(int argc, char *argv[]){
	
	int serv_sock;
	int clnt_sock;
	char msg[1024];
	int str_len;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	int clnt_addr_size;

	if(argc != 2){
		perror("Usage");
		return;
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1){
		perror("socket()");
		return;
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, &serv_addr, sizeof(serv_addr)) == -1){
		perror("bind()");
		return;
	}

	if(listen(serv_sock, 5) == -1){
		perror("listen()");
		return;
	}

	while(1){
		clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, &clnt_addr, &clnt_addr_size);
		if(clnt_sock == -1){
			perror("accept()");
		}

		while((str_len = read(clnt_sock, msg, 1024) )!= 0){
			write(clnt_sock, msg, str_len);
			write(1, msg, str_len);
		}
		close(clnt_sock);
	}
}
