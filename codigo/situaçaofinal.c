#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* determinarSituacao(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    FILE *arquivoEntrada = fopen("alunos1.txt", "r");
    FILE *arquivoSaida = fopen("SituacaoFinal.csv", "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        perror("Erro ao abrir os arquivos");
        exit(EXIT_FAILURE);
    }

    fprintf(arquivoSaida, "Nome do Aluno,Nota Média,Situação\n");

    char nome[100], sobrenome[100];
    float nota1, nota2, media;
    while (fscanf(arquivoEntrada, "%99s %99s %f %f", nome,sobrenome, &nota1, &nota2) == 4) {
        media = (nota1 + nota2) / 2.0;
        char *situacao = determinarSituacao(media);
        fprintf(arquivoSaida, "%s %s,%.2f,%s\n", nome,sobrenome, media, situacao);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Processo concluído. Os resultados foram salvos em 'SituacaoFinal.csv'.\n");

    return 0;
}
