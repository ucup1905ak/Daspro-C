#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char string[100];
/*
if(!s_login) {
	printf("[!] Anda harus login terlebih dahulu.");
	printf("\nTekan Enter untuk melanjutkan...");
	getch();
	break;
}

*/
int main(int argc, char *argv[]) {
	int i, j;
	int menu, s_login = 0;
	// Fitur LOGINNN
	string username, password;
	string username_key = "Farel";
	string password_key = "240713000";
	
	//FITUR Cetak Bilangan Genap & segitiga sama kaki
	int n;
	
	//jajar genjang
	int t, l;
	
	//tugas
	struct tm *waktu;
	time_t mytime = mktime(waktu);
	time(&mytime);
	waktu = gmtime(&mytime);
	char *  yes = asctime(waktu);
//	printf("%d , %s ", (*waktu).tm_sec, yes);

	int asci;
	
do {
		time(&mytime);
		waktu = gmtime(&mytime);
		system("cls");
		printf("=== FARELINO ALEXANDER KIM ===\n");
		printf("=== BANGUN RUANG INTERAKTIF ===");
		printf("\n1. Login");
		printf("\n2. Cetak Bilangan Genap");
		printf("\n3. Segitiga Sama Kaki");
		printf("\n4. Jajar Genjang (bonusssss...)");
		printf("\n5. Logout");
		printf("\n6. QR Code [TUGAS]");

		printf("\n0. Exit");
		printf("\n>> "); fflush(stdin);
		scanf("%d", &menu);
//	s_login = 1; //testing
	switch(menu) {
		
		case 1:
			if(s_login){
				printf("[!] Anda sudah login.");
				break;
			}
			do{
				system("cls");
				printf("Username: "); fflush(stdin); gets(username);
				printf("Password: "); fflush(stdin); gets(password);

			  if(strcmp(username, username_key)!= 0 || strcmp(password, password_key)!= 0){
			   	printf("[!] Login gagal, coba lagi!");
			   	getch();
			  }
			}while(strcmp(username, username_key)!= 0 || strcmp(password, password_key)!= 0);
			printf("[+] Login berhasil!");
			s_login = 1;
			break;
		case 2:
			if(!s_login) {
				printf("[!] Anda harus login terlebih dahulu.");
				break;
			}
			printf("Masukkan nilai rentang: ");
			scanf("%d", &n);
		 	printf("Bilangan genap dalam rentang 1-%d: ", n);
		 	for(i = 1 ; i <= n ; i++ ) {
				if(i%2 == 1) {
					continue;
				}
				printf("%d ", i);

			}
			break;
		case 3: // segitiga sama kaki
			if(!s_login) {
				printf("[!] Anda harus login terlebih dahulu.");
				break;
			}
			printf("Masukkan ukuran segitiga: "); scanf("%d", &n);
			for(i = 1 ;i <= n; i++){
				for(j = n - i ; j >= 1 ; j--) printf(" ");
//				printf("%d ", (2*i)-1);
				for(j = 1 ;j<=(2*i)-1;j++) printf("*");
				printf("\n");
			}

			break;
		case 4:
			if(!s_login) {
				printf("[!] Anda harus login terlebih dahulu.");
				break;
			}
			do {
			printf("Masukkan tinggi jajar genjang: "); scanf("%d", &t);
			printf("Masukkan lebar jajar genjang: "); scanf("%d", &l);
			if(t <2 || l < 2){
				printf("\n[!] Ukuran harus lebih dari 1!\n\n");
			}
			} while(t < 2 || l < 2);

			for(i = 1 ;i <= t; i++){
				for(j = t - i ; j >= 1 ; j--) printf(" ");
//				printf("%d ", (2*i)-1);
				for(j = 1 ;j<=l;j++) printf("* ");
				printf("\n");
			}
			break;
		case 5:
			if(!s_login) {
				printf("[!] Anda harus login terlebih dahulu.");
				break;
			}
			printf("[-] Logout berhasil.");
			s_login = 0;
			break;
		case 6:
			
			if(!s_login) {
				printf("[!] Anda harus login terlebih dahulu.");
				break;
			}
			printf("Masukkan BESAR QR: "); scanf("%d", &n);
						printf("%d , %s \n", (*waktu).tm_sec, yes);
					asci = (*waktu).tm_sec % 4;
			for(i = 1; i < n;i++) {
				for(j = 1; j < 2*n ;j++) {
					asci %= 4;
					switch(asci){
						case 1:
							printf("%c",219);
							break;
						case 2:
							printf("%c",220 );
							break;
						case 3:
							printf("%c",223 );
							break;
						case 4:
							printf("%c",254 );
							break;
					}
					asci++;
				}
				printf("\n");
			}



			break;
		case 0:
			printf("Keluar dari program...");
			break;
		default:
			printf("\n[!] Pilihan tidak valid, coba lagi.");
			break;
	}
			printf("\n\nTekan Enter untuk melanjutkan...");
	getch();
} while(menu != 0);

	return 0;
}
