#include <stdio.h>
#include "stabla.h"

void pronadji(Cvor* stablo, Cvor* konstanta){
	if(stablo != NULL){
		pronadji(stablo->levo, konstanta);
		pronadji(stablo->desno, konstanta);
		if(stablo == konstanta){
			return;
		}
		if(stablo->desno == NULL && stablo->levo == NULL){ // 1 grana
			return;
		} else if((stablo->levo != NULL && stablo->desno == NULL) || (stablo->levo == NULL && stablo->desno != NULL)){ // 1 grana
			printf("%d ", stablo->vrednost);
		}else if(stablo->levo != NULL && stablo->desno != NULL){
			return; // 3 grane
		}else{
			printf("%d ", stablo->vrednost);
		}

	}

}

int main(){
	Cvor *stablo = NULL;	
	napravi_stablo_iz_fajla_v2(&stablo, stdin);
	if(stablo == NULL){
		return 0;
	}
	pronadji(stablo, stablo);
	if(stablo->levo != NULL && stablo->desno != NULL)
		printf("%d \n", stablo->vrednost);
	return 0;

}
