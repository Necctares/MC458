#include <stdio.h>
#define TAMANHO_MAX 100 //Tamanho Maximo do numero de elementos da Sequencia.

/*Função para achar a Subsequencia consecutiva maxima. Considerando as operações basicas como constantes, então
a função será O(n), pois precisamos apenas executar um unico laço percorrendo o vetor com n elementos uma unica vez.*/
double acharSubseqConsecMax(double elementos[], int tamSeq)
{
    //Variaveis para armazenar o valor maximo achado, o max da subsequencia atual e o minimo da subseq. atual.
    //Como o produto de uma subsquencia vazia foi definido como 1, então valorMax começa em 1.
    double valorMax = 1, maxAtual = 0, minAtual = 0;
    //Percorremos uma unica vez o vetor.
    for (int i = 0; i < tamSeq; i++)
    {
        //Variavel auxiliar p/ armazenar o maxAtual antes de troca-lo.
        double aux = maxAtual;

        /*Considerando que podemos ter uma multiplicação entre (+)*(+), (+)*(-) ou (-)*(-) e numeros entre 0<x<1 que diminuem o valor total do produto,
        procuramos o valor maximo atual, entre, (maxAtual*elementos[i]), (minAtual*elementos[i]) e o proprio elementos[i].*/
        if ((maxAtual * elementos[i]) >= (minAtual * elementos[i]) && (maxAtual * elementos[i]) >= elementos[i])
        {
            maxAtual = (maxAtual * elementos[i]);
        }
        else if ((minAtual * elementos[i]) >= (maxAtual * elementos[i]) && (minAtual * elementos[i]) >= elementos[i])
        {
            maxAtual = (minAtual * elementos[i]);
        }
        else
        {
            maxAtual = elementos[i];
        }

        //Usando a mesma logica do maxAtual, procuramos agora atualizar o valor minimo.
        if ((aux * elementos[i]) <= (minAtual * elementos[i]) && (aux * elementos[i]) <= elementos[i])
        {
            minAtual = (aux * elementos[i]);
        }
        else if ((minAtual * elementos[i]) <= (aux * elementos[i]) && (minAtual * elementos[i]) <= elementos[i])
        {
            minAtual = (minAtual * elementos[i]);
        }
        else
        {
            minAtual = elementos[i];
        }

        //Caso o maximo atual seja maior que o maximo total, atualizamos o valorMax.
        if (maxAtual > valorMax)
        {
            valorMax = maxAtual;
        }
    }
    return valorMax;
}

int main()
{
    //Variaveis para armazenar o tamanho da sequencia e os elementos da mesma.
    int tamSeq;
    double elementos[TAMANHO_MAX];
    //Lê a entrada.
    scanf("%d", &tamSeq);
    for (int i = 0; i < tamSeq; i++)
    {
        scanf(" %lf", &elementos[i]);
    }
    //Chama a função para achar a subseq. consecutiva maxima e imprime seu resultado.
    printf("%lf\n", acharSubseqConsecMax(elementos, tamSeq));
    return 0;
}