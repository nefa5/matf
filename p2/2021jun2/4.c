#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

void func(Cvor *stablo, int nivo, int*suma){
	if(stablo == NULL){
		return;
	}
	if(nivo%2 == 0){
		*suma+= stablo->vrednost;
	}else {	
		*suma -= stablo->vrednost;
	}	
	func(stablo->levo, nivo+1, suma);
	func(stablo->desno, nivo+1, suma);	

}

int main(){
	Cvor *stablo = NULL;
	napravi_stablo_iz_fajla_v2(&stablo, stdin);
	
	int suma = 0;
       	func(stablo, 0, &suma);
	printf("%d\n", suma);

	oslobodi(stablo);	
	return 0;
}

