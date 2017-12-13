#include "common.h"
#include "MsgFormat.h"
void main(){
	Msg msg;
	int msgqid = msgget(key, IPC_CREAT|0644);
	if(msgqid == -1){
		perror("msgget()");
		return;
	}
	memset(msg.buf, 0, sizeof(msg.buf));
	if(msgrcv(msgqid, &msg, sizeof(msg.buf), 0, 0) == -1){
		perror("msgrcv()");
		return;
	}
	
	msgctl(msgqid, IPC_RMID, NULL);
	printf("rcv : %s\n", msg.buf);


}
