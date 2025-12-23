#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef char string[50];

int main(int argc, char *argv[]) {
	int menu, umur;
	string nama, jenisKelamin, username;
	string password, kategori, kategoriIndex;
	float berat, tinggi, indexMassaTubuh;


	printf("\t==[LOGIN]==\n");
	printf("\nUsername  : "); fflush(stdin); gets(username);
	printf("\nPassword  : "); fflush(stdin); gets(password);

	if(strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0){
	    system("cls");

	    printf("\t==[ RUMAH SAKIT ATMA JAYA ]==\n");
	    printf("\n[1] Input Data Pasien");
	    printf("\n[2] Klasifikasi BMI");
	    printf("\n>> "); scanf("%d", &menu);
	    
	    switch(menu){
	    	case 1:
				printf("\nMasukan nama lengkap : ");fflush(stdin); gets(nama);
				printf("\nMasukan umur : ");scanf("%d", &umur);
				printf("\nMasukan jenis kelaminn : ");fflush(stdin); gets(jenisKelamin);
				
				if( umur >= 0 && umur <=5){
					strcpy(kategori,"balita");
				}else if( umur >= 6 && umur <=12){
					strcpy(kategori,"anak-anak");
				}else if( umur >= 13 && umur <=17){
					strcpy(kategori,"remaja");
				}else if( umur >= 18 && umur <=59){
					strcpy(kategori,"dewasa");
				}else{
					strcpy(kategori,"lansia");
				}
				
				printf("\n\n\t=== Data Pasien ===");
				printf("\nNama          : %s", nama);
				printf("\nUmur          : %d", umur);
				printf("\nJenis Kelamin : %s", jenisKelamin);
				printf("\nKategori      : %s", kategori);
				printf("\n\nFarelino Alexander Kim | 240713000 | D");
				break;
			case 2:
				printf("Masukan berat badan Anda (kg)   : ");scanf("%f", &berat);
				printf("Masukan tinggi badan Anda (m)  : ");scanf("%f", &tinggi);
				
				indexMassaTubuh = berat / (tinggi * tinggi);
				
				if(indexMassaTubuh < 18.5){
					strcpy(kategoriIndex, "Kurus");
				}else if(indexMassaTubuh >= 18.5 && indexMassaTubuh <= 24.9){
					strcpy(kategoriIndex, "Normal");
				}else if(indexMassaTubuh >= 25 && indexMassaTubuh <= 29.9){
					strcpy(kategoriIndex, "Overweight");
				}else{
					strcpy(kategoriIndex, "Obesitas");
				}

				printf("\n\t=== Hasil Perhitungan BMI ===");
				printf("\nBMI Anda    : %.2f", indexMassaTubuh);
				printf("\nKategori    : %s", kategoriIndex);
				printf("\n\nFarelino Alexander Kim | 240713000 | D");
	    		break;
			default:
				printf("\n\t[!] Menu tidak tersedia [!]\n");

				printf("\n\nFarelino Alexander Kim | 240713000 | D");
				break;
		}
	}else{
		printf("\n[!] Username & Password Salah [!]\n\n");
		
		printf("Farelino Alexander Kim | 240713000 | D");
	}
	return 0;
}
