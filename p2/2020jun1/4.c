#include <stdio.h>
#include "stabla.h"

void zbir_stabla(Cvor* stablo, int *zbir){
	if(stablo == NULL)
		return;
	if((stablo->desno != NULL && stablo->levo == NULL) ||
			(stablo->levo != NULL && stablo->desno == NULL)){
		*zbir += stablo->vrednost;
	}
	zbir_stabla(stablo->levo, zbir);
	zbir_stabla(stablo->desno, zbir);

	
		
}

void ispisi(Cvor* stablo, int zbir){
	if(stablo == NULL)
		return;
	ispisi(stablo->levo, zbir);
	if(stablo->vrednost > zbir){
		printf("%d ", stablo->vrednost);
	}
	ispisi(stablo->desno, zbir);
}

int main(){
	Cvor* stablo = NULL;
	napravi_stablo_iz_fajla_v2(&stablo, stdin);
	
	int zbir = 0;
	zbir_stabla(stablo, &zbir);
	printf("%d ", zbir);
	
	ispisi(stablo, zbir);

	oslobodi(stablo);
	return 0;	
}
