#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
#include <sys/sem.h>
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
/*	retval=semctl(semid,0,SETVAL,0);//init semaphores
	if(retval<0)
	{
		perror("INIT:");
		return -1;
	}
	retval=semctl(semid,1,SETVAL,0);//init semaphores
	if(retval<0)
	{
		perror("INIT:");
		return -1;
	}*/
	memcpy(mem,"jkas",10);
	printf("writer completed....\n");
	semb.sem_num=0;
	semb.sem_op=1;
	semb.sem_flg=0;//SEM_UNDO;
	semop(semid,&semb,1);
	semb.sem_num=1;
	semb.sem_op=-1;
	semb.sem_flg=0;//SEM_UNDO;
	semop(semid,&semb,1);
	printf("data at mem=%s\n",mem);
	printf("data at mem+256=%s\n",mem+256);
	shmdt(mem);
	shmctl(shmid,IPC_RMID,NULL);
	semctl(semid,0,IPC_RMID);
	return 0;
}
