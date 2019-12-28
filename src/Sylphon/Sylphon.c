/**
 * @file phonetisation.c
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */

#include <assert.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Sylphon.h"
#include "listePrio.h"



void afficher_Sylphon(Sylphon* s){
	printf("syllabe : %s, phonetisation :\n",s->syllabe);
	afficher_ListePrio(s->phonetisation);

}

Sylphon* init_Sylphon(Sylphon* s){
	s = malloc(sizeof(Sylphon));
	return s;
}

void destroy_Sylphon(Sylphon* s){
	delete_ListePrio(s->phonetisation);
	free(s);
}
