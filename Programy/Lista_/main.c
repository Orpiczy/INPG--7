#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
union search
{
 char imie[30];
 char nazwisko[30];
 int rok_ur;
};

struct osoba
{
char imie[30];
char nazwisko[30];
int rok_ur;
};

struct lista
{
struct osoba  ktos;
struct lista* nast;
};

int add_begin(struct lista** head);
int add_middle(struct lista* head, int n);
int add_end(struct lista* head);

void delete_begin(struct lista** head);
int delete_middle(struct lista** oryg_head,int i);
int delete_end(struct lista** head);
void deleteList(struct lista** head);

struct lista* search(struct lista *head, union search element, int dezycja);
int isEqual(char*str1, char*str2);

void printList(struct lista *head);
void printElement(struct lista *elem, struct lista *head);


int main()
{
int decyzja_menu=0;
int decyzja_gl=0;
int decyzja=0;
int pow_dzial=-1;
int nr_elem;
union search element;
struct lista* elem=NULL;
struct lista* head=NULL;

printf("\nWitam w twojej prywatnej bazie osob\n\n");
printf("Stworz swoj pierwszy kontakt\n");
add_begin(&head);
do
{
    printf("Dodaj osobe(1), usun osobe(2),znajdz osobe(3), wydrukuj liste(4),wyjdz z programu(0)\n");
    scanf(" %d", &decyzja_menu);

        switch (decyzja_menu)
        {
            case 1:
            {
               printf("Na poczatku listy(1),na koncu listy(2), za elementem(3)\n");
               scanf(" %d",&decyzja_gl);
               if(decyzja_gl==1)
               {
                   pow_dzial=add_begin(&head);
                   if(pow_dzial==-1)
                   {
                       printf("\nNie udalo sie dodac wpisu\n");
                   }

                   if(pow_dzial==0)
                   {
                       printf("\nWpis zostal dodany\n");
                   }
               }
               else if(decyzja_gl==2)
               {
                   pow_dzial=add_end(head);
                   if(pow_dzial==-1)
                   {
                       printf("\nNie udalo sie dodac wpisu\n");
                   }

                   if(pow_dzial==0)
                   {
                       printf("\nWpis zostal dodany\n");
                   }
               }

               else if(decyzja_gl==3)
               {
                   printf("Jaki indeks ma miec nowy wpis\n");
                   scanf(" %d", &nr_elem);
                   pow_dzial=add_middle(head, nr_elem);
                   if(pow_dzial==-1)
                   {
                       printf("\nNie udalo sie dodac wpisu\n");
                   }
                   if(pow_dzial==0)
                   {
                       printf("\nWpis zostal dodany\n");
                   }
               }
               else
               {
                   printf("\nPodaj liczbe od 1 do 3\n");
               }

               decyzja_gl=0;
               break;
            }




            case 2:
            {
               printf("\nUsun pierwszy element(1), usun ostatni element (2), usun wskazany element (3), usun cala liste(4)\n");
               scanf(" %d",&decyzja_gl);
               if(decyzja_gl==1)
               {
                   delete_begin(&head);
                   printf("Wpis zostal usuniety\n");
               }
               else if(decyzja_gl==2)
               {
                   delete_end(&head);
                   printf("Wpis zostal usuniety\n");
               }

               else if(decyzja_gl==3)
               {
                   printf("Indeks elementu do usuniecia\n");
                   scanf(" %d", &nr_elem);
                   delete_middle(&head, nr_elem);
                   printf("Wpis zostal usuniety\n");
               }

               else if(decyzja_gl==4)
               {
                   deleteList(&head);
                   printf("Lista zostala usunieta\n");
               }
               break;
            }


            case 3:
            {
                do
                {
                elem=NULL;
                printf("Dane szukanej osoby?(imie (1),nazwisko (2), data urodzenia (3), wyjscie(0)\n");

                scanf("%d",&decyzja);

                switch (decyzja)
                {
                    case 1:
                    {
                        printf("Imie szukanej osoby\n");
                        scanf(" %s",&element.imie);
                        elem=search(head,element,decyzja);
                        if(elem==NULL)
                        {
                          printf("Nie znaleziono osoby o takim imieniu\n");
                        }
                        break;
                    }

                        case 2:
                    {
                        printf("Nazwisko szukanej osoby \n");
                        scanf(" %s",&element.nazwisko);
                        elem=search(head,element,decyzja);
                        if(elem==NULL)
                        {
                          printf("Nie znaleziono osoby o takim nazwisku\n");
                        }
                        break;
                    }

                     case 3:
                    {
                        printf("Data urodzenia szukanej osoby \n");
                        scanf(" %d",&element.rok_ur);
                        elem=search(head,element,decyzja);
                        if(elem==NULL)
                        {
                          printf("Nie znaleziono osoby o takiej dacie urodzenia\n");
                        }
                        break;
                    }
                     default:
                    {
                     printf("\nProsze wpisac cyfre od 0 do 4\n");
                    }
                }
                }while(decyzja!=0&&elem==NULL);
                printElement(elem,head);


            break;
            }


            case 4:
            {
                printList(head);
                break;
            }

            default:
            {
                printf("\nPodano bledna komende, wpisz cyfre od 0 do 4\n");
            }


        }

}while(decyzja_menu!=0);

printf("\nDziekujemy za skorzystanie z programu");
return 0;
}






int add_begin(struct lista** head)
{


struct lista* tmp=(struct lista*)calloc(1,sizeof(struct lista));
 if(tmp==NULL)
 {
 return -1;
 }

 getchar();
 printf("Podaj imie\n");
 gets((*tmp).ktos.imie);

 printf("Podaj nazwisko\n");
 gets((*tmp).ktos.nazwisko);

 printf("Podaj rok urodzenia\n");
 scanf("%d",&(*tmp).ktos.rok_ur);

 (*tmp).nast=(*head);
 (*head)=tmp;
 return 0;

}

int add_middle(struct lista* head,int n)
{
     int i;
     struct lista* wcz_elem;
     struct lista* tmp=(struct lista*)calloc(1,sizeof(struct lista));
     if(tmp==NULL)
     {
        return -1;
     }

     getchar();
     printf("Podaj imie\n");
     gets((*tmp).ktos.imie);

     printf("Podaj nazwisko\n");
     gets((*tmp).ktos.nazwisko);

     printf("Podaj rok urodzenia\n");
     scanf("%d",&(*tmp).ktos.rok_ur);

     for(i=1;(head!=NULL)&&(n!=i);head=(*head).nast,i++)
     {
         wcz_elem=head;
     }

     (*tmp).nast=(*wcz_elem).nast;
     (*wcz_elem).nast=tmp;

     return 0;

}

int add_end(struct lista* head)
{

 struct lista* wcze_element;

 for(;head!=NULL;head=(*head).nast)
 {
    wcze_element=head;
 }



 struct lista* tmp=(struct lista*)calloc(1,sizeof(struct lista));
 if(tmp==NULL)
 {
    return -1;
 }

 (*wcze_element).nast=tmp;

 getchar();
 printf("Podaj imie\n");
 gets((*tmp).ktos.imie);

 printf("Podaj nazwisko\n");
 gets((*tmp).ktos.nazwisko);

 printf("Podaj rok urodzenia\n");
 scanf("%d",&(*tmp).ktos.rok_ur);

 (*tmp).nast=NULL;
 return 0;
}

void delete_begin(struct lista** head)
{
  struct lista* tmp=(*head)->nast;
  free(*head);
  (*head)=tmp;
}
int delete_middle(struct lista** oryg_head,int i)
{
   int n=1;
   if(i==1)
   {
       delete_begin(oryg_head);
       return -1;
   }
   struct lista* head=(*oryg_head);
   struct lista* element=head;


   for(n=1;(*head).nast!=NULL&&n!=(i-1);head=(*head).nast,n++)
   {
       element=head;
   }

   head=(*(*element).nast).nast;
   free((*element).nast);
   (*element).nast=head;
   return 0;
}


int delete_end(struct lista** head)
{

 if((**head).nast==NULL)
 {
 free(*head);
 *head=NULL;
 return -1;  //syganalizuje wyzerowanie g³ównego heada
 }

struct lista* element=(*head);
struct lista* szuk_elem;

 for(;(*(*element).nast).nast!=NULL; element=(*element).nast);
 {
     szuk_elem=element;
 }
 szuk_elem=element;
 free((*szuk_elem).nast);
 (*szuk_elem).nast=NULL;

  return 0;
}

void deleteList(struct lista** head)
{
struct lista* tmp=NULL;

for(;(*head)!=NULL;*head=(**head).nast)
 {
    free(tmp);
    tmp=(*head);
 }
 free(tmp);

}

void printList(struct lista *head)
{
int n=1;

for(;head!=NULL;head=(*head).nast,n++)
 {
    printf("%d. Imie: %s\n   Nazwisko: %s\n   Data Urodzenia: %d r.\n",n,head->ktos.imie,head->ktos.nazwisko,head->ktos.rok_ur);
 }

}

void printElement(struct lista *elem, struct lista *head)
{
    int n=1;
    int i=0;
    for(;head!=NULL&&i==0;head=(*head).nast,n++)
 {
    if(head==elem)
    {
        i=1;
    }
    n--;
 }
    printf("Dane szukanej osoby\n%d. Imie: %s\n   Nazwisko: %s\n   Data Urodzenia: %d r.\n",n,elem->ktos.imie,elem->ktos.nazwisko,elem->ktos.rok_ur);
}

struct lista* search(struct lista *head, union search element, int dezycja)
{

     switch (dezycja)
{
    case 1:
    {
        for(;head!=NULL;head=(*head).nast)
        {

            if(isEqual(head->ktos.imie,element.imie)==1)
            {
                    return head;
            }
        }
        break;
    }

        case 2:
    {
         for(;head!=NULL;head=(*head).nast)
        {
            if(isEqual(head->ktos.nazwisko,element.nazwisko)==1)
                {
                    return head;
                }
        }
        break;
    }

     case 3:
    {
        for(;head!=NULL;head=(*head).nast)
        {
            if(head->ktos.rok_ur==element.rok_ur)
                {
                    return head;
                }
        }
        break;
    }
    default:
    {
       printf("Niepoprawna wartosc \"decyzja\"\n");
    }

    return NULL;
}
}

int isEqual(char *str1, char *str2)
{
    int i;


    for(i=0; str1[i]!='\0'||str2[i]!='\0'; i++)
        {

              if(str1[i]!=str2[i])
            {
                return FALSE;
            }
        }

    return TRUE;
}
