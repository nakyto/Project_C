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

#include "../../../c-test-master/src/Sylphon/Sylphon.h"
#include "../../../c-test-master/src/Phonetisation/phonetisation.h"
#include "../../../c-test-master/src/Phonetisation/phonetisation.c"

int main(void) {
	
	char* s = "sal-ut";
	char* p = "SA-LU";
	int n = compteurTiret(s);
	
	ListePrio* lp = create_ListePrio("cou",NULL);
	insert_end(lp,"coo");
  Sylphon* sy = init_Sylphon(sy);
  sy->syllabe = "coucou";
  sy->phonetisation = lp;
	ABR* abr= create_leaf(sy);
	int ns = compteurTiret(s);
	int np = compteurTiret(p);
	//printf("%d %d\n",ns,np);
	if(ns == np){
		abr = CutWord(s,p,abr);
	}
	
	afficher(abr);
	
	delete_ABR(abr);

  	return EXIT_SUCCESS;
}
