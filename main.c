#include "NaryTree.h"

#define NUM_NODES 25	
node * node_arr[NUM_NODES];
//node_arr[0]
#define ORIGEN node_arr[11]
#define DESTINO 24


int main(int argc, char *argv[]) {
	////////
	init_nodes(node_arr , NUM_NODES);
	////////
	
	/* !!!!!!!!!!!!!!ARBOL PRUEBA
	add_child(node_arr[0], node_arr[1]); //Raiz

		//RAMA NODO 2
	add_sibling(node_arr[1], node_arr[2]);
	add_sibling(node_arr[1], node_arr[3]);

	add_child(node_arr[1], node_arr[4]);
	add_child(node_arr[4], node_arr[5]);
	add_sibling(node_arr[4], node_arr[6]);

	//RAMA NODO 3
	add_child(node_arr[2], node_arr[7]);
	add_sibling(node_arr[7], node_arr[8]);
	add_sibling(node_arr[7], node_arr[9]);

	add_child(node_arr[9], node_arr[10]);
	add_sibling(node_arr[10], node_arr[11]);
	add_child(node_arr[11], node_arr[12]);

	add_sibling(node_arr[12], node_arr[13]);
	add_sibling(node_arr[12], node_arr[14]);
	
	//RAMA NODO 4
	add_child(node_arr[3], node_arr[15]);

	add_sibling(node_arr[15], node_arr[16]);
	add_sibling(node_arr[15], node_arr[17]);
	

	add_child(node_arr[15], node_arr[19]);
	add_child(node_arr[19], node_arr[20]);
	add_sibling(node_arr[20], node_arr[21]);


	//RAMA NODO 23
	add_sibling(node_arr[1], node_arr[18]);
	*/
	
	
	add_child(node_arr[0], node_arr[1]); //Raiz
	
	add_sibling(node_arr[1], node_arr[2]);
	add_sibling(node_arr[1], node_arr[3]);
	//RAMA DEL 2
		
	add_child(node_arr[1], node_arr[4]);
	add_sibling(node_arr[4], node_arr[5]);
	add_sibling(node_arr[4], node_arr[6]);
	add_sibling(node_arr[4], node_arr[7]);
	
	add_child(node_arr[6], node_arr[13]);	
	add_sibling(node_arr[13], node_arr[14]);	
	add_sibling(node_arr[13], node_arr[15]);	

	add_child(node_arr[15], node_arr[20]);	
	add_sibling(node_arr[15], node_arr[21]);	

	//RAMA DEL 3
	add_child(node_arr[2], node_arr[8]);	
	add_sibling(node_arr[8], node_arr[9]);	
	add_sibling(node_arr[8], node_arr[10]);	


	add_child(node_arr[10], node_arr[16]);	
	add_sibling(node_arr[16], node_arr[17]);	
	
	add_child(node_arr[16], node_arr[22]);
	
	//RAMA DEL 4
	add_child(node_arr[3], node_arr[11]);
	add_sibling(node_arr[11], node_arr[12]);	

	add_child(node_arr[11], node_arr[18]);	
	add_sibling(node_arr[18], node_arr[19]);
	
	add_child(node_arr[19], node_arr[23]);				
	add_child(node_arr[23], node_arr[24]);				

	
	print_node_decendents(node_arr[0],0); //root

	printf("\r\nDEL NODO %d AL NODO %d, EL NODO FORWARDER ES %d \r\n",ORIGEN->id,DESTINO,search_forwarder(ORIGEN,DESTINO)); //node_arr[0]
}

