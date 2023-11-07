//
// Created by Giovanni on 11/3/23.
//

#ifndef DICTIONARY_ATTACK_INPUT_H
#define DICTIONARY_ATTACK_INPUT_H

struct usersDataListNode {
    char full_name[51];
    char birth_date[11];
    char login[21];
    char crypt_password[65];
    char last_change[11];
    struct usersDataListNode *nextPtr;
};

struct dictionaryListNode {
    char word[33];
    struct dictionaryListNode *nextPtr;
};

typedef struct usersDataListNode usersDataListNode;
typedef struct dictionaryListNode dictionaryListNode;

void readUsersData(usersDataListNode **sPtr, char *argv[]);
int readDictionary(dictionaryListNode **sPtr, char *argv[]);

#endif //DICTIONARY_ATTACK_INPUT_H
