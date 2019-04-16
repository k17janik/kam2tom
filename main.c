#include <stdio.h>
#include <stdlib.h>
#define ROZM 10

int *compress(double ** a_table, int *a_size);

int main()
{
    double *tab;
    int x; int rozmtab;
    rozmtab = 0;
    tab = calloc(ROZM, sizeof(*tab));
    if(tab == NULL)
        return 0;
    tab[2] = 3.0;
    tab[5] = 1.0;
    tab[8] = 7.0;
    compress(&tab, &rozmtab);
    for(x=0;x<ROZM;x++)
    {
        printf("%lf\n", tab[x]);
    }
    return 0;
}

int *compress(double ** a_table, int *a_size)
{
    int y, z;
    z = 0;
    double *tab_el;
    int *tab_i;
    for(y=0;y<ROZM;y++)
    {
        if((*a_table)[y] != 0)
            *a_size ++;
    }
    tab_el = malloc(*a_size * sizeof(*a_size));
    if(tab_el == NULL)
        return NULL;
    tab_i = malloc(*a_size * sizeof(*a_size));
    if(tab_i == NULL)
        return NULL;
    for(y=0;y<ROZM;y++)
    {
        if((*a_table)[y] != 0)
        {
            tab_el[z] = (*a_table)[y];
            z++;
        }
    }
    z = 0;
    for(y=0;y<ROZM;y++) //petla for robiaca cos//
    {
        if((*a_table)[y] != 0)
        {
            tab_i[z] = y;
            z++;
        }
    }
    free(a_table);
    *a_table = *tab_i;
    return tab_i;
}
