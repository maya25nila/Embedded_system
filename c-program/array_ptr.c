#include<stdio.h>
int main()
{

 int arr[5]={1,11,22,44,55};
 int *ptr=arr;
   printf("now array values\n") ; 
  for(int i=0;i<5;i++)
 {
    
   printf("arr[%d]=%d placed in the address %p add 5 to values %d\n",i,*(ptr+i),ptr+i,*(ptr+i)+5);
 } 
   
 //post increment operation

 int i=2;
 printf("before post increment arr[%d]=%d",i,*(ptr+i));
  (*(ptr+i))++;
 printf(" \nafter post incrment  %d and address %p",*(ptr+i),(ptr+i));


 return 0;
}


