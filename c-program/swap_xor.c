#include<stdio.h>
int main()
{
    int x,y;
    printf("enter a number");
    scanf("%d",&x);
    printf("enter the second number");
    scanf("%d",&y);
    printf("x=%d y=%d",x,y);
    printf("\nafter swap");
    x=x^y;
    y=x^y;   //x^y^y=x
    x=x^y; //x^y^x=y
    printf("\nx=%d y=%d",x,y);
    return 0;
}