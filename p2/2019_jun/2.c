#include <stdio.h>

void printbits(unsigned x,char*msg);

void printbits(unsigned x, char*msg){
	printf("%s ", msg);
	unsigned mask = 1 <<(sizeof(unsigned)*8 -1);
	while(mask){
		x&mask ? printf("1") : printf("0");
		mask >>=1;
	}
	printf("\n");
}

unsigned zameni(unsigned x){
	unsigned prva2 = 0xffff0000;
	unsigned druga2= 0x0000ffff;
	unsigned kopija = 0x0;
	prva2 = prva2 & x;
	prva2 >>= sizeof(unsigned) * 4;
	druga2 = druga2 & x;
	druga2 <<= sizeof(unsigned)*4;
	kopija = druga2 | prva2;
	return kopija;
}

int main(){

	unsigned x;
	scanf("%x", &x);
	printbits(x, "x pocetno : ");
	
	unsigned y = zameni(x);
	printf("0x%x\n", y);
	return 0;
}
