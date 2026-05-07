#include<stdio.h>
int pnumber(int num)
{ 
   int sum=1;
    for(int i=2;i<num;i++)
     {
        if(num%i==0)
        {
            sum=sum+i;
        }

     }
     return sum;
}
int main()
{
   int num,s;
   printf("Enter a positive integer number \n");
   scanf("%d",&num);
    s=pnumber(num);
    if(s==num)
      printf("The number is a perfect number \n");
    else
      printf("The number is not a perfect number\n");

   return 0;
}