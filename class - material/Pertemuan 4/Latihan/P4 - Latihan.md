**240713000_Farelino Alexander Kim** // 2025-03-12
## Kondisi Awal
`main.c`
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1, nilai2, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d",&nilai1);
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```
Hasil : **Program berjalan dengan baik.**
```
Masukkan nilai 1 : 19
Masukkan nilai 2 : 21
19 x 21 = 399
--------------------------------
Process exited after 7.277 seconds with return value 0
Press any key to continue . . .

```


## Kondisi 1
> **Hapus deklarasi variabel nilai2**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d",&nilai1);
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Compile Error**

| Line | Col | Message                                                                                 |
| ---- | --- | --------------------------------------------------------------------------------------- |
|      |     | In function 'main':                                                                     |
| 8    | 47  | [Error] 'nilai2' undeclared (first use in this function)                                |
| 8    | 47  | [Note] each undeclared identifier is reported only once for each function it appears in |
| 28   |     | recipe for target 'main.o' failed                                                       |
>[!info] Penjelasan
>Program tidak dapat di-compile akibat variabel `nilai2` tidak terdefinisi.

>[!info] Solusi
>Mendeklarasikan `nilai2` sebagai variabel berjenis integer.
## Kondisi 2
> **Ganti deklarasi nilai2 menjadi nilai21**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1, nilai21 ,nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d",&nilai1);
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Compile Error**

| Line | Col | Message                                                                                 |
| ---- | --- | --------------------------------------------------------------------------------------- |
|      |     | In function 'main':                                                                     |
| 8    | 47  | [Error] 'nilai2' undeclared (first use in this function)                                |
| 8    | 47  | [Note] each undeclared identifier is reported only once for each function it appears in |
| 28   |     | recipe for target 'main.o' failed                                                       |
>[!info] Penjelasan
>Program tidak dapat di-compile akibat variabel `nilai2` tidak terdefinisi.

>[!info] Solusi
>Mengganti nama variabel `nilai21`menjadi `nilai2`.
## Kondisi 3
> **Hapus sebuah tanda “;”**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1,nilai2, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d",&nilai1) //menghapus ";" dari line ini
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Compile Error**

| Line | Col | Message                              |
| ---- | --- | ------------------------------------ |
|      |     | In function 'main':                  |
| 8    | 2   | [Error] expected ';' before 'printf' |
| 28   | 0   | recipe for target 'main.o' failed    |
>[!info] Penjelasan
>Program tidak dapat di-compile akibat tidak ada ";" pada akhir baris 8 setelah 'scanf()'

>[!info] Solusi
> Menambahkan ";" di akhir baris 8.


## Kondisi 4
> **Hapus salah satu tanda kurung**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1,nilai2, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d",&nilai1;
	// Mengahapus tanda kurung
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Compile Error**

| Line | Col | Message                               |
| ---- | --- | ------------------------------------- |
|      |     | In function 'main':                   |
| 7    | 53  | [Error] expected ')' before ';' token |
| 15   | 1   | [Error] expected ';' before '}' token |
| 28   |     | recipe for target 'main.o' failed<br> |

>[!info] Penjelasan
>Program tidak dapat di-compile akibat tidak ada tanda `)` untuk menutup `scanf`.

>[!info] Solusi
> Menambahkan `)` sebelum tanda `;` pada baris 8.


## Kondisi 5
> **Hapus salah satu tanda `"`**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1,nilai2, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d,&nilai1);
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Compile Error**

| Line | Col | Message                               |
| ---- | --- | ------------------------------------- |
|      |     | In function 'main':                   |
| 14   | 1   | [Error] expected ';' before '}' token |
| 28   |     | recipe for target 'main.o' failed     |
>[!info] Penjelasan
>Program tidak dapat di-compile karena program menganggap `,&nilai1);` masih di dalam format, karena tidak ada tanda ".

>[!info] Solusi
> Menutup tanda petik dengan tanda petik lagi. `scanf("%d", &nilai1);`
> 

## Kondisi 6
> **Ubah printf menjadi PRINTF**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1,nilai2, nilai3;

	PRINTF ("Masukkan nilai 1 : "); scanf ("%d",&nilai1);
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Compile Error**

| Line | Col | Message                                              |
| ---- | --- | ---------------------------------------------------- |
|      |     | main.c:(.text+0x1c): undefined reference to `PRINTF' |
|      |     | [Error] ld returned 1 exit status                    |
| 25   |     | recipe for target '"Test' failed                     |
>[!info] Penjelasan
>Program tidak dapat di-compile karena tidak mengenali instruksi `PRINTF`.

>[!info] Solusi
> Mengganti `PRINTF` dengan `printf`.

## Kondisi 7
> **Hapus tanda `&`**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1,nilai2, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d",&nilai1);
	// Menghapus tanda &
	printf ("Masukkan nilai 2 : "); scanf ("%d",nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Program Berjalan, tapi tidak dengan baik** 
```
Masukkan nilai 1 : 65
Masukkan nilai 2 : 15

--------------------------------
Process exited after 4.812 seconds with return value 3221225477
Press any key to continue . . .
```

>[!info] Penjelasan
>Program berjalan tapi tidak mengembalikan nilai 0. Artinya, ada error terjadi saat program berjalan.  

>[!info] Solusi
> Menambahkan `&` sebelum variable `nilai2` pada `scanf`. prefix `&`berfungsi untuk mengirimkan alamat variabel `nilai2`agar sesuai dengan sintaks, sehingga `scanf` dapat berjalan dengan baik.
>
> `scanf("%d", &nilai2);`

## Kondisi 8
> **Parameter fungsi printf atau scanf dibuat kurang atau kebanyakan**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nilai1,nilai2, nilai3;

	printf ("Masukkan nilai 1 : "); scanf ("%d",&nilai1, &nilai2);
	// tambah parameter
	printf ("Masukkan nilai 2 : "); scanf ("%d",&nilai2);

	nilai3 = nilai1*nilai2;
	printf ("%d x %d = %d ",nilai1, nilai2, nilai3);

	return 0;
}
```

Hasil: **Program Berjalan baik-baik saja.**

>[!info] Penjelasan
> Dalam kasus ini, menambahkan 1 parameter tambahan ke dalam scanf tidak memengaruhi fungsi program.