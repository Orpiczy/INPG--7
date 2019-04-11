#include <stdio.h>
#include <stdlib.h>
int bin(int x);

int main()
{
   int x=0;


   printf("Witam w programie wypisujacym podana liczbe w postaci binarnej\nProsze o wprowadzenie liczby:\n");
   scanf("%d",&x);

   printf("\nLiczba %d w postaci binarnej wyglada nastepujaco:\n",x);
   bin(x);


    return 0;
}

int bin(x)
{
    if (x!=0)
    {

         switch (x%2)
         {
            case 0:
            {

                bin(x/2);
                printf("0");
                break;
            }


            case 1:
            {
                bin(x/2);
                printf("1");
                break;
            }
         }
     }

    else
    {
        return 1;
    }


 }
