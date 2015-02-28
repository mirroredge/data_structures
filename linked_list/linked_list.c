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

Node* insert_at(Node *root, int val, int pos){

  int list_size = size(root);
  if(pos >= list_size){
    printf("Cannot insert at pos %i size is %i", pos, list_size);
    return 0;
  }

  int i = 0;
  //get to position, using 0 indexing
  for(i=0; i < pos; i++){
    //printf("At pos %i", i);
    //printf("root's next is %i", root->next);
    root = root->next;
  }

  //root is the correct position
  Node *new_node = malloc(sizeof(Node));
  new_node->val = val;

  //now for the pointer magic
  Node * previous = root->prev;
  //Insert at is before the position found.
  //Therefore if you insert at 5, then that index will be
  //5
  Node * next = root;

  //Case if tail
  if(next != 0){
    new_node->next = next;
    next->prev = new_node;
  }else{
    new_node->next = 0;
  }
  //case if head
  if(previous != 0){
    new_node->prev = previous;
    previous->next = new_node;
  }else{
    new_node->prev = 0;
  }
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

void destroy(Node *root){
  Node *it = 0;
  while(root != 0){
    it = root->next;
    free(root);
    root = it;
  }
}

int size(Node* root){
  int size = 0;
  while(root != 0){
    size++;
    root= root->next;
  }
  return size;
}

int index_of(Node *root, int value){
  int pos = 0;
  while(root != 0){
    if(root->val == value){
      return pos;
    }
    root = root->next;
    pos++;
  }
  return -1;
}
