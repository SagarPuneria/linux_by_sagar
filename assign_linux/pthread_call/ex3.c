#include<stdio.h>
#include<pthread.h>
#include<string.h>
struct data{
	int x;
	int y;
}a;
void* print(void *arg)
{
	a=*(struct data *)arg;
	printf("before swap");
	printf("%d",a.x);
	printf("%d",a.y);
	a.x=a.x+a.y;
	a.y=a.x-a.y;
	a.x=a.x-a.y;
	printf("after swap");
	printf("%d",a.x);
	printf("%d",a.y);
	return (void *)&a;
}
int main()
{
	pthread_t t1;
	int ret;
	void *res;
	struct data d,res1;
	printf("enter two values");
	scanf("%d%d",&d.x,&d.y);
	ret=pthread_create(&t1,NULL,print,&d);
	pthread_join(t1,&res);
	res1=*(struct data *)res;
	printf("after swap");
	printf("%d",res1.x);
	printf("%d",res1.y);
	return 0;
}
