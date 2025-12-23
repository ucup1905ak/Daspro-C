#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef char string[100];

bool validasiNoRekening(int noRek);
float hitungPajakProgresif(float saldo);
float cekSaldo(float saldo, string jenis);
bool login(int noRek, string pass);

int main(){
	int rekening , menu;
	string pass, jenis;
	float saldo = 25000, biayaAdmin;
	
	while (1){
		system("cls");
		printf("Masukan Nomor  : \n");
		scanf("%d", &rekening);
		
		printf("Masukan Password  : \n");
		fflush(stdin); gets(pass);
		if(login(rekening, pass)) {
			printf("\n\t[*] Login Berhasil");
			getch();
			break;
		}
			
		printf("\n\t[!] Login gagal!!");
		getch();
	}

	do{
		system("cls");
		printf("\n\t Atma Bank\n");
		printf("\n1. Set Saldo");
		printf("\n2. Cek Saldo");
		printf("\n3. Hitung Pajak");
		printf("\n0. Keluar");
		printf("\n>> ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("masukan nilai saldo baru : ");
				scanf("%f", &saldo);
				printf("\n\tberhasil\n");
				break;
			case 2:
				printf("\nMasukan Jenis Rekening\n(gold/silver/normal) : ");
				scanf("%s", jenis);
				biayaAdmin = cekSaldo(saldo, jenis);
				saldo -= biayaAdmin;
				printf("\nBiaya Admin : %.2f", biayaAdmin);
				printf("\nSaldo : %.2f", saldo);
				break;
			case 3:
				printf("\nTotal Pajak yang harus dibayar : %.2f", hitungPajakProgresif(saldo));
				break;
			case 0:
				printf("\n\t[!] Keluar dari program.");
				break;
			default:
				printf("\n\t[!] Pilihan tidak Valid");
				break;
		}getch();
	}while(menu != 0);
  return 0;
}

bool validasiNoRekening(int noRek){
	if(noRek > 999999 || noRek < 100000) return false;
	
	int validasi = noRek;
	validasi /= 100;
	
	int modulus = noRek;
	modulus %= 100;
	modulus /= 10;
	
	if(modulus == 0) return false;
	int nilaiExpetasi = noRek;
	nilaiExpetasi %= 10;

	if(validasi % modulus == nilaiExpetasi)
		return true;
	else return false;
}
float hitungPajakProgresif(float saldo)
{
	float pajak = 0.0;
	if (saldo > 50000){
		pajak += (saldo - 50000) * 0.20;
		saldo = 50000;
	}
	if (saldo > 10000){
		pajak += (saldo - 10000 * 0.10);
	}
	
	return pajak;
}
float cekSaldo(float saldo, string jenis)
{
	if(strcmpi(jenis, "gold")== 0)return 0;
	else if(strcmpi(jenis, "silver")==0) return 2000;
	else return (saldo * 0.001);
}
bool login(int noRek, string pass)
{
	if(validasiNoRekening(noRek) == true && strcmpi(pass , "atma") == 0 )
		return true;
 	else return false;
}


