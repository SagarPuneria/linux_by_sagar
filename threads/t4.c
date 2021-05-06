#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
int i=0;
pthread_cond_t cond;
pthread_mutex_t mutex;
//void* print_f()
void* print_f(void *msg)
{
	printf("%s\n",(char *)msg);
	for(i=0;i<20;i++)
	{
		//pthread_mutex_lock(&mutex);
		if(i>=10)
		{
			pthread_cond_signal(&cond);
			return;
		}
		else
		{
			sleep(1);
			printf("%d\n",i);
		}	
		//pthread_mutex_unlock(&mutex);
	}
}
//void* print_z()
void* print_z(void *msg)
{
	printf("thread 2 is waiting\n");
	pthread_cond_wait(&cond,&mutex);
	while(i<20)
	{
		//pthread_mutex_lock(&mutex);
		sleep(1);
		printf("%d\n",i);
		i++;
		//pthread_mutex_unlock(&mutex);
	}
	printf("%s\n",(char *)msg);
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1, NULL,print_z, "hello");
	pthread_create(&t2, NULL,print_f, "world");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_exit(NULL);
	printf("sagar\n");//NO output
}
