//
// Created by Marko on 21.12.2020.
//

#ifndef TASK1_STRLIST_MYLIST_H
#define TASK1_STRLIST_MYLIST_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
/*Initialises String list*/
void initStringList(char*** list);

/*deletes String list and frees memory*/
void deleteStringList(char*** list);


void printStringlist(char** list);
/*appends the list with new string*/
void addNodeToStringList(char*** list, char* string);

/*removes string from the list*/
void removeNodeFromStringList(char*** list, const char* string);

/*returns list size*/
int getStringListSize(char** list);

/*replaces string <oldStr> with <newStr>*/
bool replaceWith(char*** list, const char* oldStr, char* newStr);

/*returns index of specified string in list.
 * If list doesn't contain string, function returns -1*/
int getIndexOfStringInStringList( char** list, const char* string);

char** getNodeAtIndex(char*** list, int index);
/*sorts list in order 'shortest string'...'largest string' */
void sortStringList(char*** list);

/*swaps two nodes in string list*/
void swapNodesInStringList(char*** list, char** node1, char**node2);

#endif //TASK1_STRLIST_MYLIST_H

