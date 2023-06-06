#include <stdio.h>
#include <stdlib.h>
#include "liste.h"



int main(){

	Cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);	
	
	Cvor *k = lista;

	while(k->sledeci != NULL){
		if(k->vrednost %2 == 0 && k->sledeci->vrednost % 2 == 0){
			Cvor* novi = napravi_cvor(0);
			Cvor* pt = k->sledeci;
			k->sledeci = novi;
			novi->sledeci = pt;
			k = k->sledeci;
		}		
		k = k->sledeci;
	}		
	ispisi_listu(lista, stdout);

	oslobodi_listu(lista);	
	return 0;
}
