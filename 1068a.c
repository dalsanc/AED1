
#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char s[MAX+1];
    while (scanf("%s", s) != EOF) {
        int n = strlen(s), top = 0;
        char st[MAX];
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st[top++] = '(';
            else if (s[i] == ')') {
                if (top == 0) { ok = 0; break; }
                top--;
            }
        }
        if (top != 0) ok = 0;
        printf("%s\n", ok ? "correct" : "incorrect");
    }
    return 0;
}
