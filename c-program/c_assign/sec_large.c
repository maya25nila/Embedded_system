#include<stdio.h>
int main()
{
    int arr[100];
    int n;
    int large,sec_lar;
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter  elements for array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    large=arr[0];
    int small=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>large)
           large=arr[i];
        if(arr[i]<small)
           small=arr[i];
            
    }
    printf("the largest %d\n",large);
    printf("the smallest %d\n",small);
    sec_lar=0;
    int sec_small=arr[0];
    for(int i=0;i<n;i++)
    {
        if((arr[i]>sec_lar) && arr[i]!= large)
           sec_lar=arr[i];
        if(arr[i]<sec_small  && arr[i]!= small)
            sec_small=arr[i];
            
    }
    printf("the sec_largest %d\n",sec_lar);   
     printf("the sec_smallest %d\n",sec_small);

    return 0;
}