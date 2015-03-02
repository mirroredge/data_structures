#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "skip_list.h"


SkipList *init(){
  SkipList *sl = malloc(sizeof(SkipList));
  sl->head = malloc(sizeof(Node));
  sl->tail = malloc(sizeof(Node));

  sl->head->key = 0;
  sl->head->value = 0;
  sl->head->up = NULL;
  sl->head->down = NULL;
  sl->head->left = NULL;
  sl->head->right = sl->tail;
  sl->head->type = HEAD;


  sl->tail-> key = 0;
  sl->tail-> value = 0;
  sl->tail->up = NULL;
  sl->tail->down = NULL;
  sl->tail->left = sl->head;
  sl->tail->right = NULL;
  sl->tail->type = TAIL;

  sl->size = 0;
  sl->levels = 0;
  return sl;
}

int insert(SkipList *sl,int key, int value){
  //so here is the trickery
  Node *prev = find_node_pos(sl, key);
  //First we gotta find position to insert
  return -1;
}


Node *find_node_pos(SkipList *sl, int key){
  Node *it = sl->head->right;

  while(1){
    //printf("at node %i\n", it->key);
    //fflush(stdout);
    if(it->key < key){
      //printf("< key\n");
      //fflush(stdout);
      //Cant just go right, if right is the tail I need
      //to go down and right
      if(it->right->type == TAIL){
    	  if(it->down == NULL){
    		  return it->left;
    	  }else{
    		  it = it->down;
    	  }
      }
      it = it->right;
    }else if(it->key > key){
      //printf("> key\n");
      //fflush(stdout);
      if(it->down != NULL){
        //printf("going down\n");
        //fflush(stdout);
        it = it->down;
      }else{
        //We reached the bottom of the list uhoh
        //printf("NOT FOUND\n");
        //fflush(stdout);
        return it->left;
      }
    }else if(it->key == key){
      //printf("FOUND\n");
      //fflush(stdout);
      return it;
    }else{
      return NULL;
    }
  }
}


int level_gen(int level){
  return rand() % level;
}
