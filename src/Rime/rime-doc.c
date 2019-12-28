#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

#include "./Rime.h"
#include "./rime.inc"

int main(void){
	char str[20];
	Lexique* l=arrayReader();
	to_string(l->words[140000]);
	
	//scanf("%s",str);
	//char* rez=malloc(sizeof(char));
	//rez=phonSyll(str,l); //Doesn't work since l is almost totaly empty
	//printf("%s",rez);
	
	/*char** thing=malloc(20);
	rimes(rez,thing);
	free(thing);*/
	free(l);
	printf("helloworld");
	return EXIT_SUCCESS;
}

Lexique* addByPrio(Lexique* lex, int* prios, Word* w, int prio){
	int place=0;
	while (place<lex->index && prios[place]>prio){
		place++;
	}
	int i;
	lex->words[lex->index]=lex->words[lex->index-1];
	for (i=lex->index-1;i>=0;i++){
		if (i==place){
			lex->words[i]=w;
		}
		if (i>place){
			lex->words[i]=lex->words[i-1];
		}
	}
	lex->index++;
	return lex;
}

int* addThePrio(Lexique* lex, int* prios, int prio){
	int place=0;
	while (place<lex->index && prios[place]>prio){
		place++;
	}
	int i;
	prios=realloc(prios,sizeof(int));
	for (i=lex->index-1;i>=0;i++){
		if (i==place){
			prios[i]=prio;
		}
		if (i>place){
			prios[i]=prios[i-1];
		}
	}
	return prios;
}

Lexique* rimes (Word* word, Lexique* lex){
		Lexique* rez;
		int* prios;
		int result=0;
		int l1;
		int l2;
		int sec1=0;
		int sec2=0;
		bool rime=true;
		char* s1;
		char* s2;
		char* s11;
		char* s21;
		size_t n = lex->index;
		int l=0;
		
		while (l<n){
			l1=strlen(lex->words[l]->word_phonetics_syllable);
			l2=strlen(word->word_phonetics_syllable);
			while (l1>0 && l2>0 && rime){
				while (strcmp(lex->words[l]->word_phonetics_syllable[l1-1],"-")!=0){
					l1--;
					sec1++;
					*s11=lex->words[l]->word_phonetics_syllable[l1-1];
					s1=strcat(s11,s1);
				}
				while (strcmp(word->word_phonetics_syllable[l2-1],"-")!=0){
					l2--;
					sec2++;
					*s21=word->word_phonetics_syllable[l2-1];
					s2=strcat(s21,s2);
				}
				sec1=0;
				sec2=0;
				if (strcmp(s1,s2)!=0){
					rime=false;
				}else{
					result++;
				}
			}
			if (result>0){
				rez=addByPrio(rez,prios,lex->words[l],result);
				prios=addThePrio(rez,prios,result);
				
			}
			l++;
		}
	free(lex);
	return rez;
}

Lexique* arrayReader(){
	FILE *fic;
	//char tab[BUFFER_SIZE];
	char buffer[124];
	long int num_line = 0;
	char *ptr_chaine;
	char data_column1[20];
	char data_column2[20];
	char data_column3[20];
	char data_column4[20];
	char vide[] = "vide";
	Lexique* lex=malloc(sizeof(lex));
	
	fic = fopen("../../Lexique382.csv", "rt");

	if(fic==NULL){
		printf("Ouverture fichier impossible !");
		fclose(fic);
		exit(0);
	}

	while(fgets(buffer, sizeof(buffer), fic) != NULL) {
		ptr_chaine = strtok (buffer, "\t");
		strcpy(data_column1,ptr_chaine);
        	ptr_chaine = strtok (NULL, "\t");
		strcpy(data_column2,ptr_chaine);
        	ptr_chaine = strtok (NULL, "\t");
		strcpy(data_column3,ptr_chaine);
		ptr_chaine = strtok (NULL, "\t");
		if (ptr_chaine){
			strcpy(data_column4,ptr_chaine);
		}else{
			strcpy(data_column4,data_column3);
			strcpy(data_column3," "); // Call external function syllabation
		}
		Word* w=word_create(data_column1,data_column2,data_column3,data_column4);
		
		size_t memory=sizeof(lex->words)+sizeof(w);
		lex=realloc(lex,memory);
		lex->words[num_line]=w; //Cf free a few lines below
		if (num_line<25){
			//to_string(lex->words[num_line]);
			//printf("%d",num_line);
			//to_string(w);
			//printf("%ld\n",num_line);
			//to_string(lex->words[num_line]);
		}
		free(w); //Does free lex->words[num_line] aswell, should "copy"
		lex->index++;
		num_line++ ;
	}
	lex->index=num_line;

	//to_string(lex->words[num_line]);
	fclose(fic);
	return lex;  //currently empty beside the last line
}


char* phonSyll(char* w, Lexique* lex){
	bool found=false;
	int l=-1;
	int n = lex->index;
	int a=3;
	//to_string(lex->words[0]);
	while (l<n && !found && a>0){
		l++;
		printf(w);
		printf(lex->words[l]->word);
		if (strcmp(w,lex->words[l]->word)==0){
			found=true;
		}
		a--;
	}
	if (found){
		w=lex->words[l]->word_phonetics_syllable;
	}else{
		w=NULL;
	}
	return w;
}

Word* word_create(char* column1, char* column2, char* column3, char* column4){
	Word* word = malloc(sizeof(Word)); 
	word->word = column1;
	word->word_syllable = column2;
	word->word_phonetics = column3;
	word->word_phonetics_syllable = column4;

	return word;
}

void to_string(Word* word){
	printf("%s\t%s\t%s\t%s\t\n",word->word,word->word_syllable,word->word_phonetics,word->word_phonetics_syllable);
}

void word_delete(Word* word){
	free(word);
}

void lexique_delete(Lexique* lexique){
	for(int i=0; i<lexique->index; i++){
		word_delete(lexique->words[i]);
	}
	free(lexique);
}

