//
// Created by Giovanni on 11/3/23.
//

#include <string.h>
#include "../include/breaking_into.h"
#include "../include/output.h"

void breakingInto(char encryptDictionary[][65], usersDataListNode *dataCurrentPtr, dictionaryListNode *dictionaryCurrentPtr, int words, char *argv[]){
    if(dataCurrentPtr == NULL){
        return;
    }
    dictionaryListNode *auxPtr = dictionaryCurrentPtr;
    while(dataCurrentPtr != NULL){
        for(int i = 0; i < words; i++){
            if(strcmp(dataCurrentPtr->crypt_password, encryptDictionary[i]) == 0){
                report(dataCurrentPtr, dictionaryCurrentPtr, argv);
            }
            dictionaryCurrentPtr = dictionaryCurrentPtr->nextPtr;
        }
        dictionaryCurrentPtr = auxPtr;
        dataCurrentPtr = dataCurrentPtr->nextPtr;
    }
}