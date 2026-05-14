#include<stdio.h>
int main()
{
    int arr[100];
    int n,num;
    char d;
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter  elements for array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter direction of rotation\n");
    printf("left-  L\nright -   R\n");
    scanf(" %c",&d);
    printf("Enter number of position to rotate\n");
    scanf("%d",&num);
   int temp;
   if((d=='R') || (d=='r'))
   {
      for(int i=0;i<num;i++)
      {
         temp=arr[n-1];
        for(int j=n-1;j>0;j--)
        {
          arr[j]=arr[j-1];
        }
        arr[0]=temp;
      }
    }
    else if((d=='L') || (d=='l'))
    {for(int i=0;i<num;i++)
      {
         temp=arr[0];
        for(int j=0;j<n;j++)
        {
          arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
      }

    }
    printf("After rotation\n");
     for(int i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }   
    printf("\n");
    return 0;
}