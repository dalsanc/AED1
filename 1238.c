#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char str1[51], str2[51];

        scanf("%s %s", str1, str2);

        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int j = 0, k = 0;

        while (j < len1 && k < len2) {
            printf("%c%c", str1[j], str2[k]);
            j++;
            k++;
        }

        while (j < len1) {
            printf("%c", str1[j]);
            j++;
        }

        while (k < len2) {
            printf("%c", str2[k]);
            k++;
        }

        printf("\n");
    }

    return 0;
}