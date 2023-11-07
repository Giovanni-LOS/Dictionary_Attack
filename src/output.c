//
// Created by Giovanni on 11/3/23.
//

#include <stdio.h>
#include <string.h>
#include "include/output.h"
#include "include/input.h"

void report(usersDataListNode *dataCurrentPtr, dictionaryListNode *dictionaryCurrentPtr, char *argv[]) {
    FILE *reportPtr = NULL;
    int len = strlen(argv[3]);
    char path[len + 1];
    strcpy(path, argv[3]);
    reportPtr = fopen(path, "r+");
    if (reportPtr == NULL) {
        reportPtr = fopen(path, "w");
        if(reportPtr == NULL){
            printf("Error opening file\n");
            return;
        }
    }
    fseek(reportPtr, 0, SEEK_END);
    fprintf(reportPtr, "%s\n", dataCurrentPtr->login);
    fprintf(reportPtr, "%s\n", dictionaryCurrentPtr->word);
    fprintf(reportPtr, "%s\n", dataCurrentPtr->full_name);
    fprintf(reportPtr, "%s\n", dataCurrentPtr->birth_date);
    fprintf(reportPtr, "---\n");
    fclose(reportPtr);
}


