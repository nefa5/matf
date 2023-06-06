#include "liste.h"

Cvor* dodaj_element(Cvor* lista, int x)
{
	if (lista == NULL)
		return napravi_cvor(x);

	if (lista->vrednost > x)
	{
		Cvor* novi = napravi_cvor(x);
		novi->sledeci = lista;
		return novi;
	}
	else
		lista->sledeci = dodaj_element(lista->sledeci, x);
}

int main()
{
	Cvor *lista1 = NULL;
	Cvor *lista2 = NULL;
	int x;
	
	printf("Uneti neopadajucu listu:\n");
	lista1 = ucitaj_listu_v2(stdin);

	printf("Uneti broj: ");
	scanf("%d", &x);
	
	lista2 = dodaj_element(lista1, x);
	printf("Lista nakon dodavanja elementa 10:\n");
	ispisi_listu(lista2, stdout);

	oslobodi_listu(lista2);

	return 0;
}