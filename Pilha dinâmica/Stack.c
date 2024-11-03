#include "Stack.h"

int main() {
	int option;
	Node *ptr;
	start_Stack( &ptr );
	
	do {
		printf( "0-Exit\n1-Pop\n2-Push\n3-Print\n" );
		scanf( "%d", &option );
		
		switch( option ) {
			case 1:
			{
				Pop( &ptr );
				break;
			}
			case 2:
			{
				Push( &ptr );
				break;
			}
			case 3:
			{
				Print( ptr );
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
	
	return 0;
}
