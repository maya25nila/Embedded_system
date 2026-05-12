#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],nstr[100];
    int i,j=0;
    char temp;
    printf("Enter the string\n");
    fgets(str,sizeof(str),stdin);
    
    for(int i=0;str[i]!='\0';i++)
    {
        nstr[j]=str[i];
         if(str[i]==' ' && str[i+1]==' ')
            continue;
         else
         j++;

    }
    nstr[j]='\0';
    printf("The new string is : %s \n",nstr);
    return 0;
}