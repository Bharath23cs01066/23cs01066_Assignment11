#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeDuplicates(char *s) {
    int len = strlen(s);
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    int result_index = 0;

    for (int i = 0; i < len; i++) {
        if (result_index > 0 && result[result_index - 1] == s[i]) {
            result_index--; // Remove the last character from result
        } else {
            result[result_index++] = s[i]; // Add current character to result
        }
    }

    result[result_index] = '\0'; // Null-terminate the result string
    return result;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline character

    char *result = removeDuplicates(input);
    printf("Final string after duplicate removals: %s\n", result);
    free(result); // Free the dynamically allocated memory
    return 0;
}