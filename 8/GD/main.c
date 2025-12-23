#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char string[50];

void init(int *kesempatan, float *batUnit1, float *batUnit2, float *batUnit3,bool *statusUnit1, bool *statusUnit2, bool *statusUnit3);
void CekLogin(bool *cek, string username, string password);
void printMenu();

void isSewa(bool *isValid, bool statusUnit1, bool statusUnit2, bool statusUnit3, int pilihUnit);
void batasBaterai(float *batUnit);
void tambahBaterai(float *batUnit, float menit);
void ubahMenit(float *persentase, float menit);
void tambahBateraiUnit(float *batUnit1, float *batUnit2, float *batUnit3, float menit, int pilihUnit);

void cekKondisi(bool *isValid, float batUnit, bool statusUnit);
void cekKondisiUnit(bool *isValid, float batUnit1, float batUnit2,float batUnit3,
										bool statusUnit1,bool statusUnit2,bool statusUnit3,int pilihUnit);


void ubahStatus(bool *statusUnit, float *durasiUnit, bool durasi);
void ubahStatusUnit(bool *statusUnit1, bool *statusUnit2, bool *statusUnit3, float *durasiUnit1, float *durasiUnit2, float *durasiUnit3, float durasi, int pilihUnit);

void kurangBaterai(float *batUnit, float menit);
void pengembalian(bool *statusUnit, float *batUnit, float durasiUnit);
void pengembalianUnit(bool *statusUnit1,bool *statusUnit2,bool *statusUnit3, float *batUnit1,float *batUnit2,float *batUnit3,
											float durasiUnit1, float durasiUnit2, float durasiUnit3, int pilihanUnit);
											


int main(int argc, char *argv[]) {
	bool loginStatus, exitStatus;
	string username, password, confirm;
	int kesempatan, menu;
	
	float batUnit1, batUnit2, batUnit3,
				durasiUnit1, durasiUnit2, durasiUnit3,
				pengisian, durasi;
	int pilihanUnit;
	bool statusUnit1,statusUnit2, statusUnit3, isValid;
	init(&kesempatan, &batUnit1, &batUnit2, &batUnit3,&statusUnit1, &statusUnit2, &statusUnit3);
	do{ //System LOGIN
		system("cls");
		system("color 07");
		
		loginStatus = false;
		printf("\n\t\t==== [ Login Page ] ====");
		printf("\n\t\t[ Sisa Kesempatan : %d]", kesempatan);
		printf("\nUsername : ");
		fflush(stdin); gets(username);
		printf("\nPassword : ");
		fflush(stdin); gets(password);
		CekLogin(&loginStatus, username, password);
		
		if(loginStatus){
			system("color a0");
			printf("\n\t\t[*] Berhasil Login [*]\n\n");
			exitStatus = false;
			system("pause");
			break;
		}
			system("color 4f");
			printf("\n\t\t[!] Username/Password salah [!]");
			kesempatan--;
			getch();
	}while(kesempatan!=0);
	if(!loginStatus) return 0; //exit
	
	
	//Main Menu
	do{
		system("cls");
		system("color 07");
		
		printf("\n\t\t==== [ Penyewaan Drone ] ====");
		printf("\n\tUnit 1: %.2f [%s] | Unit 3: %.2f [%s] |Unit 3: %.2f [%s]\n",
						batUnit1, statusUnit1? "Tersedia":"Dipinjam",
						batUnit2, statusUnit2? "Tersedia":"Dipinjam",
						batUnit3, statusUnit3? "Tersedia":"Dipinjam");
	printMenu();
	fflush(stdin);
	printf("\n\t>> "); scanf("%d", &menu);
	switch(menu){
		case 1:
			printf("\n\tPilih unit [1/2/3] : "); scanf("%d", &pilihanUnit);
			if(pilihanUnit <1 || pilihanUnit > 3) {
				printf("\n\n\t[!] Pilihan Unit Tidak Tersedia.");
				break;
			}

			isSewa(&isValid,statusUnit1, statusUnit2, statusUnit3, pilihanUnit );
			
			if(!isValid){
				printf("\n\t\t[!] Unit %d sedang disewa", pilihanUnit);
				break;
			}
			printf("\n\t Masukan lama pengisian (Menit) : ");
			scanf("%f", &pengisian);
			tambahBateraiUnit(&batUnit1, &batUnit2, &batUnit3, pengisian, pilihanUnit);
			printf("\n\n\t[+] Berhasil mengisi baterai unit %d", pilihanUnit);
			break;
		case 2:
			printf("\n\tPilih unit [1/2/3] : "); scanf("%d", &pilihanUnit);
			if(pilihanUnit <1 || pilihanUnit > 3) {
			printf("\n\n\t[!] Pilihan Unit Tidak Tersedia.");
			break;
			}
			cekKondisiUnit(&isValid, batUnit1, batUnit2, batUnit3, statusUnit1, statusUnit2, statusUnit3, pilihanUnit);
			if(!isValid){
				printf("\n\t\t[!] Unit %d tidak siap disewa", pilihanUnit);
				break;
			}
			printf("\nMasukan durasi peminjaman : ");scanf("%f", &durasi);
			ubahStatusUnit(&statusUnit1, &statusUnit2, &statusUnit3, &durasiUnit1,&durasiUnit2, &durasiUnit3, durasi, pilihanUnit);
			printf("\n\n\t[*] Berhasil meminjamkan Unit %d", pilihanUnit);

			break;
		case 3:
			printf("\n\tPilih unit [1/2/3] : "); scanf("%d", &pilihanUnit);
			if(pilihanUnit <1 || pilihanUnit > 3) {
			printf("\n\n\t[!] Pilihan Unit Tidak Tersedia.");
			break;
			}
			isSewa(&isValid, statusUnit1, statusUnit2, statusUnit3, pilihanUnit);
			if(isValid){
				printf("\n\t\t[!] Unit %d tidak sedang dipinjam", pilihanUnit);
				break;
			}

			pengembalianUnit(&statusUnit1, &statusUnit2, &statusUnit3,
												&batUnit1, &batUnit2, &batUnit3,
												durasiUnit1, durasiUnit2, durasiUnit3, pilihanUnit);
			printf("\n\n\t[*] Berhasil mengembalikan Unit %d", pilihanUnit);
			break;

		default:
			printf("\n\t\t[!] Menu tidak Valid");
			break;
		case 0: break;
	}
	printf("\n\t\tTekan keyboard untuk melanjutkan...");
	getch();
	}while(menu!=0);

	return 0;
}



void init(int *kesempatan, float *batUnit1, float *batUnit2, float *batUnit3,bool *statusUnit1, bool *statusUnit2, bool *statusUnit3)
{
	*kesempatan = 3;
	*batUnit1 = 20.0;
	*batUnit2 = 80.0;
	*batUnit3 = 75.5;
	*statusUnit1 = *statusUnit2 = *statusUnit3 = true;
}
void CekLogin(bool *cek, string username, string password)
{
	if(strcmp(username,"Farel")==0 &&strcmp(password,"13000")==0)
	{
		*cek = true;
	}
}
void printMenu(){
	printf("\n[1] Isi Baterai Drone");
	printf("\n[2] Sewa Drone");
	printf("\n[3] Kembalikan Drone");
	printf("\n[0] Keluar");
}

void isSewa(bool *isValid, bool statusUnit1, bool statusUnit2, bool statusUnit3, int pilihUnit)
{
	switch(pilihUnit){
		case 1: *isValid = statusUnit1; break;
		case 2: *isValid = statusUnit2; break;
		case 3: *isValid = statusUnit3; break;
		default: *isValid = false;
	}
}

void batasBaterai(float *batUnit)
{
	if(*batUnit > 100){
		*batUnit = 100;
	} else if(*batUnit<0){
		*batUnit = 0;
	}
}
void tambahBaterai(float *batUnit, float menit){
	float persentase;
	ubahMenit(&persentase, menit);
	*batUnit += persentase;
	batasBaterai(batUnit);
}
void ubahMenit(float *persentase, float menit)
{
	*persentase = (menit/60)*100;
}
void tambahBateraiUnit(float *batUnit1, float *batUnit2, float *batUnit3, float menit, int pilihUnit)
{
	switch(pilihUnit){
		case 1: tambahBaterai(batUnit1, menit);break;
		case 2: tambahBaterai(batUnit2, menit);break;
		case 3: tambahBaterai(batUnit3, menit);break;
	}
}

void cekKondisi(bool *isValid, float batUnit, bool statusUnit)
{
	*isValid = (statusUnit && batUnit >= 30);
}
void cekKondisiUnit(bool *isValid, float batUnit1, float batUnit2,float batUnit3,
										bool statusUnit1,bool statusUnit2,bool statusUnit3,int pilihUnit){
	switch(pilihUnit) {
		case 1: cekKondisi(isValid, batUnit1, statusUnit1); break;
		case 2: cekKondisi(isValid, batUnit2, statusUnit2); break;
		case 3: cekKondisi(isValid, batUnit3, statusUnit3); break;
	default: *isValid = false;
	}
}
void kurangBaterai(float *batUnit, float menit)
{
	float persentase;
	ubahMenit(&persentase, menit);;
	
	*batUnit -= persentase;
	batasBaterai(batUnit);
}
void pengembalian(bool *statusUnit, float *batUnit, float durasiUnit)
{
	*statusUnit = true;
	kurangBaterai(batUnit, durasiUnit);
}


void pengembalianUnit(bool *statusUnit1,bool *statusUnit2,bool *statusUnit3, float *batUnit1,float *batUnit2,float *batUnit3,
											float durasiUnit1, float durasiUnit2, float durasiUnit3, int pilihanUnit){
	switch(pilihanUnit){
		case 1: pengembalian(statusUnit1, batUnit1, durasiUnit1);break;
		case 2: pengembalian(statusUnit2, batUnit3, durasiUnit2);break;
		case 3: pengembalian(statusUnit3, batUnit3, durasiUnit3);break;
	}
}


void ubahStatus(bool *statusUnit, float *durasiUnit, bool durasi){
	*statusUnit = false;
	*durasiUnit = durasi;
}
void ubahStatusUnit(bool *statusUnit1, bool *statusUnit2, bool *statusUnit3, float *durasiUnit1, float *durasiUnit2, float *durasiUnit3, float durasi, int pilihUnit)
{
	switch(pilihUnit){
		case 1: ubahStatus(statusUnit1, durasiUnit1, durasi);break;
		case 2: ubahStatus(statusUnit2, durasiUnit2, durasi);break;
		case 3: ubahStatus(statusUnit3, durasiUnit3, durasi);break;
	}
}
