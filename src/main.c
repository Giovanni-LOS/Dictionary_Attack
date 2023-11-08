//
// Created by Giovanni on 11/3/23.
//
#include <stdio.h>
#include "../include/input.h"
#include "../include/encrypt.h"
#include "../include/breaking_into.h"
#include "../include/free.h"

int main (int argc, char *argv[]){

    usersDataListNode *dataStartPtr = NULL;
    dictionaryListNode *dictionaryStartPtr = NULL;
    readUsersData(&dataStartPtr, argv);
    int words = readDictionary(&dictionaryStartPtr, argv);
    char encryptDictionary[words][65];
    encryptDictionaryF(dictionaryStartPtr, encryptDictionary);
    breakingInto(encryptDictionary, dataStartPtr, dictionaryStartPtr, words, argv);
    freeUsersDataList(dataStartPtr);
    freeDictionaryList(dictionaryStartPtr);
    return 0;
}
