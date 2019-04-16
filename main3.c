#include <stdio.h>
#include <stdlib.h>

void deleteMatrix(double*** tab, int n)
{
    int x;
    for(x=0;x<n;x++)
    {
        free((*tab)[x]);
    }
    free(*tab);
    *tab = NULL;
    return;
}

double** createMatrix(int n)
{
    double **tab;
    int x;
    tab = malloc(n * sizeof(*tab));
    if(tab == NULL)
        return NULL;
    for(x=0;x<n;x++)
    {
        tab[x] = malloc(n * sizeof(tab));
        if(tab[x] == NULL)
        {
            deleteMatrix(&tab, x);
            return NULL;
        }
    }
    return tab;
}

void fillMatrix(double** tab, int n)
{
    int x, y, ln;
    ln = 1;
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            tab[x][y] = ln;
            ln++;
        }
    }
    return;
}

void printMatrix(double** tab, int n)
{
    int x, y;
    printf("Twoja macierz to:\n");
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            printf("%10lf", tab[x][y]);
        }
        printf("\n");
    }
}

int createContinousMatrix(double*** atab, int n)
{
    int x;
    double **tabwsk;
    double *tab;
    tabwsk = (double**)malloc(n * sizeof(double*));
    if(tabwsk == NULL)
        return -1;
    tab = (double*)malloc(n * n * sizeof(double));
    if(tab == NULL)
    {
        free(tabwsk);
        return -1;
    }
    for(x=0;x<n;x++)
        tabwsk[x] = (tab + x * n);
    *atab = tabwsk;
    return 0;
}

void deleteContinousMatrix(double*** atab)
{
    free(*atab);
    *atab = NULL;
}

int copyMatrix(double*** pdest, double** src, int n)
{
    double **dest;
    int x,y;
    createContinousMatrix(&dest, n);
    if(dest == NULL)
        return -1;
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            dest[x][y] = src[x][y];
        }
    }
    *pdest = dest;
    return 0;
}

int main()
{
    int n;
    double **macierz;
    double **new_macierz;
    printf("Podaj rozmiar macierzy:\n");
    scanf("%i", &n);
    macierz = createMatrix(n);
    if(macierz == NULL)
    {
        printf("Blad alokacji.\n");
        return -1;
    }
    fillMatrix(macierz, n);
    copyMatrix(&new_macierz, macierz, n);
    printMatrix(macierz,n);
    printMatrix(new_macierz, n);
    deleteMatrix(&macierz, n);
    deleteContinousMatrix(&new_macierz);
    return 0;
}

