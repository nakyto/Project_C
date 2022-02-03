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

#include "./ABR.h"
#include "./ABR.c"

int main(void) {
	ListePrio* lp = create_ListePrio("cou",NULL);
	insert_end(lp,"cou");
  Sylphon* s = init_Sylphon(s);
  s->syllabe = "coucou";
  s->phonetisation = lp;
	ABR* abr = create_leaf(s);
	afficher(abr);
  return EXIT_SUCCESS;
}


