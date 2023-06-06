#include <stdio.h>

void printbits(int n){
	unsigned mask = 1;
	for(int i = 0; i < sizeof(int)*8; i++){
		n&mask? printf("1") : printf("0");
		mask<<=1;
	}
}

int main(){

	int j, n;
	scanf("%d %d", &j, &n);
	unsigned mask = 1;
	printbits(n);
	for(unsigned i = 0,c = 0; i <= sizeof(int)*8 && c <= sizeof(int)*8; c++){
		if(i%j == 0){
			if((n&mask) == 0){
				n = n | mask;
			}else{
				n = n ^ mask;
			}
			i = 0;
		}
		mask <<= 1;
		i++;
	}	
	printf("\n");
	printbits(n);

	return 0;
}
