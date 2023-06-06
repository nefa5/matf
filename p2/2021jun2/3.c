#include <stdlib.h>
#include <stdio.h>
#include "liste.h"


int main(){
	Cvor *lista1 = NULL;
	ucitaj_listu(&lista1,stdin);	
	
	Cvor *lista = lista1;
	while(lista->sledeci != NULL){
		if(lista->vrednost <= (lista)->sledeci->vrednost){
			lista = (lista)->sledeci;
		}else{
			(lista)->sledeci = (lista)->sledeci->sledeci;
		}
	}	
	ispisi_listu(lista1, stdout);	
	oslobodi_listu(lista1);
	return 0;
}
