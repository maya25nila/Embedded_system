#include<stdio.h>

PrintBin(int a){
    int i,mask;
    for(i=7;i>=0;i--){
      mask=1<<i;
      if(a & mask)
      printf("1");
      else
            printf("0");
    }
}
setBit(int num,int pos)
{
    int mask;
    int i;
    mask=1<<pos;
    num=num | mask;
     PrintBin(num);
}
clearBit(int num,int loc)
{
    int mask;
    mask=~(1<<loc);
    num=num & mask;
    PrintBin(num);
}
int main()
{
 int n;
 int pos;
 printf("Enter the number: ");
 scanf("%d",&n);
 printf("The binary value of %d is ",n);
 PrintBin(n);
 printf("\nenter the position to set: ");
 scanf("%d",&pos);
 printf("set the %d th bit ",pos);
 setBit(n,pos);
 printf("enter the positin to clear the bit:");
 scanf("%d",&pos);
 
 printf("The number with %dth bit cleared  ",pos);
  clearBit(n,pos);
return 0;



}