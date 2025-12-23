[Farelino Alexander Kim - DASPRO](Farelino%20Alexander%20Kim%20-%20DASPRO.md)**240713000_Farelino Alexander Kim** // 2025-03-12

---
# Latihan 1
![[Pasted image 20250313141323.png]]

![[Pasted image 20250313141401.png]]

# Latihan 2
![[Pasted image 20250313150341.png]]
``` c
#define phi 3.14

int main()
{
	float r=5, h=9;
	
	printf("Volume tabung : %/2f\n", V);
	V = phi * r * r * h;

	return 0;
}
```

#### **apakah sudah benar? Jika belum, apa penyebabnya? Mengapa?**

**Kode belum benar dan tidak dapat berjalan.**
>[!info] Kesalahan kode:
> 1. Tidak menggunakan library `stdio.h`
> 2. Tidak mendeklarasi variabel `V`

> [!info] Solusi
> Sertakan `#include <stdio.h>`
> Deklarasi variabel `V` dengan `float V = phi * r * r * h;`

# Latihan 3
![[Pasted image 20250313150416.png]]
```c
int main()
{
	int a, t, L;
	printf("Alas   : "); scanf("%d", &a);
	printf("Tinggi : "); scanf("%d", &t);

	L = (a * t)/2;

	printf("Luas segitiga : %d\n", L);

	return 0;
}
```

#### **Pada saat kode program di bawah ini dieksekusi, apakah sudah benar? Jika belum, apa penyebabnya? Mengapa?**

**kode belum bisa dibilang baik.**
>[!info] Kesalahan kode:
> 1. Tidak menggunakan library `stdio.h`
> 2. Variabel `L`, `t`, `a` seharusnya menggunakan tipe data float agar dapat menyimpan nilai fraksional.

>[!info] Solusi
> ```c
> #include <stdio.h>
> int main()
> {
> 	float a, t, L;
> 	printf("Alas   : "); scanf("%f", &a);
> 	printf("Tinggi : "); scanf("%f", &t);
> 	
> 	L = (a * t)/2;
> 	printf("Luas segitiga : %.2f\n", L);
> 	return 0;
> }
> ```


Output:
![[Pasted image 20250313143606.png]]

# Latihan 4
![[Pasted image 20250313150458.png]]
```c
#include <math.h>
#define phi 3.14

int main()
{
	float r = 5, h = 9, L;
	
	printf("Jari-jari Tabung : ");scanf("%f", &r);
	printf("Tinggi tabung    : ");scanf("%f", &h);
	
	L = 3 * phi * pow(r,2) + 2 * phi * r * h;
	printf("Luas permukaan ketiga tabung: %.2f", Luas);
	return 0;
}
```
>[!info] Kesalahan kode:
> 1. Tidak menggunakan library `stdio.h`
> 2. `Luas` tidak terdefinisi, seharusnya diganti dengan variable `L`


**Perbaikan kode:**
```c
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
```
Output:
![[Pasted image 20250313150146.png]]