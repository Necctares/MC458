#include <stdio.h>
#include <stdlib.h>

//Implementação do countingSort, onde será chamada para ordenar v[] para cada ordem pelo radixSort.
void countingSort(int v[], int tamanho, int ordem)
{
    int *resultado = malloc(sizeof(int) * tamanho);
    int contagem[10]; //Armazena a contagem de cada digito

    //Zera o vetor contagem
    for (int i = 0; i < 10; i++)
    {
        contagem[i] = 0;
    }

    //Conta a ocorrencia de cada digito
    for (int i = 0; i < tamanho; i++)
    {
        contagem[(v[i] / ordem) % 10] += 1;
    }

    //Atualiza a contagem com o somatorio das ocorrencias das posições antecedentes
    for (int i = 1; i < 10; i++)
    {
        contagem[i] += contagem[i - 1];
    }

    //Coloca os elementos em sua posição correta usando a contagem
    for (int i = (tamanho - 1); i >= 0; i--)
    {
        resultado[contagem[(v[i] / ordem) % 10] - 1] = v[i];
        contagem[(v[i] / ordem) % 10] -= 1;
    }

    //Copia o vetor ordenado para o vetor original
    for (int i = 0; i < tamanho; i++)
    {
        v[i] = resultado[i];
    }
    free(resultado);
    return;
}

//Implementação do RadixSort
void radixSort(int v[], int tamanho)
{
    //Pega o valor maximo do vetor v[]
    int maximo = v[0];
    for (int i = 0; i < tamanho; i++)
    {
        if (v[i] > maximo)
        {
            maximo = v[i];
        }
    }

    //Chama o countingSort para cada digito. Onde i é a ordem atual (Unidade, dezena, centena, ...) na base decimal.
    for (int i = 1; (maximo / i) > 0; i *= 10)
    {
        countingSort(v, tamanho, i);
    }
    return;
}

int main()
{
    int tamanho;
    //Lê a entrada
    scanf("%d", &tamanho);
    int *v = malloc(sizeof(int) * tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        scanf(" %d", &v[i]);
    }
    //Chama o radixSort para ordenar o vetor
    radixSort(v, tamanho);
    //Printa a saida
    for (int i = 0; i < (tamanho - 1); i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[tamanho - 1]);
    free(v);
    return 0;
}