/*
 *  File: Lab7_Sec2.c
 *  Description:  Understand how linked lists are implemented in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Element or Node of a linked list
typedef struct Node {

  double value;
  node *ptr_next_node;

} node;

node *create_node(double value);

//##############################################################################################################################

int main(){
  srand(time(NULL));

  //head of list
  node *head = NULL;

  //pointer to current element
  node *current = NULL;

  //create 50 nodes with random values and append them to the list
  for(int i=0; i<50; i++){
    node *new_node = create_node(rand());

    if(new_node == NULL){
      printf("Error: Creation of new node failed\n");
      return 1;
    }

    if(head == NULL){
      head = new_node;
      current = head;
    }
    else{
      current->ptr_next_node = new_node;
      current = new_node;
    }
  }
  
  //create array with 51 elements
  int arr[51];
  for(int i=0; i<50; i++){
    arr[i] = rand();
  }
  
  //create additional random number
  int random = rand();

  //insert additional random number in array at index 3
  arr[3] = random;

  //create new node for insertion at position 3 of the list
  node *new_node = create_node(random);
  node *temp = head;

  //insert the new node into the linked list as 3rd node
  for(int i=0; i<2; i++){
    temp = temp->ptr_next_node;
  }

  //whatthehelly
  new_node->ptr_next_node = temp->ptr_next_node;
  temp->ptr_next_node = new_node;

  // Print array
    printf("Array:\n");
    for (int i = 0; i < 51; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print linked list
    printf("Linked List:\n");
    node *iter = head;
    while (iter != NULL)
    {
        printf("%.0f ", iter->value);
        iter = iter->ptr_next_node;
    }
    printf("\n");

    // Free linked list memory
    node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->ptr_next_node;
        free(tmp);
    }

  return 0;
}

//##############################################################################################################################

//Function to create new node
node *create_node(double value){

  //reserve memory for node
  node *new_node = malloc(sizeof(*new_node));
  if(new_node == NULL){
    printf("Error: Memory allocation failed\n");
    return NULL;
  }

  //fill node-parameters: value to given value and pointer to next node to NULL
  new_node->value = value;
  new_node->ptr_next_node = NULL;

  return new_node;
}