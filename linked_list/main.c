#include <stdio.h>
#include "linked_list.h"

int main(){
  int i = 0;
  Node *root = insert(0,1);
  for(i=2; i< 100; i++){
    //printf("Node %i\n", root->val );
    root = insert(root, i);
  }

  Node *j = root;

  printf("After inserting 0->100\n");
  while(j != 0){
    printf(" %i,", j->val );
    j = j->next;
  }

  printf("\nIts size is %i\n", size(root));


  //Delete all the odd numbers
  for(i=1; i<100; i+=2){
    root = delete(root, i);
  }

  printf("\nAfter deleting all the odd ones\n");
  j = root;
  while(j != 0){
    printf(" %i,", j->val );
    j = j->next;
  }

  printf("\nIts size is %i\n", size(root));

  printf("\nFinding 50\n");
  Node *found = find(root, 50);
  printf("50's next = %i\n", found->next->val);
  printf("50's prev = %i\n", found->prev->val);

  destroy(root);

  root = insert(0, 3);
  root = insert(root,1);
  root = insert_at(root, 2, 1);

  printf("After inserting at\n");
  j = root;
  while(j != 0){
    printf(" %i,", j->val );
    j = j->next;
  }

  printf("\nIndex of 2 is %i\n", index_of(root, 2));
  printf("\nIndex of 500 is %i\n", index_of(root, 500));


  printf("\nGoodbye\n");

}
