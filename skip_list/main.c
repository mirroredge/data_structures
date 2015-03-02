#include <stdio.h>
#include <stdlib.h>
#include "skip_list.h"

int main(){

  //Seed the random num
  //FIXME just being lazy and not using a proper lib
  srand(time(NULL));

  SkipList *sl = init();

  Node *n1 = malloc(sizeof(Node));
  Node *n2 = malloc(sizeof(Node));
  Node *n3 = malloc(sizeof(Node));
  Node *n22 = malloc(sizeof(Node));
  Node *ne1 = malloc(sizeof(Node));
  Node *nb1 = malloc(sizeof(Node));



  n1->key = 1;
  n1->value = 1;
  n1->up = NULL;
  n1->down = NULL;
  n1->left = sl->head;
  n1->right = n2;
  n1->type = BODY;

  n2->key = 2;
  n2->value = 2;
  n2->up = n22;
  n2->down = NULL;
  n2->left = n1;
  n2->right = n3;
  n2->type = BODY;

  n3->key = 3;
  n3->value = 3;
  n3->up = NULL;
  n3->down = NULL;
  n3->left = n2;
  n3->right = sl->tail;
  n3->type = BODY;

  n22->key = 2;
  n22->value = 2;
  n22->up = NULL;
  n22->down = n2;
  n22->left = nb1;
  n22->right = ne1;
  n22->type = HEAD;

  ne1->key = 0;
  ne1->value = 0;
  ne1->up = NULL;
  ne1->down = sl->tail;
  ne1->left = n22;
  ne1->right = NULL;
  ne1->type = TAIL;

  nb1->key = 0;
  nb1->value = 0;
  nb1->up = NULL;
  nb1->down = sl->head;
  nb1->left = NULL;
  nb1->right = n22;
  nb1->type = HEAD;

  sl->head->right = n1;
  sl->tail->left = n3;

  printf("HERE\n");
  fflush(stdout);

  sl->head = nb1;
  sl->tail = ne1;

  Node *k = find_node_pos(sl, 3);
  printf("Finding 2 %i", k->key);
}
