/*GCD by eucledian method using recursion */
#include<stdio.h>


int gcd_num(int num1,int num2)
{      
    
        if(num1%num2==0)
         return num2;
        else
         {
           return gcd_num(num2,num1%num2);
         }
         
} 
int main()
{
    int num1,num2;
    int gcd;
    printf("***Greatest common Divisor***\n");
    printf("Enter the first positive integer number:");
    scanf("%d",&num1);
    printf("Enter the second positive integer number:");
    scanf("%d",&num2);
    gcd=gcd_num(num1,num2);
    printf("GCD of %d and %d is %d\n",num1,num2,gcd);

    return 0;

}