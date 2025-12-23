#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
//#include <stdbool.h>
#include <time.h>
typedef char string[100];
//#define USERNAME "Farel"
//#define PASSWORD "13000"
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
	char nama[100];
	int HP;
	int low_Attack;
	int high_Attack;
	int critChance;
}Pokemon_13000;
int ShowMenu(int select, Pokemon_13000 X, Pokemon_13000 Y);
void printPokemon(Pokemon_13000 X, Pokemon_13000 Y);
int calcDmg(Pokemon_13000 P);

int main(int argc, char * argv[]){
		srand(time(NULL));
		int round = 1 , surrender = 0;
		char menu = NULL;
		Pokemon_13000 Bulbasaur, Squirtle;
		// init
		strcpy (Bulbasaur.nama, "Bulbasaur");
		strcpy (Squirtle.nama, "Squirtle");
		Bulbasaur.HP = 1000;
		Squirtle.HP = 1500;
		Bulbasaur.low_Attack = 75;
		Bulbasaur.high_Attack = 130;
		Squirtle.low_Attack = 50;
		Squirtle.high_Attack = 80;
		Bulbasaur.critChance = 50;
		Squirtle.critChance = 50;

		int dmg,crit;
		
		while(1){
    	system("cls");
    	fflush(stdin);
      switch(ShowMenu(round%2,Bulbasaur, Squirtle)){
          case 49:
          	dmg = calcDmg((round%2)?Bulbasaur:Squirtle);
          	crit = calcCrit((round%2)?Bulbasaur:Squirtle);
						if(crit) dmg *= 2;
						if(crit) printf(GREEN"\n[*] CRITICAL HIT !"NORMAL);
						printf("\n[*] %d Damage has been done !", dmg);
						if(round % 2)
							Squirtle.HP -= dmg; // damage to squirtle
						else
							Bulbasaur.HP -= dmg; // damage to bulbasour
    				round++;
          break;
          case 50:
						surrender++;
          break;
          case 27:
              warning("Exiting...");
              return 0;
              break;
          default:
              warning("Input tidak valid");
              break;
      }
      if(surrender)break;
			if(Bulbasaur.HP <=0 || Squirtle.HP <=0)break;
      pause();
    }
		if(surrender){
		if(round%2){
  		printf(GREEN"\n[*] Bulbasaur surrendered, Squirtle won with %d HP left", Squirtle.HP);
			printf(NORMAL);
  		return 0;
		}else{
  		printf(GREEN"\n[*] Squirtle surrendered, Bulbasaur won with %d HP left", Bulbasaur.HP);
			printf(NORMAL);
			return 0;
		}
		}

    
    system("cls");
   if(Bulbasaur.HP <=0){
    	Bulbasaur.HP = 0;
			printPokemon(Bulbasaur, Squirtle);
			printf(RED"\n[!] Bulbasaur fainted [!]");
    	printf(GREEN"\n[*] Squirtle won with %d HP left [*]", Squirtle.HP);
		}else if(Squirtle.HP <=0){
    	system("cls");
    	Squirtle.HP = 0;
			printPokemon(Bulbasaur, Squirtle);
    	printf(RED"\n[!] Squirtle fainted [!]");
    	printf(GREEN"\n[*] Bulbasaur won with %d HP left [*]", Bulbasaur.HP);
    	
		}
		printf(NORMAL);
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



int calcDmg(Pokemon_13000 P){
	return rand()%(P.high_Attack-P.low_Attack) + P.low_Attack;
}

int calcCrit(Pokemon_13000 P){
	return ((rand()%100 + 1) < (P.critChance))?1:0;
}
void printPokemon(Pokemon_13000 X, Pokemon_13000 Y){
	printf("-------------- POKEMON BATTLE --------------\n\n");
	printf("------------\t\t\t------------\n");
	printf("|%-10s|\t    vs  \t|%-10s|\n", X.nama, Y.nama);
	printf("------------\t\t\t------------\n");
	printf("HP  : %-4d\t\t\tHP  : %-4d\n", X.HP, Y.HP);
	printf("Att : %d-%d\t\t\tAtt : %d-%d\n", X.low_Attack, X.high_Attack, Y.low_Attack, Y.high_Attack);

}
int ShowMenu(int select,Pokemon_13000 X, Pokemon_13000 Y){
	printPokemon(X,Y);
	printf("\n%s's Turn !", (select)?X.nama:Y.nama);
	printf("\n[1] Normal Attack");
	printf("\n[2] Surrender");
	printf("\n>>> ");
	return getchar();
}

















