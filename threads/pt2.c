#include<stdio.h>
#include<pthread.h>
#include<string.h>
void* print_f(void *msg)
{
	int s=0,r,i;
	r=*(int *)msg;
	printf("n=%d\n",*(int *)msg);
	for(i=0;i<=r;i++)
	{
		s=s+i;
	}
	return (void *)s;
}
int main()
{

	pthread_t t1,t2,t3;
	void * val;
	int n;
	printf("enter n intger\n");
	scanf("%d",&n);
//////////////////////thread 1///////////////////////////////////
	pthread_create(&t1,NULL,print_f,&n);//pthread_create(&t1,NULL,(void *)print_f,"hello_world");
	pthread_join(t1,&val);//pthread_join(t1,NULL);//NO return value in thread fun
	printf("sum of n integers=%ld\n",val);
	pthread_exit(NULL);
}
