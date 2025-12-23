#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	float IPK;
	int SKS;
	
	printf("Masukan SKS : "); scanf("%d", &SKS);
	printf("Masukan IPK : "); scanf("%f", &IPK);
	if(IPK<2.0||SKS < 30){
		printf("\nMahasiswa dinyatakan DO");		
	}else{
		printf("\nMahasiswa dinyatakan LOLOS DO");
	}
	
	return 0;
}
