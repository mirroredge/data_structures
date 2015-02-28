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

  printf("\nFinding 50\n");
  Node *found = find(root, 50);
  printf("50's next = %i\n", found->next->val);
  printf("50's prev = %i\n", found->prev->val);

  printf("\nGoodbye\n");

}
