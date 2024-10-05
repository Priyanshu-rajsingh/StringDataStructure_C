#include <stdio.h>
#include <stdlib.h>

char* DynamicString(int *);

int main() {
    int i = 0; // Initialize i to 0
    char *str = DynamicString(&i); // Pass the address of i

    if (str != NULL) { // Check if memory allocation was successful
        printf("You entered: %s\n", str);
        free(str); // Free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

char* DynamicString(int *i) {
    *i = 0; // Initialize the counter
    char c, *str = (char *)malloc(sizeof(char)), *temp; // Allocate initial memory
    temp = str;
    if (str == NULL) {
        return NULL; // Check for allocation failure
    }
    str[*i] = '\0'; // Null-terminate the string

    while ((c = getchar()) != '\n' && c != EOF) { // Read characters until newline or EOF
        temp = (char *)realloc(str, ((*i) + 2) * sizeof(char)); // Reallocate memory
        if (temp == NULL) {
            free(str); // Free the original memory on failure
            return NULL; // Return NULL on failure
        }
        str = temp; // Update str only if realloc was successful
        str[(*i)++] = c; // Store the character and increment the counter
    }
    str[*i] = '\0'; // Null-terminate the string
    return str; // Return the dynamic string
}
