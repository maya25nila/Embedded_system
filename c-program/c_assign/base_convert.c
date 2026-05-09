#include<stdio.h>

void convert(int number,int base)
{
int rem;

    if(number==0)
     return;
  else  
    { rem=number%base;
     convert(number/base,base);
    }

if(rem<10)
printf("%d",rem);
else
printf("%c",rem-10+'A');
}


int main()
{
   int num,base;
   printf("Enter a decimal number :");
   scanf("%d",&num);
   printf("Enter the base between 2 to 16 :");
   scanf("%d",&base);
   printf("the converted number :\n");
   convert(num,base);
   printf("\n");

return 0;

}