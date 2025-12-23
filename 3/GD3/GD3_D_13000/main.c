#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char string[100];

int main(int argc, char *argv[]) {
	string namaMahasiswa = "Farelino Alexander Kim";
	string programStudi;
	float ipkSemesterSebelumnya, ipkSemesterTerakhir, totalIpk=0, meanIpk=0;
	int semester;
	char jenisKelamin;
	bool boolean;

	//Input data mahasiswa
	printf("\t=== [Input data Mahasiswa] ===");
	printf("\nNama Mahasiswa         : %s", namaMahasiswa);
	printf("\nProgram Studi          : ");fflush(stdin); gets(programStudi);
	printf("IPK Semester Sebelumnya: ");scanf("%f",&ipkSemesterSebelumnya);
	printf("IPK Semester Terakhir  : ");scanf("%f", &ipkSemesterTerakhir);
	printf("Semester               : ");scanf("%d",&semester);
	printf("Jenis Kelamin (L/P)    : ");jenisKelamin = getch();
	printf("%c",jenisKelamin);

	//Tampil data mahasiswa
	printf("\n\n\t=== [Tampil Data Mahasiswa] ===");
	printf("\nNama Mahasiswa              : %s", namaMahasiswa);
	printf("\nProgram Studi               : %s", programStudi);
	printf("\nIPK Semester Sebelumnya     : %.2f", ipkSemesterSebelumnya);
	printf("\nIPK Semester Terakhir       : %.2f", ipkSemesterTerakhir);
	printf("\nSemseter Saat ini           : %d", semester);
		semester++;
	printf("\nSemester Setelah Diincrement: %d", semester);
		semester--;
	printf("\nSemester Setelah Didecrement: %d", semester);
	printf("\nJenis Kelamin (L/P)         : %c", jenisKelamin);


	printf("\n\n\t=== [Perbandingan IPK] ===");
	printf("\n1: Benar/True");
	printf("\n0: Salah/False\n");

	//Input data mahasiswa
		boolean = ipkSemesterSebelumnya == ipkSemesterTerakhir;
	printf("\nApakah IPK semester sebelumnya sama dengan IPK semester terakhir? %d", boolean);
		boolean = ipkSemesterSebelumnya != ipkSemesterTerakhir;
	printf("\nApakah IPK semester sebelumnya tidak sama dengan IPK semester terakhir? %d", boolean);
		boolean = ipkSemesterSebelumnya > ipkSemesterTerakhir;
	printf("\nApakah IPK semester sebelumnya lebih besar IPK semester terakhir? %d", boolean);
		boolean = ipkSemesterSebelumnya < ipkSemesterTerakhir;
	printf("\nApakah IPK semester sebelumnya lebih kecil IPK semester terakhir? %d", boolean);

	//tugas...


	//Perhitungan
		totalIpk = ipkSemesterSebelumnya+ipkSemesterTerakhir;
		meanIpk = totalIpk / 2;
	printf("\n\n\t=== [ Tugas ] ===");
	printf("\nTotal IPK\t: %.2f", totalIpk);
	printf("\nRata-rata IPK\t: %.2f", meanIpk);

		boolean = meanIpk >= ipkSemesterSebelumnya;
	printf("\nApakah rata-rata IPK lebih besar sama dengan IPK semester sebelumnya? %d", boolean);
		boolean = meanIpk >= ipkSemesterTerakhir;
	printf("\nApakah rata-rata IPK lebih besar sama dengan IPK semester terakhir? %d", boolean);
		boolean = meanIpk <= ipkSemesterSebelumnya;
	printf("\nApakah rata-rata IPK lebih kecil sama dengan IPK semester sebelumnya? %d", boolean);
		boolean = meanIpk <= ipkSemesterTerakhir;
	printf("\nApakah rata-rata IPK lebih kecil sama dengan IPK semester terakhir? %d", boolean);

	return 0;

	
}
