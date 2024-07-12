#include <stdio.h>
#include <string.h>

// Function to encrypt the plaintext using the shift key
void encrypt(char *plaintext, int key, char *ciphertext) 
{
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) 
    {
        char ch = plaintext[i];
        
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') 
        {
            ch = (ch - 'a' + key) % 26 + 'a';
        }
        ciphertext[i] = ch;
    }
    ciphertext[i] = '\0';
}

// Function to decrypt the ciphertext using the shift key
void decrypt(char *ciphertext, int key, char *plaintext) 
{
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) 
    {
        char ch = ciphertext[i];
        
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') 
        {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        }
        plaintext[i] = ch;
    }
    plaintext[i] = '\0';
}

int main() 
{
    char plaintext[100], ciphertext[100];
    int key;

    printf("Enter a plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    // Remove newline character if present
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len-1] == '\n') {
        plaintext[len-1] = '\0';
    }

    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted Text: %s\n", plaintext);
    
    return 0;
}
