i#include <stdio.h>
#include <stdlib.h>

int mask(int x){
	unsigned mask1 = 1 << (sizeof(int)*8-1);
       	while(mask1){
		if(x&mask1)
			break;
		mask1>>=1;
	}	
	unsigned mask2 = 1;
	while(mask2){
		if(x&mask2)
			break;
		mask2<<=1;
	}
	while(mask1 != mask2){
		x = x | mask1;
		mask1 >>= 1;
	}
	return x;

}

void printbits(int x){
	unsigned mask = 1 << (sizeof(int)*8-1);
	while(mask){
		x&mask? printf("1") : printf("0");
		mask >>=1;
	}
	printf("\n");
}

int main(){

	int x;
	scanf("%d", &x);
	printbits(x);
	int y = mask(x);
	printbits(y);
	printf("%d\n",y);	
	return 0;
}
