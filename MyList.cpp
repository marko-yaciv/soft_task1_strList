#include "MyList.h"
#define DATA 0
#define NEXT 1
/*HELPER FUNCTIONS*/
void validateList(char*** list)
{
    if(list == NULL)
    {
        throw "The pointer cannot be NULL";
    }
}
void validateNode(char** node)
{
    if(node == NULL)
    {
        throw "Invalid pointer of node (NULL)";
    }

}
void validateData(const char* data)
{
    if(data == NULL)
    {
        throw "Invalid pointer on data in node (NULL)";
    }
}

/* INTERFACE FUNCTIONS*/
void initStringList(char*** list)
{
    validateList(list);

    *list = (char**)calloc(2, sizeof(char*));
    validateNode(*list);

    (*list)[DATA] = NULL;
    (*list)[NEXT] = NULL;
}

void deleteStringList(char*** list)
{
    validateList(list);

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
    validateNode(list);

    char** head = list;
    printf("List of string is: \n");
    if(head == NULL)
    {
        printf("EMPTY!\n");
        return;
    }
    while(head != NULL)
    {
        printf("%s", head[DATA]);
        head = (char**)head[NEXT];
    }
}

void addNodeToStringList(char*** list, char* string)
{
    validateList(list);

    char** head = *list;
    char* stringToAdd = (char*)calloc(strlen(string), sizeof(char));
    validateData(stringToAdd);
    strcpy(stringToAdd, string);

    if(head[NEXT] == NULL && head[DATA] == NULL)
    {
        head[DATA] = stringToAdd;
    }
    else
    {
        while(head[NEXT] != NULL)
        {
            head = (char**)head[NEXT];
        }

        char** newNode = (char**)calloc(2, sizeof(char*));
        validateNode(newNode);

        newNode[DATA] = stringToAdd;
        newNode[NEXT] = NULL;

        head[NEXT] = (char*)newNode;
    }
}

int removeNodeFromStringList(char*** list, const char* string)
{
    validateList(list);

    char** head = *list;
    char** prevNode = head;
    char** tmp = NULL;
    try{
        validateNode(head);
    }
    catch (const char* ex)
    {
        throw "The List is empty";
    }
    do{
        if(strcmp(head[DATA], string) == 0)
        {
            tmp = head;
            prevNode[NEXT] = head[NEXT];
            break;
        }
        prevNode = head;
        head = (char**)head[NEXT];
    }while(head != NULL);

    if(tmp == NULL)
    {
        return -1;
    }
    free(tmp[DATA]);
    free(tmp);
    return 0;
}

int getStringListSize(char** list)
{
    validateNode(list);

    char ** head = list;
    int size = 0;
    while(head != NULL)
    {
        ++size;
        head = (char**)head[NEXT];
    }
    return size;
}

bool replaceWith(char*** list,const char* oldStr,const char* newStr)
{
    validateList(list);

    char** head = *list;
    bool isReplaced = false;
    while(head != NULL)
    {
        if(strcmp(head[DATA], oldStr) == 0)
        {
            isReplaced = true;
            memcpy(head[DATA],newStr,strlen(newStr));
            break;
        }
        head = (char**)head[NEXT];
    }
    return isReplaced;
}

int getIndexOfStringInStringList(char** list, const char* string)
{
    validateNode(list);

    char ** head = list;
    int index = -1;
    while(head != NULL)
    {
        ++index;
        if(strcmp(head[DATA],string) == 0)
        {
            return index;
        }
        head = (char**)head[NEXT];
    }
    return -1;
}
char** getNodeAtIndex(char*** list, int index)
{
    validateList(list);

    char**head = *list;
    int size = getStringListSize(*list);
    if(index >= size)
    {
        throw "Index out of range";
    }
    while(index--)
    {
        head = (char**)head[NEXT];
    }
    return head;
}
void sortStringList(char*** list)
{
    validateList(list);

    char** head = *list;
    while(head != NULL)
    {
        char** node = (char**)head[NEXT];
        while(node != NULL)
        {
            if(strcmp(head[DATA], node[DATA]) > 0)
            {
                char** tmp = (char**)head[DATA];
                head[DATA] = node[DATA];
                node[DATA] = (char*)tmp;
            }
            else
            {
                node = (char**)node[NEXT];
            }
        }
        head = (char**)head[NEXT];
    }
}


