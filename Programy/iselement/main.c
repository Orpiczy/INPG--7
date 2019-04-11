#include <stdio.h>
#include <stdlib.h>
#define ROZMIAR 200
char *iselement(char *tab, char znak);

int main()
{
    char napis[ROZMIAR];
    char znak;
    char *odp;

    printf("\nWitam w programie sprawdzajacym czy podany napis zawiera wskazany znak\n\n");
    printf("Prosze wpisac napis ktory chcialbys\\chcialabys sprawdzic:\n");
    fgets(napis,200,stdin);
    printf("A teraz szukany znak:\n");
    scanf("%c", &znak);
    odp=iselement(napis,znak);

    if(odp!=NULL)
    {
            printf("Sprawdzany napis zawiera szukany znak \"%c\"",*odp);
    }

    else
    {
            printf("Sprawdzany napis nie zawiera szukanego znaku");
    }



    return 0;
}





char *iselement(char *tab, char znak)
{
 int i=0;

 for(i=0;tab[i]!='\0';i++)
 {
     if(tab[i]==znak)
     {
          return &tab[i];
     }
 }



     return NULL;


}





