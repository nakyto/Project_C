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


#include "./phonetisation.h"
#include "../Sylphon/Sylphon.h"

int compteurTiret(char* string){
	int i=0;
	int compteur = 0;
	while(string[i] != '\0'){
		if(string[i] == '-'){
			compteur++;	
		}
		i++;
	}
	return compteur;
}

Sylphon* Sylphon_init(Sylphon* s){
	s = malloc(sizeof(Sylphon));
	/*s->syllabe = "";
	s->phonetisation = NULL;*/
}



ABR* CutWord(char* syllabe, char* phonet, ABR* abr){
	int i=0;
	int j=0;
	int countS = 0;
	int countP = 0;
	char* syltmp = malloc(100);
	char* phontmp = malloc(100);
	ABR* ABRtmp = malloc(sizeof(ABR));
	Sylphon* Sylphontmp = Sylphon_init(Sylphontmp); 
	ListePrio* Listetmp = malloc(sizeof(ListePrio));
	printf("%s\n",syllabe);
	printf("%s\n",phonet);
	
	while(syllabe[i] != '\0'){
		if(syllabe[i] == '-'){
			syltmp = strncpy(syltmp,syllabe,i);
			i++;
			
			while(phonet[j] != '\0' & phonet[j] != '-'){
				j++;
			}
			strncpy(phontmp,phonet,j);
			j++;
			
			
			Sylphontmp->syllabe = syltmp;
			printf("%s\n",Sylphontmp->syllabe);
			
			ABRtmp = trouverABR(abr,Sylphontmp);
			
			
			if(ABRtmp){
				Sylphontmp = ABRtmp->racine;
				Listetmp = Sylphontmp->phonetisation;
				Listetmp = trouver_ListePrio(Listetmp,phontmp);
				if(Listetmp){
					Listetmp->priorite++;
				}else{
					insert_end(ABRtmp->racine->phonetisation,phontmp);
				}
			}else{
				//Sylphontmp->syllabe = syltmp;
				Listetmp = Sylphontmp->phonetisation;
				if(Listetmp){
					insert_end(Listetmp, phontmp);
				}else{
					Listetmp = create_ListePrio(phontmp, NULL);
				}
				
				printf("\n");
				afficher_ListePrio(Listetmp);
				printf("\n");
				
				Sylphontmp->phonetisation = Listetmp; //marche pas
				insert(abr, Sylphontmp);
			}
			
		}
		
		i++;
	}
	
	free(ABRtmp);
	//free(Sylphontmp);
	//free(Listetmp);
	free(syltmp);
	free(phontmp);
	
	return abr;
} 












/*

ABR* CreateABR(Lexique* lexique){
	int i=0;
	//faut creer l'arbre
	
	for(i; i<lexique->n; i++){
		if(compteurTiret(lexique->mot[i]->syllabe) == compteurTiret(lexique->mot[i]->phonetisationSyllabique)){
			MakeMot(ABR*, lexique->mot[i]->syllabe, lexique->mot[i]->phonetisationSyllabique);
		}
	} 

}



ABR* MakeMot(ABR* abr, char** syl, char** pho, int n){
	int i = 0;
	for(i;i<n;i++){
		ABR* crt= trouverABR(abr, syl[i]); //structure sylphon
		if(crt != NULL){
			ListePrio lp = trouverListePrio(crt->racine.phonetisation, pho[i];
			if(lp != NULL){
				lp->prio=lp->prio + 1; //orthographe prio ?
			}else{
				insert_end(crt->racine.phonetisation, pho[i]);
			}
		}else{
			Create/insert ABR; //reprendre
			insert_end(crt->racine.phonetisation, pho[i]);
			ADD; //si insert
		}
		i++;
	}
	return abr;
}
*/

















