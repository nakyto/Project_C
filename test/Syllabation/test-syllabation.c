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
  char* mot = malloc(sizeof(char)*30);
	strcpy(mot,"france");
	mot = syllabation(mot);
	printf("%s\n",mot);
  //assert(strcmp(mot,"fran-ce"));
	strcpy(mot,"obstruer");
	mot = syllabation(mot);
	printf("%s\n",mot);
  //assert(syllabation(mot) == "ob-struer");
	strcpy(mot,"developpements");
	mot = syllabation(mot);
	printf("%s\n",mot);

	strcpy(mot,"campagnes");
	mot = syllabation(mot);
	printf("%s\n",mot);

	strcpy(mot,"chemin");
	mot = syllabation(mot);
	printf("%s\n",mot);

	strcpy(mot,"yacht");
	mot = syllabation(mot);
	printf("%s\n",mot);

	strcpy(mot,"dichotomie");
	mot = syllabation(mot);
	printf("%s\n",mot);
	
	strcpy(mot,"développements");
	mot = syllabation(mot);
	printf("%s\n",mot);

	
	strcpy(mot,"thèbes");
	mot = syllabation(mot);
	printf("%s\n",mot);

	strcpy(mot,"enchantements");
	mot = syllabation(mot);
	printf("%s\n",mot);

	strcpy(mot,"mondialisation");
	mot = syllabation(mot);
	printf("%s\n",mot);

	free(mot);
  return EXIT_SUCCESS;
}
