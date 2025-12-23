#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a,b,c;
	float P, Q, R;

	a = 15;
	b = 9;
	c = 5;
	
	R = a;
	
	a++;
	b--;
	R /= c;
	R--;
	
	printf("Masukan nilai P : ");
	scanf("%f", &P);
	printf("Masukan nilai Q : ");
	scanf("%f", &Q);
	P += Q;
	Q = a / b;
	
	
	printf("\n[a] : %d", a);
	printf("\n[b] : %d", b);
	printf("\n[c] : %d", c);
	printf("\n[P] : %f", P);
	printf("\n[Q] : %f", Q);
	printf("\n[R] : %f", R);
	return 0;
}
