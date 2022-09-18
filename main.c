/*****************************************************************************/  
/**                  File Name : main.c                                     **/                              
/**                  File Info : Library Management System                  **/
/**                  Author    : Hagar Tarek El-Hassanien                   **/
/**                  Date      : 31.07.2022                                 **/
/**                  Version   : V1.0                                       **/
/*****************************************************************************/

#include "main.h"

/*****************************************************************************/
/************************ Global Declaration Section *************************/
/*****************************************************************************/
u32 x,BookPrice,DelBook,ReturnValue;
u8 BookName[MAX];
u8 AuthorName[MAX];

/*****************************************************************************/
/******************************* Main Section ********************************/
/*****************************************************************************/
u32 main(void){
	
	List_t *List1 =NULL;
	List1 = CreateList();

	printf("-----------!! WELCOME TO LIBRARY APP !!-----------\n\n");
	printf("Choose one of the options:\n");
	printf("To view all books               Enter '1'\n");
	printf("To add a New book               Enter '2'\n");
	printf("To Delete a book                Enter '3'\n");
	printf("To view No. of available books  Enter '4'\n");
	printf("To Exist the Library App        Enter '5'\n");
	printf("\n---------------------------------------------\n");
	printf("\n----->  Your choise is : ");
	scanf("%d",&x);
	fflush(stdin);
	printf("\n");
	
	while(x != 5){
		if(x==1){                        /* if user entered 1 to view all books */
			
			Display(List1);
			printf("\n---------------------------------------------\n\n");
			
		}else if(x==2){                  /* if user entered 2 to add a new book*/
			
			printf("Enter the name of the book : ");
			gets(BookName);
			
			printf(" Enter the name of the author : ");
			gets(AuthorName);
			
			printf("Enter the price of the book : ");
			scanf("%d",&BookPrice);
			fflush(stdin);
			
			AddToBack(List1,BookName,AuthorName,BookPrice);
			
			printf("\n!! The Book has been added succefully !!\n");
			printf("\n---------------------------------------------\n\n");
			
		}else if(x==3){                  /* if user entered 3 to delete a book*/
			
			printf("Enter the Number of the book you want to delete :\n");
			scanf("%d",&DelBook);
				
			if(DelBook==1){
				
				RemoveFromFront(List1, &ReturnValue);
				
			}
			else if((DelBook>1) && (DelBook <(List1->Size))){             
				
			RemoveMiddleNode(DelBook,List1);}
				
			else{
				
				RemoveFromBack(List1,&ReturnValue);
			}
			
			printf("!! The Book has been deleted succefully !!\n\n");
			printf("\n---------------------------------------------\n");
			
			
		}else if(x==4){               /* if user entered 4 to view no. of available books*/
			
			printf("The Number of available Books is : %d\n",(List1->Size));
			printf("\n---------------------------------------------\n\n");
			
		}else{                        /* if user entered 5 to exit the library app */
			printf("Wrong Choice\n");
			printf("\n---------------------------------------------\n\n");
		}
		
		printf("-----------!! WELCOME TO LIBRARY APP !!-----------\n\n");
		printf("Choose one of the options:\n");
		printf("To view all books               Enter '1'\n");
		printf("To add a New book               Enter '2'\n");
		printf("To Delete a book                Enter '3'\n");
		printf("To view No. of available books  Enter '4'\n");
		printf("To Exist the Library App        Enter '5'\n");
		printf("\n---------------------------------------------\n");
		printf("\n----->  Your choise is : ");
		scanf("%d",&x);
		fflush(stdin);
		printf("\n");
		
		}
	
	return 0; 
	
}
