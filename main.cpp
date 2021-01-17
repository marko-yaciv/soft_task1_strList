#include <cstdio>
#include <cstring>
#include "MyList.h"
#include "helper.h"

int main() {

    try{
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
        printf("\nSorted ");
        printStringlist(list);

        deleteStringList(&list);
    }
    catch (const char* msg)
    {
        printf("%s", msg);
        return 1;
    }
    return 0;
}
