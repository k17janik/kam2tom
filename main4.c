#include <stdio.h>
#include <stdlib.h>
#define ROW1 2
#define COL1 5
#define ROW2 5
#define COL2 2

int main()//b³¹d w tej linijce//
{
    float taba[ROW1][COL1] =
    {
        { 1,0,2 },
        { -1,3,1}
    }
    float tabb[ROW2][COL2] =
    {
        { 3,1 },
        { 2,1 },
        { 1,0 }
    }
    float tabc[ROW1][COL2] = {};
    float iloczyn;
    iloczyn = 0;
    int x,y,z;
    for(x=0;x<ROW1;x++)
    {
        for(y=0;y<COL2;y++)
        {
            for(z=0;z<COL1;z++)
            {
                iloczyn = taba[x][z] * tabb[z][y];
                tabc[x][y] = tabc[x][y] + iloczyn;
            }
        }
    }
    printf("Wynik mnozenia dwoch macierzy to:\n");
    for(x=0;x<ROW1;x++)
    {
        for(y=0;y<COL2;y++)
        {
            printf("%9f", tabc[x][y]);
        }
        printf("\n");
    }
    return 0;
}
