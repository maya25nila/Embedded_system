#include<stdio.h>
#include<string.h>
int main()
{
  int num,l;
  int i;
  int sign;
  char str[50];
  printf("Enter a whole number\n");
  scanf("%d",&num);
  if(num<0)
  {
     sign =1;
     num = -num;
  }

  for( i=0;num!=0;i++)
    {
    str[i]=(num%10)+'0';
    num=num/10;
    }
    if(sign==1)
     str[i++]='-';
    
  
     str[i]='\0';  //at the end put \0 for string termination 
  l=strlen(str);

    for(int j=l-1;j>=0;j--)//print in reverse order to get the number
    {
       printf("%c",(str[j]));
    }
 printf("\n");
 return 0;
}