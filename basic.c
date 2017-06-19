///\file basic.c
///Implemented functions for: finding the number of occurrences, replacing words and finding out if a word exists or not in the text.
/// Created by Baciu Lidia

#include "basic.h"
#include "menu.h"

static int counter = 0; // it's global because its value needs to be saved in number_of_occurrences, but also in main
int number_of_occurrences( char *text, char *word){//determines how many times a word is present in the text
    ///\fn int number_of_occurrences( char *text, char *word)
    ///\brief Returns the number of occurrences of a word within a text
    ///\param text in which we are looking
    ///\param word the word we are looking for

        int count = 0;
        char *pch;
        char *aux = (char *)malloc(3000 * sizeof(char));
        strcpy(aux, text); // saves the text in a temporary variable

        pch = strtok(aux, " ,.:;?!'-\t\n"); // selects the words from the text

        while( pch != NULL )  { //while we did not reach the end of the line
                if( stricmp(pch, word) == 0){//if the current word and the word that is to be compared are identical
                        count++; // counts the word
                }
                pch = strtok('\0', " ,.:;?!-'\t\n"); // move on the next word
        }

        free(pch);
        free(aux);//give back the memory you took!

        return count;
}//returns the number of occurrences

int exists_word( char *text, char *word ){//determines if a word is present in the text
    ///\fn int exists_word( char *text, char *word )
    ///\brief Returns 1 if the word exists and 0 otherwise
    ///\param text text where in which we are looking
    ///\param word the word we are looking for

        if(number_of_occurrences(text, word) != 0){
                return 1; // found it!
        }

        return 0; // sorry!

}//returns 1 is the word is present in the text, 0 otherwise

void replace_word( char *text, char *what_toReplace, char *with_whatToReplace, FILE *file_out){
        //replaces all the occurrences of a word
    ///\fn void replace_word( char *text, char *what_toReplace, char *with_whatToReplace, FILE *file_out)
    ///\brief Replaces ALL instances of a word in a text
    ///\param text text where in which we are looking
    ///\param what_toReplace the word we are looking
    ///\param with_whatToReplace represents the replacement
    ///\param file_out represents the file in which we are writing
        char *token = strtok(text, "  .,;:'-?'!\n\t"); // selects the words from the text

        while( token != NULL){ // while you did not reach the end of the line
                if( stricmp(token, what_toReplace) == 0){ // if the words match
                        fprintf(file_out, "%s ", with_whatToReplace); // print the replace-word
                }else{
                        fprintf(file_out, "%s ", token); // print the current word
                }

                token = strtok(NULL, "  .,;:?-!'\n\t"); //move on to the next word
        }

}

void replaceSpecific( char *text, char *what_toReplace, char *with_whatToReplace, int number, FILE *file_out){
        //replaces a specific occurrence of a word
    ///\fn void replaceSpecific( char *text, char *what_toReplace, char *with_whatToReplace, int number, FILE *file_out)
    ///\brief Replaces ALL instances of a word in a text
    ///\param text text where in which we are looking
    ///\param what_toReplace the word we are looking
    ///\param with_whatToReplace represents the replacement
    ///\param number represents the index of the occurrence
    ///\param file_out represents the file in which we are writing
        char *token = strtok(text, "  .,;:'?-!\n\t"); // selects the words from the text

        while( token != NULL){// while you didn't reach the end of the text
                if( stricmp(token, what_toReplace) == 0){//if the words match
                        counter++; // you found something good! keep on!

                        if( counter == number){ // that's what you're looking for
                                fprintf(file_out, "%s ", with_whatToReplace); // print the replace-word
                        }else{
                                fprintf(file_out, "%s ", token); // print the current word (that is a match, but counter is a problem!)
                        }

                }else{
                        fprintf(file_out, "%s ", token); // print the current word ( that is not a match)
                }

                token = strtok(NULL, "  .,;:?-!'\n\t"); //move on to the next word
        }

}
