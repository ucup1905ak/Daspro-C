#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_MANAGER 5
#define MAX_KARYAWAN 3

typedef char string[100];

typedef struct{
	string nama;
	int npwp;
	float salary;
}Karyawan;


typedef struct{
	string nama;
	Karyawan K[MAX_KARYAWAN];
}Manager;


void printMenu();
void initDataManager(Manager manager[]);
bool isFullManager(Manager manager[]);
bool isEmptyManager(Manager manager[]);
int getEmptyManager(Manager manager[]);
void createManager(Manager manager[], int index, string nama);
Karyawan createKaryawan(string nama, int npwp, float salary);
void initDataKaryawan(Karyawan K[]);
int findMangerByNama(Manager manager[], string nama);
int getEmptyKaryawan(Manager manager);
void showAllData(Manager manager[]);

void warning(string s){
	printf("\n\t[!] %s [!]", s);
}

void good(string s){
	printf("\n\t[+] %s [+]", s);
}
int main(int argc, char *argv[]) {
	Manager manager[MAX_MANAGER];
	Karyawan temp[MAX_KARYAWAN];
	int menu, indexM, indexK, i;
	string nama, namaK;
	int npwp;
	float gaji;
	
	
	initDataManager(manager);
	
	
	do{
		system("cls");
		printf("\n\t === [ UGD ARRAY OF RECORD ] === \n");
		printMenu();
		printf("\n>>> ");
		
		scanf("%d", &menu);
		switch(menu){
			case 1:
				if(isFullManager(manager)){
					warning("Data Manager sudah penuh");
					break;
				}
				if(indexM < 0)break;
				indexM = getEmptyManager(manager);
				do{
					printf("Masukan Nama Manager \t: ");
					fflush(stdin); gets(nama);
					if(strcmp(nama, "-") == 0) warning("Invalid");
				}while(strcmp(nama, "-") == 0);
				
				createManager(manager, indexM, nama);
				good("Berhasil Menambahkan Data Manager");
				break;
			case 2:
				
				if(isEmptyManager(manager)) {
					warning("Belum Ada Data Manager");
					break;
				}
				
				printf("\nMasukan Nama Managers\t: ");
				fflush(stdin); gets(nama);
				indexM = findMangerByNama(manager, nama);
				if(indexM < 0){
					warning("Manager Tidak ditemukan.");
					break;
				}
				do{
					printf("Masukan Nama Manager \t: ");
					fflush(stdin); gets(nama);
					if(strcmp(nama, "-") == 0) warning("Invalid");
				}while(strcmp(nama, "-") == 0);
				createManager(manager, indexM, nama);
				good("Berhasil Mengubah Data Manager");
				break;
			case 3:
				if(isEmptyManager(manager)) {
					warning("Belum Ada Data Manager");
					break;
				}

				printf("\nMasukan Nama Managers\t: ");
				fflush(stdin); gets(nama);
				indexM = findMangerByNama(manager, nama);
				if(indexM < 0){
					warning("Manager Tidak ditemukan.");
					break;
				}
				
				indexK = getEmptyKaryawan(manager[indexM]);
				if(indexK < 0){
					warning("Manager Sudah Memiliki Cukup Karyawan.");
					break;
				}
				
				printf("\n\tMasukan Nama Karyawan\t: ");
				fflush(stdin); gets(namaK);

				printf("\n\tMasukan NPWP Karyawan\t: ");
				fflush(stdin); scanf("%d", &npwp);

				printf("\n\tMasukan Gaji Karyawan\t: ");
				fflush(stdin); scanf("%f", &gaji);
				
				
				manager[indexM].K[indexK] = createKaryawan(namaK, npwp , gaji);
				
				good("Berhasil Menambahkan Karyawan");
				
				break;
			case 4:
				if(isEmptyManager(manager)) {
					warning("Belum Ada Data Manager");
					break;
				}
				printf("\nMasukan Nama Managers\t: ");
				fflush(stdin); gets(nama);
				indexM = findMangerByNama(manager, nama);
				if(indexM < 0){
					warning("Manager Tidak ditemukan.");
					break;
				}
				
				createManager(manager, indexM, "-");
				for(i = 0 ; i < MAX_KARYAWAN; i++)
					manager[indexM].K[i] = createKaryawan("-", 0 ,0 );
				good("Berhasil Menghapus Data Manager");
				break;
			case 5:
				if(isEmptyManager(manager)) {
					warning("Belum Ada Data Manager");
					break;
				}
				
				showAllData(manager);
				
				break;
			case 0:
				printf("\n\tFARELINO ALEXANDER - D - 13000");
				printf("\n\tSIAP MENAMATKAN DASPRO!");
				break;
			default:
				warning("INVALID MENU");
				break;
		}
		if(menu != 0){
		printf("\n\n\tPress any key to continue.");
		getch();
		}
	}while(menu !=0);
	


	return 0;
}


void printMenu(){
	printf("\n[1]. Input Data Manager");
	printf("\n[2]. Update Data Manager");
	printf("\n[3]. Input Data Karyawan");
	printf("\n[4]. Delete Data Manager");
	printf("\n[5]. Show All Data");
	printf("\n[0]. Exit");
}
void initDataManager(Manager manager[]){
	int i;
	for(i = 0 ; i < MAX_MANAGER; i++ ){
		strcpy(manager[i].nama, "-");
		initDataKaryawan(manager[i].K);
	}
}
void initDataKaryawan(Karyawan K[]){
	int i;
	for(i = 0 ; i < MAX_KARYAWAN ; i++ ){
			strcpy(K[i].nama , "-");
			K[i].npwp = 0;
			K[i].salary = 0.0;
	}
}
bool isFullManager(Manager manager[]){
	int i;
	for(i = 0 ; i < MAX_MANAGER; i++){
		if(strcmp(manager[i].nama, "-") == 0) return false;
	}
	return true;
}
bool isEmptyManager(Manager manager[]){
	int i;
	for(i = 0 ; i < MAX_MANAGER; i++){
		if(strcmp(manager[i].nama, "-") != 0) return false;
	}
	return true;
}
int getEmptyManager(Manager manager[])
{
	int i;
	for(i = 0 ; i < MAX_MANAGER; i++){
		if(strcmp(manager[i].nama, "-") == 0) return i;
	}
	return -1;
}
void createManager(Manager manager[], int index, string nama){
	strcpy(manager[index].nama, nama);
}
Karyawan createKaryawan(string nama, int npwp, float salary){
	Karyawan temp;
	strcpy(temp.nama, nama);
	temp.npwp = npwp;
	temp.salary = salary;
	return temp;
}
int findMangerByNama(Manager manager[], string nama){
	int i;
	for(i = 0 ; i < MAX_MANAGER; i++){
		if(strcmp(manager[i].nama, nama) == 0) return i;
	}
	return -1;
}
int getEmptyKaryawan(Manager manager)
{
	int i;
	for(i = 0 ; i < MAX_KARYAWAN ; i++){
		if(strcmp(manager.K[i].nama, "-")==0) return i;
	}
	return -1;
}
void showAllData(Manager manager[]){
		int i, j ;
		int countM =  0 , countK;
		for(i = 0 ; i < MAX_MANAGER; i++){
			if(strcmp(manager[i].nama, "-") != 0){
				printf("\nDATA MANAGER -%d", countM+1);
				countM++;
				printf("\nnama : %s\n", manager[i].nama);
				
				countK = 0;
				for(j = 0 ; j < MAX_KARYAWAN ; j++){
					if( strcmp(manager[i].K[j].nama, "-") != 0){
						printf("\n\tData Karyawan -%d", countK+1);
						countK++;
						printf("\n\tNama Karyawan : %s", manager[i].K[j].nama);
						printf("\n\tNPWP Karyawan : %d", manager[i].K[j].npwp);
						printf("\n\tGaji Karyawan : Rp %.2f", manager[i].K[j].salary);
						
					}
				}
			}
		}
}


