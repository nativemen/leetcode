#include <stdio.h>

char *addBinary(char *a, char *b) {
    int size1 = strlen(a);
    int size2 = strlen(b);
    int size = (size1 > size2) ? size1 + 1 : size2 + 1;
    char *result = (char *)calloc(size + 1, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int carry = 0;
    int index1 = size1 - 1;
    int index2 = size2 - 1;
    int index3 = size - 1;

    while (index1 >= 0 && index2 >= 0) {
        int num = a[index1--] - '0' + b[index2--] - '0' + carry;
        result[index3--] = ((num & 1) == 0) ? '0' : '1';
        carry = num >> 1;
    }

    if (index1 >= 0) {
        while (index1 >= 0) {
            int num = a[index1--] - '0' + carry;
            result[index3--] = ((num & 1) == 0) ? '0' : '1';
            carry = num >> 1;
        }
    } else {
        while (index2 >= 0) {
            int num = b[index2--] - '0' + carry;
            result[index3--] = ((num & 1) == 0) ? '0' : '1';
            carry = num >> 1;
        }
    }

    if (carry > 0) {
        result[index3] = '1';
    } else {
        for (int i = 0; i < size - 1; i++) {
            result[i] = result[i + 1];
        }
        result[size - 1] = '\0';
    }

    return result;
}

char *addBinary(char *a, char *b) {
    int size1 = strlen(a);
    int size2 = strlen(b);
    int size = (size1 > size2) ? size1 + 1 : size2 + 1;
    char *result = (char *)calloc(size + 1, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int carry = 0;
    int index1 = size1 - 1;
    int index2 = size2 - 1;
    int index3 = size - 1;

    while (index1 >= 0 || index2 >= 0 || carry > 0) {
        int digit1 = (index1 >= 0) ? a[index1--] - '0' : 0;
        int digit2 = (index2 >= 0) ? b[index2--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[index3--] = ((sum & 1) == 0) ? '0' : '1';
        carry = sum >> 1;
    }

    if (index3 == 0) {
        char *newResult = (char *)calloc(size, sizeof(char));
        if (newResult == NULL) {
            free(result);
            return NULL;
        }
        strcpy(newResult, result + 1);
        free(result);
        return newResult;
    }

    return result;
}