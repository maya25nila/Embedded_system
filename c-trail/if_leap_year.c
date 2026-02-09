#include<stdio.h>         //to find the given year leap year or not
int main()
{
 int year;
 // int leap;

  printf("enter the year:");
  scanf("%d",&year);
  if(year%100==0 && year%400==0 || year%4==0)
   printf("the year is leapyear");
   else
       printf(" year is not leap year");



return 0;

}