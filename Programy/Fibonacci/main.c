#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n);
int main()
{
    int n;
    int wynik;

    printf("Prosze podac ktora ktory wyraz ciagu fibonacciego chcesz poznac\n");
    scanf("%d",&n);
    wynik=fibonacci(n);
    if(wynik==-1)
    {
        printf("W ciagu Fibonnaciego nie wystepuja wyrazy o ujemnym indeksie");
    }
    els
    {
        printf("Wyraz %d ciagu fibonacciego jest rowny %d", n, wynik);
    }



    return 0;
}

int fibonacci(int n)
{
    if(n<0)
    {
        return -1;
    }
    if(n==0)
    {
        return 0;
    }

    if(n==1)
    {
        return 1;
    }

    if(n>1)
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
