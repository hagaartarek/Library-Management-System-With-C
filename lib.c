/*****************************************************************************/  
/**             File Name : main.c                                          **/                              
/**             File Info : this file has all functions implementations.    **/
/**             Author    : Hagar Tarek El-Hassanien.                       **/
/**             Date      : 31.07.2022                                      **/
/**             Version   : V1.0                                            **/
/*****************************************************************************/

#include "lib.h"

/*****************************************************************************/
/************************ Global Declaration Section *************************/
/*****************************************************************************/
u8 i ;

/*****************************************************************************/
/************************* Functions ProtoTypes ******************************/
/*****************************************************************************/


/*****************************************************************************/
/** Function Name   : CreateList()                                          **/
/** Function Info   : this function creates a singly linked list.           **/
/** Function Input  : none.                                                 **/
/** Function Return : ListPtr: Pointer to the created list.                 **/
/*****************************************************************************/
List_t *CreateList(void){
	
	List_t *ListPtr = (List_t *)malloc(sizeof(List_t));
	ListPtr -> Size = 0;
	ListPtr -> Head = NULL;
	return ListPtr;
	
}


/*****************************************************************************/
/** Function Name   : ListEmpty()                                           **/
/** Function Info   : this function checks whether the list                 **/
/**                    is empty or not.                                     **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -ReturnValue : Pointer to list state.                 **/
/** Function Return : FunctionState: indicates Execution state of Function. **/
/*****************************************************************************/
ErrorState_t  ListEmpty(List_t *List, List_State_t *ReturnValue){
	
	ErrorState_t FunctionState = RET_OK;
	if(List != NULL){
		
		if(List->Size == 0){
			
			*ReturnValue = LIST_EMPTY;
			
		}else{
			
			*ReturnValue = LIST_NEMPTY;
		}
	}else{
		
		FunctionState = RET_NULL_PTR;
		
	}
	
	return FunctionState;
}


/*****************************************************************************/
/** Function Name   : AddToFront()                                          **/
/** Function Info   : this function adds nodes to the front of the List.    **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -bookname[] : array to add book name to the list.     **/
/**                   -authorname[] : array to add author name to the list. **/
/**                   -price : variable to add book price to the list.      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t AddToFront(List_t *List,u8 bookname[],u8 authorname[], u32 price){
	
	ErrorState_t ReturnState = RET_OK;
	
	if(NULL != List){
		node_t *NodePtr = (node_t *)malloc(sizeof(node_t));
		
		if(NULL != NodePtr){
			
			NodePtr->Price = price;
			
		    for(i=0;((i<MAX)&&(bookname[i]!='0'));i++){
				NodePtr->BookName[i] = bookname[i];
			}
			
			for(i=0;((i<MAX)&&(authorname[i]!='0'));i++){
				NodePtr->AuthorName[i] = authorname[i];
			}
			
			NodePtr -> Next = List -> Head;
			List -> Head = NodePtr;
			List->Size++;
			
		}else{
			
			ReturnState = RET_NULL_PTR;
		}
	}else{
		
		ReturnState = RET_NULL_PTR;
	}
	
	return ReturnState;
}


/*****************************************************************************/
/** Function Name   : RemoveFromFront()                                     **/
/** Function Info   : this function removes nodes from the front of List.   **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -Ret : Pointer to removed value.                      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t RemoveFromFront(List_t *List, s32 *Ret){
	
	ErrorState_t ReturnState = RET_OK;
	List_State_t List_Status = LIST_NEMPTY;
	node_t *Buffer = NULL;
	
	if((List != NULL) && (Ret != NULL)){
		
		ListEmpty(List, &List_Status);
		if(List_Status == LIST_EMPTY){
			
			printf("Sorry ! the library is Empty.... \n");
			
		}else{
			*Ret = List->Head->Price;
			Buffer = List->Head;
			List->Head = Buffer->Next;
			free(Buffer);
			List->Size--;
		}
	}else{
		
		ReturnState = RET_NULL_PTR;
		
	}
	
	return ReturnState;
}


/*****************************************************************************/
/** Function Name   : AddToBack()                                           **/
/** Function Info   : this function adds nodes to the back of the List.     **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -bookname[] : array to add book name to the list.     **/
/**                   -authorname[] : array to add author name to the list. **/
/**                   -price : variable to add book price to the list.      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t AddToBack(List_t *List, u8 bookname[], u8 authorname[], u32 price){
	
	ErrorState_t ReturnState = RET_OK;
	node_t *LoopPtr = NULL;
	if(NULL != List){
		
		node_t *NodePtr = (node_t *)malloc(sizeof(node_t));
		NodePtr->Price = price;
		
		for(i=0;((i<MAX)&&(bookname[i]!='0'));i++){
			NodePtr->BookName[i] = bookname[i];
		}
		
		for(i=0;((i<MAX)&&(authorname[i]!='0'));i++){
			NodePtr->AuthorName[i] = authorname[i];
		}
		
		NodePtr->Next = NULL;
		LoopPtr = List->Head;
		
		if(LoopPtr == NULL){
			
			List->Head = NodePtr;
			
		}else{
			
			while(LoopPtr->Next != NULL)
			{
				LoopPtr = LoopPtr->Next;
			}
			LoopPtr->Next = NodePtr;
		}
		
		List->Size++;
		
	}else{
		
		ReturnState = RET_NULL_PTR;
		
	}
	
	return ReturnState;
}


/*****************************************************************************/
/** Function Name   : RemoveFromBack()                                      **/
/** Function Info   : this function removes nodes from the back of the List.**/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -Ret : Pointer to removed value.                      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t RemoveFromBack(List_t *List, s32 *Ret){
	
	ErrorState_t ReturnState = RET_OK;
	List_State_t List_State = LIST_NEMPTY;
	node_t *Ptr = NULL;
	
	if((List != NULL) && (Ret != NULL)){
		
		ListEmpty(List, &List_State);
		if(List_State == LIST_EMPTY){
			
			printf("Sorry ,the library is Empty ...\n");
		}
		else{
			if(List -> Size == 1){
				
				*Ret = List->Head->Price;
				free(List->Head);
				List->Head = NULL;
				List->Size--;
			}else{
				
				Ptr = List->Head;
				while(Ptr->Next->Next != NULL){
					
					Ptr = Ptr->Next;
				}
				
				*Ret = Ptr->Next->Price;
				free(Ptr->Next);
				Ptr->Next = NULL;
				List->Size--;
			}
		}
	}
	else{
		
		ReturnState = RET_NULL_PTR;
	}
	
	return ReturnState;
}


/*****************************************************************************/
/** Function Name   : RemoveMiddleNode()                                    **/
/** Function Info   : this function removes nodes from the middle of List.  **/
/** Function Input  : -nodeposition : variable that contains node position. **/
/**                   -List : Pointer to list.                              **/
/** Function Return : none.                                                 **/
/*****************************************************************************/
void RemoveMiddleNode(u32 nodeposition,List_t *List){

    node_t *Del;
    node_t *prev;

    if(List -> Head == NULL){
		
        printf("sorry Library is empty...");
		
    }else{
		
        Del = List -> Head;
        prev = List -> Head;

        for(i=2; i<=nodeposition; i++){
			
            prev = Del;
            Del = Del->Next;

            if(Del == NULL){
                break;
			}	
        }

        if(Del != NULL){
			
            if(Del == List -> Head){
				
                List -> Head = List -> Head->Next;
			}
			
            prev->Next = Del->Next;
            Del->Next = NULL;

           
            free(Del);
			List->Size --;

            printf("!! The Book has been deleted succefully !!\n");
			
        }else{
			
            printf("Invaled book number \n");
			
        }
    }
}


/*****************************************************************************/
/** Function Name   : Display()                                             **/
/** Function Info   : this function display the List.                       **/
/** Function Input  : -List : Pointer to list.                              **/
/** Function Return : FunctionState: indicates Execution state of Function. **/
/*****************************************************************************/
ErrorState_t Display(List_t *List){
	
	ErrorState_t FunctionState = RET_OK;
	List_State_t ListState = LIST_EMPTY;
	
	if(NULL == List){
		
		FunctionState = RET_NULL_PTR;
		
	} else{
		u8 n=1;
		node_t *NodePTR = List -> Head;
		
		ListEmpty(List,&ListState);
		if(ListState == LIST_EMPTY){
			
			printf("Library Is Empty...\n");
			
		}else{
			
			while( NodePTR != NULL){
				
				printf("Book Name is %s\n", NodePTR -> BookName);
				printf("Author Name is %s\n", NodePTR -> AuthorName);
				printf("Book Price is %d\n", NodePTR -> Price);
				printf("----------------------------------------------\n");
				NodePTR = NodePTR -> Next;
				
			}
		}
	}
	
	return FunctionState;
}