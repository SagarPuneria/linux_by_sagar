#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#include<stdio.h>
int main()
{
	struct msgbuf
	{
		long mtype;
		char mtext[6];
	}buf;
	int msgid,retval;
	msgid=msgget((key_t)1234,IPC_CREAT|IPC_EXCL);
	if(msgid<0)
	{
		msgid=msgget((key_t)1234,0666);
		if(msgid<0)
		{
			perror("msgget2:");
			return 0;
		}
	}
	printf("msg id from write process is %d\n",msgid);
	buf.mtype=2;
	strcpy(buf.mtext,"ogrw");
	retval=msgsnd(msgid,&buf,6,0);
	if(retval<0)
	{
		perror("msgsnd:");
		return 0;
	}
	//memset(&buf,0,sizeof(buf));
	printf("sent the msg to read process\n");
	buf.mtype=5;
	strcpy(buf.mtext,"wowwo");
	retval=msgsnd(msgid,&buf,6,0);

}
