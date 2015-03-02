#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "skip_list.h"


void init_node(Node *to_set, int key, int value, Node* up, Node *down, Node *left, Node *right, node_type_t type){
	to_set->key = key;
	to_set->value = value;
	to_set->up = up;
	to_set->down = down;
	to_set->left = left;
	to_set->right= right;
	to_set->type= type;
}

SkipList *init(){
	SkipList *sl = malloc(sizeof(SkipList));
	sl->head = malloc(sizeof(Node));
	sl->tail = malloc(sizeof(Node));

	init_node(sl->head, 0,0, NULL, NULL, NULL, sl->tail, HEAD);
	init_node(sl->tail,0,0,NULL,NULL,sl->head,NULL, TAIL);
	sl->size = 0;
	sl->levels = 0;
	return sl;
}


int level_gen(int level){
	//This needs to have a binomial distribution to have
	//log n search
	int levels = -1;
	int random = 0;
	do{
		levels++;
		random = rand() % 3;
		//cheat to make it taller
		//if(random > 1){
		//	random = 2;
		//}
	}while(random && levels <= level);
	return levels;
}

int insert(SkipList *sl,int key, int value){
	//First find the node to insert it at
	Node *found = find_node_pos(sl, key);
	if(found->key == key && found->type == BODY){
		//it exists just update
		found->value = value;
		return key;
	}
	//Figure out what level we should make it up to
	int height = level_gen(sl->levels+1);
	int i = 0;
	sl->size++;
	//Create the nodes of the found height height
	Node *new_nodes[height+1];
	//Create all the nodes
	for(i=0;i<=height; i++){
		new_nodes[i] = malloc(sizeof(Node));
	}
	for(i=0; i<=height; i++){
		if(i==0 && height > 0){
			//at bottom don't add down
			new_nodes[i]->up = new_nodes[i+1];
		}else if(i == height && height > 0){
			//at top don't add up
			new_nodes[i]->down = new_nodes[i-1];
		}else if(height != 0){
			//add up and down
			new_nodes[i]->up = new_nodes[i+1];
			new_nodes[i]->down = new_nodes[i-1];
		}
		//We are out so now add the key and value
		new_nodes[i]->key = key;
		new_nodes[i]->value = value;
		new_nodes[i]->type = BODY;
	}

	//if its the tallest (levels+1) create a new head tail and increment the levels var
	if(height == sl->levels+1){
		Node *new_head = malloc(sizeof(Node));
		Node *new_tail = malloc(sizeof(Node));

		init_node(new_head, 0,0,NULL,sl->head, NULL, new_tail, HEAD);
		init_node(new_tail, 0,0,NULL,sl->tail, new_head, NULL, TAIL);

		sl->head->up = new_head;
		sl->tail->up = new_tail;
		sl->head = new_head;
		sl->tail = new_tail;

		sl->levels++;
	}

	//for each level insert it like a linked list.
	Node* node_at_level = sl->head;
	while(node_at_level->down != NULL){
		node_at_level = node_at_level->down;
	}
	for(i=0; node_at_level != NULL && i<=height; i++){
		int inserted = 0;
		Node *ll_head = node_at_level->right;
		while(!inserted){
			if(ll_head->type == TAIL || new_nodes[i]->key < ll_head->key){
				//the current is larger so we add the new node now
				new_nodes[i]->left = ll_head->left;
				new_nodes[i]->right = ll_head;
				ll_head->left->right = new_nodes[i];
				ll_head->left = new_nodes[i];
				inserted = 1;
			}else if(new_nodes[i]->key > ll_head->key){
				//its less than go to next
				ll_head = ll_head->right;
			}
		}
		node_at_level = node_at_level->up;
	}
	return key;
}


Node *find_node_pos(SkipList *sl, int key){
	Node *it = sl->head->right;
	if(it->type == TAIL){
		return it->left;
	}
	while(1){
		fflush(stdout);
		if(it->type == TAIL){
			if(it->down == NULL){
				return it->left;
			}else{
				//printf("\tdown");
				it = it->left->down;
			}
		}else if(it->key < key){
			//printf("\tright");
			it = it->right;
		}else if(it->key > key){
			if(it->down != NULL){
				//printf("\tdown");
				it = it->down;
			}else{
				//We reached the bottom of the list uhoh
				return it->left;
			}
		}else if(it->key == key){
			return it;
		}else{
			return NULL;
		}
	}
}


