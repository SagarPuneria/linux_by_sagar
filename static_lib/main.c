#include<stdio.h>
float div(int,int);
int main()
{
	int res,a,b;
	long int res1;
	float res2;
	printf("enter any 2 no.\n");
	scanf("%d%d",&a,&b);
	res=add(a,b);
	printf("addition is %d\n",res);
	res=sub(a,b);
	printf("subtraction is %d\n",res);
	res1=mul(a,b);
	printf("multiplication is %ld\n",res1);
	res2=div(a,b);
	printf("division is %f\n",res2);
	res=mod(a,b);
	printf("module is %d\n",res);
	return 0;
}
