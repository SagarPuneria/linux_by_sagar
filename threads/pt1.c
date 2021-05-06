#include<stdio.h>
#include<pthread.h>
#include<string.h>
int x=0;
void* print_f(void *msg)
{
	char *str;
	str=(char *)msg;
	x=x+1;
	printf("%s %d\n",str,x);//printf("%s\n",(char *)msg);
	//return (void *)strlen(str);//return (void *)strlen((char *)msg);
	//pthread_exit((void *)"hello");
	//pthread_exit((void *)5);
	pthread_exit((void *)strlen(str));
}
int main()
{

	pthread_t t1,t2,t3;
	void * val;

//////////////////////thread 1///////////////////////////////////
	pthread_create(&t1,NULL,print_f,"helloworld");//pthread_create(&t1,NULL,(void *)print_f,"hello_world");
	pthread_join(t1,&val);//pthread_join(t1,NULL);//NO return value in thread fun
	printf("status=%d\n",val);//printf("status=%s\n",val);
	printf("id=%ld\n",t1);
	
//////////////////////thread 2///////////////////////////////////
	pthread_create(&t2,NULL,print_f,"byeworld");//pthread_create(&t2,NULL,(void *)print_f,"hello_world");
	pthread_join(t2,&val);//pthread_join(t2,NULL);//NO return value in thread fun
	printf("status=%d\n",val);
	printf("id=%ld\n",t2);

//////////////////////thread 3///////////////////////////////////
	pthread_create(&t3,NULL,print_f,"thank_you");//pthread_create(&t3,NULL,(void *)print_f,"hello_world");
	pthread_join(t3,&val);//pthread_join(t3,NULL);//NO return value in thread fun
	printf("status=%d\n",val);
	printf("id=%ld\n",t3);

	pthread_exit(NULL);
}
