#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    int i,l;
    char temp;
    printf("Enter the string\n");
    fgets(str,sizeof(str),stdin);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]  >= 'A' && str[i] <= 'Z')
        {
            str[i]=str[i] + 32; //ASCII of A 65 and a is 97
        }
    }
    printf("%s \n",str);

    return 0;
}
    