#include "liste.h"

Cvor* izbaci_susede(Cvor* lista, int k) {
	Cvor* next;
	if(lista == NULL || lista->sledeci == NULL)
		return lista;
	next = lista->sledeci;
	if(lista->vrednost + next->vrednost == k) {
		lista->sledeci = izbaci_susede(next, k);
		if(lista->sledeci == next) {
			// Izbacuju se oba
			Cvor* povratni = next->sledeci;
			free(lista);
			free(next);
			return povratni;
		} else {
			// Izbacuje se samo glava
			Cvor* povratni = lista->sledeci;
			free(lista);
			return povratni;
		}
	} else {
		lista->sledeci = izbaci_susede(lista->sledeci, k);
		return lista;
	}
}

int main()
{
	Cvor *lista1 = NULL;
	Cvor *lista2 = NULL;
	int k;
	
	printf("Uneti listu:\n");
	lista1 = ucitaj_listu_v2(stdin);

	printf("Uneti zbir: ");
	scanf("%d", &k);

	lista2 = izbaci_susede(lista1, k);
	ispisi_listu(lista2, stdout);

	oslobodi_listu(lista2);
	return 0;
}