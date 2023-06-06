#include <stdio.h>
#include <math.h>
#include "liste.h"

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}


Cvor* izvrsi(Cvor *lista, int k, int p){
	Cvor* lista1 = NULL;
	while(lista->sledeci){
		int var = (lista->vrednost + lista->sledeci->vrednost);
		var = mod(var, k);
		if(var == p){
			dodaj_na_kraj(&lista1, lista->vrednost);
		//	dodaj_na_kraj(&lista1, lista->sledeci->vrednost);
			dodaj_na_kraj(&lista1, 0);
			dodaj_na_kraj(&lista1, 0);
		}else{
			dodaj_na_kraj(&lista1, lista->vrednost);
		}
		lista = lista->sledeci;
	}
	dodaj_na_kraj(&lista1, lista->vrednost);
	return lista1;
	
}

int main(){
	int k, p;
	scanf("%d %d", &k, &p);

	Cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);

	Cvor *lista1 = izvrsi(lista, k, p);
	ispisi_listu(lista1, stdout);
	oslobodi_listu(lista1);
	oslobodi_listu(lista);

	return 0;
}
