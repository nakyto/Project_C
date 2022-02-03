/**
 * @file test-ABR.c
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */


#include <stdlib.h>
#include <stdio.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "./listePrio.h"
#include "./listePrio.c"

int main(void) {
  
	ListePrio* lp = create_ListePrio("bb",NULL);
	ListePrio* lp2 = create_ListePrio("aa",lp);
	insert_end(lp2,"cc");
	lp2 = insert_prio(lp2,"oo",8);
	lp2 = insert_prio(lp2,"gg",4);
	lp2 = insert_prio(lp2,"dd",1);

	afficher_ListePrio(lp2);
	delete_ListePrio(lp2);
	
  	return EXIT_SUCCESS;
}
