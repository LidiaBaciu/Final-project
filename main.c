///\file main.c
/// The main function - calls the corresponding function so the task is completed.
/// Created by Baciu Lidia


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "basic.h"
#include "structure.h"
#include "list.h"


int main(){

        menu();
        int command;
        int prev_command = 0;
        printf("\n Now you have to make a choice. How would you like me to help you? \n[input the number of the command]");
        scanf("%d", &command);

        FILE *file_out;
        FILE *file_in;

        file_in = fopen("text.txt", "r");

        if( file_in == NULL){
                printf("There is an error reading from the file.");
                exit(1);
        }

        file_out = fopen("results.txt", "w");

        if( file_out == NULL){
                printf("There is an error writing to the file.");
                exit(1);
        }


        while( command >=1 && command <= 5){


                if( command == 1){//tests the existence of a word
                        first(file_in);
                }

                if( command == 2){// how many times does a word occur?
                        second(file_in);
                }

                if(command == 3){//replaces all the occurrences of a word with another word
                        third(file_in, file_out);
                }

                if( command == 4){//replaces a specific occurrence of a word with another word
                        fourth(file_in, file_out, prev_command);
                }

                if( command == 5){// shows a top of the most frequent words
                        fifth(file_in, prev_command);
                }

                prev_command = command;
                printf("If you finished, press 0. If not, press the number of the command. \n");
                scanf(" %d", &command);


                fclose(file_in); // closes the file from which we are reading

        }


        return 0; // there were no errors
}

