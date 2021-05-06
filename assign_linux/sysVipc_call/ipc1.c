#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
#include <sys/sem.h>
int main()
{
	//char buf[1024]="dfishguiiiiiiiihvvkjhfjkhgfjffdgaiuiouroiotredssssssssssssssssssssssssssssshioewwwwwwwwwwwwwwwwww\
hgdfhhsfhgkjhfgkf;dsfgshgioshgesghsdhgfhgf;hfdhogiogiostougouoiurutreu7t8retre8rey8yt9regfhgkdfh";
	int shmid,retval,semid,ret;
	struct sembuf semb;
	void *mem;
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
	if(mem==NULL)
	{
		perror("shmat:");
		return -1;
	}
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
	memcpy(mem,"jhjkas",10);
	printf("writer completed....\n");
	semb.sem_num=0;
	semb.sem_op=1;
	semb.sem_flg=0;//SEM_UNDO;
	retval=semop(semid,&semb,1);
	if(retval<0)
	{
		perror("semop wait:");
		return -1;
	}
	retval=shmdt(mem);
	if(retval<0)
	{
		perror("shmdt:");
		return -1;
	}
	return 0;
}
