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
void toggle_from_pos(int num,int pos,int n)
{
    int i,mask;
    
    for(i=pos;i<=pos+n;i++)
    {  
        mask=1<<i;
        num=num ^ mask;
    }
    print_Binary(num);
}
int main()
{
    int num;
    int pos,no;
    printf("Enter a number\n");
    scanf("%d",&num);
    printf("The binary  of the number :\n");
    print_Binary(num);
    printf("Enter the starting position of bit\n");
    scanf("%d",&pos);
    printf("Enter the number of bits to be modified\n");
    scanf("%d",&no);
    printf("The number after toggle\n");
    toggle_from_pos(num,pos,no);
    return 0;
}