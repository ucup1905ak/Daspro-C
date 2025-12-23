#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	float IPK, masaStudi;
	printf("Masukan IPK: ");fflush(stdin);scanf("%f", &IPK);
	printf("Masukan Masa Studi (tahun): ");fflush(stdin);scanf("%f", &masaStudi);
	if(IPK>3.51 && masaStudi <= 4.5){
		printf("\nSelamat anda telah lulus dengan predikat Cumlaude!!\IPK sebesar %.2f", IPK);		
		printf("\nStatus : Cumlaude");		
		printf("\nSelamat, Anda Lulus");
	}else if (IPK>2,76){
		printf("\nStatus : Sangat Memuaskan");		
		printf("\nSelamat, Anda Lulus");
	}else if (IPK>2,25){
		printf("Status : Memuaskan");		
		printf("\nSelamat, Anda Lulus");		
	}else if (IPK<2,25){
		printf("\nSelamat, Anda Lulus");
	}
	return 0;
}
