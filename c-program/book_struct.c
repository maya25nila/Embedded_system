#include <stdio.h>



typedef struct
{
	char title[25];
	char author[20];
	int price; /* data */
} book;


int main()
{
	book b1,b2,b3;
	printf("enter the first book details\n");
	printf("\ttitle:");
	scanf("%s",b1.title);
	printf("\tAuthor name:");
	scanf("%s",b1.author);
	printf("\tprice:");
	scanf("%d",&b1.price);

	printf("enter the second book details\n");
	printf("\ttitle:");
	scanf("%s",b2.title);
	printf("\tAuthor name:");
	scanf("%s",b2.author);
	printf("\tprice:");
	scanf("%d",&b2.price);

	printf("enter the third book details\n");
	printf("\ttitle:");
	scanf("%s",b3.title);
	printf("\tAuthor name:");
	scanf("%s",b3.author);
	printf("\tprice:");
	scanf("%d",&b3.price);

	if(b1.price>b2.price)
	{
		if(b1.price>b3.price)
		
			printf("The book one has the highest price");
		
		else
			printf("book 3 has the highest price");
	}
	else
	   {
	       if(b2.price>b3.price)
	
	    	printf("the book 2 has the highest price");
	        
	    
		 else
			printf("the book 3 has the highest price");
		

	   }


	return 0;

}