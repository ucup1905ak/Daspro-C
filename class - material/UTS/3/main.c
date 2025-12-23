#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float UTS_a, UTS_b, UTS_c, UTS_jml;
	float UAS;
	float NilaiAkhir;
	printf("format input xxx, xxx, xxx\n");
	printf("Masukan tiga nilai tes tengah semester (masing-masing dari 25) : ");
	fflush(stdin);scanf("%f,%f,%f",&UTS_a, &UTS_b,&UTS_c);
	printf("Masukan nilai tes akhir semester (dari 100) : ");
	fflush(stdin);scanf("%f", &UAS);

	UTS_jml = (UTS_a + UTS_b + UTS_c) * 4 / 3;
	NilaiAkhir = (UAS + UTS_jml)/ 2;

	printf("Nilai Akhir : %3.f", NilaiAkhir);

	if(NilaiAkhir > 50)
		printf("\nStatus : LULUS");
	else
		printf("\nStatus : GAGAL");

	return 0;
}
