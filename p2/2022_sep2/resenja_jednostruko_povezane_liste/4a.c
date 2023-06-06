#include "liste.h"

Cvor* izbaci1(Cvor* lista, int x)
{
	if (lista == NULL)
		return NULL;
		
	//izbacujemo glavu
	if (lista->vrednost == x)
	{
	  Cvor *pom = lista->sledeci;
		free(lista);
		return pom;
	}
	
	else
	{
		lista->sledeci = izbaci1(lista->sledeci, x);
		return lista;
	}
}

int main()
{
	Cvor *lista1 = NULL;
	Cvor *lista2 = NULL;
	int x;
	
	printf("Uneti listu:\n");
	lista1 = ucitaj_listu_v2(stdin);

	printf("Uneti broj: ");
	scanf("%d", &x);
	
	lista2 = izbaci1(lista1, x);
	printf("Zadatak 4a: Lista nakon izbacivanja %x:\n", x);
	ispisi_listu(lista2, stdout);

	oslobodi_listu(lista2);

	return 0;
}