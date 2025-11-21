//FEITO POR RAYANE GABRIELLE CASTRO CARDOSO
#include <stdio.h>

int main() {
    int n, i;

    printf("Quantos processos? ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Digite o Burst Time de cada processo:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcesso\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
