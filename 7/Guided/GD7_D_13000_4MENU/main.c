#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tampilMenu();
void Item();
void hitungHarga(float * total,int a_jml,int b_jml,int c_jml);
void Reciept(struct tm* time,float kembalian,float uang,float total,int a_jml, int b_jml, int c_jml);
void ListItem(float *total,int a_jml, int b_jml, int c_jml);
void Bayar(float * kembalian, float * uang,float * total);
void HapusBarang(int item,int *a_jml,int *b_jml,int * c_jml);
void checkPesanan(int *status, int a, int b, int c);

int main(){
	//flow & temp
	int menu, idx, jml, status, bayar = 0;
	float total, kembalian, uang;
	
	//stored data
	int a=0, b=0, c=0;
	
	//time
	time_t t;
	t = time(NULL);
	struct tm *waktu = localtime(&t);

	do{
		checkPesanan(&status, a,b,c);
		if(status == 0) bayar = 0;
		tampilMenu();
		scanf("%d", &menu);
		switch(menu){
			case 1:
				do{
					Item(a,b,c); //semi naive input
					printf("\n\nMasukan ID Item yang mau ditambahkan : ");
					scanf("%d", &idx);
					if(idx < 1 || idx > 3){
						printf("\n\n\t[!] Item Tidak ada!");
						getch();
					}
				}while(idx < 0 || idx > 3);
				do{
					printf("\n\nMasukan Jumlah Item %d : ", idx);
					scanf("%d", &jml);
					if(jml<1 || jml > 50){
						printf("\n\n\t[!] Item tidak bisa negatif atau melebihi 50 ");
						getch();
					}
				}while(jml<1 || jml > 50);
				if(idx == 1){
					a = jml;
				}else if(idx == 2){
					b = jml;
				}else {
					c = jml;
				}
				printf("\n\n\t[+] Item telah ditambahkan");
				break;
			case 2:
				if(!status){
					printf("\n\n\t[!]Lakukan Pesanan Terlebih Dahulu!!");
					break;
				}
				ListItem(&total,a,b,c);
				printf("\n\nMasukan Id Item yang akan dihapus : ");
				scanf("%d", &idx);
				if(idx < 0 || idx > 3){
					printf("\n\n\t[!] Gagal menghapus item, item tidak valid");
					break;
				} else if(idx == 1 && a <= 0){
					printf("\n\n\t[!] Gagal menghapus item, item Buku tidak dipilih");
					break;
				} else if(idx == 2 && b <= 0){
					printf("\n\n\t[!] Gagal menghapus item, item Pulpen tidak dipilih");
					break;
				} else if(idx == 3 && c <= 0){
					printf("\n\n\t[!] Gagal menghapus item, Item Pensil tidak dipilih");
					break;
				}
				HapusBarang(idx, &a, &b, &c);
				printf("\n\n\t[+]Item Berhasil dihapus");
				break;
			case 3:

				if(!status){
					printf("\n\n\t[!]Lakukan Pesanan Terlebih Dahulu!!");
					break;
				}
	
				ListItem(&total,a,b,c);
				Bayar(&kembalian, &uang, &total );
				bayar = 1;
				break;
			case 4:

				if(!status){
					printf("\n\n\t[!]Lakukan Pesanan Terlebih Dahulu!!");
					break;
				}
				if(!bayar){
					printf("\n\n\t[!]Lakukan Pembayaran Terlebih Dahulu!!");
					break;
				}
				Reciept(waktu,kembalian,uang,total, a,b,c); //semi naive input
				break;
			case 0:
				printf("Byeeee....");
				break;
			default:
				printf("\n\n\t[!] Menu tidak Valid [!]");
				break;
		}getch();
	}while(menu != 0);
	
	return 0;
}


void tampilMenu(){ //naive
	system("cls");
	printf("\n\t=== [ Aplikasi Kasir ] ===");
	printf("\n[1] Pilih Item");
	printf("\n[2] Hapus Item");
	printf("\n[3] Bayar");
	printf("\n[4] Print Reciept");
	printf("\n[0] Exit");
	printf("\n>> ");
}
void Item(){ //naive
	system("cls");
	printf("\n[Id]\t[Nama Item]\t[Harga]");
	printf("\n==============================================");
		printf("\n[001]\t%15s\tRp%10.2f", "Buku",(float)15000);
		printf("\n[002]\t%15s\tRp%10.2f", "Pulpen",(float)20000);
		printf("\n[003]\t%15s\tRp%10.2f", "Pensil",(float)7000);
	printf("\n==============================================\n");
}
void hitungHarga(float * total,int a_jml,int b_jml,int c_jml){ //nett effect
 *total = 0;
 *total += a_jml * 15000;
 *total += b_jml * 20000;
 *total += c_jml * 7000;
}

void Reciept(struct tm* time,float kembalian,float uang,float total,int a_jml, int b_jml, int c_jml){ //semi naive input
	system("cls");
	printf("%s", asctime(time));
	printf("Farelino Alexander Kim");
	printf("\nNPM	: 240713000");
	printf("\n\n[Id]\t[Nama Item]\t[Qty]\t[Harga]");
	printf("\n==============================================");
	if(a_jml >0)
		printf("\n[001]\t%15s\t%3d\tRp%10.2f", "Buku",a_jml,(float)15000);
	if(b_jml >0)
		printf("\n[002]\t%15s\t%3d\tRp%10.2f", "Pulpen",b_jml,(float)20000);
	if(c_jml >0)
		printf("\n[003]\t%15s\t%3d\tRp%10.2f", "Pensil",c_jml,(float)7000);
	printf("\n==============================================\n");
	printf("\nTotal\t\t: Rp%10.2f", total);
	printf("\n\nUang Bayar\t: Rp%10.2f", uang);
	printf("\nKembalian\t: Rp%10.2f",kembalian);
}

void ListItem(float *total,int a_jml, int b_jml, int c_jml){
	system("cls");
	printf("\n[Id]\t[Nama Item]\t[Qty]\t[Harga]");
	printf("\n==============================================");
	if(a_jml >0)
		printf("\n[001]\t%15s\t%3d\tRp%10.2f", "Buku",a_jml,(float)15000);
	if(b_jml >0)
		printf("\n[002]\t%15s\t%3d\tRp%10.2f", "Pulpen",b_jml,(float)20000);
	if(c_jml >0)
		printf("\n[003]\t%15s\t%3d\tRp%10.2f", "Pensil",c_jml,(float)7000);
	printf("\n==============================================\n");
	hitungHarga(total, a_jml, b_jml, c_jml);
	printf("\nTotal\t: Rp%10.2f", *total);
}
void Bayar(float * kembalian, float * uang,float * total){//semi naive output
	do{
		printf("\nMasukan Jumlah pembayaran : Rp");
		scanf("%f", uang);
		if(*uang < *total){
			printf("\n\n\t[!] Uang tidak cukup!! [!]");
			getch();
		}
	}while(*uang < *total);

	printf("\n\n\t[!] Pembayaran berhasil");

	*kembalian = *uang - *total;
	printf("\n\nKembalian\t: Rp%10.2f",*kembalian);

}
void HapusBarang(int item,int *a_jml,int *b_jml,int * c_jml){ //semi naive output
	switch(item){
		case 1:
			*a_jml = 0;
			break;
		case 2:
			*b_jml = 0;
			break;
		case 3:
			*c_jml = 0;

			break;
	}
}

void checkPesanan(int *status, int a, int b, int c){
	*status = (a <= 0 && b <=0 && c<=0)?0:1;
}

