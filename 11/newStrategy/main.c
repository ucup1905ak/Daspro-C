#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
//#include <string.h>
//#include <stdbool.h>
//#include <time.h>
typedef char string[100];
//#define USERNAME "Farel"
//#define PASSWORD "13000"
//#define DEV 0
//#define SAVE "\033[s"
//#define GOBACK "\033[u"
//#define CLEARDOWN "\033[0J"
#define RED "\033[38;2;255;0;0m"
#define GREEN "\033[38;2;0;255;0m"
#define NORMAL "\033[0m"

void warning(char * s);
void success(char *s);
void pause();

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

int main(int argc, char * argv[]){
    char menu = NULL;
    while(1){
        switch(getch()){
            case 49:
            break;
            case 50:
            break;
            case 51:
            break;
            case 52:
            break;
            case 27:
                warning("Exiting...");
                return 0;
                break;
            default:
                warning("Input tidak valid");
                break;
        }
        pause();
    }
    return 0;
}
