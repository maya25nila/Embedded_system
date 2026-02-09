#include<stdio.h>
void second_largest(int A[],int size)
{
      int large;
      int sec_large;
   large=A[0];
  for(int i=1;i<size;i++)
  {
    if(A[i]>large)
    large=A[i];
      }
printf("\nThe largest number is:%d",large);
sec_large=A[0];
for(int i=1;i<size;i++){
if(A[i]!=large){
 if( (A[i]>sec_large))
 
      sec_large=A[i];
}
}
printf("\nsecond largest number:%d",sec_large);
}
int main()
{
    int arr[5]={0};
    int i;
    
    printf("Enter 5 elements for the array");
    for(i=0;i<5;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("\nThe array elements are");
    for(i=0;i<5;i++)
    {
        printf("\narr[%d]=%d",i,arr[i]);

    }
    
  second_largest(arr,5);
  return 0;
}