/**
 * @file ABR.c
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ABR-doc.h"



ABR* create_leaf(Sylphon* a) {
	ABR* point = malloc(sizeof(ABR));
	point->racine = a;
	point->ABRright = NULL;
	point->ABRleft = NULL;
	return point;
}

ABR* create_ABR(Sylphon* a, ABR* right, ABR* left) {
	ABR* point = malloc(sizeof(ABR));
	point->racine = a;
	point->ABRright = right;
	point->ABRleft = left;
	return point;

}


bool is_leaf(ABR* a) {
	if(a->ABRright == NULL & a->ABRleft == NULL)
		return true;
	return false;
}

void setRoot(ABR* a, Sylphon* x) {
	a->racine = x;
}

ABR* insert(ABR* a, Sylphon* x) {
	if(!is_leaf(a)) {
		Sylphon* k = a->racine;
		Sylphon* k2 = x;
		int i = strcmp(k->syllabe, k2->syllabe);
		if (i != 0) {
			if(i < 0) {
				insert(a->ABRright, x);
			} else {
				insert(a->ABRleft, x); 
			}
		}
	} else {
		Sylphon* k = a->racine;
		Sylphon* k2 = x;
		int i = strcmp(k->syllabe, k2->syllabe);
		if (i != 0){
			if(i < 0){
				a->ABRright = create_leaf(x);
			} else {
				a->ABRleft = create_leaf(x);
			}
		}
	}
	return a;
}

void afficher(ABR* a) {
	if(a->ABRleft != NULL){
		afficher(a->ABRleft);
	}
	afficher_Sylphon(a->racine);
	if(a->ABRright != NULL){
		afficher(a->ABRright);
	}
}

void delete_ABR(ABR* a) {
	if(a->ABRleft != NULL){
		delete_ABR(a->ABRleft);
	}
	if(a->ABRright != NULL){
		delete_ABR(a->ABRright);
	}
	destroy_Sylphon(a->racine);
	free(a);
}


ABR* trouverABR(ABR* a, Sylphon* x) {
	Sylphon* tmp = a->racine;
	int i = strcmp(tmp->syllabe, x->syllabe);
	if(i==0){
		return a;
	}
	if(i<0){
		if(a->ABRleft != NULL){
			return trouverABR(a->ABRleft,x);
		}
	}else{
		if(a->ABRright != NULL){
			return trouverABR(a->ABRright,x);
		}
	}
	return NULL;
}






