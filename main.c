// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "m.h"

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int id; // char entered by user
   char name[50];

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice ); //%u=unsigned int

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter id and name: " );
            scanf( "%d %s", &id, name );
            insert( &startPtr, id, name ); // insert item in list
            printList( startPtr );
            printListR( startPtr );
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &id );
               // if character is found, remove it
               if ( deletes( &startPtr, id ) ) { // remove item
                  printf( "%d deleted.\n", id );
                  printList( startPtr );
                  printListR( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", id );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else
            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch
      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while
  /* Clear all nodes at the end of nodes*/
   alldelete( &startPtr );
   puts( "End of run." );
} // end main
