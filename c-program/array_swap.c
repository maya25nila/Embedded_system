#include<stdio.h>
void print_Array(int arr[],int n)
{
for(int i=0;i<n;i++)
    {
    printf("arr[%d]=%d\n",i,arr[i]);
    }
    
}
int main()
{
    int arr[5];
    int i;
    printf("Enter the 5 elements for the array\n");
    for( i=0;i<5;i++)
    {
       scanf("%d",&arr[i]);

    }
    printf("The array elements are:");
    print_Array(arr[5],5);
    
    printf("The swap values for array\n");
     int temp;
     int n=5;
    for(i=0;i<n/2;i++)
    {  
        temp=arr[i];
        arr[i]=arr[n];
        arr[n]=temp;
        
    }
    print_Array(arr,5);
    return 0;
}