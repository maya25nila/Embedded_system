#include<stdio.h>
int main()
{

 int i,j;
 int num;
 
 printf("enter the number for rows of pyramid");
 scanf("%d",&num);
 
 for(i=num;i>0;i--)
 {
    for(j=1;j<=i;j++)
    {
        printf("*");
    }
    printf("\n");
    
  }


return 0;

}
