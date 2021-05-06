#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
int main()
{
	int shmid,retval;
	void *mem;
	char buff[6];
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
	printf("shmid from reader is %d\n",shmid);
	mem=shmat(shmid,NULL,0);
	if(mem==NULL)
	{
		perror("shmat:");
		return -1;
	}
	memcpy(buff,mem,6);
	printf("msg from writer to the reader is %s\n",buff);
	retval=shmdt(mem);
	if(retval<0)
	{
		perror("shmdt:");
		return -1;
	}
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
