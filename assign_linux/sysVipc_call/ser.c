#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
#include <sys/sem.h>
toggle(char *arg)
{
	int i;
	for(i=0;arg[i]!='\0';i++)
	{
		if(arg[i]>='A' && arg[i]<='Z')
			arg[i]+=32;
		else if(arg[i]>='a' && arg[i]<='z')
			arg[i]-=32;
		else
			arg[i]=arg[i];
	}
}
int main()
{
	int shmid,semid,retval;
	void *mem;
	struct sembuf semb;
	shmid=shmget((key_t)4321,6,IPC_CREAT|IPC_EXCL);
	if(shmid<0)
	{
		shmid=shmget((key_t)4321,6,0644);
		if(shmid<0)
		{
			perror("shmget2:");
			return -1;
		}
	}
	printf("shmid from writer is %d\n",shmid);
	mem=shmat(shmid,NULL,0);
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
	printf("semid is %d\n",semid);
	semctl(semid,0,SETVAL,0);//init semaphores
	semctl(semid,1,SETVAL,0);//init semaphores
	semb.sem_num=0;
	semb.sem_op=-1;
	semb.sem_flg=0;//SEM_UNDO;
	semop(semid,&semb,1);
	strcpy(mem+256,mem);
	toggle(mem+256);
	semb.sem_num=1;
	semb.sem_op=1;
	semb.sem_flg=0;//SEM_UNDO;
	semop(semid,&semb,1);
	shmdt(mem);
	return 0;
}
