#include "stdio.h"
#include "string.h"
#include "MyList.h"
#define MAX_LEN 30

void readWord(const char* textToAsk, char* word){
    printf_s(textToAsk);
    fgets(word,MAX_LEN,stdin);
}
void readStrings(char***list){
    printf("Enter string to add (or <q> to comit):\n");
    char word[MAX_LEN] = "";

    while(strcmp(fgets(word,MAX_LEN,stdin), "q\n") != 0){
        addNodeToStringList(list,word);
    }
}
void readWordAndGetIndex(char**list){
    char word[MAX_LEN] = "";
    readWord("Enter word to get index:\n", word);

    int index = getIndexOfStringInStringList(list,word);
    if(index >= 0)
        printf("Index is: %d\n", index);
    else
        printf("No such word in list\n");
}
void readWordAndRemove(char*** list){
    char word[MAX_LEN] = "";
    readWord("Enter word to remove:\n",word);
    removeNodeFromStringList(list,word);
}
void readWordAndReplace(char*** list){
    char word1[MAX_LEN] = "";
    char word2[MAX_LEN] = "";
    readWord("Enter word to be replaced: ",word1);
    readWord("Enter word to replace with: ",word2);

    if(!replaceWith(list,word1,word2)){
        printf("Cannot replace!\n");
    }
}

int main() {
    char ** list = NULL;
    initStringList(&list);

    readStrings(&list);
    printStringlist(list);
    printf("Size of list is: %d\n", getStringListSize(list));

    readWordAndGetIndex(list);
    readWordAndRemove(&list);

    printStringlist(list);
    printf("Size of list is: %d\n", getStringListSize(list));

    readWordAndReplace(&list);
    printStringlist(list);

    sortStringList(&list);
    printf("Sorted ");
    printStringlist(list);

    deleteStringList(&list);
    return 0;
}
