#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
	int info;
	//int access;
	struct sNode *next;
}Node;

void start_Stack( Node **ptr ) {
	ptr = NULL;
	printf( "\n---Successfully initialized stack!---\n" );
}

int empty_Stack( Node *ptr ) {
	if( ptr == NULL ) {
		return 1;
	} else {
		return 0;
	}
}

Node *allocate_Node() {
	Node *New = ( Node * ) malloc( sizeof( Node ) );
	if( New != NULL ) {
		New->info = 0;
		New->next = NULL;
		return New;
	} else {
		printf( "\n---Error to allocate memory!---\n" );
		return NULL;
	}
}

void deallocate_Node( Node *ptr ) {
	free( ptr );
	printf( "\n---Successfully freed memory!---\n" );
}

int return_Integer() {
	int number;
	printf( "\n---Enter an integer---\n" );
	scanf( "%d", &number );
	return number;
}

void print_Integer( int number ) {
	printf( "%d\n", number );
}

void Pop( Node **ptr ) {
	Node *New = allocate_Node();
	New->info = return_Integer();
	New->next = *ptr;
	*ptr = New;
	printf( "\n---Success inserting element into the stack!---\n" );
}

void Push( Node **ptr ) {
	if( empty_Stack( *ptr ) ) {
		printf( "\n---Empty stack!---\n" );
	} else {
		Node *aux = *ptr;
		*ptr = aux->next;
		deallocate_Node( aux );
	}
}

void Print( Node *ptr ) {
	if( empty_Stack( ptr ) ) {
		printf( "\n---Empty stack!---\n" );
	} else {
		Node *aux = ptr;
		printf( "\n---Begin of stack---\n" );
		while( aux != NULL ) {
			print_Integer( aux->info );
			aux = aux->next;
		}
		printf( "\n---End of stack---\n" );
	}
}

	
	
	
