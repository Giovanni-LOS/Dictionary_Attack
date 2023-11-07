//
// Created by Giovanni on 11/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/input.h"


void insertUsersData(usersDataListNode **sPtr,const char full_name[],const char birth_date[],const char login[],const char crypt_password[],const char last_change[]) {
    usersDataListNode *newPtr = malloc(sizeof(usersDataListNode));
    if (newPtr != NULL) {
        strcpy(newPtr->full_name, full_name);
        strcpy(newPtr->birth_date, birth_date);
        strcpy(newPtr->login, login);
        strcpy(newPtr->crypt_password, crypt_password);
        strcpy(newPtr->last_change, last_change);
        newPtr->nextPtr = NULL;
        usersDataListNode *previousPtr = NULL;
        usersDataListNode *currentPtr = *sPtr;
        while (currentPtr != NULL) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (previousPtr == NULL) {
            newPtr->nextPtr = NULL;
            *sPtr = newPtr;
        } else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    } else {
        puts("Not inserted. No memory available.");
    }
}

void readUsersData(usersDataListNode **sPtr, char *argv[]) {
    FILE *filePtr = NULL;
    int len = strlen(argv[1]);
    char path[len + 1];
    strcpy(path, argv[1]);
    if (( filePtr = fopen(path, "r")) == NULL) {
        puts("File could not be opened.");
        return;
    }
    while (!feof(filePtr))
    {
        char full_name[51];
        fscanf(filePtr, "%50[^\n]\n", full_name);
        char birth_date[11];
        fscanf(filePtr, "%10[^\n]\n", birth_date);
        char login[21];
        fscanf(filePtr, "%20[^\n]\n", login);
        char crypt_password[65];
        fscanf(filePtr, "%64[^\n]\n", crypt_password);
        char last_change[11];
        fscanf(filePtr, "%10[^\n]\n", last_change);
        char line_break[4];
        fscanf(filePtr, "%3[^\n]\n", line_break);
        insertUsersData(sPtr, full_name, birth_date, login, crypt_password, last_change);
    }
    fclose(filePtr);
}

void insertDictionaryWords(dictionaryListNode **sPtr,const char word[]) {
    dictionaryListNode *newPtr = malloc(sizeof(dictionaryListNode));
    if (newPtr != NULL) {
        strcpy(newPtr->word, word);
        newPtr->nextPtr = NULL;
        dictionaryListNode *previousPtr = NULL;
        dictionaryListNode *currentPtr = *sPtr;
        while (currentPtr != NULL) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (previousPtr == NULL) {
            newPtr->nextPtr = NULL;
            *sPtr = newPtr;
        } else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    } else {
        puts("Not inserted. No memory available.");
    }
}

int readDictionary(dictionaryListNode **sPtr, char *argv[]) {
    FILE *filePtr = NULL;
    int words = 0;
    int len = strlen(argv[2]);
    char path[len + 1];
    strcpy(path, argv[2]);
    if (( filePtr = fopen(path, "r")) == NULL) {
        puts("File could not be opened.");
    }
    while (!feof(filePtr))
    {
        char word[33];
        fscanf(filePtr, "%32[^\n]\n", word);
        words++;
        insertDictionaryWords(sPtr, word);
    }
    fclose(filePtr);
    return words;
}


