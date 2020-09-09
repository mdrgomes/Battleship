#include "stats.h"

/*void insertAtTheBegin(struct Stats **start, int data, Player *name)
{ 
    struct Stats *ptr1 = (struct Stats*)malloc(sizeof(struct Stats)); 
    ptr1->points = data; 
    ptr1->nick = name;
    ptr1->next = *start; 
    *start = ptr1; 
} 

void bubbleSort(struct Stats *start) 
{ 
    int swapped, i; 
    struct Stats *ptr1; 
    struct Stats *lptr = NULL; 
  
     Checking for empty list 
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->points > ptr1->next->points) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  */
/* function to swap data of two nodes a and b*/
/*void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} */


/*Boolean checkGame(int player){
    //ver stats de player mais simples
    if((pointsStats+player)->points==NUM_SHIPS_CELL)
        return TRUE;
    else 
        return FALSE;
}*/