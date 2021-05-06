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
	printf("before swap\n");
	printf("x=%d\n",a.x);
	printf("y=%d\n",a.y);
	a.x=a.x+a.y;
	a.y=a.x-a.y;
	a.x=a.x-a.y;
	printf("after swap\n");
	printf("x=%d\n",a.x);
	printf("y=%d\n",a.y);
	return (void *)&a;
}
int main()
{
	pthread_t t1;
	int ret;
	void *res;
	struct data d,res1;
	printf("enter two values\n");
	scanf("%d%d",&d.x,&d.y);
	ret=pthread_create(&t1,NULL,print,&d);
	pthread_join(t1,&res);
	res1=*(struct data *)res;
	printf("after swap\n");
	printf("x=%d\n",res1.x);
	printf("y=%d\n",res1.y);
	return 0;
}/*
void* print_f(void *arg)
{
	int *d1;
	d1=(int *)arg;
	printf("before swap\n");
	printf("x=%d\n",d1[0]);
	printf("y=%d\n",d1[1]);
	d1[0]=d1[0]+d1[1];
	d1[1]=d1[0]-d1[1];
	d1[0]=d1[0]-d1[1];
	return (void *)d1;
}
int main()
{
	pthread_t t1;
	void * val;
	int d[2]={111,20},*v;
//////////////////////thread 1///////////////////////////////////
	pthread_create(&t1,NULL,print_f,d);//pthread_create(&t1,NULL,(void *)print_f,"hello_world");
	pthread_join(t1,&val);//pthread_join(t1,NULL);//NO return value in thread fun
	v=(int *)val;
	//d[2]=(int )val;
	printf("after swap\n");
	printf("x=%d\n",v[0]);
	printf("y=%d\n",v[1]);	
	pthread_exit(NULL);
}*/
/*#include<stdio.h>
main()
{
	int p=1,q=2;
	p=p+q;
	q=p-q;
	p=p-q;
	printf("p=%d,q=%d\n",p,q);
}*/
