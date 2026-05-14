#include<stdio.h>
int main()
{
    int arr1[5],arr2[5],arr3[10]={0};
    int i=0,j=0,k=0;
    
    
    printf("Enter  5 sorted elements for array1\n");
    for( i=0;i<5;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter  5 sorted elements for array2\n");
    for(j=0;j<5;j++)
    {
        scanf("%d",&arr2[j]);
    }
    i=0;
    j=0;
    while((i<5) && (j<5))
    {
        if(arr1[i]<arr2[j])
        {
           arr3[k]=arr1[i];
           k++;
           i++;
        }
        else
        {
            arr3[k]=arr2[j];
            k++;
            j++;
        }
    }   
        while(i<5)
        {
            arr3[k]=arr1[i];
            k++;
            i++;
        }
        while(j<5)
        {
            arr3[k]=arr2[j];
            k++;
            j++;
        }
    
    
    printf("The sorted array\n");
    for(int k=0;k<10;k++)
    {
        printf("%d\t",arr3[k]);
    }
    printf("\n");
    return 0;
}