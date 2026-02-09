 #include<stdio.h>

int add(int a,int b)
{
    int sum;
    sum=a+b;
    return sum;
}
int sub(int a,int b)
{
    int diff;
    diff=a-b;
    return diff;
}
int mul(int a,int b)
{   int pdt;
    pdt=a*b;
    return pdt;
}
float division(int a,int b)
{
    float divis;
    
    divis=(float)a/b;
    return divis;
    
}

int main()
{
int num1;
int num2;
char operator;
float result;
printf("****calculator*****");
printf("\nEnter the first number: ");
scanf("%d", &num1);

printf("\nenter the second number:");
scanf("%d", &num2);

printf("\nenter the operator: ");
scanf(" %c", &operator);
switch(operator)
{
    case '+' :

      result=add(num1,num2);
      printf("\nsum of the number is :%g",result);
      break;
     case '-':
     result =sub(num1,num2);
     printf("\n difference of the number is :%g",result) ;
     break;

     case '*':
     result=mul(num1,num2);
     printf("\nproduct of the numbers %g",result);
     break;
    
     case '/':
        if (num2==0)
        printf("error:division by zero invalid");
        else
        {
            result=division(num1,num2);
            printf("\ndivision of the numbers %.3f",result);
        }
     break;
     default :
      printf("\n Invalid operator");




}

    return 0;
}