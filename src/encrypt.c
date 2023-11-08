//
// Created by Giovanni on 11/3/23.
//

#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include "../include/encrypt.h"

void encrypt(char *password, char *encrypted_password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&encrypted_password[i * 2], "%02x", hash[i]);
    }
}

void encryptDictionaryF(dictionaryListNode *currentPtr, char encryptDictionary[][65]) {
    int i = 0;
    while (currentPtr != NULL) {
        encrypt(currentPtr->word, encryptDictionary[i]);
        currentPtr = currentPtr->nextPtr;
        i++;
    }
}