#include <stdio.h>

int main() {
    int hora_inicial, minuto_inicial, hora_final, minuto_final;
    int duracao_horas, duracao_minutos;

    scanf("%d %d %d %d", &hora_inicial, &minuto_inicial, &hora_final, &minuto_final);

    int inicio = hora_inicial * 60 + minuto_inicial;
    int fim = hora_final * 60 + minuto_final;

    if (fim <= inicio) {
        fim += 24 * 60; // Adiciona 24 horas (1440 minutos) ao horário final
    }

    int duracao_total = fim - inicio;

    duracao_horas = duracao_total / 60;
    duracao_minutos = duracao_total % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_horas, duracao_minutos);

    return 0;
}
