## Parameter Formal
adalah parameter yang disertakan ketika proses deklarasi.
## Parameter Aktual
adalah parameter yang sebenarnya digunakan pada saat pemanggilan.

``` c
#include <stdio.h>
void foo(int x);
int main(){
	int var;
	foo(var);
	return 0;
}
```

>[!info] 
>`x `adalah parameter Formal <br>
>`var` adalah parameter Aktual

>[!info]  Aturan
>- Parameter Aktual = Parameter Formal
>- Tipe Parameter harus sama



