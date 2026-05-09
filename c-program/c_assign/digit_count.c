/*Write a C program that uses a function to count the frequency of each digit (0–9) in a given integer.
*/
#include<stdio.h>
int* dig_count(int num)
{   static int str[10]={0} ;  
      int digit;  //for count
      while(num>0)
      {
        digit=num%10; //to get last digit
        num=num/10; //remove last digit
      
        str[digit]++;
      }
   
return str;
}
int main()
{
    int num;
    int *dig;
    printf("Enter an Integer number :");
    scanf("%d",&num);
    dig=dig_count(num);
    for(int i=0;i<10;i++)

    printf("%d occurs %d times\n",i,dig[i]);

 return 0;
}