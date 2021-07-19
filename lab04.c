#include <stdio.h>
#include <stdlib.h>

//Struct para armazenamento dos dados das tarefas
typedef struct Tarefa
{
    int id;
    int tempoConclusao;
} Tarefa;

//Função merge para o mergeSort
void merge(Tarefa t[], int ini, int meio, int fim)
{
    int div1 = meio - ini + 1;
    int div2 = fim - meio;

    Tarefa *v_div1 = malloc(sizeof(Tarefa) * div1);
    Tarefa *v_div2 = malloc(sizeof(Tarefa) * div2);

    for (int i = 0; i < div1; i++)
    {
        v_div1[i] = t[ini + i];
    }
    for (int i = 0; i < div2; i++)
    {
        v_div2[i] = t[meio + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = ini;
    while (i < div1 && j < div2)
    {
        if (v_div1[i].tempoConclusao <= v_div2[j].tempoConclusao)
        {
            t[k].id = v_div1[i].id;
            t[k].tempoConclusao = v_div1[i].tempoConclusao;
            i++;
        }
        else
        {
            t[k].id = v_div2[j].id;
            t[k].tempoConclusao = v_div2[j].tempoConclusao;
            j++;
        }
        k++;
    }

    while (i < div1)
    {
        t[k].id = v_div1[i].id;
        t[k].tempoConclusao = v_div1[i].tempoConclusao;
        i++;
        k++;
    }

    while (j < div2)
    {
        t[k].id = v_div2[j].id;
        t[k].tempoConclusao = v_div2[j].tempoConclusao;
        j++;
        k++;
    }
    free(v_div1);
    free(v_div2);
    return;
}

//MergeSort para ordernar as tarefas
void mergeSort(Tarefa t[], int ini, int fim)
{
    if (ini < fim)
    {
        int meio = ini + ((fim - ini) / 2);

        mergeSort(t, ini, meio);
        mergeSort(t, meio + 1, fim);

        merge(t, ini, meio, fim);
    }
    return;
}

int main()
{
    int num_tarefas;
    scanf("%d", &num_tarefas);
    Tarefa *tarefas = malloc(sizeof(Tarefa) * num_tarefas);

    //Lê as entradas
    for (int i = 0; i < num_tarefas; i++)
    {
        tarefas[i].id = i + 1;
        scanf("%d", &tarefas[i].tempoConclusao);
    }

    //Chama o mergeSort para ordenar em tempo O(n*log n)
    mergeSort(tarefas, 0, num_tarefas - 1);

    //Contabiliza o tempo total
    int tempoTotal = 0;
    int parcial = 0;
    for (int i = 0; i < num_tarefas; i++)
    {
        tempoTotal += parcial + tarefas[i].tempoConclusao;
        parcial += tarefas[i].tempoConclusao;
    }
    //Imprime os valores obtidos
    printf("%d\n", tempoTotal);
    for (int i = 0; i < num_tarefas - 1; i++)
    {
        printf("%d ", tarefas[i].id);
    }
    printf("%d\n", tarefas[num_tarefas - 1].id);
    return 0;
}