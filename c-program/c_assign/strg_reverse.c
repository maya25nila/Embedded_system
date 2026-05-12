#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int i,l;
    char temp;
    printf("Enter the string\n");
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l/2;i++)
    {
        temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
    }
    printf("%s",str);
    printf("\n");
}