/**
 * @file test-syllabation.c
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

#include "../../../c-test-master/src/syllabation/syllabation.h"
#include "../../../c-test-master/src/syllabation/syllabation.c"

int main(void) {
	char* fin = malloc(sizeof(char)*38);
	char* mot = malloc(sizeof(char)*38);
	
	strcpy(mot,"france");
	printf("%s : ",mot); 
	mot = cut(mot,4, fin);
	printf("%s%s \n",fin,mot); 
	//assert(strcmp(mot, "fran-ce"));
	
	strcpy(mot,"obstruer");
	fin[0]='\0';
	printf("%s : ",mot); 
	mot = cut(mot,2, fin);
	printf("%s%s \n",fin,mot);
	//assert(strcmp(mot, "ob-struer"));


	free(mot);
	free(fin);

  return EXIT_SUCCESS;
}
