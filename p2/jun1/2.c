#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv){	

	int x;
	int k;
	scanf("%d %d", &x, &k);
	int jedinica = 0;
	int ukupno = 0;
	for(long long i = 1; i<=4294967296; i = i << 1){
		if((x&i) != 0){
			jedinica++;
		}else{
			jedinica=0;
		}		
		if(jedinica>=k)
			ukupno++;

	}
	printf("%d\n", ukupno);
	return 0;
}
