#include<stdio.h>
void print_Binary(int n)
{
    int mask;
   
    for(int i=7;i>=0;i--){
         mask=1<<i;
    if(n & mask)
    printf("1");
    else
    printf("0");
    
}
}

void swap_Bits(int n,int a,int b)
{  
    int mask=1<<a;
    int mask2=1<<b;

    if(((n>>a) & 1)==((n>>b) & 1)) //abstract the bits and check if  equal
        print_Binary(n);    //if bits are equal no change in bits
    
        else{             //if bits are different flips the bits
            n=n ^ mask;
            n=n ^ mask2;
            print_Binary(n);
        }    
    

}




int main()
{
    int num;
    int a,b;  //position of bit to swap
    printf("enter the number :");
    scanf("%d",&num);
    printf("The binary representation of the number :");
    print_Binary(num);
    printf("\nenter the bit position to swap :\n");
    scanf("%d %d",&a,&b);
    printf("after swap bits:");
    swap_Bits(num,a,b);
    return 0;
}