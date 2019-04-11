#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FALSE NULL
float* funk_kwadr( float a, float b, float c, float *tab);


int main()
{
    float a;
    float b;
    float c;
    float O[2];
    float *ptr;


    printf("Witaj w programie wyznaczajacym miejsca zerowe:\n");
    printf("Podaj wspolczynnik a:\n");
    scanf("%f", &a);
    printf("Podaj wspolczynnik b:\n");
    scanf("%f", &b);
    printf("Podaj wspolczynnik c:\n");
    scanf("%f", &c);
    printf("Podana funkcja wyglada nastepujaco:\n%.1fx^2+%.1fx+%.1f\n",a,b,c);

    ptr=funk_kwadr( a, b, c, O);

    if( ptr!=NULL)
    {
        if(ptr[0]==ptr[1])
        {
            printf("Podana funkcja kwadratowa ma jedno miejsce zerowe rowne %f", ptr[0]);
        }
        else
            printf("Podana funkcja ma dwa miejsca zerowe %f i %f", ptr[0], ptr[1]);

    }
    else
    {
        printf("Podana funkcja nie posiada niestety miejsc zerowych dla delty nalezacej do liczb rzeczywistych");
    }

    return 0;
}



float* funk_kwadr( float a, float b, float c, float *tab)
{

    float delta;

    delta=(b*b)-(4*a*c);

    if(delta>=0)
    {
        tab[0]=(-b+sqrt(delta))/(2*a);
        tab[1]=(-b-sqrt(delta))/(2*a);

        return tab;
    }

    else
    {
        return FALSE;
    }
}
