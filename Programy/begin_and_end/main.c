#include <stdio.h>
#include <stdlib.h>

#define then
#define begin{
#define end }

int main()
{
 int i, a, b;

 srand(time(NULL));
 i=rand()%50;


 if (i > 10) then
 begin
 a = 10;
 b = 12;
 end

 printf("\"i\"jest wieksze od dziesieciu jesli a=10, a b=12, sam ocen czy to prawda - a=%d, a b=%d.",a,b);
    return 0;
}
