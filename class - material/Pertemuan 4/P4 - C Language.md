#C -- 2025/03/12
___
## Why do we learn C?
1. **Mudah Dipahami**
2. **Mudah Dipelajari**
3. **Mudah Digunakan**

>[!info]
> - C is a **Programing language**
> - C menggunakan **Paradigma Prosedural** (Sudut pandang programer).
> - C is **widely used**.
> - C is used in **microcontroler** even in **modern operating system**.

>[!tip] Compiler
>Software yang mentranslate **human-readable** menjadi **machine-readable** sehingga bisa dieksekusi.
****

## Basic C Structure
#structure
``` c
#include <stdio.h> // library

int main(){
	// user's code
	return 0;
}
```

>[!tip]- Info
> ### `stdio.h`
>basic library for C. Includes basic function like `printf()`, and `scanf()`
> ### `int main();`
> main function.
> ### `return 0;`
>returning 0 to the terminal in the case that the program has finished without any error.

# Variable
#variable
> - A place-holder for a value.
> - Can be many types (int, float, char, etc.) [[P4 - C Language#Data Types|Data Types]]

```c
// Deklarasi
int thisIsAnInteger; // 4 bytes / 32 bit
```

```c
// Inisialisasi
thisIsAnInteger = 10; //supaya nilai dalam variable tidak random.
```

# Constant
```c
#define THIS_IS_A_CONSTANT 100
```
>[!info] Constant
> - All **UPPERCASE**
> - **Cannot be change** while the code runs



# Data Types
#datatypes 
## Basic Data Types (Built-In)
### Character (`char`)
> [!info]
> `char` is **1 byte** and can hold 1 ASCII character.
### Integer (`int`)
>[!info]
>Can hold a **whole number** value.

| Types           | Bytes | Format Specifier | Range                                                   |
| --------------- | ----- | ---------------- | ------------------------------------------------------- |
| `short int`     | 2     | %hd              | -32,768 to 32,767                                       |
| `int`           | 4     | %d               | -2,147,483,648 to 2,147,483,647                         |
| `long int`      | 4     | %ld              | -2,147,483,648 to 2,147,483,647                         |
| `long long int` | 8     | %lld             | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
### Float (float)
>[!info]
>`float` can store decimal/fractional values. using **sign-bit** and **exponent bits**

| Types         | Bytes | Format Specifier | Range                                              |
| ------------- | ----- | ---------------- | -------------------------------------------------- |
| `float`       | 4     | %f               | -3.4 x 10<sup>-38</sup> to 3.4 x 10<sup>+38.</sup> |
| `double`      | 8     | %lf              | 1.7×10<sup>-308</sup> to 1.7×10<sup>+308</sup>     |
| `long double` | 16    | %Lf              | 3.4E-4932 to 1.1E+4932                             |
### Boolean (`Bool`)
>[!info]
>Can hold a value of `true` or `false`. Can be represented by 1 and 0.
## User-Defined datatypes

```c
typedef char string[100];
```
It means that 'string' is an array of 100 char

>[!info] `typedef`
> You can create whatever datatypes you want with this.

# Reserved Word in C
#reserved
`auto`|`else`|`long`|`switch`
`break`|`enum`|`register`|`typedef`
`case`|`extern`|`return`|`union`
`char`|`float`|`short`|`unsigned`
`const`|`for`|`signed`|`void`
`continue`|`goto`|`sizeof`|`volatile`
`default`|`if`|`static`|`while`
`do`|`int`|`struct`|`_Packed`
`double`|||



# Azas

>[!info] Algoritma
> - Runtutan **Sequence** dari satu atau lebih instruksi.
> - Urutan *dari atas ke bawah dan dari kiri ke kanan*.
> - Tiap instruksi dilaksanakan **satu kali**
> - Urutan instruksi yang dilaksanakan pemroses sama dengan urutan aksi sebagaimana tertulis di dalam Algoritma
> - Akhir dari **instruksi terakhir merupakan akhir algoritma**




>[!info] test
>ucup


```c


int main(){

	return 0;
}
```

#c