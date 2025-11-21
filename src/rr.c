//FEITO POR ÉRICA ELLEN ARAÚJO DE BARROS
#include <stdio.h>
#include <ctype.h> //biblioteca com função pra verificar digitos
#include <windows.h> //para usar funcao de sleep no windows

void testaDigito(int *digito); //funcao que testa entrada valida
void roundRobin(int vetor[], int tempo); //funcao que roda algoritmo round robin

int main (void)
{
    int vet_processos[5], quantum, tempoExe, i; //vetor que armazena o tempo de cada processo

    printf("======================================\n");
    printf("\tALGORITMO ROUND ROBIN\n");
    printf("======================================\n\n");
    
    printf("Defina o quantum:\n");
    testaDigito(&quantum); //Testa se a pessoa deu a entrada em inteiro!

    printf("======================================\n");
    printf("Digite o tempo de execucao de cada processo.\n");

    for (i = 0; i < 5; i++)
    {
        printf("Processo %d:\n", i + 1);
        testaDigito(&tempoExe); //Testa se a pessoa deu a entrada válida!

        vet_processos[i] = tempoExe;
    }

    printf("======================================\n");

    roundRobin(vet_processos, quantum);
    
    return 0;
}

void testaDigito(int *ptrDigito)
{
    int invalido, numero = 0, testaZero = -1, digito;
    do
    {
        invalido = 0;
        //while pra detectar se a pessoa digitou um dígito
        while (((digito = getchar()) != '\n') && (digito != EOF))
        {
            if (!isdigit(digito))
            {
                invalido = 1;
            } else {
                numero = numero * 10 + (digito - '0');
                testaZero = numero;
            }
        }

        if ((invalido) || (testaZero == 0)) //se a entrada for invalida ou 0, digite de novo
        {
            if (testaZero == 0)
            {
                printf("Valor zero invalido.\n");
            }
            
            printf("Digite o valor corretamente!\n");
            numero = 0;
            invalido = 1;

        } else {
            *ptrDigito = numero;
            return; //se estiver tudo certo, ele sai da função
        }
    } while (invalido); //sai do loop se invalido for 0
}

void roundRobin (int vetor[], int tempo) //executa algoritmo round robin
{
    int i, todosZerados = 0; //variavel que testa se todos processos ja estão concluidos
    do
    {
        for (i = 0; i < 5; i++)
        {
            if (vetor[i] != 0) //só imprime os processos pendentes
            {
                printf("Processo %d possui %dms de execucao.\n", i + 1, vetor[i]);
                printf("Quantum do processador: %d\n", tempo);
                printf("Executando.");
                for (int cont = 0; cont < 2; cont++) //pra simular a espera de 2 segundos
                {
                    Sleep(1000); //Pausa execução por 1000 milisegundos (1 segundo)
                    printf(" .");
                    if (cont == 1)
                    {
                        Sleep(1000);
                    }
                }

                printf("\n");

                vetor[i] -= tempo; //vetor diminui o quantum dele mesmo
                if (vetor[i] < 0)
                {
                    vetor[i] = 0;
                }
                printf("Tarefas do processo %d executadas por %dms, restam: %d.\n", i + 1, tempo, vetor[i]);
                printf("======================================\n");
            }
        }
        
        for (i = 0; i < 5; i++) //for que testa se todos processos já executaram
        {
            if (vetor[i] != 0)
            {
                todosZerados = 0;
                break;
            }
            todosZerados = 1; //se todos estiverem zerados, recebe 1
        }

    } while (!todosZerados); //loop roda enquanto todos não estiverem zerados 

    printf("Todos processos foram finalizados com sucesso.\n");
    printf("======================================\n");
    printf("\tFIM ROUND ROBIN\n");
    printf("======================================\n\n");

    return;
}
