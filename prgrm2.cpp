#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isValidString(const char *str) {
    if (str == NULL) {
        return false;
    }
    
    if (strlen(str) == 0) {
        return false;
    }
    
    
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isprint(str[i])) {
            return false;
        }
    }
    
    
    return true;
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    
    input[strcspn(input, "\n")] = '\0';
    
    if (isValidString(input)) {
        printf("The input is a valid string.\n");
    } else {
        printf("The input is not a valid string.\n");
    }
    
    return 0;
}

