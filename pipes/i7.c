#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
int main()
{
	int shmid,retval;
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
	memcpy(mem,"hello",6);
	printf("writer completed....\n");
	retval=shmdt(mem);
	if(retval<0)
	{
		perror("shmdt:");
		return -1;
	}
	return 0;
}
