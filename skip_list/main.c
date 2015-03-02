#include <stdio.h>
#include <stdlib.h>
#include "skip_list.h"

void print_skip_list(SkipList *sl){
	//bottom head
	Node * bottom = sl->head;

	while(bottom != NULL){
	Node* ll = bottom;
	//loop through this list twice
	//First print out left and right pointers
	while(ll != NULL){
	  if(ll-> left != NULL){
		  printf(" <--> ");
	  }
	  printf("%i", ll->key);
	  ll = ll->right;
	}
	printf("\n");
	bottom = bottom->down;
	}
	printf("\n\n");
}


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


	init_node(n1, 1,1,NULL,NULL, sl->head, n2, BODY);
	init_node(n2, 3,3,n22,NULL, n1, n3, BODY);
	init_node(n3, 5,5,NULL,NULL, n2, sl->tail, BODY);
	init_node(n22, 3,3,NULL,n2, nb1, ne1, BODY);
	init_node(ne1, 0,0,NULL,sl->tail, n22, NULL, TAIL);
	init_node(nb1, 0,0,NULL, sl->head,NULL, n22, HEAD);

	sl->head->up = nb1;
	sl->tail->up = ne1;
	sl->head->right = n1;
	sl->tail->left = n3;

	sl->head = nb1;
	sl->tail = ne1;

	sl->size = 3;
	sl->levels=2;

	Node *k = find_node_pos(sl, 9);
	printf("Finding 2 %i\n", k->key);

	print_skip_list(sl);


	SkipList *sl1 = init();

	insert(sl1, 1,1);
	insert(sl1,3,3);
	insert(sl1,5,5);
	insert(sl1,7,7);
	insert(sl1,9,9);
	insert(sl1,11,11);
	insert(sl1,13,13);
	insert(sl1,2,2);
	insert(sl1,4,4);
	insert(sl1,8,8);
	insert(sl1,10,10);

	print_skip_list(sl1);

	k = find_node_pos(sl1, 9);
    printf("Found node 9 with a value of %i\n", k->value);

    insert(sl1,9,100);
    printf("Found node 9 with a value of %i\n", k->value);

	fflush(stdout);

	printf("The size is %i\n", sl1->size);
	printf("The height is %i\n", sl1->levels);

	printf("Goodbye");



}
