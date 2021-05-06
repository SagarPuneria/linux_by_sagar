#include<stdio.h>
#include<pthread.h>
int x=0;
void* print_f(char *msg)
{
	int i,j;
	printf("%s\n",msg);

		j=x;
		j=j+1;
		sleep(1);
		x=j;
	
		printf("%d %s\n",x,msg);
}
void* print_z(char *msg)
{
	int i,j;
	printf("%s\n",msg);

		j=x;
		j=j-1;
		sleep(1);
		x=j;
	
	printf("%d %s\n",x,msg);
}
/*
void* print_f(char *msg)
{
	int i,j;
	printf("%s\n",msg);
	for(i=0;i<20;i++)
	{
	//	printf("%s\n",msg);
		j=x;
		j=j+1;
		sleep(1);
		x=j;
	}
	printf("%d\n",x);
}
*/
int main()
{
	pthread_t t1,t2;
	int ret=-1,ret1=-1;
	ret1=pthread_create(&t2, NULL,(void *)print_f, "world");
	if(ret1<0)
	{
		printf("error");
		return;
	}
	//ret=pthread_create(&t1, NULL,(void *)print_f, "hello");
	ret=pthread_create(&t1, NULL,(void *)print_z, "hello");
	if(ret<0)
	{
		printf("error");
		return;
	}
	ret=pthread_join(t1,NULL);
	if(ret<0)
	{
		printf("error");
		return;
	}
	ret1=pthread_join(t2,NULL);
	if(ret1<0)
	{
		printf("error");
		return;
	}
	pthread_exit(NULL);
}
