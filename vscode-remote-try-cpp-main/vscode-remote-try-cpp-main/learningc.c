
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONSTANT 250

int main() {
    char input[CONSTANT];
    char *tokens[CONSTANT];
    int i = 0;

    printf("Enter String: ");
    fgets(input, CONSTANT, stdin);

    // Remove newline
    int j = 0;
    while (input[j] != '\0') {
        if (input[j] == '\n') {
            input[j] = '\0';
        }
        j++;
    }

    char *token = strtok(input, " ");
    while (token != NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    int k;
    for (k = 0; k < i; k++) {
        printf("Token[%d] = %s\n", k, tokens[k]);
    }

    for (k = 0; k < i; k++) {
        free(tokens[k]);
    }

    return 0;
}