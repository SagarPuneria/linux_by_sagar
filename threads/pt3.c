#include<stdio.h>
#include<pthread.h>
#include<string.h>
struct data
{
	int x;
	int y;
}d;
void* print_f(void *arg)
{
	printf("before swap\n");
	printf("x=%d\n",d.x);
	printf("y=%d\n",d.y);
	d.x=d.x+d.y;
	d.y=d.x-d.y;
	d.x=d.x-d.y;
}
int main()
{

	pthread_t t1;
	void * val;
	printf("enter x val\n");
	scanf("%d",&d.x);
	printf("enter y val\n");
	scanf("%d",&d.y);
//////////////////////thread 1///////////////////////////////////
	pthread_create(&t1,NULL,print_f,&d);//pthread_create(&t1,NULL,(void *)print_f,"hello_world");
	pthread_join(t1,NULL);//pthread_join(t1,NULL);//NO return value in thread fun
	printf("after swap\n");
	printf("x=%d\n",d.x);
	printf("y=%d\n",d.y);	
	pthread_exit(NULL);
}
/*struct data
{
	int x;
	int y;
};
void* print_f(void *arg)
{
	struct data d1;
	d1=*(struct data *)arg;
	printf("before swap\n");
	printf("x=%d\n",d1.x);
	printf("y=%d\n",d1.y);
	d1.x=d1.x+d1.y;
	d1.y=d1.x-d1.y;
	d1.x=d1.x-d1.y;
	printf("%d\n",&d1);
	return (void *)&d1;
}
int main()
{

	pthread_t t1;
	void * val;
	struct data d,*d1;//={100,20};
	printf("enter x val\n");
	scanf("%d",&d.x);
	printf("enter y val\n");
	scanf("%d",&d.y);
//////////////////////thread 1///////////////////////////////////
	pthread_create(&t1,NULL,print_f,&d);//pthread_create(&t1,NULL,(void *)print_f,"hello_world");
	pthread_join(t1,&val);//pthread_join(t1,NULL);//NO return value in thread fun
//printf("%d\n",val);
	d1=(struct data *)val;
	printf("after swap\n");
	printf("x=%d\n",d1->x);
	printf("y=%d\n",d1->y);	
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
