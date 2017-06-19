///\file structure.h
///\brief C structure
///
///Created by Lidia Baciu
///Presents a structure for the nodes of a singly linked list, containing the word, its counter and the link to the next node


#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

struct g_node{//declaration of a node
        ///\fn struct g_node
        ///\brief the information of a node is presented here
        ///\param info represents the word
        ///\param counterWord represents the number of the occurrences of the word in text
        ///\param next represents the link to the next node
        char *info; // represents the value/text
        int counterWord;
        struct g_node *next; // represents the link
};

#endif // STRUCTURE_H_INCLUDED
