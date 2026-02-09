#include<stdio.h>
int main()     //post decrement and predecrement in array element
{
   int arr[]={10,20,30,40,50};
   int *p=arr;
   int i=1,x;
   int y;
   printf("The 2nd element of the array arr[%d]=%d at the address %p ",i,*(p+i),p+i);
   printf("\npost decrement array value and put in x ");
    x=(*(p+i))--;

  printf("\nNow element in the array arr[%d]=%d at the address %p value in the x=%d",i,*(p+i),p+i,x);
  printf("\npost decrement the array address and read the array value");
  y=(*(p+i--)); //value in the y is still previous value in p+i due to post decrement
  printf("\narr[%d]=%d and its address %p",i,*(p+i),p+i);
  printf("\ny=%d due to post decrement the address   ",y);
  printf("\n******pre-decrement operation***");
  int a,b;
  
  printf("\n 4th elementof the array:arr[3]=%d and its address %p",*(p+3),p+3);
  a=--(*(p+3));
  printf("\narr[3]=%d at address %p  \na=%d,after pre decrement",*(p+3),p+3,a);


return 0;

}