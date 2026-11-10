# Debugging using gdb
See the following sample program:
```C
#include <stdio.h>

int main(){
	int a[10];

	for(int i=0; i<10; i++){
		a[i] = 2*i;
	}

	for(int i=0; i<11; i++){
		int j = i + 1000000;
		printf("%d\n", a[j]);
	}
}

```

To debug the program compile as follows:
```sh
gcc -g -o debugtest debug.c
```

Run the debugger:
```sh
gdb
```

Inside the debugger, specify the executable:
```sh
file debugtest
```

Run the program in debug mode:
```sh
run debugtest
```

Add breakpoint:
```sh
break 12
```

Run again, print variables, and use `step` to continue execution:
```sh
run debugtest
print i
print j
print a[0]@100
step
step
exit
```

**Note: Use an IDE like Eclipse if possible**
