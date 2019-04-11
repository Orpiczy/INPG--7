#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FALSE 0
#define TRUE 1
int funk_kwadr( float a, float b, float c, float *O_1, float *O_2);

int main()
{
    float a;
    float b;
    float c;
    float O_1=0;
    float O_2=0;
    int wyn=0;


    printf("Witaj w programie wyznaczajacym miejsca zerowe:\n");
    printf("Podaj wspolczynnik a:\n");
    scanf("%f", &a);
    printf("Podaj wspolczynnik b:\n");
    scanf("%f", &b);
    printf("Podaj wspolczynnik c:\n");
    scanf("%f", &c);
    printf("Podana funkcja wyglada nastepujaco:\n%.1fx^2+%.1fx+%.1f\n",a,b,c);

    wyn=funk_kwadr( a, b, c, &O_1, &O_2);

    if(wyn==1)
    {
        if(O_1==O_2)
        {
            printf("Podana funkcja kwadratowa ma jedno miejsce zerowe rowne %f", O_1);
        }
        else
            printf("Podana funkcja ma dwa miejsca zerowe %f i %f", O_1, O_2);

    }
    else
    {
        printf("Podana funkcja nie posiada niestety miejsc zerowych dla delty nalezacej do liczb rzeczywistych");
    }

    return 0;
}

int funk_kwadr( float a, float b, float c, float *O_1, float *O_2)
{
    float delta;

    delta=(b*b)-(4*a*c);

    if(delta>=0)
    {
        *O_1=(-b+sqrt(delta))/(2*a);
        *O_2=(-b-sqrt(delta))/(2*a);

        return TRUE;
    }

    else
    {
        return FALSE;
    }
}
