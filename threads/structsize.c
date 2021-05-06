#include<stdio.h>
struct data
{
	int a;
	char b;
	float c;
};
struct data1
{
	int a;
	float b;
	char c;
};
struct data2
{
	int a;
	short b;
	char c;
};

main()
{
	printf("size=%d\n",sizeof(struct data));//output=12bytes
	printf("size=%d\n",sizeof(struct data1));//output=12bytes
	printf("size=%d\n",sizeof(struct data2));//output=12bytes
}
