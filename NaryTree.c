#include "NaryTree.h"

int forwarder;

void init_nodes(node *n[], int num_nodes) {
	int i;
	int j = 1;
	for (i = 0; i < num_nodes; i++) {
		// itera en la direccion del array
		n[i] = new_node(j++);
	};
}

node *new_node(int id) {
	node *new_node = malloc(sizeof(node));

	if (new_node) {
		new_node->sibling = NULL;
		new_node->child = NULL;
		new_node->id = id;
	}

	return new_node;
}

node *add_sibling(node *n, node *new_n) {
	if (n == NULL)
		return NULL;

	while (n->sibling) {
		// Recorre la lista de hermanos
		if (new_n->id == n->sibling->id) {
			// Si encuentra el id del nuevo nodo en el siguiente hermano
			// se valida si el siguiente nodo tiene hermanos
			// if(n->sibling->sibling != NULL) {
			//}
			printf("SE REEMPLAZA NODO EXISTENTE");
			new_n->sibling = n->sibling->sibling; // Se agrega el hermano actual al nuevo nodo
			return (n->sibling = new_n);		  // Reemplaza el nodo existente por el nuevo
		}
		n = n->sibling;
	}
	return (n->sibling = new_n); // new_node()
}

node *add_child(node *n, node *new_n) {
	if (n == NULL)
		return NULL;

	if (n->child) {
		// Si hay un hijo
		// if(n->id == 1) { // si es raiz entonces
		//	return add_sibling(n->child, new_n); //n->child
		// } else {
		return add_sibling(n, new_n); // n->child
		//}
	} else {
		return (n->child = new_n); // new_node()
	}
}

void print_node_decendents(node *n, int level) {
	/*
	if (n->sibling != NULL) { // Recorre la lista de hermanos
		printf("Sibling: %d\n",n->sibling->id); //Node: %d\n   ,n->child->id
		print_node_decendents(n->sibling);
	}

	if(n->child != NULL) { // Recorre la lista de hijos
		printf("Children: %d\n",n->child->id); //Node: %d\n   ,n->child->id
		print_node_decendents(n->child);
	}
	*/
	while (n != NULL) {
		print_tabs(level);
		printf("Node: %d\n", n->id);
		if (n->child != NULL) {
			// Si tiene hijos
			print_tabs(level);
			printf("Children:\n"); // Node: %d\n   ,n->child->id
			print_node_decendents(n->child, level + 1);
		}
		n = n->sibling;
	}
}

/*
int search_forwarder(node *n, int id_dest) {
	while (n != NULL) {
		while(n != NULL){
			n = n->child;
			printf("ESTOY EN EL NODO: %d",n->id);
			forwarder= search_forwarder(n, id_dest);
			if(forwarder != 0){
				return n->id;
			}
		}
		n = n->sibling;
	}
}
*/


int search_forwarder(node *n, int id_dest) {
	while (n != NULL) {
		//printf("Node: %d\n", n->id);

		if ( (n->child != NULL && n->child->id == id_dest) || (n->sibling != NULL && n->sibling->id == id_dest)) { // si el hermano o el hijo del nodo actual es el destino entonces retorne el id actual
			// SI encontramos el nodo entonces
			//printf("Forwarder: %d\n", n->id);
			forwarder = n->id;
			break;
		}

		if (n->child != NULL) {
			// Si tiene hijos
			//printf("Children:\n"); // Node: %d\n   ,n->child->id
			//forwarder = n;
			search_forwarder(n->child, id_dest);
		}
		//printf("Node ORIGINAL: %d\n", n->id);

		//printf("Forwarder: %d\n", forwarder);
		if (n->child != NULL && n->sibling != NULL && forwarder!=0 ) {
			search_forwarder(n, forwarder);
			break;
		}

		n = n->sibling;
	}
	//printf("Node FUERA DEL WHILE: %d\n", n->id);
	return forwarder;
}


void print_tabs(int count) {
	int i;
	for (i = 0; i < count; i++) {
		putchar('\t');
	}
}
