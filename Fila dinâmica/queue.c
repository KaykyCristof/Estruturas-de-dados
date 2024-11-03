#include "queue.h"

int main() {
	int option = -1;
	Queue *ptr;
	start_Queue( &ptr );
	
	do {
		printf( "\n0-Exit\n1-To queue\n2-Unqueue\n3-Print\n" );
		scanf( "%d", &option );
		
		switch( option ) {
			case 1:
			{
				to_Queue( &ptr );
				break;
			}
			case 2:
			{
				unqueue( &ptr );
				break;
			}
			case 3:
			{
				print_Queue( ptr );
				break;
			}
			default:
			{
				if( option != 0 ) {
					printf( "\n---Error invalid option!---\n" );
				}
			}
		}
		
	} while( option != 0 );
	
	printf( "Exit program...\n" );
	
	return 0;
}
