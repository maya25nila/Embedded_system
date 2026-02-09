#include<stdio.h>
    void print_Bit(unsigned char x)
    {
      unsigned char mask;
      for(int i=7;i>=0;i--)
      { 
         mask=1<<i;
         if(x & mask)
         printf("1");
        else
        printf("0");
      }
    }
   unsigned char set_3Bit(unsigned char x)
  {
     
      
       x=x | (1<<2);
//clear 6th bit            
              x=x & ~(1<<5);

   //toggle 1stBit
          
        x=x ^ (1<<0);
              return (x);
    }
int main()
{
    unsigned char a;
    unsigned char p;
    printf("Enter the register value:");
    scanf("%hhu",&a);
    print_Bit(a);
    p=set_3Bit(a);
    printf("\nThe modified register");
    print_Bit(p);
    return 0;
}