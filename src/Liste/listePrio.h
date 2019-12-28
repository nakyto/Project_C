/**
 * @file phonetisation.h
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */
#include <stdbool.h>

#ifndef LISTEPRIO_H_
#define LISTEPRIO_H_



typedef struct _ListePrio ListePrio;
/**
 * @param racine character pointer , @param priorite , @param next ArrayList pointer. 
 * @note Its defined how ListePrio is constructed. 
 **/ 
struct _ListePrio {
  char* racine;
  int priorite;
  ListePrio* next;
};




/** 
 * @param a character pointer , @param next ArrayList pointer. 
 * @return an ArrayList pointer 
 * @note This function allows to create an ArrayList 
 **/ 
ListePrio* create_ListePrio(char* a, ListePrio* next);

/** 
 * @param a character pointer , @param x an Integer pointer, @param next ArrayList pointer. 
 * @return an ArrayList pointer 
 * @note This function allows to create a different type of ArrayList. 
 **/ 
ListePrio* create_ListePrio2(char* a, int x, ListePrio* next);
/** 
 * @param a an ArrayList pointer. 
 * @note This function delete the ArrayList. 
 **/ 
void delete_ListePrio(ListePrio* a);

/**
 * @param a an ArrayList pointer , @param v character pointer. 
 * @return an ArrayList at the end of the actual ArrayList 
 **/ 
ListePrio* insert_end(ListePrio* a, char* v); 

/**
 * @param a an ArrayList pointer , @param v character pointer , @param prio integer pointer. 
 * @return an ArrayList at the actual ArrayList 
 * @note allows to add a  new ArrayLst in function of his priority 
 **/ 
ListePrio* insert_prio(ListePrio* a,char* v, int prio);  

/**
 * @param a an ArrayList pointer. 
 * @note allows to show the actual ArrayList. 
 **/ 
void afficher_ListePrio(ListePrio* a); 

/** 
 * @param a an ArrayList pointer , @param x character pointer. 
 * @return an ArrayList pointer. 
 * @note find the character of an ArrayList. 
 **/ 
ListePrio* trouver_ListePrio(ListePrio* a, char* x);  



#endif  // LISTEPRIO_H_
