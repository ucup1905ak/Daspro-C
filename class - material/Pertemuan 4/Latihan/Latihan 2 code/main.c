//#include <stdio.h>
//#include <stdlib.h>
/*
240713000 - Farelino Alexander Kim
*/

int main(int argc, char *argv[]) {
	int var1, var2, var3, var4, var5;
	
	printf("\nMasukan bilangan 1 : "); scanf("%d", &var1);
	printf("\nMasukan bilangan 2 : "); scanf("%d", &var2);
	printf("\nMasukan bilangan 3 : "); scanf("%d", &var3);
	printf("\nMasukan bilangan 4 : "); scanf("%d", &var4);
	printf("\nMasukan bilangan 5 : "); scanf("%d", &var5);

	float total = var1 + var2 + var3 + var4 + var5;
	float mean = total / 5;
	printf("\n\nRata-rata dari 5 bilangan tersebut adalah %.2f", mean);
	return 0;
}


