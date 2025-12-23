#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char string[100];
#define USERNAME "Farel"
#define PASSWORD "13000"
#define DEV 0
#define SAVE "\033[s"
#define GOBACK "\033[u"
#define CLEARDOWN "\033[0J"
#define RED "\033[38;2;255;0;0m"
#define GREEN "\033[38;2;0;255;0m"
#define NORMAL "\033[0m"

typedef struct{
	string tipe;
	int jumlah;
}Skin_13000;

typedef struct{
	string nama;
	string hero_type;
	string role;
	float harga;
	Skin_13000 skin;
}Hero_13000;


int resetDataHero(Hero_13000 *h1, Hero_13000 *h2);
int UpdateDataSkin(Skin_13000 *s);
void updateDataHero(Hero_13000 *h1, Hero_13000 *h2);
Hero_13000 initialize();
void printMenu();
int login(char * username, char * password);
Skin_13000 inputDataSkin();
Hero_13000 inputDataHero();
void printDataHero(Hero_13000 H);
void warning(char * s);
void success(char *s);
int cekHeroKosong(Hero_13000 h);



int main(int argc, char *argv[]) {
	if(!login(USERNAME, PASSWORD))return 1;
	system("color 0f");
	printf(NORMAL);
	Hero_13000 h1,h2;
	h1 = initialize();
	h2 = initialize();
	
	char menu;
	do{
		system("cls");
//		printf(SAVE);
		printMenu();
		fflush(stdin);
		scanf("%c", &menu);
		switch(menu){
			case 27:
				printf(GREEN"\n\nFarelino Alexander Kim| 13000 | D\n\n");
				return 0;
				break;
			default:
				warning("Menu tidak ada");
				break;
			case 49: //CASE 1
				if(cekHeroKosong(h1)){
					
					h1 = inputDataHero();
//					printDataHero(h1);
				}
				else if(cekHeroKosong(h2)){
					
					h2 = inputDataHero();
//					printDataHero(h2);
				}
				else
					warning("Anda Sudah Menginputkan Semua Data");
				break;
			case 50: //case 2
				if(cekHeroKosong(h1) && cekHeroKosong(h2)){
					warning("Data Belum Terisi");
					break;
				}
				printf("\n\n\t--- Tampil Data Hero ---");
				if(!cekHeroKosong(h1))printDataHero(h1);
				if(!cekHeroKosong(h2))printDataHero(h2);
			break;
			case 51:
				resetDataHero(&h1, &h2);
				break;
			case 52:
				puts("\t--- [Ubah Tipe Skin] ---");
				updateDataHero(&h1, &h2);
				break;
		}
		getch();
	}while(menu != 27);
	
	return 0;
}
void delay(int ms){ 
	time_t pp = clock();
	while(clock() < pp + ms){
	};
}

void loadingLoop(int i){
	switch(i%4){
		case 0:
		printf("Loading \\");
		break;
		case 1:
		printf("Loading |");
		break;
		case 2:
		printf("Loading /");
		break;
		case 3:
		printf("Loading -");
		break;
	}
}
void loading(int max, int dly){
	int i, j;
	for(i = 0 ; i < max;i++){
		printf("\r");
		loadingLoop(i);
			
		printf(" [");
		for(j=0; j <i ;j++) printf("-");
		for(j=max-i-1; j > 0 ;j--) printf(" ");
		printf("] ");
		delay(dly);
	}
}

int login(char * username, char * password){
	string user, pass;
	if(!DEV){
		
	do{
		system("cls");
		printf("\t=== LOGIN [MOONTON] ===\n");
		printf("\nMasukkan Username       :"); scanf("%s", user);
		printf("\nMasukkan Password       :"); scanf("%s", pass);
		if(strcmp(username, user)!=0 || strcmp(password, pass)!=0 ){
			printf("\n\n\tUsername atau Password Anda Salah!");
			getch();
		}
	}while(strcmp(username, user)!=0 || strcmp(password, pass)!=0 );
	printf("\n\n\tHallo admin, Anda Berhasil Login!!!");
	system("cls");
	
	}
	system("color 8f");
	printf("\n\n");
	loading(20,100);
	printf("\n\n");
	printf("\n\n\tPress Any key to continue");
	getch();
}

int cekTipeSkin(char * s){
	if(strcmpi("Elite", s)==0)return 1; //Elite
	if(strcmpi("Epic", s)==0)return 2; //Epic
	if(strcmpi("Legend", s)==0)return 3; //Legend
	return 0;
}
void warning(char * s){
	printf(RED "\n\n\t[!] %s [!]" NORMAL, s);
}
void success(char *s){
	printf(GREEN "\n\n\t[*] %s [*]" NORMAL, s);
}


Skin_13000 inputDataSkin(){
	Skin_13000 s;
	string inA;
	int inB;
	printf("\n\t\t--- Input Skin Hero ---\n\n");
	do{
		printf(SAVE);
		printf("\tMasukkan Tipe Skin (Elite | Epic | Legend)      : ");
		scanf("%s", inA);
		if(!cekTipeSkin(inA)){
			warning("Inputan Salah");
			getch();
			printf(GOBACK CLEARDOWN);
		}
	}while(!cekTipeSkin(inA));
	strcpy(s.tipe, inA);
	
	do{
		printf(SAVE);
		printf("\tMasukkan Jumlah Skin    : ");
		fflush(stdin);
		if(scanf("%d", &inB)!=1)continue;

		if(inB <=0 ){
			warning("Inputan Harus Tidak Boleh Kurang dari atau Sama Dengan 0");
			getch();
			printf(GOBACK CLEARDOWN);
		}
	}while(inB <=0 );
	s.jumlah = inB;
	success("Berhasil Menginputkan Data");
	return s;
}

int cekTipeHero(char * s){
	//(Fighter | Marksman | Mage | Support | Tanker | Assasin)
	if(strcmpi("Fighter", s)==0)return 1; 
	if(strcmpi("Marksman", s)==0)return 2;
	if(strcmpi("Mage", s)==0)return 3; 
	if(strcmpi("Support", s)==0)return 4; 
	if(strcmpi("Tanker", s)==0)return 5; 
	if(strcmpi("Assasin", s)==0)return 6; 
	return 0;
}

int cekRoleHero(char * s){
	//(Roamer | Gold | Exp | Midlane | Jungler)
	if(strcmpi("Roamer", s)==0)	return 1; 
	if(strcmpi("Gold", s)==0)	return 2; 
	if(strcmpi("Exp", s)==0)	return 3; 
	if(strcmpi("Midlane", s)==0)return 4; 
	if(strcmpi("Jungler", s)==0)return 5; 
	return 0;
}
Hero_13000 inputDataHero(){
	Hero_13000 h;
	string inA;
	printf("\n\t--- Input Data Hero ---\n\n");
	do{
		printf(SAVE);
		printf("\tMasukkan Nama Hero\t: ");fflush(stdin);gets(inA);
		if(strcmpi(inA, "")==0 || strcmpi(inA, "-")==0){
			warning("Inputan Tidak Boleh Kosong atau '-'");
			getch();
			printf(GOBACK CLEARDOWN);
		}
	}while(strcmpi(inA, "")==0|| strcmpi(inA, "-")==0);
	strcpy(h.nama, inA);
	do{
		printf(SAVE);
		printf("\n\tMasukkan Hero Type (Fighter | Marksman | Mage | Support | Tanker | Assasin)  : ");
		scanf("%s", inA);
		if(!cekTipeHero(inA)){
			warning("Inputan Salah");
			getch();
			printf(GOBACK CLEARDOWN);
		}
	}while(!cekTipeHero(inA));
	strcpy(h.hero_type, inA);
	
	do{
		printf(SAVE);
		printf("\n\tMasukkan Role Hero (Roamer | Gold | Exp | Midlane | Jungler)\t: ");
		scanf("%s", inA);
		if(!cekRoleHero(inA)){
			warning("Inputan Salah");
			getch();
			printf(GOBACK CLEARDOWN);
		}
	}while(!cekRoleHero(inA));
	strcpy(h.role, inA);
	h.skin = inputDataSkin();
	return h;
}


void printDataHero(Hero_13000 H){
	printf("\n\t\t[*] Data Hero\n");
	printf("\t\t\t nama Hero\t\t: %s\n", H.nama);
	printf("\t\t\t Type Hero\t\t: %s\n", H.hero_type);
	printf("\t\t\t Role Hero\t\t: %s\n", H.role);
	printf("\t\t\t Harga Hero\t\t: %.2f\n\n", H.harga);
	printf("\t\t\t --- Tampil Skin Hero ---\n\n");
	printf("\t\t\t\t Tipe Skin\t\t: %s\n\n", H.skin.tipe);
	printf("\t\t\t\t Jumlah Skin\t\t: %d\n\n", H.skin.jumlah);	
}


void printMenu(){
	puts("=== [UGD RECORD (MOBILE LEGENDS)] ===\n\n");
	puts("[1]   Masukkan Data Hero");
	puts("[2]   Show Data Hero");
	puts("[3]   Reset Data Hero");
	puts("[4]   Ubah Data Hero [BONUS]");
	puts("[ESC] Keluar Program");
	printf(">> ");
}


Hero_13000 initialize(){
	Hero_13000 h;
	strcpy(h.nama, "-");
	strcpy(h.hero_type, "-");
	strcpy(h.role, "-");
	h.harga = 0;
	h.skin.jumlah =0;
	strcpy(h.skin.tipe, "-");
	return h;
}


int cekHeroKosong(Hero_13000 h){
	if(strcmp(h.nama, "-")==0) return 1;
	return 0;
}







int resetDataHero(Hero_13000 *h1, Hero_13000 *h2){
	char input;
	string inA;
	do{

	system("cls");
	puts("\t--- [Reset Data Hero] ---");
	puts("1. Reset Semua Data Hero");
	puts("2. Reset Salah Satu Data Hero");
	puts("[ESC] Keluar Menu Reset Data Hero");
	printf(">> ");
	fflush(stdin);
//	scanf("%c", &input);
	switch(getch()){
		case 49:
			*h1 = initialize();
			*h2 = initialize();
			success("Berhasil Menghapus Data");
			break;
		case 50:
			printf("\n\n\tMasukkan Nama Hero      : ");
			scanf("%s", inA);
			if(strcmpi(h1->nama , inA) == 0){
				*h1 = initialize();
				success("Berhasil Menghapus Data");
			} else if(strcmpi(h2->nama , inA) == 0){
				*h2 = initialize();
				success("Berhasil Menghapus Data");
			}else {
				warning("Nama Hero tidak ada");
			}
			break;
		case 27:
			warning("Back to main menu");
			return 0;
			break;
		default:
			warning("Input tidak ada");
			break;
	}getch();
	}while(input != 27);
}

int UpdateDataSkin(Skin_13000 *s){
	char input; int inB;
	do{
	system("cls");
	puts("\t--- [Ubah Tipe Skin] ---");
	puts("1. Elite");
	puts("2. Epic");
	puts("3. Legend");
	puts("[ESC] Keluar Menu Reset Data Hero");
	printf(">> ");
	fflush(stdin);
//	input = getch();
	switch(getch()){
		case 49:
			if(strcmpi(s->tipe, "Elite")==0){
				warning("TIdak Bisa Merubah ke tipe ini");
				getch();
				break;
			}
			strcpy(s->tipe, "Elite");
						do{
				printf(SAVE);
				printf("\n\tMasukkan Jumlah Skin    : ");
				fflush(stdin);
				if(scanf("%d", &inB)!=1)continue;

				if(inB <=0 ){
					warning("Inputan Harus Tidak Boleh Kurang dari atau Sama Dengan 0");
					getch();
					printf(GOBACK CLEARDOWN);
				}
			}while(inB <=0 );
			s->jumlah = inB;
			success("Berhasil Menginputkan Data");
			break;
			break;
		case 50:
			if(strcmpi(s->tipe, "Epic")==0){
				warning("TIdak Bisa Merubah ke tipe ini");
				getch();
				break;
			}
			strcpy(s->tipe, "Epic");
						do{
				printf(SAVE);
				printf("\n\tMasukkan Jumlah Skin    : ");
				fflush(stdin);
				if(scanf("%d", &inB)!=1)continue;

				if(inB <=0 ){
					warning("Inputan Harus Tidak Boleh Kurang dari atau Sama Dengan 0");
					getch();
					printf(GOBACK CLEARDOWN);
				}
			}while(inB <=0 );
			s->jumlah = inB;
			success("Berhasil Menginputkan Data");
			break;
		case 51:
			if(strcmpi(s->tipe, "Legend")==0){
				warning("TIdak Bisa Merubah ke tipe ini");
				getch();
				break;
			}
			strcpy(s->tipe, "Legend");

			do{
				printf(SAVE);
				printf("\n\tMasukkan Jumlah Skin    : ");
				fflush(stdin);
				if(scanf("%d", &inB)!=1)continue;

				if(inB <=0 ){
					warning("Inputan Harus Tidak Boleh Kurang dari atau Sama Dengan 0");
					getch();
					printf(GOBACK CLEARDOWN);
				}
			}while(inB <=0 );
			s->jumlah = inB;
			success("Berhasil Menginputkan Data");
			break;
		case 27:
			warning("Kembali ke menu utama");
			return 0;
			break;
		default:
			warning("Input tidak ada");
			break;
	}getch();
 }while(input != 27);
}
void updateDataHero(Hero_13000 *h1, Hero_13000 *h2){
		char input;
		string inA;

		printf("\n\n\tMasukkan Nama Hero      : ");
			scanf("%s", inA);
			if(strcmpi(h1->nama , inA) == 0){
					UpdateDataSkin(&(h1->skin));
			} else if(strcmpi(h2->nama , inA) == 0){
					UpdateDataSkin(&(h2->skin));
			}else {
				warning("Nama Hero tidak ada");
		}

}
