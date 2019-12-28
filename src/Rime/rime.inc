#include "rime.h"

struct _Lexique
{
	Word* words[200000];
	int index;
};

struct _Word
{
	char* word;
	char* word_syllable;
	char* word_phonetics;
	char* word_phonetics_syllable;
};
