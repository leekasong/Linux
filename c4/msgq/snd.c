#include "common.h"

#include "MsgFormat.h"
void main(){
	Msg msg;
	msg.type = 1;
	memset(msg.buf, 0, sizeof(msg.buf));
	int msgqid = msgget(key, IPC_CREAT|0644);
	if(msgqid == -1){
		perror("msgget()");
		return;
	}

	strcpy(msg.buf, "Hello~ from snd");
	if(msgsnd(msgqid, &msg, sizeof(msg.buf), 0) == -1){
		perror("msgsnd()");
		return;
	}
	
	msgctl(msgqid, IPC_RMID, NULL);
	printf("snd terminated\n");

}
