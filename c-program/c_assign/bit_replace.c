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

int replace_bits(int num1,int num2,int pos,int n)
{
    int mask,part;
    int result;
    mask=(1<<n)-1; //mask of n bits
    //clear bits in num1
    num1 &=~(mask<<pos);
    //extract n bits from num2
    part= (num2>>pos) & mask ;
    //replace
    result= num1 |(part<<pos);
    return result;
    
}
int main()
{
    
    int num1,num2,pos,count;
    int result;
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
    printf("Enter the no of bits to replace\n");
    scanf("%d",&count);
    
    result=replace_bits(num1,num2,pos,count);
    printf("After replace num1 is  \n");
    print_Binary(result);
    printf("The integer value :%d \n",result);
    return 0;

}