#include<stdio.h>
int main()  //swap without 3rd variable
{

  int a,b;
  printf("swap two numbers");
  printf("\nenter  the first numbers ");
  scanf("%d",&a);
  printf("enter the second number ");
  scanf("%d",&b);
  printf("a=%d b=%d",a,b);
  a=a+b;
  b=a-b;  //b=a
  a=a-b;  //a+b-a since b=a
  printf("\nafter swap a=%d  b=%d",a,b);


return 0;

}