#include<stdio.h>
int main()
{
    int arr[100];
    int n;
    int count=0;
    printf("Enter no.of Elements\n");
    scanf("%d",&n);
    printf("Enter elements for array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
     for(int j=i+1;j<n;j++)
      {

        if(arr[i]==arr[j])//if duplicate found shift number   next number to this place
        {
            for(int k=j;k<n-1;k++)
             arr[k]=arr[k+1];
            count=count+1;
        }   

      }
    }
      printf("The values in array after removing duplicate\n");
      for(int i=0;i<=n-count;i++)
      {
        printf("%d\t ",arr[i]);
      }
    printf("\n");
    return 0;
}