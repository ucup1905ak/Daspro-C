#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, usia, count_P = 0, count_L = 0;
	char JenisKel;
	float mean_P = 0, mean_L = 0;
	
	for(i = 1; i <= 10;i++){
		system("cls");
		printf("*** Responden %d\n", i);
		printf("[!] Masukan Usia Anda\t\t: ");
		fflush(stdin); scanf("%d", &usia);
		printf("[!] Masukan Jenis Kelamin Anda (l / p)\t: ");
		fflush(stdin); scanf("%c", &JenisKel);
		if(JenisKel == 'p'|| JenisKel == 'P'){
			count_P++;
			mean_P += usia;
		}
		if(JenisKel == 'l' || JenisKel == 'L'){
			count_L++;
			mean_L += usia;
		}
		printf("\nPress any key to continue...");
		fflush(stdin);
		getch();
	}
	system("cls");
	
	mean_P /= count_P;
	mean_L /= count_L;
	
	printf("Rata - Rata Usia Responden Perempuan adalah %.1f tahun", mean_P);
	return 0;
}



		//testing (uncoment to test :))
		/*
		printf("sum L [%.f]  count L [%d]\nsum P [%.f] count P [%d]", mean_L, count_L, mean_P,count_P);
		*/
