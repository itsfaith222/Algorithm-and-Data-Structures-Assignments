/************************************************************************************* 
* This file defines the List data structure as implemented by a doubly-linked list 
* A List stores a list of <int>
*
* Modified by: Mahimaa Vardini BR, Faith Aikhionbare, Samarpita Sharma  
* Date: Thursday February 13th, 2025
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

	//insert data into the node
	np->data = new_data;
	np->prev = NULL; //prev of data is null because this is going to be the new head node.

	if(isEmpty(S)){ //check if list is empty
		np->next = NULL; //node pointer next is null
		S->head = np; // head points to new node
		S->tail = np; //tail points to new node
	}else{
		//new node next connects to head
		np->next = S->head;

		//old head prev points to the new node
		S->head->prev = np;

		//update the new node to be the head
		S->head = np;

	}

	//increses the size of the list 
	S->size ++;
}
		 
 
// This function searches the list for new_data, and returns the address of the node 
// containing new_data if found, and NULL otherwise 
NodePtr search(List S, ListData new_data) {
     //ADD YOUR CODE HERE TO COMPLETE THIS FUNCTION:

	 NodePtr current_node = S->head; //make a pointer that points to the head

	 if(!isEmpty(S)){//check if list is empty 
		//uses the pointer created to point to each node in the list
		while(current_node != NULL){
			if(new_data == current_node->data){ 
				return current_node; //return node address if currentNode is same as data we are looking for.
			}
			current_node = current_node->next; //points to the next node.
		}
	 }

	return NULL;
}


// This function removes the node from the list S 
void removeFromList(List S, NodePtr np) {
	//ADD YOUR CODE HERE TO COMPLETE THIS FUNCTION
	//Remember to check first if list is empty; don't forget to free memory 
	//and decrement size if necessary.

	//if list is empty we return
	if(isEmpty(S)){
		printf("Error: List is empty.");
		return;
	}
	//if node address is null return
	if(np == NULL){
		printf("Node is null");
		return;
	}

	//if node is the head remove else if node is tail remove else node is in the middle and we remove
	if (np = S->head){
		S->head = np->next;
		np->next->prev = NULL;
	}else if(np = S->tail){
		S->tail = np->prev;
		np->prev->next = NULL;
	}else{
		//rearranges the pointer to disconnect the node from the list.
		np->prev->next = np->next->prev;
		np->next->prev = np->prev->next;
	}

	free(np);

	S->size --;


}