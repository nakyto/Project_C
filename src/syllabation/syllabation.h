/**
 * @file syllabation.h
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */
#include <stdbool.h>

#ifndef SYLLABATION_H_
#define SYLLABATION_H_

typedef struct _Voyelle Voyelle;
struct _Voyelle {
  char lettre;
};
/**
 * @param string 
 * 
 * @return a boulean true or false
 **/
bool est_voyelle(char* string);

/**
 * @param string 
 * 
 * @return a arrray of string
 **/
char* syllabation(char* string);

/**
 * @param string 
 * 
 * @param j 
 * 
 * @param fin 
 * 
 * @return a arrray of string
 **/
char* cut(char* string, int j, char* fin);

/**
 * @param void 
 * 
 * @return a arrray of string
 * @note add at end
 **/
char* create_fin();
/**
 * @note free memory 
 **/
void free_fin(char* fin);




#endif  // SYLLABATION_H_
