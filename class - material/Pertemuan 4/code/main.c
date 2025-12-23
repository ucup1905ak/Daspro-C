#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1,nilai2, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d");
	// tambah parameter
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
