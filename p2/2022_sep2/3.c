#include <stdio.h>
#include "liste.h"


Cvor* obrni_mesta(Cvor *lista){
	Cvor *lista1 = NULL;
	int i = 1;
	int prethodni;
	while(lista){
		if(i%2 == 0){
			dodaj_na_kraj(&lista1, lista->vrednost);
			dodaj_na_kraj(&lista1, prethodni);
			lista = lista->sledeci;
			i++;
			continue;
		}else{
			prethodni = lista->vrednost;
		}
		i++;
		lista = lista->sledeci;
	}	
	i--;
	if(i%2 == 1){
		dodaj_na_kraj(&lista1, prethodni);
	}
	return lista1;

		
}

int main(){
	Cvor* lista= NULL;
	ucitaj_listu(&lista, stdin);
	
	Cvor *lista1 = obrni_mesta(lista);
	ispisi_listu(lista1, stdout);
	return 0;
}	
