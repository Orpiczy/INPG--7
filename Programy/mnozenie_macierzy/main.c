#include <stdio.h>
#include <stdlib.h>
#define ROW_1 4
#define COL_1 3
#define ROW_2 3
#define COL_2 3

int main()

{
   int mac_1[ROW_1][COL_1]={
                           {29,19,3},
                           {1,4,3},
                           {7,14,21},
                           {2,3,4}
                           };

   int mac_2[ROW_2][COL_2]={
                           {6,2,1},
                           {1,4,3},
                           {7,3,9}
                           };

   int mac_3[ROW_1][COL_2]={};



   int indeks_wiersza_m1=0;
   int indeks_kolumny_m1=0;

   int indeks_wiersza_m2=0;
   int indeks_kolumny_m2=0;

   int indeks_wiersza_m3=0;
   int indeks_kolumny_m3=0;

   int i=0;
   int x=0;

   for(indeks_wiersza_m3=0;indeks_wiersza_m3<ROW_1;indeks_wiersza_m3++)
   {
                      for(indeks_kolumny_m3=0;indeks_kolumny_m3<COL_2;indeks_kolumny_m3++)
                      {
                                         for(i=0;i<COL_1;i++)
                                         {
                                         mac_3[indeks_wiersza_m3][indeks_kolumny_m3]=mac_3[indeks_wiersza_m3][indeks_kolumny_m3]+mac_1[indeks_wiersza_m1][indeks_kolumny_m1+i]*mac_2[indeks_wiersza_m2+i][indeks_kolumny_m2];
                                         }
                      indeks_kolumny_m2++;
                      }

                      indeks_wiersza_m1++;

                      indeks_kolumny_m2=0;
   }




printf("ILoczyn macierzy 1 i macierzy 2 wyglada nastepujaco:\n\n");

for(indeks_wiersza_m1=0;indeks_wiersza_m1<ROW_1;indeks_wiersza_m1++)
   {
                      for(indeks_kolumny_m1=0;indeks_kolumny_m1<COL_1;indeks_kolumny_m1++)
                      {
                                        printf("|%d",mac_1[indeks_wiersza_m1][indeks_kolumny_m1]);
                      }
                      printf("|\n");

   }

 printf("\n     *\n\n");

 for(indeks_wiersza_m2=0;indeks_wiersza_m2<ROW_2;indeks_wiersza_m2++)
   {
                      for(indeks_kolumny_m2=0;indeks_kolumny_m2<COL_2;indeks_kolumny_m2++)
                      {
                                        printf("|%d",mac_2[indeks_wiersza_m2][indeks_kolumny_m2]);
                      }
                      printf("|\n");

   }


printf("\n     =\n\n");

for(indeks_wiersza_m3=0;indeks_wiersza_m3<ROW_1;indeks_wiersza_m3++)
   {
                      for(indeks_kolumny_m3=0;indeks_kolumny_m3<COL_2;indeks_kolumny_m3++)
                      {
                                        printf("|%d",mac_3[indeks_wiersza_m3][indeks_kolumny_m3]);
                      }
                      printf("|\n");

   }










   return 0;


}


