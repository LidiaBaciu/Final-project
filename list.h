///\file list.h
///\brief C library for working within a text
///
///Created by Lidia Baciu
///Implements functions for: finding the number of occurrences, replacing words and finding out if a word exists or not in the text.

#ifndef LISTSWORDS_H_INCLUDED
#define LISTSWORDS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"

void swapWords(char **i, char **d); //swaps two words
void swapCounters(struct g_node *a, struct g_node *b); //swaps the counters of a list
int isEmpty( struct g_node *list); //determines if a list is empty
void push_word_begining(struct g_node **heads, char *word); //adds elements at the beginning
int search_word (struct g_node **heads, char *word); // says if a word is present in the lists
void printf_counters( struct g_node **heads); // prints the counters of a list, along with the words
void sort( struct g_node *head);
void combine( struct g_node **heads, struct g_node *headG);
void print_list(struct g_node *head);
void push_element_begining(struct g_node *head , char *new_element_value);
void fifth(FILE *file_in, int prev_command);

#endif // LISTSWORDS_H_INCLUDED
