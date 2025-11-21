//FEITO POR MAISE SANTANA DOS SANTOS
#include <stdio.h>
#include <limits.h>

typedef struct Processo {
    int id;
    int chegada;
    int duracao;
    int prioridade;
    int concluido;
    int ordem;
} Processo;

int main() {

    int n;
    printf("Digite o numero de processos: ");
    scanf("%d", &n);

    Processo p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Digite chegada, duracao e prioridade do processo %d: ", p[i].id);
        scanf("%d %d %d", &p[i].chegada, &p[i].duracao, &p[i].prioridade);
        p[i].concluido = 0;
        p[i].ordem = 0;
    }

    int tempo = 0;
    int finalizados = 0;
    int ordemExecucao = 1;

    while (finalizados < n) {

        int escolhido = -1;
        int melhorPrioridade = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!p[i].concluido && p[i].chegada <= tempo) {
                if (p[i].prioridade < melhorPrioridade) {
                    melhorPrioridade = p[i].prioridade;
                    escolhido = i;
                }
            }
        }

        if (escolhido == -1) {
            tempo++;
            continue;
        }

        tempo += p[escolhido].duracao;
        p[escolhido].concluido = 1;
        p[escolhido].ordem = ordemExecucao;
        ordemExecucao++;
        finalizados++;
    }

    printf("\nTabela de Processos:\n");
    printf("ID\tChegada\tDuracao\tPrioridade\tOrdem\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\n",
               p[i].id,
               p[i].chegada,
               p[i].duracao,
               p[i].prioridade,
               p[i].ordem);
    }

    return 0;
}
