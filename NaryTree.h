#ifndef NARYTREE_H
#define NARYTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node {
	int id;
	//struct node *parent;
	struct node *sibling;
	struct node *child;
};


void init_nodes(node *n[] , int num_nodes);
node * new_node(int id);
node * add_sibling(node * n, node * new_n) ;
node * add_child(node * n, node * new_n) ;
void print_node_decendents(node * n , int level);
void print_tabs(int count);

int search_forwarder(node * n , int id); //int


#endif
