//
// Created by Giovanni on 11/3/23.
//

#ifndef DICTIONARY_ATTACK_ENCRYPT_H
#define DICTIONARY_ATTACK_ENCRYPT_H

#include "../include/input.h"

void encrypt(char *password, char *encrypted_password);
void encryptDictionaryF(dictionaryListNode *currentPtr, char encryptDictionary[][65]);

#endif //DICTIONARY_ATTACK_ENCRYPT_H
