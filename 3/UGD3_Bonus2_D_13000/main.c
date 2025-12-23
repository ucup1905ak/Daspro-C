/*
240713000
Farelino Alexander Kim
D
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef char string[100];

int main(int argc, char *argv[]) {
	//part 1
	int mm, dd, yyyy;
	string nama;
	//part 2
	string konserA;
	float hargaA;
	int jumlahA;
	//part3
	string konserB;
	float hargaB;
	int jumlahB;
	//part 4 >>> BONUS
	int ddKembali, mmKembali, yyyyKembali;
	
	
	
	//kode
	printf("\t=== [ Platform Tiket Konser ] ===");
	printf("\nSelamat datang, tolong masukan Identitas Anda");
	printf("\n\nMasukan nama anda\t\t: "); gets(nama);
	printf("Masukan tanggal pemesanan\t: ");
	scanf("%d-%d-%d", &dd, &mm, &yyyy);
	printf("Masukan tanggal pengembalian\t: ");
	scanf("%d-%d-%d", &ddKembali, &mmKembali, &yyyyKembali);
	


	printf("\n\t=== [ Input Tiket Kategori A ] ===");
	printf("\nMasukan nama konser pertama\t: "); fflush(stdin);gets(konserA);
	printf("Masukan harga tiket pertama\t: Rp. "); scanf("%f", &hargaA);
	printf("Masukan jumlah tiket pertama\t: "); scanf("%d", &jumlahA);
//		printf("\n\t[Testing] [%s][%f][%d]", konserA, hargaA, jumlahA);
	
	printf("\n\t=== [ Input Tiket Kategori B ] ===");
	printf("\nMasukan nama konser kedua\t: "); fflush(stdin);gets(konserB);
	printf("Masukan harga tiket kedua\t: Rp. "); scanf("%f", &hargaB);
	printf("Masukan jumlah tiket kedua\t: "); scanf("%d", &jumlahB);
//		printf("\n\t[Testing] [%s][%f][%d]", konserB, hargaB, jumlahB);
	
	// ID PEMBELI (11 Digit) >> 3 digit  NPM (0101) + 8 digit(Jumlah Tiket A dan B)
		
	unsigned long long int i_idPembeli = 71300000000 + jumlahA +jumlahB;
	printf("\n\n\t=== [ Tampilkan Detail ] ===");
	printf("\nNama Pembeli\t\t: %s", nama);
	printf("\nID Pembeli\t\t: %llu", i_idPembeli); // 1 3000000000
	printf("\nTanggal Pesanan\t\t: %d-%d-%d", dd,mm,yyyy);
	printf("\nTanggal Pengembalian\t: %d-%d-%d", ddKembali,mmKembali,yyyyKembali);
	printf("\n\n Data Tiket Kategori A");
	printf("\nNama Konser\t: %s", konserA);
	printf("\nHarga Tiket\t: Rp %.2f", hargaA);
	printf("\njumlah Tiket\t: %d", jumlahA);
	printf("\n\n Data Tiket Kategori B");
	printf("\nNama Konser\t: %s", konserB);
	printf("\nHarga Tiket\t: Rp %.2f", hargaB);
	printf("\njumlah Tiket\t: %d", jumlahB);
	
	float totalHarga = (hargaA * jumlahA)+(hargaB * jumlahB);
	printf("\nTotal Harga sebelum pajak\t: Rp %.2f", totalHarga);
	//stelah Pajak (PPN 10%)
	totalHarga *= 1.1;
	printf("\nTotal Harga setelah pajak\t: Rp %.2f", totalHarga);
	
	//BONUS ======================================================
	int dt_Beli = yyyy*365 + mm*30 + dd;
	int dt_Kembali = yyyyKembali*365 + mmKembali*30 + ddKembali;
	printf("\n=== [ Bonus ] ===");
	printf("\nSelisih Antara tanggal Beli dan tanggal Kembali = %d hari", dt_Kembali-dt_Beli);
	
	
	//	TUGAS
	printf("\n\n\t=== [ Cek Pengembalian ] ===");
	printf("\n1: True");
	printf("\n0: False");
	printf("\nApakah tiket konser yang dipesan dapat dikembalikan? %d", (dt_Kembali-dt_Beli)<=3);
			
			//diskon
	printf("\n\n\t=== [ Diskon ] ===");
	int jumlahPembelian = jumlahA+jumlahB;
	int diskonPembelian = jumlahPembelian / 3;
	printf("\nAnda mendapatkan Diskon\t\t: %d %%", diskonPembelian);
	float hemat = (totalHarga*diskonPembelian/100);
	totalHarga = totalHarga - hemat;
	printf("\nTotal Harga setelah diskon\t: Rp %.2f", totalHarga);
	printf("\nAnda telah Hemat\t\t: Rp %.2f", hemat);
	return 0;
}


/*
testing::
	printf("\n%d - %d - %d", dd,mm,yyyy);
	printf("\n%d - %d - %d", dd / 100,mm / 100,yyyy/10000);

*/
