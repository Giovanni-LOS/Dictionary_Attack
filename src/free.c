//
// Created by Giovanni on 11/6/23.
//

#include <stdlib.h>
#include "../include/free.h"

void freeUsersDataList(usersDataListNode *currentPtr) {
    usersDataListNode *tempPtr = NULL;

    while (currentPtr != NULL) {
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        free(tempPtr);
    }
}

void freeDictionaryList(dictionaryListNode *currentPtr) {
    dictionaryListNode *tempPtr = NULL;

    while (currentPtr != NULL) {
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        free(tempPtr);
    }
}