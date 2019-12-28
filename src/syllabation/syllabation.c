/**
 * @file syllabation.c
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 */

#include <assert.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./syllabation.h"



bool estVoyelle(char* string) {
  char* voyelles[] = {"a","e","i","o","u","y","à","â","ä","é","è","ê","ë","î","ï","ô","ö","ù","û","ü"};
  char** voyelles2 = voyelles;
  int i;
  for (i = 0; i < sizeof(voyelles) / sizeof(*voyelles); i++) {
    if (strncmp(string, voyelles[i], strlen(voyelles[i])) == 0) {
      return true;
    }
  }
  return false;
}

char* cut(char* mot, int j, char* fin){
	int i = 0;
	char* s = malloc(60);
	for(i;i<j;i++){
		s[i]=mot[i];	
	}
	s[i+1]='\0';
	strncat(fin,s,sizeof(s));
	while(mot[i] != '\0'){
		s[i-j]=mot[i++];
	}
	s[i-j]= '\0';
	strcpy(mot,s);
	strncat(fin, "-",sizeof("-"));
	free(s);
	return mot;
	
}


char* syllabation(char* mot){
	int i=0;
	int comptCons = 0;
	bool booleanVoy =false;
	char* fin = malloc(strlen(mot) + 15);
	strcpy(fin, "\0"); 
	char* motus = malloc(strlen(mot));
	int j;
	while(mot[i]!='\0'){
	
	for(j=0;j<strlen(mot)-i;j++){
		motus[j]=mot[j+i];
	}
	motus[j]='\0';
	
		if(estVoyelle(motus)){
			if(comptCons!=0){
				if(comptCons>1){
					mot=cut(mot,i-comptCons+1,fin);
				}else{
					mot=cut(mot,i-comptCons,fin);
				}
				booleanVoy=false;
				comptCons=0;
				i=0;
			}else{
				booleanVoy=true;
			}
		}else{
			if(booleanVoy){
				if(comptCons!=0){
					if(mot[i]=='n' & mot[i-1]=='g'){
						comptCons=comptCons+1;
					} 
					if(comptCons==1 & (mot[i]=='h' & (mot[i-1]=='c' | mot[i-1]=='s' | mot[i-1]=='p'))){
						comptCons=comptCons+1;
					}
						
					comptCons++;
				}else{
					comptCons=1;
				}
			}
		}
		
		i++;
	}
	strncat(fin, mot,sizeof(mot));
	strcpy(mot,fin);
	free(fin);
	free(motus);
	return mot;
}
/*
if(boolean2){
				strcpy(m,cut(m,i,fin));
				i=0;
				boolean1 = false;
				boolean2 = false;
			}else{
				boolean1 = true;
				l = m[i++];
			}
		}else{
			if(boolean1){
				if(boolean2){
					l = m[i-2];
					strcpy(m,cut(m,i,fin));
					i=0;
					boolean1 = false;
					boolean2 = false;
				}else{
					l = m[i++];
					boolean2 = true;
				}
			}else{
				l = m[i++];
				boolean = true;
			}
		}
			

*/
/*
bool estVoyelle(char* l){
	if( l=='a' | l=='e' | l=='i' | l=='o' | l=='u' | l=='y' | l=='à' | l=='â' | l=='ä' | l=='é' | l=='è' | l='ê' | l=='ë'| l=='ï' | l=='î' | l=='ô' | l=='ö' | l=='û' | l=='ü')
	
	if(strcmp(l,"a")
	
		return true;
	else
		return false;
}*/


