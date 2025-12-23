
// 240713000
// Farelino
// D
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef char string[100];
int main(int argc, char *argv[]) {
	//stat
	bool run = true;
	bool auth = false;
	int menu;
	//account
	string secret_name = "Farel";
	string secret_pass = "240713000";
	
	string name, password;
	//opt
	int a, b, hasil, i;
	while (run){
		system("cls");
	printf("=== Kalkulator Sederhana ===");
	printf("\n[1]. Login");
	printf("\n[2]. Perkalian Loop");
	printf("\n[0]. Exit");
	printf("\n>> "); scanf("%d", &menu);
	
	switch(menu){
		case 1:
			do{
				system("cls");
				//
				printf("Name\t\t:");fflush(stdin);gets(name);
				printf("Password\t:");fflush(stdin);gets(password);
				if(strcmp(name, secret_name) != 0 ||strcmp(password, secret_pass) != 0 ){
					printf("\n\t[!] Username atau Password salah!");
					getch();
				}
			}while(strcmp(name, secret_name) != 0 ||strcmp(password, secret_pass) != 0 );
			auth = true;
			puts("\n\t[!] Logged in successfully");
		break;
		case 2:
			if(!auth){
				puts("\t[!] Login Required");
				break;
			}
			printf("\nMasukan angka pertama : ");scanf("%d", &a);
			printf("Masukan angka kedua   : ");scanf("%d", &b);
			hasil = 0;
			for(i = 0; i < a; i++)
				hasil += b;
				
			printf("\nHasil %d x %d = %d", a, b, hasil);
		break;
		case 0:
			printf("\n\t Bye...");
			run = false;
			break;
		default:
			printf("\n\t[!] Menu Salah ");
	}getch();
	}
	return 0;
}
