//
// Created by Marko on 17.01.2021.
//

#ifndef TASK1_STRLIST_HELPER_H
#define TASK1_STRLIST_HELPER_H
#define MAX_LEN 30

/*HELPER FUNCTIONS FOR USER INPUT/OUTPUT */
void readWord(const char* textToAsk, char* word)
{
    printf_s(textToAsk);
    fflush(stdin);
    fgets(word,MAX_LEN,stdin);
}
void readStrings(char***list)
{
    printf("Enter string to add (or <q> to commit):\n");
    char word[MAX_LEN] = "";

    while(strcmp(fgets(word,MAX_LEN,stdin), "q\n") != 0)
    {
        addNodeToStringList(list,word);
    }
}
void readWordAndGetIndex(char**list)
{
    char word[MAX_LEN] = "";
    while(true)
    {
        readWord("Enter word to get index:\n", word);
        int index = getIndexOfStringInStringList(list,word);

        if(index >= 0)
        {
            printf("Index is: %d\n", index);
            break;
        }
        else
        {
            printf("No such word in list\n");
            printf("Try again?(y/n): ");
            auto c = getchar();
            if(c == 'n' || c == 'N')
            {
                break;
            }
        }
    }

}
void readWordAndRemove(char*** list){
    char word[MAX_LEN] = "";
    while(true)
    {
        readWord("Enter word to remove:\n",word);
        int res = removeNodeFromStringList(list,word);
        if(res == -1)
        {
            printf("Nothing to remove!\n");
            printf("Try again?(y/n): ");
            auto c = getchar();
            if(c == 'n' || c == 'N')
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

}
void readWordAndReplace(char*** list){
    char word1[MAX_LEN] = "";
    char word2[MAX_LEN] = "";
    while(true)
    {
        readWord("Enter word to be replaced: ",word1);
        readWord("Enter word to replace with: ",word2);

        if(!replaceWith(list,word1,word2))
        {
            printf("Cannot replace!\n");
            printf("Try again?(y/n): ");
            auto c = getchar();
            if(c == 'n' || c == 'N')
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

#endif //TASK1_STRLIST_HELPER_H
