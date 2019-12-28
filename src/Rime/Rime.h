#ifndef RIME_H_
#define RIME_H_

#include "rime.inc"
/**
 * It's defined how to a word is constructed
 **/
typedef struct _Word Word;

/**
 * It's defined how the library is constructed
 * 
 * @note The library contains pointer words
 * 
 * @note An index allows to the library to count each line 
 **/
typedef struct _Lexique Lexique;

/**
 * @file Lexique382.csv
 * @param column1 selecte The column 1 in the file
 * 
 * @param column2 selecte The column 2 in the file
 * 
 * @param column3 selecte The column 3 in the file
 * 
 * @param column4 selecte The column 4 in the file
 * 
 * @return a pointer to a memory area that contains the 4 column
 **/

Word* word_create(char* column1, char* column2, char* column3, char* column4);

/**
 * @param word is a word pointer
 * 
 * @note: this function allows to show a word
 **/
void to_string(Word* word);
/**
 * @param word is a word pointer
 * 
 * @ote: this function delete a word
 **/
void word_delete(Word* word);

/**
 * @param lexique is a library pointer 
 * 
 * @note: lexique_delete allows to delete the library in parameter
 **/
void lexique_delete(Lexique* lexique);

/**
 * @param word is the words the word pass in parameter in graphic interface
 * 
 * @param lex  is the list of "all" words
 * 
 * @return a list with the rhyme of the word `word` 
 **/
Lexique* rimes (Word* word, Lexique* lex);

/**
 * @param void
 * 
 * @return a list
 **/
Lexique* arrayReader();

/**
 * @param w is a struct words 
 * 
 * @param lex is a list 
 * 
 * @return a String
 **/
char* phonSyll(char* w, Lexique* lex);

/**
 * @param lex list of all words
 * 
 * @param prios array of prio 
 * 
 * @param w the rime
 * 
 * @param prio the prio of the rime
 * 
 * @return a list ordered by prio
 **/
Lexique* addByPrio(Lexique* lex, int* prios, Word* w, int prio);

/** 
 * @param lex list of all words
 * 
 * @param prios is a array of prio
 * 
 * @param prio the prio of the rime
 * 
 * @return array of prio int
 **/
int* addThePrio(Lexique* lex, int* prios, int prio);

#endif // RIME_H_