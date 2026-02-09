#include<stdio.h>
void printBit(int n)
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
int setBit(int n,int pos)
{
   int mask;
   mask=1<<pos;
   n=n | mask;
   printBit(n);
   return (n);
}
 int setbit_No(int num)
 {
    int mask;
    int count=0;
        for(int i=0;i<=7;i++)
    {   
        mask=1<<i;
         if(num & mask)
             count++;

    }
   return count;
}
int main()
{

int a,pos;
int b;
int count;
printf("enter a number :");
scanf("%d",&a);
//printf("enter the bit position :");
//scanf("%d",&pos);
printBit(a);
pos=5;
printf("\n after set the 5th bit");
b=setBit(a,pos);
count=setbit_No(b);
printf("\nThe no.of set bits in the number:%d",count);
return 0;
}






