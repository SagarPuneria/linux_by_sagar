#include<stdio.h>
main()
{
int a = 0, b = 0 ;
int sum = 0 ;
printf("Enter any two numbers\n") ;
scanf("%d %d",&a, &b) ;
sum = a+b;
if(sum > 10)
printf("sum is greater than 10\n") ;
else
printf("sum is less than 10\n") ;
}
