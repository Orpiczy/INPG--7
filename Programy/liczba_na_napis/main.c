#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    char znak;

    printf("Witam w programie zmieniajacym liczbe na napis\nWpisz cyfre: ");
    scanf("%d",&x);

    for(;x!=0;x=x/10)
    {
        znak=97;
        printf("znak %c, znak w ascii %d, i x=%d\n",znak, znak, x );
    }

    return 0;
}
