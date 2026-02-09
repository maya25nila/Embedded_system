#include<stdio.h>
void print_Bin(int n)
{
    int mask;
    for(int i=7;i>=0;i--)
    {  
        mask=1<<i;
        if(n & mask)
        printf("1");
        else
        printf("0");
    }
    printf("\n");
}
void toggle_Bit(int n,int loc)
{
    int mask;
    mask=1<<loc;
    n=n ^ mask;
    print_Bin(n);
}
int main()
{

    int num;
    int pos;
    printf("enter a number");
    scanf("%d",&num);
    printf("\nThe binary for the number");
    print_Bin(num);
    printf("\n-----toggle the bit----");
    printf("\nenter the bit position to toggle ");
    scanf("%d",&pos);
    printf("\nnumber after toggle the bit\n");
    toggle_Bit(num,pos);

    return 0;



}