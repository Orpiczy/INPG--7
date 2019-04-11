#include <stdio.h>
#include <stdlib.h>

struct wpis
{
char imie[30];
char nazwisko[30];
long nr_tel;
};

struct baza
{
long maks_rec;
long akt_rec;
struct wpis* a_wpis;
};


int dodaj(struct baza* ksiazka_tel,struct wpis*a);
void usun(struct baza* ksiazka_tel,int wpis);
void wypisz(struct baza *ksiazka_tel);




int main()
{
struct wpis a;
struct baza ksiazka_tel=
{
.maks_rec=10,
.akt_rec=0,
.a_wpis=calloc(10,sizeof(struct wpis))
};

char wybor;
int u_wpis;
int rezultat=-1; //czy operacja udala sie czy nie

printf("\nWitam w twojej osobistej ksiazce telefonicznej\n\n");

do
{
   printf("\nDodanie wpisu [d], usuniecie wpisu[u], wypisanie ksiazki telefonicznej[w], wyjscie z programu[e]\n");
   scanf(" %c",&wybor);

   switch (wybor)
   {

   case 'd':
   {

        printf("\nPodaj imie nowego kontaktu:\n");
        getchar();
        gets(a.imie);

        printf("Podaj nazwisko nowego kontaktu:\n");
        gets(a.nazwisko);

        printf("Podaj numer telefonu nowego kontaktu:\n");
        scanf("%ld", &a.nr_tel);

        rezultat=dodaj(&ksiazka_tel,&a);
        if(rezultat==-1)
        {
            printf("Niestety blad alokacji pamieci, nie udalo sie dodac nowego kontaktu\n");
        }
        else
        {
            printf("Nowy kontakt zostal pomyslnie dodany\n");
        }
        break;
   }

   case 'u':
   {
       printf("\nKtorego kontaktu chcialbys/chcialabys sie pozbyc z listy kontaktow?(podaj numer wpisu)\n");
       scanf("%d",&u_wpis);

       usun(&ksiazka_tel, u_wpis);

       printf("\nProces usuniecia kontaktu przebiegl pomyslnie");
       break;

   }

   case 'w':
   {
       wypisz(&ksiazka_tel);
       break;
   }
   }




}while(wybor!='e');

printf("Dziekujemy za skorzystanie z naszego programu");

return 0;
}

int dodaj(struct baza* ksiazka_tel,struct wpis* a)
{

if((*ksiazka_tel).maks_rec<=(*ksiazka_tel).akt_rec)
{
   (*ksiazka_tel).a_wpis=realloc((*ksiazka_tel).a_wpis,((*ksiazka_tel).akt_rec+10) * sizeof(struct wpis));//przydzielanie pamieci na wpis
   (*ksiazka_tel).maks_rec+=10;
    if((*ksiazka_tel).a_wpis==NULL)
    {
        return -1;
    }
}


(*ksiazka_tel).a_wpis[(*ksiazka_tel).akt_rec]= *a; //dodawanie wpisu
(*ksiazka_tel).akt_rec++;

return 0;
}



void usun(struct baza *ksiazka_tel,int wpis)
{
 wpis--;  //wpisy nie sa liczone od zera

 for(wpis;wpis<((*ksiazka_tel).akt_rec-1);wpis++)
 {
    (*ksiazka_tel).a_wpis[wpis]= (*ksiazka_tel).a_wpis[wpis+1];
 }

 (*ksiazka_tel).akt_rec--;

}


void wypisz(struct baza *ksiazka_tel)
{
    int n;

    printf("\nKsiazka telefonicza:\n");

    for(n=0;n<(*ksiazka_tel).akt_rec;n++)
    {
        printf("%d.%s %s \n  tel:%ld\n",n+1,(*ksiazka_tel).a_wpis[n].imie,(*ksiazka_tel).a_wpis[n].nazwisko,(*ksiazka_tel).a_wpis[n].nr_tel);
    }


}
