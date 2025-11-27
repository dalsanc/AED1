#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 102

void desembaralhar(char *linha) {
    int tamanho = strlen(linha);
    int meio = tamanho / 2;
    
    // Inverter a primeira metade
    for (int i = 0, j = meio - 1; i < j; i++, j--) {
        char temp = linha[i];
        linha[i] = linha[j];
        linha[j] = temp;
    }
    
    // Inverter a segunda metade
    for (int i = meio, j = tamanho - 1; i < j; i++, j--) {
        char temp = linha[i];
        linha[i] = linha[j];
        linha[j] = temp;
    }
}

int main() {
    int n;
    char linha[MAX_TAMANHO];
    
    scanf("%d", &n);
    getchar();
    
    while (n--) {
        fgets(linha, MAX_TAMANHO, stdin);
        linha[strcspn(linha, "\n")] = '\0'; 
        
        desembaralhar(linha);
        printf("%s\n", linha);
    }
    
    return 0;
}