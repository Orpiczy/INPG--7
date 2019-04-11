#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 2
#define MAX 10
#define ROZMIAR
int main()
{
 int tab[20]={};
 int i=0;


 printf("Dwadziescia liczb wygenerowanych losowo z zakresu od %d do %d ksztaltuja sie nastepujaco:\n", MIN, MAX);

 srand(time(NULL));

 for (i=0;tab[i]!='\0';i++)
 {
    tab[i]=(MIN+rand())%(MAX+1);

    printf("Tab[%d] jest rowna %d\n",i, tab[i]);

 }


 printf("A ich srednia wynosi\n");

    return 0;
}

