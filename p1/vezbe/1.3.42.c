#include <stdio.h>
#include <stdlib.h>

int main(){
	float b = 2.0;
	unsigned x;
	scanf("%u",&x);
	unsigned kopija = x;
	float rezultat=0;
	for(int i=0;i<x;i++){
		rezultat = 1.0/(kopija+rezultat) + (x-i-1);
		kopija=0;
	}
	printf("%f\n", rezultat);

	printf("a: %f\n", b+1/2.0);

	return 0;
}
