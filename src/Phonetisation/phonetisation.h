/**
 * @file phonetisation.h
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */




#ifndef PHONETISATION_H_
#define PHONETISATION_H_

#include <stdbool.h>
#include "../Liste/listePrio.h"
#include "../ABR/ABR-doc.h"


/**
 * 
 **/
extern int compteurTiret(char* string);

/**
 * @param syllabe is the
 * 
 * @param phonet is  phoneme 
 * 
 * @param abr  is a tree
 * 
 * 
 **/

extern ABR* CutWord(char* syllabe, char* phonet, ABR* abr);

#endif  // SYLLABATION_H_
