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
	printf("msg id from write process is %d\n",msgid);
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
	retval=semctl(semid,0,SETVAL,0);//init semaphores
	if(retval<0)
	{
		perror("INIT:");
		return -1;
	}
	printf("semid is %d\n",semid);
	semb.sem_num=0;
	semb.sem_op=-1;
	semb.sem_flg=0;//SEM_UNDO;
	retval=semop(semid,&semb,1);
	if(retval<0)
	{
		perror("semop wait:");
		return -1;
	}
	retval=msgrcv(msgid,&buf,6,1,0);
	if(retval<0)
	{
		perror("msgrcv:");
		return 0;
	}
	printf("msg from write process is %s\n",buf.mtext);
	msgctl(msgid,IPC_RMID,NULL);
	semctl(semid,0,IPC_RMID);
}
