#include<stdio.h>
#include<pthread.h>
int x=0;
pthread_mutex_t mutex;
void* print_f(void *msg)
//void* print_f(void *lp)
{
	int i,j;
	printf("%s\n",(char *)msg);
	//printf("%d\n",*(int *)lp);
	for(i=0;i<10;i++)
	//for(i=0;i<*(int *)lp;i++)
	{
		pthread_mutex_lock(&mutex);
		j=x;
		j=j+1;
		sleep(1);
		x=j;
		printf("%d\n",x);
		pthread_mutex_unlock(&mutex);
	}
	printf("%d %s\n",x,(char *)msg);
}

int main()
{
	int loop=5;
	pthread_t t1,t2;
	pthread_create(&t2, NULL,print_f, "world");
	//pthread_create(&t2, NULL,print_f, &loop);
	pthread_create(&t1, NULL,print_f, "hello");
	//pthread_create(&t1, NULL,print_f, &loop);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("glob=%d\n",x);
	pthread_exit(NULL);
}
