#include <conio.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
#define WARNING "\x1b[1;31m"
#define DEFAULT "\x1b[0m"
#define DONE "\x1b[1;32m"

typedef char string[50];

void initDataFlorist(string namaFlorist[]);
void initDataBunga(string namaBunga[]);
int getEmptyIndex(string array[]);
int cekKosong(string array[]);
int checkNamaUnik(string namaBunga[], string namaB);

int main(int argc, char *argv[]) {
    string namaFlorist[N], namaBunga[N], namaF, namaB, namaBungaBaru;
    int menu, index1, index2, i;
    char yayNay;

    initDataBunga(namaBunga);
    initDataFlorist(namaFlorist);
    do {
        system("cls");
        printf("\n\t--==[ PROJECT FLORIST ]==--");
        printf("\n[1] Create");
        printf("\n[2] Read");
        printf("\n[3] Update");
        printf("\n[4] Delete");
        printf("\n[0] Exit");
        printf("\n\t>>> ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                if (!(getEmptyIndex(namaFlorist) != -1) ||
                    !(getEmptyIndex(namaBunga) != -1)) {
                    printf("\n\t%s[!] ARRAY FLORIST PENUH [!]%s",WARNING, DEFAULT);
                    break;
                }
                index1 = getEmptyIndex(namaFlorist);
                index2 = getEmptyIndex(namaBunga);
                printf("\n\t CREATE DATA FLORIST");

                do {
                    printf("\n\t- Masukan nama florist : ");
                    fflush(stdin);
                    gets(namaF);
                    if (strlen(namaF) == 0)
                        printf("\n\t%s[!] Nama tidak boleh kosong [!]%s", WARNING, DEFAULT);
                } while (strlen(namaF) == 0);
                do {
                    printf("\n\t- Masukan nama bunga : ");
                    fflush(stdin);
                    gets(namaB);
                    if (strlen(namaB) == 0) {
                        printf("\n\t%s[!] Nama tidak boleh kosong [!]%s",WARNING, DEFAULT);
                        continue;
                    }
                    if (checkNamaUnik(namaBunga, namaB)!=-1) {
                        printf("\n\t%s[!] Nama bunga tidak boleh sama [!]%s",WARNING, DEFAULT);
                    }
                } while (strlen(namaB) == 0);
                strcpy(namaFlorist[index1], namaF);
                strcpy(namaBunga[index2], namaB);

                printf("\n\t%s[+] Berhasil create data [+]%s",DONE,DEFAULT);
                break;
            case 2:
                if(!(cekKosong(namaFlorist)!=-1)|| !(cekKosong(namaBunga)!=-1))
                {
                    printf("\n\t%s[!] Data masih Kosong [!]%s", WARNING, DEFAULT);
                    break;
                }
                printf("\n\t\t DATA FLORIST");
                for(i =0; i < N;i++)
                    if(strcmp(namaFlorist[i], "-")!= 0){
                        printf("\n\t[%2d]. Nama Florist    : %s", i+1, namaFlorist[i]);
                        printf("\n\t      Nama Bunga unik : %s", namaBunga[i]);

                    }
                break;
            case 3:
                if(cekKosong(namaFlorist)==-1||cekKosong(namaBunga)==-1){
                    printf("\n\t%s[!] Data masih Kosong [!]%s",WARNING, DEFAULT);
                    break;
                }
                printf("\n\t\t UPDATE DATA BUNGA FLORIST");
                printf("\n\tMasukan nama bunga : "); fflush(stdin); gets(namaB);
                if(checkNamaUnik(namaBunga, namaB)==-1){
                    printf("\n\t%s[!] Bunga tidak ditemukan [!]%s",WARNING, DEFAULT);
                    break;
                }
                printf("\n\tMasukan nama bunga baru : ");
                fflush(stdin); gets(namaBungaBaru);
                if(checkNamaUnik(namaBunga, namaBungaBaru)!=-1)
                {
                    printf("\n\t%s[!] Nama bunga harus unik [!]%s",WARNING, DEFAULT);
                    break;
                }
                index1 = checkNamaUnik(namaBunga, namaB);
                strcpy(namaBunga[index1], namaBungaBaru);
                printf("\n\t%s[+] Berhasil update data [+]%s", DONE, DEFAULT);
                break;
            case 4:
                if(cekKosong(namaFlorist)==-1||cekKosong(namaBunga)==-1){
                    printf("\n\t%s[!] Data masih Kosong [!]%s",WARNING, DEFAULT);
                    break;
                }
                printf("\n\t HAPUS DATA FLORIST");

                printf("\n\tMasukan nama florist : "); fflush(stdin); gets(namaF);
                if(checkNamaUnik(namaFlorist, namaF)==-1){
                    printf("\n\t%s[!] Florist tidak ditemukan [!]%s",WARNING, DEFAULT);
                    break;
                }
                printf("\n\tApakah anda yakin ingin menghapus florist ini ? [y/N]");
                yayNay = getchar();
                switch (yayNay) {
                    case 'Y':
                    case 'y':
                        index1 = checkNamaUnik(namaFlorist, namaF);
                        strcpy(namaFlorist[index1], "-");
                        strcpy(namaBunga[index1], "-");

                        printf("\n\t%s[*] Berhasil menghapus data [*]%s", DONE, DEFAULT);
                        break;
                    default:
                    case 27:
                    case 10:
                    case 13:
                    case 'n':
                    case 'N':
                        printf("\n\t%s[!] Batal menghapus data [!]%s", WARNING, DEFAULT);
                        break;
                }
                break;
            default:
                break;
        }
        getch();
    } while (menu != 0);
    return 0;
}

void initDataFlorist(string namaFlorist[]) {
    int i;
    for (i = 0; i < N; i++)
        strcpy(namaFlorist[i], "-");
}
void initDataBunga(string namaBunga[]) {
    int i;
    for (i = 0; i < N; i++)
        strcpy(namaBunga[i], "-");
}
int getEmptyIndex(string array[]) {
    int i;
    for (i = 0; i < N; i++)
        if (strcmp(array[i], "-") == 0)
            return i;
    return -1;
}
int cekKosong(string array[]) {
    int i;
    for (i = 0; i < N; i++)
        if (strcmp(array[i], "-") != 0)
            return i;
    return -1;
}
int checkNamaUnik(string namaBunga[], string namaB) {
    int i;
    for (i = 0; i < N; i++)
        if (strcmp(namaBunga[i], namaB) == 0)
            return i;
    return -1;
}
