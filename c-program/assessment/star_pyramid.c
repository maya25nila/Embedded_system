#include<stdio.h>
int main()
{
    int n,i,j;
    printf(" Enter the number of rows for pyramid\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)//for loop for rows
    {
     for(j=1;j<=n-i;j++)
     { 
      printf(" ");
     }
     for(j=1;j<=i*2-1;j++)
     { printf("*");
     }
     printf("\n");
    }
 printf("\n");
 return 0;
}