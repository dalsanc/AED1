#include <stdio.h>

void calcular_duracao(int hora_inicial, int minuto_inicial, int hora_final, int minuto_final) {
    int inicio = hora_inicial * 60 + minuto_inicial;
    int fim = hora_final * 60 + minuto_final;
    
    if (fim <= inicio) {
        fim += 24 * 60; 
    }
    
    int duracao_total = fim - inicio;
    int horas = duracao_total / 60;
    int minutos = duracao_total % 60;
    
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);
}

int main() {
    int hora_inicial, minuto_inicial, hora_final, minuto_final;
    scanf("%d %d %d %d", &hora_inicial, &minuto_inicial, &hora_final, &minuto_final);
    calcular_duracao(hora_inicial, minuto_inicial, hora_final, minuto_final);
    return 0;
}