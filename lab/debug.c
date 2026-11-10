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


