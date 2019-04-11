#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct l_zesp dodawanie(struct l_zesp a,struct l_zesp b);
struct l_zesp odejmowanie(struct l_zesp a,struct l_zesp b);
struct l_zesp mnozenie(struct l_zesp a,struct l_zesp b);
struct l_zesp dzielenie(struct l_zesp a,struct l_zesp b);
float modul(struct l_zesp a);
struct l_zesp sprzezenie(struct l_zesp a);
void wypisz_zesp(struct l_zesp z);

struct l_zesp
{
float re;
float im;
};

int main()
{

float mod=0;

struct l_zesp a=
{
2,
3
};

struct l_zesp b=
{
.re=5,
.im=6
};

struct l_zesp wyn=
{
.re=0,
.im=0
};


wyn=sprzezenie(a);
wypisz_zesp(wyn);



return 0;
}

struct l_zesp dodawanie(struct l_zesp a,struct l_zesp b)
{
struct l_zesp wynik={.re=a.re+b.re,.im=a.im+b.im};

return wynik;
}

float modul(struct l_zesp a)
{
float modul=sqrt((a.re*a.re)+(a.im*a.im));
return modul;
}

struct l_zesp sprzezenie(struct l_zesp a)
{
struct l_zesp wynik={.re=a.re,.im=-a.im};

return wynik;
}

void wypisz_zesp(struct l_zesp z)
{
   printf("Liczba zespolona wynosi x=%.2f yi=%+.2fi \n", z.re, z.im);
}

struct l_zesp odejmowanie(struct l_zesp a,struct l_zesp b)
{
struct l_zesp wynik={.re=a.re-b.re,.im=a.im-b.im};

return wynik;
}

struct l_zesp mnozenie(struct l_zesp a,struct l_zesp b)
{
struct l_zesp wynik={.re=(a.re*b.re)-(a.im*b.im),.im=(a.re*b.im)+(a.im*b.re)};

return wynik;
}

struct l_zesp dzielenie(struct l_zesp a,struct l_zesp b)
{
float dzielnik;
dzielnik=(b.re*b.re)+(b.im*b.im);

struct l_zesp wynik={.re=((a.re*b.re)+(a.im*b.im))/dzielnik,.im=((a.im*b.re)-(a.re*b.im))/dzielnik};


return wynik;
}
