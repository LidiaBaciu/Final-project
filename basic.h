///\file basic.h
///\brief C library for working within a text
///
///Created by Lidia Baciu
///Implements functions for: finding the number of occurrences, replacing words and finding out if a word exists or not in the text.


#ifndef BASICWORDS_H_INCLUDED
#define BASICWORDS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int number_of_occurrences( char *text, char *word);//returns the number of occurrences of a word
int exists_word( char *text, char *word );//says if a word is present in text or not
void replace_word( char *text, char *what_toReplace, char *with_whatToReplace, FILE *file_out); //replaces all the occurrences of a word
void replaceSpecific( char *text, char *what_toReplace, char *with_whatToReplace, int number, FILE *file_out); //replaces a specific occurrence


#endif // BASICWORDS_H_INCLUDED
