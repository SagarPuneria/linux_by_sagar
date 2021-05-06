#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
	printf("msg id from write process to read process is %d\n",msgid);
	retval=msgrcv(msgid,&buf,6,5,0);
	if(retval<0)
	{
		perror("msgrcv:");
		return 0;
	}
	printf("msg from write process is %s\n",buf.mtext);
	//msgctl(msgid,IPC_RMID,NULL);
}
