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
void extract_from_pos(int num,int pos,int n)
{
    int i,mask;
    int part;
    printf("The extracted part is:\n");
    for(i=pos+n-1;i>=pos;i--)
    {  
        mask=1<<i;
        if(num & mask)
           printf("1");
        else
        printf("0");
    }
    
}
int main()
{
    int num1,num2,pos,count;
    printf("Enter a number\n");
    scanf("%d",&num);
    printf("Enter second number\n");
    scanf("%d",&num2);
    
    printf("The binary  of the second number :\n");
    print_Binary(num2);

    printf("Enter the starting position of bit\n");
    scanf("%d",&pos);
    printf("Enter the number of bits to be extract\n");
    scanf("%d",&count);
    extract_from_pos(num,pos,count);
    printf("\nNow the binary  of the number :\n");
    print_Binary(num);
    
    return 0;

}