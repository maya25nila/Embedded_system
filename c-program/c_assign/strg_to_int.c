#include<stdio.h>
#include<string.h>
int main()
{
    int n;
char str[50];
printf("Enter a string\n");
scanf("%s",str);
n=strlen(str);

for(int i=0;i<n;i++)
{
    printf("%d",str[i]-'0');  //ASCII OF '0' 48 to make integer  subtract 48 from ASCII
}
printf("\n");

}