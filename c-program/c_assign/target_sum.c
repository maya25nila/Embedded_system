#include<stdio.h>
int main()
{
    int arr[100];
    int n;
    int s;
    int count=0;
    
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter  elements for array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter target sum for array\n");
    scanf("%d",&s);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n ;j++)
        {
            if(i==j)
            continue;
            
            if(s==arr[i]+arr[j])
            {
                
             printf("%d + %d = %d\n",arr[i],arr[j],s);
             count++;
            }
        }
    }
    if(count==0)
    {
        printf("There is no target sum of pairs found ");
    }
    printf("\n");
    return 0;
}