#include<stdio.h>
#include<pthread.h>
int a=1;
int p=0;
void* print_f(int *a)
{
	 ++p;
	printf("a=%d\n",*a);
	printf("p=%d\n",p);
}

int main()
{
	pthread_t t1,t2;
	int ret=-1,ret1=-1;
	pthread_t pthread_self(void);

	ret=pthread_create(&t1, NULL,(void *)print_f,&a);
	if(ret<0)
	{
	 //printf("%d",ret);
	 printf("error");
	 return;
	}
	ret=pthread_join(t1,NULL);
	if(ret<0)
	{
	 printf("error");
	 return;
	}
	ret1=pthread_create(&t2, NULL,(void *)print_f,&a);
	if(ret1<0)
	{
	 printf("error");
	 return;
	}
	ret1=pthread_join(t1,NULL);
	if(ret1<0)
	{
	 printf("error");
	 return;
	}
	pthread_exit(NULL);
}

