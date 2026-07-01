#include<stdio.h>
void printBit(unsigned char n)
{
    int mask,i;
    for(i=7;i>=0;i--)
    {   mask=1<<i;
        if(n & mask)
        printf("1");
        else
        printf("0");

    }
}
void bit_manipulate(unsigned char n)
{  
    int mask;
    //set the 3rd bit
    mask =(1<<2);
    n=n | mask; 
    //clear the 6th bit
    mask=0;
    mask =(1<<5);
    n &= ~mask;
    //toggle the first bit
    mask=0;
    mask=(1<<0);
    n= n ^ mask;
 
    printBit(n);
}
int main()
{
    unsigned char n;
    printf("Enter the register value ");
    scanf(" %hhu",&n);
    printf("The binary value is \n");
    printBit(n);
    printf(" \nAfter bit manipulation\n");
    bit_manipulate(n);
    printf("\n");
    return 0;
}
