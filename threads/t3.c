#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
int x=0;
//pthread_mutex_t mutex;
sem_t sem;
void* print_f(void *msg)
{
	int i,j;
	printf("%s\n",(char *)msg);
	for(i=0;i<20;i++)
	{
	//	pthread_mutex_lock(&mutex);
		sem_wait(&sem);	
		j=x;
		j=j+1;
		sleep(1);
		x=j;
		sem_post(&sem);
	//	pthread_mutex_unlock(&mutex);
	}
	printf("%d %s\n",x,(char *)msg);
}

int main()
{
	pthread_t t1,t2;
	sem_init(&sem,0,1);
	pthread_create(&t2, NULL,print_f, "world");
	pthread_create(&t1, NULL,print_f, "hello");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("glob=%d\n",x);
	pthread_exit(NULL);
}
