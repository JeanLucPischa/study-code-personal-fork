/*
 *  File: Lab7_Sec2.c
 *  Description:  
 */

#include <stdio.h>

typedef struct node {
  double value;
  Node *ptr_next;
} Node;

typedef struct list {
  Node *head;
} List;

Node *create_node(double value);

int main(){

  List list1 = {NULL};
  List *ptr_list1 = &list1;
  Node *temp_ptr = NULL;

  for(int i=50; i>0; i--){
    if(ptr_list1->head == NULL){
      
    }
    else{
      create_node(i)->ptr_next = temp_ptr;
    }
  }


  return 0;
}

Node *create_node(double value){
  Node this_node;
  Node *ptr_this_node = &this_node;
  ptr_this_node->value = value;
  ptr_this_node->ptr_next = NULL;

  return ptr_this_node;
}