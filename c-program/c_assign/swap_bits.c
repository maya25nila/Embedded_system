#include<stdio.h>
void print_Binary(int num)
{
    int mask;
    for(int i=7;i>=0;i--)
    {   
        mask=1<<i;
        if(num & mask)
         printf("1");
        else
        printf("0");
    }
    printf("\n");
}
void swap(int num1,int num2,int pos,int n)
{
    int mask;
    int n1,n2;
    mask=(1<<n)-1;
    
    //extract n bits from num1
    n1=(num1>>pos) & mask;
    n2=(num2>>pos) & mask;
    //clear the target bit
    num1 = (num1) & ~(mask<<pos);
    num2 = (num2) & ~(mask<<pos);
   //swap bits
    num1=num1 | (n2<<pos);
    num2=num2 | (n1<<pos);
    printf("the swap value of num1 %d\n binary: ",num1);
    print_Binary(num1);
    
    printf("the swap value of num2 %d\n binary: ",num2);
    print_Binary(num2);

}
int main()
{
    
    int num1,num2,pos,count;
    
    printf("Enter a number\n");
    scanf("%d",&num1);
    printf("Enter second number\n");
    scanf("%d",&num2);

    printf("The binary  of the first number :\n");
    print_Binary(num1);
    
    printf("The binary  of the second number :\n");
    print_Binary(num2);
    
    printf("Enter the position\n");
    scanf("%d",&pos);
    printf("Enter the no of bits to swap\n");
    scanf("%d",&count);

    swap(num1,num2,pos,count);

    return 0;
}