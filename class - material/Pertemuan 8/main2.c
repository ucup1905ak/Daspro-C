#include <stdio.h>
#include <conio.h>

int ucup;
void tampil_data(int a);



int main ()
{
   int gab;
   gab = 5;
   tampil_data(gab);
   printf("\n%d", ucup);
   return 0;
}

void tampil_data(int a)
{
   ucup = 5;
   printf("Halo, selamat datang");
}
