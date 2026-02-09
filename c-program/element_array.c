#include<stdio.h>     //searching an element in the array
int main()
{
  int array[5]={10,20,30,40,50};
  int *ptr=array;
  int i,loc;
  printf("searching an element\n");
  printf("enter the position of element ");
  scanf("%d",&loc);
  for( i=0;i<5;i++)
  {
    if(i==loc)
   { printf("array[%d] element is%d and its address is %p",i,*(ptr+i),(ptr+i));
    
   }
  }
      if(loc>5)
   printf("\ninvalid location");
   
  
  

return 0;

}