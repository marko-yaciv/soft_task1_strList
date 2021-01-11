#include "MyList.h"
#define DATA 0
#define NEXT 1
void initStringList(char*** list)
{
    *list = (char**)calloc(2, sizeof(char*));
    (*list)[DATA] = NULL;
    (*list)[NEXT] = NULL;
}

void deleteStringList(char*** list)
{
    char ** head = *list;
    char ** tmp = NULL;
    while(head != NULL){
        tmp = head;
        head = (char**)head[NEXT];
        free(tmp[DATA]);
        free(tmp);
    }

}

void printStringlist(char** list)
{
    char** head = list;
    printf("List of string is: \n");
    if(head == NULL) {
        printf("EMPTY!\n");
        return;
    }
    while(head != NULL){
        printf("%s", head[DATA]);
        head = (char**)head[NEXT];
    }
}

void addNodeToStringList(char*** list, char* string)
{
    char** head = *list;

    char* stringToAdd = (char*)calloc(strlen(string), sizeof(char));
    strcpy(stringToAdd, string);

    if(head[NEXT] == NULL && head[DATA] == NULL){
        head[DATA] = stringToAdd;
    }
    else{
        while(head[NEXT] != NULL){
            head = (char**)head[NEXT];
        }
        char** newNode = (char**)calloc(2, sizeof(char*));
        if(!newNode) return;
        newNode[DATA] = stringToAdd;
        newNode[NEXT] = NULL;

        head[NEXT] = (char*)newNode;
    }
}

void removeNodeFromStringList(char*** list, const char* string)
{
    char** head = *list;
    char** prevNode = head;
    char** tmp = NULL;
    do{
        if(strcmp(head[DATA], string) == 0){
            tmp = head;
            prevNode[NEXT] = head[NEXT];
            break;
        }
        prevNode = head;
        head = (char**)head[NEXT];
    }while(head != NULL);
    if(tmp == NULL){
        printf("Nothing to remove!\n");
        return;
    }
    free(tmp[DATA]);
    free(tmp);

}

int getStringListSize(char** list)
{
    char ** head = list;
    int size = 0;
    while(head != NULL){
        ++size;
        head = (char**)head[NEXT];
    }
    return size;
}

bool replaceWith(char*** list,const char* oldStr, char* newStr)
{
    char** head = *list;
    bool isReplaced = false;
    while(head != NULL){
        if(strcmp(head[DATA], oldStr) == 0){
            isReplaced = true;
            memcpy(head[DATA],newStr,strlen(newStr));
            break;
        }
        head = (char**)head[NEXT];
    }
    return isReplaced;
}

int getIndexOfStringInStringList( char** list, const char* string)
{
    char ** head = list;
    int index = -1;
    bool isFound = false;
    while(head != NULL){
        ++index;
        if(strcmp(head[DATA],string) == 0){
            isFound = true;
            break;
        }
        head = (char**)head[NEXT];
    }
    return isFound?index:-1;
}
char** getNodeAtIndex(char*** list, int index){
    char**head = *list;
    int size = getStringListSize(*list);
    if(index >= size) return NULL;
    while(index--) head = (char**)head[NEXT];
    return head;
}
void sortStringList(char*** list)
{
    char** head = *list;
    while(head != NULL){
        char** node = (char**)head[NEXT];
        while(node != NULL){
            if(strcmp(head[DATA], node[DATA]) > 0){
                char** tmp = (char**)head[DATA];
                head[DATA] = node[DATA];
                node[DATA] = (char*)tmp;
            }
            else
                node = (char**)node[NEXT];
        }
        head = (char**)head[NEXT];
    }
}


