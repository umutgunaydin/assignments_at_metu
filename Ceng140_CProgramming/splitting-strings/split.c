#include <stdio.h>
#include <stdlib.h>

char** split(char* str, char delimiter) {
    int lenStr = 0;
    int i = 0;
    int firstIndexOfSubstring = 0;
    int result_index = 0;
    char* temp = str;
    int j;
    int lenOfSubstring;
    char** result;
    while (*temp != '\0') {
        if (*temp == delimiter) {
            lenStr++;
        }
        temp++;
    }

    result = (char**)malloc((lenStr + 2) * sizeof(char*));

    while (str[i] != '\0') {
        if (str[i] == delimiter) {
            int j;
            int lenOfSubstring = i - firstIndexOfSubstring;
            result[result_index] = (char*)malloc((lenOfSubstring + 1) * sizeof(char));

            for (j = firstIndexOfSubstring; j < i; j++) {
                result[result_index][j - firstIndexOfSubstring] = str[j];
            }
            result[result_index][j - firstIndexOfSubstring] = '\0';

            result_index++;
            firstIndexOfSubstring = i + 1;
        }
        i++;
    }

    lenOfSubstring = i - firstIndexOfSubstring;
    result[result_index] = (char*)malloc((lenOfSubstring + 1) * sizeof(char));

    for (j = firstIndexOfSubstring; j < i; j++) {
        result[result_index][j - firstIndexOfSubstring] = str[j];
    }
    result[result_index][j - firstIndexOfSubstring] = '\0';
    result[result_index + 1] = NULL;

    return result;
}
