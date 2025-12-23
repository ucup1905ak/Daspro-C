#include <stdio.h>
#include <math.h>
#define phi 3.14

int main()
{
	float r = 5, h = 9, L;

	printf("Jari-jari Tabung : ");scanf("%f", &r);
	printf("Tinggi tabung    : ");scanf("%f", &h);

	L = 3 * phi * pow(r,2) + 2 * phi * r * h;
	printf("Luas permukaan ketiga tabung: %.2f", L);
	return 0;
}
