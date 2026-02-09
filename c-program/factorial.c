#include<stdio.h>
int fact(int n){
    if(n==1)
    {
    printf("1 ");
      return 1;
    }
    
      printf("%d*",n);
      return(n*fact(n-1));
      }
       
      

int main()
{
    int num;
    int facts;
    printf("enter the number: ");
    scanf("%d",&num);
    printf("factorial of %d\n",num);
     facts=fact(num);
     printf("=%d",facts);
    
   
    return 0;


}