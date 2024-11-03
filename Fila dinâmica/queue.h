#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
	int info;
	struct sNode *next;
}Node;

typedef struct sQueue {
	Node *begin;
	Node *end;
}Queue;

void start_Queue( Queue **ptr ) {
	*ptr = ( Queue* ) malloc( sizeof( Queue ) );
	if( ptr != NULL ) {
		( *ptr )->begin = NULL;
		( *ptr )->end = NULL;
		printf( "\n---Successfully to initialized queue!---\n" );
	} else {
		printf( "\n---Error to allocate node!---\n" );
		exit( 1 );
	}
}

int empty_Queue( Queue *ptr ) {
	if( ( ptr )->begin == NULL && ( ptr )->end == NULL ) {
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
	} else {
		printf( "\n---Error to allocate memory!---\n" );
		return NULL;
	} 
}

void deallocate_Node( Node *ptr ) {
	free( ptr );
	printf( "\n---Successfully to deallocate node!---\n" );
}


int return_Integer() {
	int number;
	printf( "\n---Enter an integer:---\n" );
	scanf( "%d", &number );
	return number;
}

void print_Integer( int number ) {
	printf( "%d ", number );
}

void to_Queue( Queue **ptr ) {
	Node *New = allocate_Node();
	New->info = return_Integer();
	if( empty_Queue( *ptr ) ) {
		( *ptr )->begin = New;
		( *ptr )->end = New;
	} else {
		( *ptr )->end->next = New;
		( *ptr )->end = New;
	}
	printf( "\n---Successfully to queue!---\n" );
}
void unqueue( Queue **ptr ) {
	if( empty_Queue( *ptr ) ) {
		printf( "\n---Empty queue!---\n" );
	} else {
		Node *aux = ( *ptr )->begin;
		if( ( *ptr )->begin->next == NULL ) {
			deallocate_Node( aux );
			( *ptr )->begin = NULL;
			( *ptr )->end = NULL;
		} else {
			( *ptr )->begin = aux->next;
			deallocate_Node( aux );
		}
	}
}

void print_Queue( Queue *ptr ) {
	if( empty_Queue( ptr ) ) {
		printf( "\n---Empty queue!---\n" );
	} else {
		Node *aux = ( ptr )->begin;
		printf( "\n---Begin of queue---\n" );
		while( aux != NULL ) {
			print_Integer( aux->info );
			aux = aux->next;
		}
		printf( "\n---End of queue---\n" );
	}
}

#endif
