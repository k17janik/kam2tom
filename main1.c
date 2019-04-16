#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ROZM 100

int isEqual(char* str1, char* str2)
{
    for(int x=0; x<ROZM && str1[x] != '\0'; x++)
    {
        if(str1[x] != str2[x])
            return FALSE;
    }
    return TRUE;
}

int main()
{
    char str1[ROZM];
    char str2[ROZM];
    int wynik;
    printf("Podaj pierwszy napis:\n");
    fgets(str1, ROZM, stdin);
    printf("Podaj drugi napis:\n");
    fgets(str2, ROZM, stdin);
    wynik = isEqual(str1, str2);
    if(wynik == TRUE)
        printf("Podane napisy sa takie same.\n");
    else if(wynik == FALSE)
        printf("Podane napisy nie sa takie same.\n");
    return 0;
}
