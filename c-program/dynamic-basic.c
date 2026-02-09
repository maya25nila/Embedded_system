#include<stdio.h>
#include<stdlib.h>
int main()
{
    
    int num;
    int *ptr;
    int n;    //for no.of new location
    int i;

    printf("Enter no of elements for the array:\n ");
    scanf("%d",&num);

    
     
   // ptr=(int*) malloc(num * sizeof(int));      /*dynamic m/m allocation by malloc()*/


    ptr=(int*)calloc(num,sizeof(int));  //dynamic memory allocation by calloc()


     if(ptr==0)
     {
        printf("\nmemory allocation invalid");
        return 0;
     }
     printf("\nenter the %d numbers for the array",num);
   for(int i=0;i<num;i++){
   
    printf("\nenter the %d th element:",i+1);
      scanf("%d",ptr+i);
   }
   printf("\nThe elements in the array and its address\n");
   for(int i=0;i<num;i++)
   printf("ptr[%d]=%d with address%p\n",i,*(ptr+i),ptr+i);

   //reallocate m/m by realloc()

   printf("enter the number of new locations:");
   scanf("%d",&n);
   
   ptr=(int*)realloc(ptr,(num+n)*sizeof(int));

   for(i=num;i<(num+n);i++)
   {
   printf("\nenter the %d th element:",i+1);
   scanf("%d",&ptr[i]);
   }
printf("the new elements are\n");
for(i=num;i<num+n;i++){
    printf("ptr[%d]=%d and its address is %p\n",i,*(ptr+i),ptr+i);
} 
   free(ptr);
   ptr=NULL;
    return 0;
}