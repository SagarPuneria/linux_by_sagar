#include<stdio.h>
#include<pthread.h>
#include<string.h>
int x=1;
void* print_f(void *msg)
{
	char *str;
	str=(char *)msg;
	x=x+1;
	printf("%s %d\n",str,x);//printf("%s\n",(char *)msg);
	return (void *)strlen(str);//return (void *)strlen((char *)msg);
}
int main()
{

	pthread_t t1,t2;
	void * val;
	pthread_create(&t1,NULL,print_f,"hi");//pthread_create(&t1,NULL,(void *)print_f,"hello_world");
	pthread_join(t1,&val);//pthread_join(t1,NULL);//NO return value in thread fun
	printf("%d\n",val);

//////////////////////thread 2///////////////////////////////////
	pthread_create(&t2, NULL,print_f, "bye");//pthread_create(&t2, NULL,(void *)print_f,"by_world");
	pthread_join(t2,&val);//pthread_join(t2,NULL);//NO return value in thread fun
	printf("%d\n",val);
	pthread_exit(NULL);
}
