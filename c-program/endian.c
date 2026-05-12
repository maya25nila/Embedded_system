#include<stdio.h>
int main()
{
 unsigned int a=1;
 unsigned char *p= &a;
      
 if(*p==1){            //*p points to 1st byte ie.if LSB first stored it will be one
    printf("The system is little endian");
    
 }
    else
   { printf("The system is Big endian");
    
   }
   printf("\nThe value in the first byte :%d",*(p+0));
    printf("\nThe value in the second byte :%d",*(p+1));
     printf("\nThe value in the third  byte :%d",*(p+2));
      printf("\nThe value in the fourth byte :%d",*(p+3));

 
 return 0;

}