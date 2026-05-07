#include<stdio.h>
int main()
{
    int num,n1=0,n2=1,sum=0;
    printf("Enter number of terms for fibonacci series\n");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("%d \t",sum);
        
        n1=n2;
        n2=sum;
        sum = n1+n2;
        
    }
    printf("\n");
    return 1;
}