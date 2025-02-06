/************************************************************************************* 
* This file defines the List data structure as implemented by a doubly-linked list 
* A List stores a list of <int>
*
* Modified by: 
* Date:
*************************************************************************************/

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

typedef int ListData;

typedef struct node {
	   ListData data;
	   struct node* next;
	   struct node* prev;
	} Node, *NodePtr;
	
typedef struct {
	NodePtr head, tail;
	int size;
} ListType, *List;	

bool isEmpty(List S) {
	return (S->head==NULL);
}

// Initializes a list, returning the address of the empty List
List initList(void) {
	List s;
	s = (List) malloc (sizeof(ListType));
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
	return s;
}

// This function returns the number of elements stored in the List
int getSize(List S) {
	return S->size;
}

// This function prints the contents of linked list starting from the head of the list.
// You may use this function to verify that your algorithm executes as expected.
void displayList(List S) {
	if (isEmpty(S)) {
		printf("The list is empty\n");
	}
	else {
		NodePtr current_node = S->head;
  
   		while (current_node != S->tail) {
	  		printf("%d<==>",current_node->data);
	  		current_node = current_node->next;
		}

    	printf("%d==>",current_node->data);
		printf("END\n");	
	}
	
}

// This function iteratively deallocates memory assigned to the list S
void freeList(List S) {
	NodePtr current_node = S->head;
  
   while (current_node != NULL) {
	 
	  S->head = current_node->next;
	  free(current_node);
	  S->size--;
	  current_node = S->head;
	}
	free(S);
}


/***************  DO NOT CHANGE ANYTHING ABOVE THIS LINE ****************/

/***** The following functions need to be completed *****/

// This function inserts a new node containing new_data at the front 
// of the list S and increments the size of the list
void insertAtFront(List S, ListData new_data) {
  	//ADD YOUR CODE HERE TO COMPLETE THIS FUNCTION:
   	//Allocating memory for the new node
	NodePtr np = (NodePtr) malloc (sizeof(Node));

}
		 
 
// This function searches the list for new_data, and returns the address of the node 
// containing new_data if found, and NULL otherwise 
NodePtr search(List S, ListData new_data) {
     //ADD YOUR CODE HERE TO COMPLETE THIS FUNCTION:

	return NULL;
}


// This function removes the node from the list S 
void removeFromList(List S, NodePtr np) {
	//ADD YOUR CODE HERE TO COMPLETE THIS FUNCTION
	//Remember to check first if list is empty; don't forget to free memory 
	//and decrement size if necessary.
	
} 		 