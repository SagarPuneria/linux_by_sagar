#include<stdio.h>
#include<pthread.h>
void *threadfun(void *arg);
struct data
{
	int x;
	short y;
	char z;
};
void *threadfun(void *arg)
{
	int q;
	struct data d1;
	d1=*(struct data *)arg;
	printf("%d\n",d1.x);
	printf("%d\n",d1.y);
	printf("%c\n",d1.z);
	q=sizeof(d1);//x=sizeof(struct data);
	return (void *)q;
}
int main()
{
	void * val;
	struct data d={100,20,'a'};
	pthread_t t;
	pthread_create(&t,NULL,threadfun,&d);
	pthread_join(t,&val);
	printf("%d\n",val);
	pthread_exit(NULL);
	printf("sagar");//NO output
}
