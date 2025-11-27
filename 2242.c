#include <stdio.h>
#include <string.h>

int main() {
    char laugh[51];
    scanf("%s", laugh);

    char vowels[51];
    int idx = 0;

    for (int i = 0; i < strlen(laugh); i++) {
        if (laugh[i] == 'a' || laugh[i] == 'e' || laugh[i] == 'i' || laugh[i] == 'o' || laugh[i] == 'u') {
            vowels[idx++] = laugh[i];
        }
    }

    int is_palindrome = 1;
    for (int i = 0; i < idx / 2; i++) {
        if (vowels[i] != vowels[idx - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}