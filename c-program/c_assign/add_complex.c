/**Define a structure Complex with real and imaginary parts. Write a C program 
to add two complex numbers and display the result. */
#include<stdio.h>
    struct complex{
        float real;
        float img;
    }c1;

int main()
{
        
        
    struct complex c2;
    
    printf("The addition of 2 complex numbers\n");
    printf("Enter 1st complex number\n");
    scanf("%f %f",&c1.real,&c1.img);
    printf("Enter 2nd complex number\n");
    scanf("%f %f",&c2.real,&c2.img);
    printf("The sum of this complex number :\n");
    printf("%.2f+%.2fi",(c1.real+c2.real),(c1.img+c2.img));


    return 0;
}