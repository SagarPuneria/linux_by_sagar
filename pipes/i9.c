#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<stdio.h>
#include<semaphore.h>
 //union semun {
           //    int              val;    /* Value for SETVAL */
         //      struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       //        unsigned short  *array;  /* Array for GETALL, SETALL */

   //            struct seminfo  *__buf;  /* Buffer for IPC_INFO
     //                                      (Linux-specific) */
 //          };

   
int main()
{
	int semid,retval;
	//union semun un;
	struct sembuf semb;
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
	//init semaphores
	//un.val=1;//init MUTEX
	//retval=semctl(semid,0,SETVAL,un);//init semaphores
	retval=semctl(semid,0,SETVAL,1);//init semaphores
	if(retval<0)
	{
		perror("INIT:");
		return -1;
	}
	printf("semid is %d\n",semid);
	//wait
	semb.sem_num=0;
	semb.sem_op=-1;
	semb.sem_flg=SEM_UNDO;
	retval=semop(semid,&semb,1);
	if(retval<0)
	{
		perror("semop wait:");
		return -1;
	}
	//CS
	
	sleep(3);
	
	//signal
	semb.sem_op=1;
	retval=semop(semid,&semb,1);
	if(retval<0)
	{
		perror("semop signal:");
		return -1;
	}
	semctl(semid,0,IPC_RMID);
	return 0;
}
