#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int l;
    int flag=0;
    printf("Enter a string\n");
    scanf("%s",str);
    l=strlen(str);
    
    for(int i=0;i<l/2;i++)
    {
        if(str[i]==str[l-i-1])
             flag=1;
            else
            {
              flag=0;
               break;
            }
         
    }
    if(flag==1)
    printf("The string is palindrome\n");
    else
    printf("The string is not palindrome\n");
 return 0;
}