#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int buf[10];
sem_t full,empty;
pthread_mutex_t mutex;
void * pro_fun(void *arg)
{
	int pindex=0,i;
	for(i=0;i<5;i++)
	{
		sleep(2);
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		printf("producer adding item %d in buf[%d]\n",i,pindex);
		buf[pindex++]=i;
		if(pindex == 10)
			pindex=0;
		printf("produced item....\n");
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
	pthread_exit("SUCCESSFUL");
}
void* con_fun(void *arg)
{
	int cindex=0,i;
	for(i=0;i<5;i++)
	{
		printf("Consumer tries to consume .......\n");
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		printf("Consumer wants to consume ...\n");
		printf("Consumer consumed item %d from buf[%d]\n",buf[cindex],cindex);
		cindex++;
		if(cindex == 10) 
			cindex=0;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
	pthread_exit("SUCCESSFUL");
}
int main()
{
	pthread_t pro,con;
	void *proret,*conret;
	sem_init(&empty,0,10);
	sem_init(&full,0,0);
//	pthread_mutex_init(&mutex,NULL);
	pthread_create(&pro,NULL,pro_fun,NULL);
	pthread_create(&con,NULL,con_fun,NULL);
	pthread_join(pro,&proret);
	pthread_join(con,&conret);
//	sem_destroy(&full);
//	sem_destroy(&empty);
//	pthread_mutex_destroy(&mutex);
	printf("Ret status of pro %s\n",(char *)proret);
	printf("Ret status of con %s\n",(char *)conret);
	return(0);
}

