#include <stdio.h>
#include <string.h>

void decodificar(char* mensagem, int deslocamento) {
    for (int i = 0; i < strlen(mensagem); i++) {
        if (mensagem[i] >= 'A' && mensagem[i] <= 'Z') {
            mensagem[i] = ((mensagem[i] - 'A' - deslocamento + 26) % 26) + 'A';
        }
    }
}

int main() {
    int N;
    scanf("%d", &N); 

    for (int i = 0; i < N; i++) {
        char mensagem[51]; 
        int deslocamento;

        scanf("%s", mensagem);
        scanf("%d", &deslocamento);

        decodificar(mensagem, deslocamento);

        printf("%s\n", mensagem);
    }

    return 0;
}