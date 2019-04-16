#include <stdio.h>
#include <stdlib.h>
#define ROZM 6

int main()
{
    int roz;
    roz = ROZM;
    int start, end, x;
    start  = 0;
    end = roz - 1;
    int tab[ROZM] = {6, 2, 3, 4, 5, 1};
    zamiana(tab, start, end);
    for(x=0;x<roz;x++)
        printf("%i\n", tab[x]);
    printf("Hello world!\n");
    return 0;
}
 void zamiana(int *tab, int s, int e)
 {
     int y;
     if(s == e)
        return 0;
     y = tab[s];
     tab[s] = tab[e];
     tab[e] = y;
     if(s == e+1)
        return 0;
     zamiana(tab, s+1, e-1);
 }
