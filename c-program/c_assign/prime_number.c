#include<stdio.h>
int main()
{
    int num;
    int prime_chk;
    printf("Enter a number\n");
    scanf("%d",&num);
    if(num<=1)
    {
        printf("The number is not prime.please enter a number greater than 1\n");
    }
    else if(num==2)
         printf("The number 2 is prime number\n");
    else if(num>2)
    {
        for(int i=2;i<num;i++)
        {
         if(num%i==0)
         {
         prime_chk=0;
         break;
         }
        else
         prime_chk=1;

        }
    
      if(prime_chk==1)
      printf("The number is prime \n");
       else
       printf("The number is not prime \n");
    }
    return 1;
}