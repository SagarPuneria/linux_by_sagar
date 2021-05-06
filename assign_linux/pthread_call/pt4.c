#include<stdio.h>
#include<pthread.h>
#include<string.h>
//int n[5]={5,4,1,2,3};
void* print_f(void *msg)
{
	int s=0,*r,i=0,j,min;
	r=(int *)msg;
	//printf("n=%d\n",*(int *)msg);
	min=i;
	for(j=i+1;j<5;j++)
		if(*(r+min)>*(r+j))
			min=j;
	
	return (void *)min;
}
int main()
{
	int n[5]={5,6,4,7,9};
	pthread_t t1,t2,t3;
	void * val;
//////////////////////thread 1///////////////////////////////////
	pthread_create(&t1,NULL,print_f,n);//pthread_create(&t1,NULL,(void *)print_f,"hello_world");
	pthread_join(t1,&val);//pthread_join(t1,NULL);//NO return value in thread fun
	printf("index=%d\n",val);
	printf("min number=%d\n",n[(int )val]);
	pthread_exit(NULL);
}
