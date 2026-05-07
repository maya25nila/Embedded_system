#include<stdio.h>
int main()
{
    int num;
    unsigned long long int fact=1;
    printf("Enter a number for factorial\n");
    scanf("%d",&num);
    if(num==0)
    {
        printf("0 factorial is 1\n");
    }
    else
    {
    for(int i=1;i<=num;i++)
      {
        fact=fact*i;
      }
    printf("The factorial of %d is %llu \n",num,fact);
    }
    return 1;
}