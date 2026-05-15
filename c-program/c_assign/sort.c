/***Write a C program that rearranges an array such that all negative numbers
appear before all positive numbers while preserving the relative order of both groups.
****/
#include<stdio.h>
int main()
{
    int arr[100];
    int i,n;
    
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter  elements for array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        printf("%d\t",arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]>=0)
        printf("%d\t",arr[i]);
        
    }
    return 0;
}