#include<stdio.h>
void add(float num1,float num2)
{
    float s;
    s=(num1+num2);
    printf("The sum of the numbers %.3f and %.3f is %.3f \n",num1,num2,s);
}
void sub(float num1,float num2)
{
    float s;
    s=(num1-num2);
    printf("The subtraction of the numbers %.3f and %.3f is %.3f \n",num1,num2,s);
}
void mul(float num1,float num2)
{
    float s;
    s=(num1*num2);
    printf("The product of the numbers %.3f and %.3f is %.3f \n",num1,num2,s);
}
void division(float num1,float num2)
{
    float s;
    s=(num1/num2);
    printf("The division of the numbers %.3f and %.3f is %.3f \n",num1,num2,s);
}
int main()
{
    float num1,num2;
    float result;
    char operator;
    printf("Enter two floating point number");
    scanf("%f  %f",&num1,&num2);
    printf("Enter the operator +  -  /  * \n");
    scanf(" %c", &operator);
    switch(operator)
    {     
    
    case '+':
    {
        add(num1,num2);
        break;
    }
    case '-':
    sub(num1,num2);
    break;
    case '*':
    mul(num1,num2);
    break;
    case '/':
    if(num2==0)
    {
        printf("division by zero invalid\n please enter another number\n");
    }
    else
    {
    division(num1,num2);
    break;
    }
    default:
    printf("Invalid operator\n");
    break;
   }
   return 0;
}