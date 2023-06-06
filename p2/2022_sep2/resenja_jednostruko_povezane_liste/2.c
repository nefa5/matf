#include "liste.h"

int veci_od(Cvor* lista, int x)
{
	if (lista == NULL)
		return 0;

	if (lista->vrednost > x)
		return veci_od(lista->sledeci, x) + 1;
	else
		return veci_od(lista->sledeci, x);
}

int main()
{
	Cvor *lista1 = NULL;
	int x;
	
	printf("Uneti listu:\n");
	lista1 = ucitaj_listu_v2(stdin);

	printf("Uneti broj: ");
	scanf("%d", &x);
	
	//zad 2
	printf("Broj elementa vecih od broja %d u listi1 su %d\n", x, veci_od(lista1, x));

	oslobodi_listu(lista1);

	return 0;
}