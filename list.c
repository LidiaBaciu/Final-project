
///\file list.c

///
/// Created by Baciu Lidia
///Implemented functions for: swapping words or counters, adding elements to a list, printing and sorting the list

#include "list.h"
#include "structure.h"


void swapWords(char **i, char **d){//swaps two words
        ///\fn void swapWords(char **i, char **d)
        ///\brief Swaps two strings
        ///\param i is the first string
        ///\param d is the second string
        ///
        ///The operation is executed no matter what
        char *t = *d;
        *d = *i;
        *i = t;
}

void swapCounters(struct g_node *a, struct g_node *b){//swaps two counters
        ///\fn void swapCounters(struct g_node *a, struct g_node *b)
        ///\brief Swaps two infos of a node
        ///\param a is the info of the first node
        ///\param b is the info of the second node
        ///
        ///The operation is executed no matter what
        int temp = a->counterWord;
        a->counterWord = b->counterWord;
        b->counterWord = temp;
}

int isEmpty( struct g_node *list){//determines if a list is empty
        ///\fn int isEmpty( struct g_node *list)
        ///\brief Return 1 if the list is empty and 0 otherwise.
        ///\param list represents the list we are testing.
        ///

        if(list->next == NULL){
                return 1;
        }else{
                return 0;
        }

}//returns 1 if it is empty, 0 otherwise

void push_word_begining(struct g_node **heads, char *word){//adds a word at the beginning of the list
        ///\fn void push_word_begining(struct g_node **heads, char *word)
        ///\brief Adds a word to the beginning of the list
        ///\param heads represents the pointer to the pointer of the beginning of the heads[i]
        ///\param word represents the word which is to be added
        ///
        ///The operation is executed no matter what
        struct g_node *new_element = malloc(sizeof(struct g_node));

        new_element->info = malloc(strlen(word) + 1);// allocate memory
        strcpy(new_element->info, word);//put the word in the list
        new_element->next = (*heads)->next;
        new_element->counterWord = 1;
        (*heads)->next = new_element; // make the link

}

void push_element_begining(struct g_node *head , char *new_element_value){
        ///\fn void push_element_begining(struct g_node *head, char *new_element_value)
        ///\brief Adds a word to the beginning of the list
        ///\param head represents the pointer to the beginning of the final list
        ///\param new_element_value represents the word which is to be added
        ///
        ///The operation is executed no matter what
        struct g_node *new_element = malloc(sizeof(struct g_node));
        new_element->info = malloc(strlen(new_element_value) + 1);
        strcpy(new_element->info, new_element_value);
        new_element->next = head->next;
        new_element->counterWord = 1;
        head->next = new_element;

}


int search_word (struct g_node **heads, char *word){//determines if a word is already in the list
        ///\fn int search_word (struct g_node **heads, char *word)
        ///\brief Returns 1 if the word is already in the text, increasing its counter, and 0 otherwise
        ///\param heads represents the pointer to the pointer of the beginning of the heads[i]
        ///\param word represents the word we are looking for

        ///The operation is executed if the list is not empty
        struct g_node *iterator = *heads;

        if(isEmpty(iterator) == 0){//if the list is empty
                while( iterator->next != NULL ){//while did not reach the end of the file
                        iterator = iterator->next;//move on
                        if(stricmp(iterator->info, word) == 0){//if the words match
                                iterator->counterWord = iterator->counterWord + 1; // add to counter
                                return 1;//already exits
                        }

                }
        }
        return 0;//does not exist
}

void printf_counters( struct g_node **heads){//prints the counters and the specific words
        ///\fn void printf_counters(struct g_node **heads)
        ///\brief Prints the words and the counters of the list
        ///\param heads represents the pointer to the pointer of the beginning of the heads[i]
        ///
        ///The operation is executed if the list is not empty
        struct g_node *iterator = *heads;

        if(isEmpty(iterator) == 0){//if list is empty
                printf("\t\tThe list is:\n");

                while(iterator->next != NULL){//while did not reach the end
                        printf("the word is: %s [%d times]\n", iterator->next->info, iterator->next->counterWord );//print the infos
                        iterator = iterator->next; //move on
                }

        }
}

void print_list(struct g_node *head){
        ///\fn void print_list(struct g_node *head)
        ///\brief Prints the words and the counters of the list
        ///\param head represents the pointer to the beginning of the list
        ///
        ///The operation is executed if the list is not empty
        struct g_node *iterator = head;

        if(isEmpty(iterator) == 0){
                while(iterator->next != NULL){
                        printf("%s %d\n", iterator->next->info, iterator->next->counterWord);
                        iterator = iterator->next;
                }
        }

}


void sort( struct g_node *head){
        ///\fn void sort(struct g_node *heads)
        ///\brief Sorts the elements of the list, by the value of the counter, in decreasing order
        ///\param head represents the address of the beginning of the list
        ///
        ///The operation is executed if the list is not empty
        struct g_node *iterator = head;

        int swapped;
        struct g_node *pointer1;

        if(isEmpty(iterator) == 0){//if the list is empty, there is nothing to be sorted


                do{
                        swapped = 0; // did not swap
                        pointer1 = iterator->next;
                        while (pointer1 != NULL && pointer1->next != NULL){ // while did not reach the end

                                if( pointer1->counterWord < pointer1->next->counterWord){ //if the order does not match
                                        swapCounters(pointer1, pointer1->next); // swap the counters
                                        swapWords(&pointer1->info, &pointer1->next->info); // along with the words
                                        swapped = 1; // did swap
                                }

                                pointer1 = pointer1->next; // move on
                        }

                }while (swapped);

                free(pointer1); // give back the memory
        }

}


void combine( struct g_node **heads, struct g_node *headG){
        ///\fn void combine(struct g_node **heads, struct g_node *headG)
        ///\brief Adds to a global node the current list;
        ///\param headG represents the address of the beginning of the list
        ///\param heads represents the address to the address of the beginning of the list


        struct g_node *iterator = *heads;

        while(iterator->next != NULL){
                push_element_begining(headG, iterator->next->info);
                headG->next->counterWord = iterator->next->counterWord;
                iterator = iterator->next;
        }

}

void fifth(FILE *file_in, int prev_command){
        ///\fn void fifth(FILE *file_in)
        ///\brief Calls the proper functions so that the 5th task is complete
        ///\param file_in represents the file from where we are reading the text
        ///\param prev_command represents the previous command
        ///the previous command is used so the user can modify the output from command 3 or 4

        file_in=fopen("text.txt", "r");

        if( file_in == NULL){
                printf("There is an error reading from file.");
                exit(1);
        }

        char *buffer = (char *)malloc(3000*sizeof(char)); // saves the current paragraph
        int indexHeads; //tells on which list you are
        struct g_node *heads[26]; // the heads of the lists

        for( indexHeads = 0; indexHeads < 26; indexHeads++){
                heads[indexHeads] = malloc(sizeof(struct g_node)); // make space
                heads[indexHeads]->next = NULL; // point to NULL;
        }

        struct g_node *headG;
        headG = malloc(sizeof(struct g_node));
        headG->next = NULL;

        char *token; // will be the current word
        int initial; // initial of the word
                //is int because will be used as index of the specific heads[]

        if( prev_command == 3 || prev_command == 4){
                FILE *file_inSpecific;
                file_inSpecific = fopen("results.txt", "r");

                while(fgets(buffer,3000,file_inSpecific)){ //while there is what to read
                        token = strtok(buffer, "  .,;:'?-!\n\t"); // get the current word

                        while( token != 0){ // while there are words
                                initial = token[0]; // find out the initial of the word
                                if (initial >= 'a' && initial <= 'z'){
                                        initial -= 'a';
                                }else if (initial >= 'A' && initial <= 'Z'){
                                        initial -= 'A';
                                        }else {
                                                break;
                                        } // not a letter, can't store this in your scheme

                                if( search_word(&heads[initial], token) == 0){//if the word is not already present in the list
                                        push_word_begining(&heads[initial], token); //add the word
                                }
                                token = strtok(0, "  .,;:'?-!\n\t"); //move on to the next word
                        }
                }
                fclose(file_inSpecific);
        }else{
                while(fgets(buffer,3000,file_in)){ //while there is what to read
                        token = strtok(buffer, "  .,;:'?-!\n\t"); // get the current word

                        while( token != 0){ // while there are words
                                initial = token[0]; // find out the initial of the word
                                if (initial >= 'a' && initial <= 'z'){
                                        initial -= 'a';
                                }else if (initial >= 'A' && initial <= 'Z'){
                                        initial -= 'A';
                                        }else {
                                                break;
                                        } // not a letter, can't store this in your scheme

                                if( search_word(&heads[initial], token) == 0){//if the word is not already present in the list
                                        push_word_begining(&heads[initial], token); //add the word
                                }
                                        token = strtok(0, "  .,;:'?-!\n\t"); //move on to the next word
                        }
                }
        }


        for (indexHeads = 0; indexHeads < 25; ++indexHeads){
                combine(&heads[indexHeads], headG);
        }

        sort(headG);
        print_list(headG);

}
