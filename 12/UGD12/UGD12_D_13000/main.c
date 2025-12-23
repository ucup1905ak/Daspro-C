#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
typedef char string[100];

#define MAX_VOTER 10
#define MAX_KANDIDAT 10



#define S "\033[s"
#define U "\033[u"
#define CLEAR "\033[0J"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define NORMAL "\033[0m"

void warning(char * s);
void success(char *s);
void pause();

typedef struct{
	string nama;
	string NIK;
	string asal;
}Voter;

typedef struct{
	string nama;
	int umur;
	string partai;
	Voter voters[MAX_VOTER];
}Kandidat;
int isAlreadyExistNIK(Kandidat K[], string NIK);
int countVote(Kandidat K);
float countPercent(Kandidat K[], int vote);
void initializeKandidat(Kandidat K[]);
void initializeVoters(Voter V[]);
Kandidat createKandidat(string nama, int umur, string partai);
int getEmptyKandidat(Kandidat K[]);
int isEmptyKandidat(Kandidat K[]);
int isAlreadyExist(Kandidat K[], string partai);
int getKandidat(Kandidat K[], string nama);
int uniqueAsal(Voter V[]);
int isAlreadyExistName(string array[], string s, int max);
int getEmptyString(string array[], int max);
int getPemenang(Kandidat K[]);

int main(int argc, char * argv[]){
    char menu = NULL;
    Kandidat K[MAX_KANDIDAT];
    initializeKandidat(K);
    string tempNama, tempPartai;
    int umur , idx, voteIdx;
    int err_1, err_2;
    int i;
    
    while(menu != 27){
	    system("cls");
    	printf("\n\t=== [ SISTEM PEMILIHAN UMUM SEDERHANA ] ===");
    	printf("\n[1]. Ajukan Kandidat");
    	printf("\n[2]. Diskualifikasi Kandidat");
    	printf("\n[3]. Cek Suara Kandidat");
    	printf("\n[4]. Lakukan Vote");
    	printf("\n[5]. Cek Perhitungan Sementara");
    	printf("\n[6]. Hitung Pemenang [TIDAK BONUS]");
    	printf("\n>>> ");
    	fflush(stdin);menu = getch();
		Sleep(100);
      	switch(menu){
	      	case 49://create kandidat
	      	idx = getEmptyKandidat(K);
	      	if(idx < 0){
	      	warning("Kandidat sudah penuh");
	      	break;
		  	}
	      	do{
	    	printf(S);
		  	printf("\nMasukan Nama Partai Pengusung   : "); fflush(stdin);
	      	gets(tempPartai);
	      	if(strcmp(tempPartai, "")==0||strcmp(tempPartai, "-")==0){
	          	warning("Nama Tidak Boleh Kosong");
				getch();
				printf(U CLEAR);
				continue;
			  }else
			if(isAlreadyExist(K, tempPartai)){
	          	warning("1 partai hanya boleh mengusung 1 kandidat");
				getch();
				printf(U CLEAR);
				continue;
			}
			break;
		  }while(1);
		  
			do{
	      	printf(S);
	      	printf("\nMasukan Nama Kandidat   		: "); fflush(stdin);
	      	gets(tempNama);
	      	if(strcmp(tempNama, "")==0||strcmp(tempNama, "-")==0){
	          	warning("Nama Tidak Boleh Kosong");
				getch();
				printf(U CLEAR);
			  }
		  	}while(strcmp(tempNama, "")==0||strcmp(tempNama, "-")==0);
		  		  
			do{
	      	printf(S);
	      	printf("\nMasukan Umur Kandidat   		: ");
	      	fflush(stdin);
	      	if( scanf("%d", &umur) !=1|| umur < 40){
	          	warning("Umur Tidak Valid");
				getch();
				printf(U CLEAR);
				continue;
			  }
			break;
		  	}while(1);
		  
	    
	    	K[idx] = createKandidat(tempNama, umur,tempPartai);
	    	printf(GREEN"\n\t[*] Partai %s telah mengusung %s [*]"NORMAL, K[idx].partai, K[idx].nama);
	      break;
	      case 50:
	      	if(isEmptyKandidat(K)){
	      		warning("Belum ada kandidat");
	      		break;
			  }
			  
			printf("\nMasukan Nama Kandidat : ");fflush(stdin);
			gets(tempNama);
			idx = getKandidat(K, tempNama);
//			printf("\n\n%d", idx);
			if(idx < 0){
				warning("Kandidat tidak ditemukan");
				break;
			}
			
			K[idx] = createKandidat("-", 0, "-");
	    	printf(GREEN"\n\t[*] Berhasil mendiskualifikasi Kandidat [*]"NORMAL);
			
			
	      break;
	      case 51:
	      	if(isEmptyKandidat(K)){
	      		warning("Belum ada kandidat");
	      		break;
			}
			printf("\nMasukan Nama Kandidat : ");fflush(stdin);
			gets(tempNama);
			idx = getKandidat(K, tempNama);
//			printf("\n\n%d", idx);
			if(idx < 0){
				warning("Kandidat tidak ditemukan");
				break;
			}
			
			printf("\n\tKandidat %s memiliki %d suara", K[idx].nama , countVote(K[idx]));
			  
		  break;
	      case 52:
	      	if(isEmptyKandidat(K)){
	      		warning("Belum ada kandidat");
	      		break;
			}
			
			printf("\nMasukan Nama Kandidat : ");fflush(stdin);
			gets(tempNama);
			idx = getKandidat(K, tempNama);
//			printf("\n\n%d", idx);
			if(idx < 0){
				warning("Kandidat tidak ditemukan");
				break;
			}
			
			voteIdx = getEmptyVote(K[idx]);
	      	printf(S);
			do{
	      	printf("\nMasukan Nama Voter   		: "); fflush(stdin);
	      	gets(tempNama);
	      	if(strcmp(tempNama, "")==0||strcmp(tempNama, "-")==0){
	          	warning("Nama Tidak Boleh Kosong");
				getch();
				printf(U CLEAR);
			  }
		  	}while(strcmp(tempNama, "")==0||strcmp(tempNama, "-")==0);
		  	
			strcpy(K[idx].voters[voteIdx].nama,tempNama);

	      	printf(S);
			while(1){
	      		printf("\nMasukan NIK Voter   		: "); fflush(stdin);
	      		gets(tempNama);
				if(strcmp(tempNama, "")==0||strcmp(tempNama, "-")==0){
					warning("NIK Tidak Boleh Kosong");
					getch();
					printf(U CLEAR);
					continue;
				}
				if(isAlreadyExistNIK(K, tempNama)){
					warning("NIK ini sudah digunakan");
					getch();
					printf(U CLEAR);
					continue;
				}
				break;
			}
			strcpy(K[idx].voters[voteIdx].NIK,tempNama);
			
			printf(S);
			do{
	      	printf("\nMasukan Asal Voter   		: "); fflush(stdin);
	      	gets(tempNama);
	      	if(strcmp(tempNama, "")==0||strcmp(tempNama, "-")==0){
	          	warning("Asal Tidak Boleh Kosong");
				getch();
				printf(U CLEAR);
			  }
		  	}while(strcmp(tempNama, "")==0||strcmp(tempNama, "-")==0);
		  	
			strcpy(K[idx].voters[voteIdx].asal,tempNama);

//			
		  	break;
		  	
	      case 53:
	      if(isEmptyKandidat(K)){
	      		warning("Belum ada kandidat");
	      		break;
			  }
//		  system("cls");
		  
		  for(i=0;i<MAX_KANDIDAT ; i++){
		  	if(strcmp(K[i].nama, "-") ==0) continue;
			printf("\nKandidat nomor urut %d", i);
			printf("\nNama\t: %s", K[i].nama );
			printf("\nPartai\t: %s", K[i].partai );
			printf("\nJumlah Suara\t: %d", countVote(K[i]));
			printf("\n%.2f persen dari populasi suara", countPercent(K, countVote(K[i])));
		  }
		  
		  break;
	      case 54:
	      if(isEmptyKandidat(K)){
	      		warning("Belum ada kandidat");
	      		break;
			  }



							printf("\nMasukan Nama Kandidat : ");fflush(stdin);
			gets(tempNama);
			idx = getKandidat(K, tempNama);
//			printf("\n\n%d", idx);
			if(idx < 0){
				warning("Kandidat tidak ditemukan");
				break;
			}
			
			printf("\n\t[%d] << ASAL UNIK", uniqueAsal(K[idx].voters));
			getPemenang(K);
		  break;
	      case 27:
	          warning("Exiting...");
	          break;
	      default:
	          warning("Input tidak valid");
	          break;
      }
      if(menu!=27)pause();
    }
    return 0;
}


///----------------------------------------------


void warning(char * s){
	printf(RED "\n\n\t[!] %s [!]" NORMAL, s);
}
void success(char *s){
	printf(GREEN "\n\n\t[*] %s [*]" NORMAL, s);
}

void pause(){
    printf(NORMAL "\n\n\tPress any key to continue.");
    getch();
}

///-----------------------------------------------




void initializeKandidat(Kandidat K[]){
	int i;
	for(i = 0 ; i < MAX_KANDIDAT ; i++){
		K[i] = createKandidat("-", 0, "-");
	}
}
void initializeVoters(Voter V[]){
	int i;
	for(i = 0 ; i < MAX_VOTER ; i++){
		strcpy(V[i].nama,"-");
		strcpy(V[i].NIK,"-");
		strcpy(V[i].asal,"-");
	}
}
Kandidat createKandidat(string nama, int umur, string partai){
	Voter voters[MAX_VOTER];
	Kandidat K;

	initializeVoters(K.voters);
	strcpy(K.nama , nama);
	K.umur = umur;
	strcpy(K.partai , partai);
	return K;
}



int countVote(Kandidat K){
	int count = 0, i;
	for(i = 0 ; i < MAX_VOTER; i++ ){
		if(strcmp(K.voters[i].nama, "-") != 0)count++;
	}
	return count;
}

int getEmptyVote(Kandidat K){
	int i;
	for(i = 0 ; i < MAX_VOTER; i++){
		if(strcmp(K.voters[i].nama, "-") == 0) return i;
	}
	return -1;
}
float countPercent(Kandidat K[], int vote){
	int i, j;
	float count = 0;
	for (i = 0 ; i < MAX_KANDIDAT; i++){
		count += countVote(K[i]);
//		for(j = 0 ; j < MAX_VOTER ; j++){	
//		}
	}
	return ((float)vote / count ) * 100;	
}

int getEmptyString(string array[], int max){
	int i;
	for(i = 0 ; i < max; i++){
		if(strcmp(array[i], "") == 0) return i;
	}
	return -1;
}

int isAlreadyExistName(string array[], string s, int max){
	int i;
	for(i = 0 ; i < max ; i++){
		if(strcmp(array[i], s) == 0) return i;
	}
	return -1;
}

int uniqueAsal(Voter V[]){
	int i  ;
	int count = 0;
	string X[MAX_VOTER];
	for(i = 0 ; i < MAX_VOTER ; i++)strcpy(X[i],"-");
	
	for(i = 0 ; i < MAX_VOTER; i++){
		if(isAlreadyExistName(X, V[i].asal, MAX_VOTER) < 0){
			strcpy(X[count++], V[i].asal);
//			printf("\n[ TAMBAHHH WOEE   ]");
		}
	}
	/*
	for(i = 0 ; i < MAX_VOTER ; i++){
		printf("\n[%s]", X[i]);
	}
	*/
	return count;
}

int isAlreadyExistNIK(Kandidat K[], string NIK){
	int i, j;
	for (i = 0 ; i < MAX_KANDIDAT; i++){
		for(j = 0 ; j < MAX_VOTER ; j++){	
//		printf("\nCEK NIK : [%s] << [%s]",K[i].voters[j].NIK, NIK );
		if(strcmp(K[i].voters[j].NIK, NIK) == 0)return 1;
		}
	}
	return 0;	
}
int getKandidat(Kandidat K[], string tempnama){
	int i;
	for (i = 0 ; i < MAX_KANDIDAT; i++){
//		printf("\n%s - %s", K[i].nama , tempnama);
		if(strcmpi(K[i].nama, tempnama) == 0)return i;
	}
	return -1;
}


int isAlreadyExist(Kandidat K[], string partai){
	int i;
	for (i = 0 ; i < MAX_KANDIDAT; i++){
		if(strcmp(K[i].partai, partai) == 0)return 1;
	}
	return 0;
}


int getEmptyKandidat(Kandidat K[]){
	int i;
	for(i = 0 ; i < MAX_KANDIDAT; i++){
		if(strcmp(K[i].nama, "-") == 0) return i;
	}
	return -1;
}
int isEmptyKandidat(Kandidat K[]){
	int i;
	for(i = 0 ; i < MAX_KANDIDAT; i++){
		if(strcmp(K[i].nama, "-") != 0) return 0;
	}
	return 1;
}


int getPemenang(Kandidat K[]){
	int i,temp = 0;
	int hitungA[MAX_KANDIDAT], hitungB[MAX_KANDIDAT];
	
	
	for(i=0; i < MAX_KANDIDAT; i++){
		hitungA[i] = countVote(K[i]);
		hitungB[i] = uniqueAsal(K[i].voters);
	}
	
	for(i = 0 ; i < MAX_KANDIDAT ; i++)
	printf("\n[%s] -> %d[%d]", K[i].nama, hitungA[i], hitungB[i]);
}












