#include <stdio.h>
#include <stdlib.h>                //dynamic m/m allocation
int main()
{
   int a =10;
   int *ptr= &a;
   int *p;
   int *c;
   int n=3;

  p = (int *)malloc(0); //dynamic m/m not allocate
   if(p == NULL){
         printf("Memory allocation failed\n");
         return 1;
    }


    for(int i=0;i<n;i++){
        printf("Enter %dth integer:",i+1);
        scanf("%d", p+i);
    }
    p=(int *)realloc(p, (2*n) * sizeof(int));
    if(p == NULL){
         printf("Memory reallocation failed\n");
         return 1;
    }
    for(int i=n;i<2*n;i++){
        printf("Enter %dth integer:",i+1);
        scanf("%d", p+i);
    }
    printf("The integers stored are:\n");
    for(int i=0;i<2*n;i++){
        printf("%d\n", *(p+i));
    }
   free (p);
   p=NULL;
 
   return 0;
}