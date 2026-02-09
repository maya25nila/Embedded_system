#include<stdio.h>
int main()
{

char ch;
printf("enter a character:");
scanf("%c",&ch);
printf("%d\n",ch);             //print the ascii value of ch



printf("%10s\n","India");
printf("%4s\n","India");
printf("%.2s\n","India");
printf("%5.2s\n","India");


float a1,a2,a3,b1,b2;
double b3;
a1=2;
a2=4.2;
a3=9.82;
b1=6.8;
b2=3.57;
b3=853457.673;
printf("%3.1f,%4.2f\n",a1,b1);
printf("%5.1f,%6.2f\n",a2,b2);
printf("%7.1f,%8.2lf\n",a3,b3);





return 0;



}