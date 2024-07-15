#include <stdio.h>

void caesarCipher(char* text) {
    int i = 0;
    while (text[i] != '\0') {
        char ch = text[i];
        
        // Encrypt for uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = ((ch - 'A' + 3) % 26) + 'A';
        }
        // Encrypt for lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = ((ch - 'a' + 3) % 26) + 'a';
        }
        
        i++;
    }
}

int main() {
    char text[] = "Kush";
    caesarCipher(text);
    printf("Encrypted text: %s\n", text);
    return 0;
}
