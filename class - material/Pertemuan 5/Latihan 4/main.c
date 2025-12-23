#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	char input;
	printf("Masukan Minuman Favorit [k/t/s]");
	fflush(stdin); scanf("%c", &input);
	
	
	switch(input){
		case 'k':
		case 'K':
			printf("\nMinuman favorit anda adalah Kopi");
		break;
		case 't':
		case 'T':
			printf("\nMinuman favorit anda adalah Teh");
		break;
		case 's':
		case 'S':
			printf("\nMinuman favorit anda adalah Softdrink");
		break;
		default:
			printf("\napakah anda tidak punya minuman favorit?");
	}
	
	
	
	
	return 0;
}
