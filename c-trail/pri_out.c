#include<stdio.h>
#define MSG "hello world\n"
#include<limits.h>
int main()
{
    int a=4000000000;
    unsigned int b=4000000000;

    printf("a=%d,b=%u\n",a,b);
    printf("maxi_value a=%d,max_value b=%u",INT_MAX,UINT_MAX);


printf(MSG);
printf("Indian\b\n");
printf("New\rdelhi\n");



printf("a=%x",a);
printf("a=%X",a);
return 0;



}