#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node * delete(Node *root, int value){
  int i = 0;
  Node *iterator = root;
  while(iterator != 0){
    if(iterator->val == value){
      if(iterator->prev ==0){
        //means its the root
        root = iterator->next;
      }else if(iterator->next == 0){
        //means its the tail
        iterator->prev->next = 0;
      }else{
        iterator->prev->next = iterator->next;
        iterator->next->prev = iterator->prev;
      }
      free(iterator);
      return root;
    }else{
      iterator = iterator->next;
    }
  }
  return 0;
}
Node *insert(Node *root, int value){
  //just insert at the head
  Node *new_root = malloc(sizeof(Node));

  if(root != 0){
    root->prev = new_root;
    new_root->next = root;
  }
  new_root->prev = 0;
  new_root->val = value;

  return new_root;

}
Node *find(Node *root,int value){
  while(root != 0){
    if(root->val == value){
      return root;
    }
    root = root->next;
  }
  return 0;
}
