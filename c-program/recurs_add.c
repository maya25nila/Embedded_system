#include<stdio.h>

int rec(int n)
{
    int s;
    if(n==0)
       return 0;
    
    return(n+rec(n-1));
    
    
}

int main()
{
    int num,s;
    printf("enter a number");
    scanf("%d",&num);
    s=rec(num);
    printf("the sum of numbers upto %d is %d",num,s);



return 0;
}