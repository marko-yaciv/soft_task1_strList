//
// Created by Marko on 21.12.2020.
//

#ifndef TASK1_STRLIST_MYLIST_H
#define TASK1_STRLIST_MYLIST_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
/*Initialises String list
 * Throws exception in case
 * Invalid pointer on list
 * Failure of allocating memory*/
void initStringList(char*** list);

/*deletes String list and free memory*/
void deleteStringList(char*** list);

/*prints String list in console.
 * If the list is empty, prints message*/
void printStringlist(char** list);

/*appends the list with new string
 * If function cannot allocate memory for string or
 * new node it throws exception*/
void addNodeToStringList(char*** list, char* string);

/*removes string from the list.
 * If the list is empty, throws exception*/
int removeNodeFromStringList(char*** list, const char* string);

/*returns list size*/
int getStringListSize(char** list);

/*replaces string <oldStr> with <newStr>.
 * If replacing is succesfull, returns true, otherwise - false*/
bool replaceWith(char*** list, const char* oldStr,const char* newStr);

/*returns index of specified string in list.
 * If list doesn't contain string, function returns -1*/
int getIndexOfStringInStringList(char** list, const char* string);

/*returns node at index.
 * If the index is larger than list size, throws message*/
char** getNodeAtIndex(char*** list, int index);

/*sorts list in Alphabetic order*/
void sortStringList(char*** list);

#endif //TASK1_STRLIST_MYLIST_H

