#include <stdio.h>
#include <stdlib.h>

typedef struct Valores
{
    int valor;
    int x;
    int y;
} Valores;

Valores **inicializar_valores(int n)
{
    Valores **novo = malloc(sizeof(Valores) * n);
    for (int i = 0; i < n; i++)
    {
        novo[i] = malloc(sizeof(Valores) * n);
    }
    return novo;
}

void printar_colunas(Valores v, Valores **moedas, int jMax)
{
    if(v.x == -1){
        printf("%d ", jMax);
        return;
    }
    printar_colunas(moedas[v.x][v.y], moedas, v.y);
    printf("%d ", jMax);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    Valores **moedas = inicializar_valores(n);

    for (int i = 0; i < n; i++)
    {
        moedas[0][i].valor = 0;
        moedas[0][i].x = -1;
        moedas[0][i].y = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            moedas[i][j].valor = -999;
        }
    }

    int entradas = (n - 1) * (4 + 3 * (n - 2));
    int rx, cx, ry, cy, p;
    for (int i = 0; i < entradas; i++)
    {
        scanf("%d %d %d %d %d", &rx, &cx, &ry, &cy, &p);
        if (moedas[ry][cy].valor < (moedas[rx][cx].valor + p))
        {
            moedas[ry][cy].valor = moedas[rx][cx].valor + p;
            moedas[ry][cy].x = rx;
            moedas[ry][cy].y = cx;
        }
    }

    Valores maxAtual = moedas[n - 1][0];
    int jMax = 0;
    for (int i = 1; i < n; i++)
    {
        if (maxAtual.valor < moedas[n - 1][i].valor)
        {
            maxAtual = moedas[n - 1][i];
            jMax = i;
        }
    }
    printf("%d\n", maxAtual.valor);

    printar_colunas(moedas[maxAtual.x][maxAtual.y], moedas, maxAtual.y);
    printf("%d\n", jMax);
    return 0;
}