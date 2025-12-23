#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int var;
	printf("Masukan input (angka): ");
	scanf("%d", &var);
	
	if(var > 0){
		printf("\nBilangan %d adalah bilangan positif", var);
	}else{
		printf("\nBilangan %d bukan bilangan positif", var);
	}
	return 0;
}
