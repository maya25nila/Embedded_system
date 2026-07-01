#include<stdio.h>
int sec_lar(int arr[50],int size)
{
    int large,sec_big;
     large=arr[0];
    for(int i=1;i<size;i++)
    {
        if(arr[i]>large)
         large=arr[i];
    }
    
      sec_big=0;
      for(int i=0;i<size;i++)
     {
      if((arr[i]>sec_big) && (arr[i]!= large))
      sec_big=arr[i];
     }
    
    
      
    return sec_big;
}
int main()
{
    int arr[150];
    int size,sec_big;
    printf("Ënter the size of array :");
    scanf("%d",&size);
    printf("Ënter the elements for the array \n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    sec_big=sec_lar(arr,size);
    printf("The second largest number is:%d\n",sec_big);
    
return 0;

}