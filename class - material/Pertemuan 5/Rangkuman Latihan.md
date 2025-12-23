Latihan 1
```c
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
```

Latihan 2
```c
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
```

Latihan 3
```c
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
```

Latihan 4
```c
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
```


#c