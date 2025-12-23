#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
240713000
Farelino Alexander Kim
D
*/
typedef char string[100];


int main(int argc, char *argv[]) {
	bool run = true;
	bool auth = false;
	int menu;
	
	string key_username = "Farel";
	string key_password = "240713000";
	string username, password;
	
	
	int a,b,hasil;
	int i,j,n;
	
	
	while (run){
		system("cls");
		puts("=== Kalkulator Sederhana ===");
		puts("1. Login");
		puts("2. Perkalian Loop");
		puts("3. Tabel Perkalian");
		puts("0. Exit");

		printf(">> ");
		scanf("%d", &menu);
		fflush(stdin);
		switch(menu){
			case 1:
				do{
				system("cls");
				printf("Username : ");
				fflush(stdin);
				gets(username);
				printf("Password : ");
				fflush(stdin);
				gets(password);
				if(strcmp(key_password,password)!=0||strcmp(key_username, username)!=0){
					puts("[!] Invalid Credential");
					getch();
				}
				}while(strcmp(key_password,password)!=0||strcmp(key_username,username)!=0);
				auth = true;
				puts("[!] Logged in successfully");
				break;
			case 2:
				if(!auth){
					puts("[!] Login required");
					break;
				}
				printf("Masukan angka pertama (a): ");
				scanf("%d", &a);
				printf("Masukan angka kedua (b): ");
				scanf("%d", &b);
				hasil = 0;
				
				for(i = 0; i < a;i++){
					hasil +=b;
				}
				printf("\nHasil %d x %d : %d", a , b , hasil);
				break;
			case 3:
				if(!auth){
					puts("[!] Login required");
					break;
				}
				do{
					printf("Masukan angka (maks 10, 0 untuk keluar): ");
					scanf("%d", &n);
					
					if(n == 0){
						puts("Press Enter to continue...");
						break;
					}
					
					if(n > 10){
						puts("[!] Angka Terlalu Besar");
						continue;;
					}
					
					for(i = 1 ; i <= n; i++ ){
						for(j = 1; j <= n ; j++) printf("[%3d]\t", i*j);
						printf("\n");
					}
				}while(n != 0);
				break;
			case 0:
				run = false;
				puts("Good Bye...");
				break;
			default:
				puts("[!] Invalid Menu");
				break;
		}
		getch();
	}

	return 0;
}
