#include<stdio.h>
int main()
{   int num;
    int j;
    printf("Number of rows for pyramid\n");
    scanf("%d",&num);
    for(int i=1;i<=num;i++) //for number of raws
    {
        for(j=0;j<num-i;j++)    //for space
         {
           printf(" ");       
         }
       for(j=0;j<2*i-1;j++)//for printing star in the pattern
           printf("*");
        printf("\n");
    }
return 0;
}
