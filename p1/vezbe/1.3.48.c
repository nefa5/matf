#include <stdio.h>

int main(){	
	unsigned x;
	scanf("%u", &x);
	for (int i = 0; i < x; i++){
		for (int j=0; j<x; j++){
			printf("*");
		}
		printf("\n");

	}					
						

	return 0;
}
