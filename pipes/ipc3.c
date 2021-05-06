#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#include<stdio.h>

#include <sys/sem.h>
int main()
{
	struct msgbuf
	{
		long mtype;
		char mtext[6];
	}buf;
	int msgid,retval,semid;
	struct sembuf semb;
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
	printf("msg id from read process is %d\n",msgid);
	semid=semget((key_t)7890,1,IPC_CREAT|IPC_EXCL);
	if(semid<0)
	{
		semid=semget((key_t)7890,1,0644);
		if(semid<0)
		{
			perror("semget2:");
			return -1;
		}
	}
	buf.mtype=1;
	strcpy(buf.mtext,"uhrrw");
	retval=msgsnd(msgid,&buf,6,0);
	if(retval<0)
	{
		perror("msgsnd:");
		return 0;
	}
	printf("sent the msg to read process\n");
	semb.sem_num=0;
	semb.sem_op=1;
	semb.sem_flg=0;//SEM_UNDO;
	retval=semop(semid,&semb,1);
	if(retval<0)
	{
		perror("semop wait:");
		return -1;
	}
}
