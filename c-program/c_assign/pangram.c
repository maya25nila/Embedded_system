#include<stdio.h>
int main()
{
    char str[100];
    int alph[26]={0}; //for cheking each alphabet
    int i;
    int flag=0;
    printf("Enter the string\n");
    fgets(str,sizeof(str),stdin);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A' && str[i]<='Z')
           alph[str[i]-'A']=1;
        else if(str[i]>='a' && str[i]<='z')
           alph[str[i]-'a']=1;
    }
    for(i=0;i<26;i++)
    {
        if(alph[i]==1)
           flag=1;
        else
        {
           flag=0;
           break;
        }
    }

    if(flag==1)
    printf("The string is pangram\n");
    else
    printf("The string is not pangram\n");
return 0;
    
}