///\file menu.c
/// Prints the menu and contains the instructions for each function
/// Created by Baciu Lidia
///Implemented functions for calling the first, second, third and fourth functions


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "basic.h"
#include "menu.h"

void menu(){
        ///\fn void menu()
        ///\brief prints the options
        //the menu
        printf("\n\nYou have the following options: \n");
        printf("1. Determine if a word is present in a document.\n");
        printf("2. Determine the number of occurrences for a word in a document. \n");
        printf("3. Replace all instances of a word in a document with another given word. \n");
        printf("4. Replace specific instances of a word in a document with another given word \n");
        printf("5. Create a sorted list of words by the number of occurrences in a document. \n");

}

void first(FILE *file_in){
        ///\fn void first()
        ///\brief calls the specific functions so the 1st task is completed

        file_in=fopen("text.txt", "r");

        if( file_in == NULL){
                printf("There is an error reading from file.");
                exit(1);
        }
        char *buffer = (char *)malloc(3000*sizeof(char)); // saves the current paragraph
        char *word= malloc(10*sizeof(char)); // the word that is searched
        printf("Which word?");
        scanf("%s", word); //reads the word
        int OK = 0;
        int line = 1;
        while(fgets(buffer,3000,file_in)){ // gets the paragraph
                if ( exists_word(buffer, word) == 1){ // if the word is present in the paragraph
                        printf("\nThe word exists on the line %d", line);
                        OK = 1;
                        break; // exit because you don't need to go further
                }
                line++; // increase the number of the line ( paragraph )
        }
        if( OK == 0){
                printf("The word does not exist.\n");
        }

}

void second(FILE *file_in){
        ///\fn void second()
        ///\brief calls the specific functions so the 2nd task is completed

        file_in=fopen("text.txt", "r");

        if( file_in == NULL){
                printf("There is an error reading from file.");
                exit(1);
        }
        char *buffer = (char *)malloc(3000*sizeof(char)); // saves the current paragraph
        char *word= malloc(10*sizeof(char)); // the word that is searched
        printf("Which word?");
        scanf("%s", word); // reads the word

        int sum = 0; // the sum between the numbers of occurrences from every paragraph
        //e.g.: paragraph 1 - 4 occurrences; paragraph 2 - 1 occurrence => sum = 5;

        while(fgets(buffer,3000,file_in)){ // reads a paragraph
                sum = sum + number_of_occurrences(buffer, word); //adds to the general sum the current number of occ
        }

        printf("\nThe word %s appears %d times in total.\n", word, sum); // shows the result

}

void third(FILE *file_in, FILE *file_out){
        ///\fn void third()
        ///\brief calls the specific functions so the 3rd task is completed

        file_in=fopen("text.txt", "r");

        if( file_in == NULL){
                printf("There is an error reading from file.");
                exit(1);
        }

        char *buffer = (char *)malloc(3000*sizeof(char)); // saves the current paragraph
        char *word= malloc(10*sizeof(char)); // the word that is replaced
        char *word_toBeReplacedWith = malloc(10*sizeof(char)); // the replacement
        printf("Check the file results.txt ! There is the result. \n"); // the result will be put in the file results.txt

        printf("Which word is to be replaced?"); // reads the word
        scanf("%s", word);

        getchar(); // put a trash character to save the null

        printf("To which word?");
        scanf("%s", word_toBeReplacedWith); // reads the replacement

        while(fgets(buffer,3000,file_in)){ // reads a paragraph

                if( number_of_occurrences(buffer, word) == 0){ // if the word that needs to be replaced is not present in the text
                        fprintf(file_out, "\n %s", buffer); // put the paragraph in the file
                } else{
                        replace_word(buffer, word, word_toBeReplacedWith, file_out); // replace the word and the put it on the file
                }
        }
        fclose(file_out);

}

void fourth(FILE *file_in, FILE *file_out, int prev_command){
        ///\fn void fourth()
        ///\brief calls the specific functions so the 4th task is completed

        file_in=fopen("text.txt", "r");

        if( file_in == NULL){
                printf("There is an error reading from file.");
                exit(1);
        }
        int number;

        char *buffer = (char *)malloc(3000*sizeof(char)); // saves the current paragraph
        char *word= malloc(10*sizeof(char)); // the word that is replaced
        char *word_toBeReplacedWith = malloc(10*sizeof(char)); // the replacement
        printf("Check the file results.txt !\n"); // the result will be put in the file results.txt
        printf("Which word is to be replaced?");
        scanf("%s", word); // reads the word
        getchar(); // put a trash character to save the null
        printf("To which word?");
        scanf("%s", word_toBeReplacedWith); // reads the replacement
        getchar(); // put a trash character to save the null
        printf("Which appearance?");
        scanf("%d", &number); // reads the number
        //e.g.: if the number = 3, then the 3rd appearance of the word in the whole file will be replaced with the other word

        if( prev_command == 3){

                FILE *file_inSpecific;
                file_inSpecific = fopen("results.txt", "r");
                file_out = fopen("results.txt", "w");
                while ( fgets(buffer, 3000, file_inSpecific) ){
                        replaceSpecific(buffer, word, word_toBeReplacedWith, number, file_out); // replace
                        putc('\n', file_out);
                }
                fclose(file_inSpecific);
        }else{
                while(fgets(buffer, 3000, file_in)){
                        replaceSpecific(buffer, word, word_toBeReplacedWith, number,  file_out);
                        putc('\n', file_out);
                }
        }

        fclose(file_out);

}

