/**
 * @file phonetisation.h
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */




#ifndef SYLPHON_H_
#define SYLPHON_H_

#include <stdbool.h>
#include "../Liste/listePrio.h"

typedef struct _Sylphon Sylphon;
struct _Sylphon {
 	char* syllabe;
	ListePrio* phonetisation;
};

Sylphon* init_Sylphon(Sylphon* s);

/**
 * @param s
 * @return void
 * @note delete all value in struc Sylphon
 **/
void destroy_Sylphon(Sylphon* s);

/**
 * @param s
 * @return void
 * @note show the value in struc Sylphon
 **/
extern void afficher_Sylphon(Sylphon* s);

#endif  // SYLPHON_H_
