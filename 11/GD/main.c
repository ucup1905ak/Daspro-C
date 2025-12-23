#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char str[100];

typedef struct{
    str nama;
    str jabatan;
    float gaji;
}Karyawan;

void showmenu();
void initData(Karyawan *K);
void KaryawanBuilder(Karyawan *K, str nama, str jabatan, float gaji);
bool isEmpty(Karyawan K);
void tampilData(Karyawan K);
float totalGaji(Karyawan K);
void clearBuffer();

int main(int argc, char *argv[]){
    Karyawan K;
    char menu;
    str nama, jabatan;
    float gaji;
    
    initData(&K);
    
    
    do{
        system("cls");
        showmenu();menu = getche();
        getch();
        switch(menu){
            case '1':
                if(!isEmpty(K)){
                    printf("\n\t[!] Data sudah terisi [!]",K.nama);
                    break;
                }
                
                printf("\n\t\t=== [Input Data] ===\n");
                do{
                    printf("\n\tMasukan nama karyawan : ");fflush(stdin);gets(nama);
                    if(strcmp(nama,"-")==0 || strlen(nama)==0){
                        printf("\n\t[!] Nama Karyawan tidak boleh - atau kosong [!]\n");
                    }
                }while(strcmp(nama,"-")==0 || strlen(nama)==0);
                
                do{
                    printf("\n\tMasukan jabatan karyawan : ");fflush(stdin);gets(jabatan);
                    if(strlen(jabatan)==0){
                        printf("\n\t[!] Jabatan Karyawan tidak boleh kosong [!]\n");
                    }
                }while(strlen(jabatan)==0);
                
                do{
                    printf("\n\tMasukan gaji karyawan : ");scanf("%f", &gaji);
                    if(gaji <= 0){
                        printf("\n\t[!] Gaji tidak boleh kurang atau sama dengan 0 [!]\n");
                    }
                }while(gaji <= 0);
                
                KaryawanBuilder(&K, nama, jabatan, gaji);
                printf("\n\t[+] Berhasil Input Data [+]");
                break;
            case '2':
                if(isEmpty(K)){
                    printf("\n\t[!] Data masih kosong [!]");
                    break;
                }
                
                printf("\n\t\t=== [Show Data] ===\n");
                tampilData(K);
                break;
            case '3':
                if(isEmpty(K)){
                    printf("\n\t[!] Data masih kosong [!]");
                    break;
                }
                
                printf("\n\t\t=== [Delete Data] ===\n");
                printf("\n\tApakah kamu yakin ingin menghapus Data Karyawan? [y/N]: ");
                clearBuffer();
                char confirm = getchar();
                
                if(confirm != 'y' && confirm != 'Y'){
                    printf("\n\t[!] Penghapusan dibatalkan [!]");
                    break;
                }
                
                initData(&K);
                printf("\n\t[+] Berhasil hapus data [+]");
                break;
            case '4':
                if(isEmpty(K)){
                    printf("\n\t[!] Data masih kosong [!]");
                    break;
                }
                
                printf("\n\t\t=== [Update Data] ===\n");
                printf("\n\tApakah kamu yakin ingin mengganti Data Karyawan? [y/N]: ");
                clearBuffer();
                confirm = getchar();
                
                if(confirm != 'y' && confirm != 'Y'){
                    printf("\n\t[!] Update dibatalkan [!]");
                    break;
                }
                
                do{
                    printf("\n\tMasukan nama karyawan baru : ");fflush(stdin);gets(nama);
                    if(strcmp(nama,"-")==0 || strlen(nama)==0){
                        printf("\n\t[!] Nama Karyawan tidak boleh - atau kosong [!]\n");
                    }
                }while(strcmp(nama,"-")==0 || strlen(nama)==0);
                
                do{
                    printf("\n\tMasukan jabatan karyawan baru : ");fflush(stdin);gets(jabatan);
                    if(strlen(jabatan)==0){
                        printf("\n\t[!] Jabatan Karyawan tidak boleh kosong [!]\n");
                    }
                }while(strlen(jabatan)==0);
                
                do{
                    printf("\n\tMasukan gaji karyawan baru : ");scanf("%f", &gaji);
                    if(gaji <= 0){
                        printf("\n\t[!] Gaji tidak boleh kurang atau sama dengan 0 [!]\n");
                    }
                }while(gaji <= 0);
                
                KaryawanBuilder(&K, nama, jabatan, gaji);
                printf("\n\t[+] Berhasil update data [+]");
                break;
            case 27:
                printf("\n\n\t~Farelino Alexander Kim | 240713000 | D");
                break;
            default:
                printf("\n\t[!] Menu Tidak Ada [!]");
                break;
        }
        getch();
    }while(menu!=27);
    return 0;
}

void showmenu(){
		puts("\t =============");
    puts("\t< Guided Record >");
    puts("\t =============\n");
    puts("[1] Input Data Karyawan");
    puts("[2] Show Data Karyawan");
    puts("[3] Delete Data Karyawan");
    puts("[4] Update Data Karyawan");
    puts("[0] Exit");
    printf(">>> ");
}

void initData(Karyawan *K){
    strcpy((*K).nama, "-");
    strcpy((*K).jabatan, "-");
    (*K).gaji = 0.0;
}

void KaryawanBuilder(Karyawan *K, str nama, str jabatan, float gaji){
    strcpy((*K).nama, nama);
    strcpy((*K).jabatan, jabatan);
    (*K).gaji = gaji;
}

void tampilData(Karyawan K){
    printf("\n\tNama Karyawan\t\t: %s", K.nama);
    printf("\n\tJabatan Karyawan\t: %s", K.jabatan);
    printf("\n\tGaji Karyawan\t\t: Rp %.2f", K.gaji);
    printf("\n\tTotal Gaji Karyawan\t: Rp %.2f", totalGaji(K));
}

bool isEmpty(Karyawan K){
    if(strcmp(K.nama,"-")==0){
        return true;
    }
    return false;
}

float totalGaji(Karyawan K){
    float pajak;
    if(K.gaji <= 100000){
        pajak = 0;
    }else{
        pajak = 0.02 * K.gaji;
    }
    return K.gaji - pajak;
}

void clearBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

