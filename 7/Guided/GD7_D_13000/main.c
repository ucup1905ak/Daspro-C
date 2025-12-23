#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char string[100];

void tampilMenu();
void inputBarang(string * nama, int * jumlah, float * harga);
void tampilBarang(string nama, int jumlah, float harga);
void hitungTotalHarga(float * harga, string nama, int jumlah);
void hitungKembalian(float *kembalian, float price, float uang);

int main(int argc, char *argv[]) {
	string barang;
	int jml;
	float price = 0, uang, kembalian;
	int menu;
	do{
		tampilMenu();
		scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("\n\t---=== [ Input Barang ] ===---\n");
				inputBarang(&barang, &jml, &price);
				printf("\n\t[+] Berhasil Input Barang [+]");
				break;
			case 2:
				printf("\n\t---=== [ Tampil Barang ] ===---\n");
				tampilBarang(barang, jml, price);
				printf("\n\t[~]Semua Barang sudah Ditampilkan [~]\n");
				break;
			case 3:
				printf("\n\t---=== [ Ubah Barang ] ===---\n");

				do{

					printf("\nMasukan Nama Barang	: ");
					fflush(stdin);
					gets(barang);
					
					if(			strcmpi(barang,"Gems") != 0
							&&	strcmpi(barang,"Monthly Pass") != 0
							&&	strcmpi(barang,"Double Reward Pass") != 0)
      			printf("\n\n\t[!] Nama Barang Hanya Boleh | Gems | Monthly Pass | Double Reward Pass |");

				}while(	strcmpi(barang,"Gems") != 0
						&& 	strcmpi(barang,"Monthly Pass") != 0
						&&	strcmpi(barang,"Double Reward Pass") != 0);

				do{
					printf("\nMasukan Jumlah Barang	: ");
					scanf("%d", &jml);
					if (jml < 0)
						printf("\n\t[!] Jumlah Barang Tidak Boleh Negatif [!]\n");
				}while(jml < 0);
					
				hitungTotalHarga(&price, barang, jml);
				printf("\n\nHarga yang harus dibayar	: Rp%*.2f"	, 10, price);
				break;
		 	case 4:
		 		printf("\n\t---=== [ Pembayaran ] ===---\n");
		 		tampilBarang(barang, jml, price);
		 		do{
					printf("\n~ masukan Jumlah Uang Yang Ingin Dibayarkan : Rp");
					scanf("%f", &uang);
					if(uang < 0 || uang < price)
						printf("\n\n\t[!]Uang Tidak Cukup [!]\n");
				}while(uang < 0 || uang < price);
				hitungKembalian(&kembalian, price, uang);
				printf("\n\nKembalianmu adalah		: Rp%*.2f"	, 10, kembalian);
				break;
		 	case 0:
		 		printf("\n\t[~ Farelino Alexander Kim - D - 240713000]");
		 		printf("\n\t=== Prosedur itu mudah!! Amin ... ===");
				break;
			default:
				printf("\n\n\t[!] Menu tidak tersedia [!]\n");
				break;
		} getch();
	}while(menu != 0);
	return 0;
}


void tampilMenu()
{
	system("cls");
	printf("\t---=== [ GUIDED PROSEDUR ] ===---\n");
	printf("\n[1]. Input Barang");
	printf("\n[2]. Tampil Barang");
	printf("\n[3]. Ubah Barang");
	printf("\n[4]. Pembayaran");
	printf("\n[0]. Keluar Program");
	printf("\n>> ");
}
void inputBarang(string * nama, int * jumlah, float * harga)
{
	do {
		printf("\nMasukan Nama Barang	: ");
		fflush(stdin);
		gets(*nama);
		if(		strcmpi(*nama,"Gems") != 0
			&& 	strcmpi(*nama,"Monthly Pass") != 0
			&&	strcmpi(*nama,"Double Reward Pass") != 0)
			printf("\n\n\t[!] Nama Barang Hanya Boleh | Gems | Monthly Pass | Double Reward Pass |[!]\n");
	} while(strcmpi(*nama,"Gems") != 0
			&& 	strcmpi(*nama,"Monthly Pass") != 0
			&&	strcmpi(*nama,"Double Reward Pass") != 0);

	do{
	 printf("\nMasukan Jumlah Barang	: ");
	 scanf("%d", jumlah);
	 if((*jumlah) < 0)
			printf("\n\n\t[!] Jumlah Barang tidak boleh Negatif! [!]\n");

	}while(*jumlah < 0);

	if(strcmpi(*nama, "Gems") == 0)
		*harga = 10000 * (*jumlah);
 	else if(strcmpi(*nama, "Monthly Pass") == 0)
		*harga = 75000 * (*jumlah);
 	else
		*harga = 50000 * (*jumlah);

}
void tampilBarang(string nama, int jumlah, float harga)
{
	printf("\n====================================\n");
	printf("\nNama Barang	: %s"		, nama);
	printf("\nJumlah Barang	: %d"		, jumlah);
	printf("\nHarga Barang	: Rp%*.2f"	, 10,harga);
	printf("\n====================================\n");
}
void hitungTotalHarga(float * harga, string nama, int jumlah)
{
	if			(strcmpi(nama, "Gems"					) == 0)
		*harga = 10000 * jumlah;
 	else if	(strcmpi(nama, "Monthly Pass"	) == 0)
		*harga = 75000 * jumlah;
 	else
		*harga = 50000 * jumlah;
}
void hitungKembalian(float *kembalian, float price, float uang)
{
	*kembalian = uang - price;
}
