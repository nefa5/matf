#include <stdio.h>
#include <math.h>
#include "stabla.h"
#include <limits.h>

int MAX(int x, int y, int z){
	if(x > y){
		if(x > z)
			return x;
		return z;
	}else{
		if(y > z)
			return y;
		else
			return z;
	}
}

int nadji(Cvor *stablo, int *max, int *max_c){
	if(stablo->desno == NULL && stablo->levo == NULL){
		return stablo->vrednost;
	}
	int m1 = abs(nadji(stablo->levo, max, max_c) - stablo->vrednost);
	int m2 = abs(nadji(stablo->desno, max, max_c) - stablo->vrednost);
	int m3 = *max;
	printf("m1 = %d, m2 = %d, max = %d\n", m1, m2, *max);
	*max = MAX(m1,m2,*max);
	if(m3 != *max){
		*max_c = stablo->vrednost;
	}
	return stablo->vrednost;
	 

}



int main(){
	
	Cvor *stablo = NULL;
	napravi_stablo_iz_fajla_v2(&stablo, stdin);
	if(stablo == NULL){
		printf("0\n");
		return 0;
	}	
	int max = INT_MIN;
	int max_c = INT_MIN;
	if(stablo->desno == NULL && stablo->levo == NULL){
		printf("0\n");
		return 0;
	}
	int cvor = nadji(stablo, &max, &max_c);
	printf("%d\n", max_c);

	return 0;
}
