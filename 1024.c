#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINHAS 10000
#define MAX_TAMANHO 1000

void primeira_passada(char *linha) {
    for (int i = 0; linha[i] != '\0'; i++) {
        if (isalpha(linha[i])) {
            linha[i] += 3;
        }
    }
}

void inverter_string(char *linha) {
    int tamanho = strlen(linha);
    for (int i = 0, j = tamanho - 1; i < j; i++, j--) {
        char temp = linha[i];
        linha[i] = linha[j];
        linha[j] = temp;
    }
}

void terceira_passada(char *linha) {
    int tamanho = strlen(linha);
    for (int i = tamanho / 2; i < tamanho; i++) {
        linha[i]--;
    }
}

int main() {
    int n;
    char linha[MAX_TAMANHO + 1];
    
    scanf("%d", &n);
    getchar();
    
    while (n--) {
        fgets(linha, MAX_TAMANHO + 1, stdin);
        linha[strcspn(linha, "\n")] = '\0';
        
        primeira_passada(linha);
        inverter_string(linha);
        terceira_passada(linha);
        
        printf("%s\n", linha);
    }
    
    return 0;
}