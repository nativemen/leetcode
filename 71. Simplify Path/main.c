#include <stdio.h>

char *simplifyPath(char *path) {
    size_t size = strlen(path) + 1;
    char **stack = (char **)calloc(size, sizeof(char *));
    size_t top = 0;
    char *saveptr = NULL;
    char *delimiter = "/";
    char *token = strtok_r(path, delimiter, &saveptr);

    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
        } else if (strcmp(token, "..") == 0) {
            if (top > 0) {
                top--;
            }
        } else {
            stack[top++] = token;
        }

        token = strtok_r(NULL, delimiter, &saveptr);
    }

    char *result = (char *)calloc(size, sizeof(char));

    for (size_t i = 0; i < top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    if (top == 0) {
        strcat(result, "/");
    }

    free(stack);

    return result;
}