### 26 Maret 2025
# Latihan 

### 1. Berapakah nilai n, m dan p dibawah ini?
![[Pasted image 20250326140226.png | 500]]
>[!info] Jawab
>	n = ++i * --j 
>	  = (4+1) * (8-1) 
>	  = 35
>	m = i + j--;
>	  = 4 + 8
>	  = 12
>	p = i + j
>	  = 4 + 8 = 12

---
### 2. Jika nilai n=8, berapakah output dari n dan ganjil pada program dibawah?
![[Pasted image 20250326140647.png | 600]]

>[!info] Jawab
> // sesuai inisialisasi
> 	**n = 8** 
> 	
> // awalnya ganjil =  1, dan ditambahkan 2 setiap kali perulangan **Sampai kondisi tidak memenuhi**
> 	**ganjil = 9**

---
### 3. Apakah output dari potongan program dibawah?
![[Pasted image 20250326141515.png | 300]]
>[!info] Jawab
> ``` c
> // di run di devc++
> 
> #include <stdio.h>
> #include <stdlib.h>
> 
> int main(int argc, char *argv[]) {
> 	int i = 0;
> 	while(i <= 5){
> 		printf("%3d %3d\n", i, 10 - i);
> 		i += 1;
> 	}
> 	return 0;
> }
> ```
>output dari program :
>``` c
>   0  10
  1   9
  2   8
  3   7
  4   6
  5   5
>```

---
### 4. Tulislah program dengan output :
``` c
  0   1
  1   2
  2   4
  3   8
  5  32
  6  64
```

> [!info] Jawab
> 
> ``` c
> #include <stdio.h>
> #include <stdlib.h>
> 
> int main(int argc, char *argv[]) {
> 	int i = 0, j = 0, hasil;
> 	
> 	for(i = 0; i < 7 ; i++){
> 		// hitung 2 pangkat i 
> 		hasil = 1; 
> 		for(j = 0 ;j < i ; j++)
> 			hasil *= 2;
> 		printf("%3d %3d\n", i , hasil);
> 	}
> 	
> 	return 0;
> }
> ```
> Output:
![[Pasted image 20250326142449.png]]

---
### 5. Buatlah program untuk menampilkan bilangan genap dari 2 sampai 20!

> [!info] Jawab
> ``` c
> #include <stdio.h>
> #include <stdlib.h>
> 
> int main(int argc, char *argv[]) {
> 	int bilangan;
> 	
> 	for(bilangan = 2 ; bilangan <= 20 ; bilangan++)
> 		if(bilangan % 2 == 0) printf("%3d\n", bilangan);
> 	return 0;
> }
> ```
> 
> output:
> ![[Pasted image 20250326143033.png]]

---
### 6. Buat program untuk menghitung nilai rata-rata dari nilai-nilai yang dimasukkan

•Banyak data tidak ditentukan di awal

•Progam akan terus menerima inputan sampai pengguna tidak ingin lagi memasukkan inputan baru

> [!info] Jawab
> 
> ``` c
> #include <stdio.h>
> #include <stdlib.h>
> 
> int main(int argc, char *argv[]) {
> 	int input; // penampung input user
> 	int i = 0; //counter berapa bilangan
> 	char status; // flow control
> 	float rataRata = 0; // penampung perhitungan
> 	
> 	// Rumus rata-rata = (d1 + d2 + ... + dn) / n 
> 	do {
> 		i++; // increment bilangan
> 		printf("\nMasukan Data ke-%2d : ", i);
> 		scanf("%d", &input); // input data
> 		rataRata += input;
> 		// menambahkan data ke rata-rata
> 		
> 		printf("Apakah ini melanjutkan? [Y/n] ");
> 		fflush(stdin); status = getchar();
> 		// mengambil input user
> 		
> 	}while(status != 'n'&& status != 'N');
> 	// check apakah user mengetikan 'n' atau 'N'
> 	
> 	
> 	// hitung dan tampilkan rata-rata
> 	rataRata /= i;
> 	printf("\n\nRata - Rata dari %d bilangan adalah %.2f", i, rataRata);
> 	return 0;
> }
> ```
> output program:
> ![[Pasted image 20250326145728.png]]

<p align="right">Farelino Alexander Kim<br>
240713000<br>
D<br>
26 Maret 2025</p>
#c