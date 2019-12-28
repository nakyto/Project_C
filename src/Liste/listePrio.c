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

#include "./listePrio.h"


ListePrio* create_ListePrio(char* a, ListePrio* next){
	ListePrio* point = malloc(sizeof(ListePrio));
	point->racine = a;
	point->priorite =1;
	point->next = next;
	return point;
}

ListePrio* create_ListePrio2(char* a, int x, ListePrio* next){
	ListePrio* point = malloc(sizeof(ListePrio));
	point->racine = a;
	point->priorite =x;
	point->next = next;
	return point;
}


void delete_ListePrio(ListePrio* a){
	if(a->next != NULL){
		delete_ListePrio(a->next);
	}
	free(a);
	
}

ListePrio* insert_end(ListePrio* a, char* v){
	if(a->next != NULL){
		return insert_end(a->next,v);
	}else{
		a->next = create_ListePrio(v, NULL);
		return a;
	}
}

ListePrio* insert_prio(ListePrio*a, char* v, int prio){
	if(a->next == NULL){
		a->next = create_ListePrio2(v, prio, NULL);
		return a;
	}
	if(a->priorite >= prio){
		a->next = insert_prio(a->next,v,prio);
		return a;
	}else{
		return create_ListePrio2(v,prio,a);
	}
	
}

void afficher_ListePrio(ListePrio* a){
	printf("%s %d\n",a->racine,a->priorite);
	if(a->next != NULL){
		afficher_ListePrio(a->next);
	}
}

ListePrio* trouver_ListePrio(ListePrio* a, char* x){
	int i = strcmp(a->racine, x);
		if(i==0){
			return a;
		}
		if(i<0){
			if(a->next != NULL){
				return trouver_ListePrio(a->next,x);
			}
		}
	return NULL;
}


