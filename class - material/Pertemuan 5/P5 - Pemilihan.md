>[!quote] Quote
> *"Namanya juga bahasa.... Ada reading, speaking, listening, logic dsb. yo di-practice, dipelajari"*

# Operator Precedence
1. Function Calls
2. Unary Operator ( ! , + , - , &)
3. *,  /,  %
4. + -
5. < <= >= >
6. == ,  !=
7. &&
8. ||
9. =

# Pemilihan
tentang:
	*Kondisi* dan *Aksi*
Operator : &&, || , == , > , >= , < , <=

## If-else
```c 
// STRUKTUR IF
if(case 1){
	aksi();
}else if( case 2){
	aksi();
}else { //default
	aksi()
}



```
## Switch
```c
// STRUKTUR SWITCH 
// var << int atau char
// char var;
int var;
switch(var){
	case 1:
		aksi();
	break;
	case 2:
		aksi();
	break;
	default: //apabila tidak ada case yang cocok
		aksi();
	break;
}


//atau

switch(var){
	case 'y': 
	case 'Y':
		aksi(); //dilakukan ketika var == y atau var == Y
	break;
}

```
## Ternary

```c
// STRUKTUR TERNARY
(kondisi)? <aksi jika benar>: <aksi jika salah>;
//e. g.
int var = 1;
printf("this is tenary : %s",(var == 1)?"var a sama dengan 1":"var a bukan 1");
```

#c