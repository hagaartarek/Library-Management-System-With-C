#ifndef LIB_H
#define LIB_H

/*****************************************************************************/
/***************************** Linking Section *******************************/
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"


/*****************************************************************************/
/************************* Macro Definition Section **************************/
/*****************************************************************************/
#define MAX 30


/*****************************************************************************/
/*************************** Structure for Book ******************************/
/*****************************************************************************/
typedef struct Node{
	u8 BookName[MAX];
	u8 AuthorName[MAX];
	u32 Price;
	struct Node *Next;
}node_t;

/*****************************************************************************/
/************************* Structure for Books list **************************/
/*****************************************************************************/
typedef struct List{
	u32 Size;
	node_t *Head;
}List_t;


/*****************************************************************************/
/************************ Enumeration for List State *************************/
/*****************************************************************************/
typedef enum{
	LIST_EMPTY,
	LIST_NEMPTY
}List_State_t;


/*****************************************************************************/
/*************************** Functions Declaration ***************************/
/*****************************************************************************/


/*****************************************************************************/
/** Function Name   : CreateList()                                          **/
/** Function Info   : this function creates a singly linked list.           **/
/** Function Input  : none.                                                 **/
/** Function Return : ListPtr: Pointer to the created list.                 **/
/*****************************************************************************/
List_t *CreateList(void);

/*****************************************************************************/
/** Function Name   : ListEmpty()                                           **/
/** Function Info   : this function checks whether the list                 **/
/**                    is empty or not.                                     **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -ReturnValue : Pointer to list state.                 **/
/** Function Return : FunctionState: indicates Execution state of Function. **/
/*****************************************************************************/
ErrorState_t  ListEmpty(List_t *List, List_State_t *ReturnValue);

/*****************************************************************************/
/** Function Name   : AddToFront()                                          **/
/** Function Info   : this function adds nodes to the front of the List.    **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -bookname[] : array to add book name to the list.     **/
/**                   -authorname[] : array to add author name to the list. **/
/**                   -price : variable to add book price to the list.      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t AddToFront(List_t *List, u8 bookname[],u8 authorname[], u32 price);

/*****************************************************************************/
/** Function Name   : RemoveFromFront()                                     **/
/** Function Info   : this function removes nodes from the front of List.   **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -Ret : Pointer to removed value.                      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t RemoveFromFront(List_t *List, s32 *Ret_Data);

/*****************************************************************************/
/** Function Name   : AddToBack()                                           **/
/** Function Info   : this function adds nodes to the back of the List.     **/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -bookname[] : array to add book name to the list.     **/
/**                   -authorname[] : array to add author name to the list. **/
/**                   -price : variable to add book price to the list.      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t AddToBack(List_t *List, u8 bookname[], u8 authorname[], u32 price);

/*****************************************************************************/
/** Function Name   : RemoveFromBack()                                      **/
/** Function Info   : this function removes nodes from the back of the List.**/
/** Function Input  : -List : Pointer to list.                              **/
/**                   -Ret : Pointer to removed value.                      **/
/** Function Return : ReturnState: indicates Execution state of Function.   **/
/*****************************************************************************/
ErrorState_t RemoveFromBack(List_t *List, s32 *Ret_Val);

/*****************************************************************************/
/** Function Name   : RemoveMiddleNode()                                    **/
/** Function Info   : this function removes nodes from the middle of List.  **/
/** Function Input  : -nodeposition : variable that contains node position. **/
/**                   -List : Pointer to list.                              **/
/** Function Return : none.                                                 **/
/*****************************************************************************/
void RemoveMiddleNode(u32 nodeposition,List_t *List);

/*****************************************************************************/
/** Function Name   : Display()                                             **/
/** Function Info   : this function display the List.                       **/
/** Function Input  : -List : Pointer to list.                              **/
/** Function Return : FunctionState: indicates Execution state of Function. **/
/*****************************************************************************/
ErrorState_t Display(List_t *List);




#endif