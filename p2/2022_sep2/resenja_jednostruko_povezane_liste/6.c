#include "liste.h"

//zad 6
Cvor* spoji(Cvor* lista1, Cvor* lista2)
{
	if (lista1 == NULL)
		return lista2;
		
	if (lista2 == NULL)
		return lista1;
		
	if (lista1->vrednost <= lista2->vrednost)
  {
  	lista1->sledeci = spoji(lista1->sledeci, lista2);
  	return lista1;
	}
	else
	{
		lista2->sledeci = spoji(lista1, lista2->sledeci);
		return lista2;
	}
}

int main()
{
	Cvor *lista1 = NULL;
	Cvor *lista2 = NULL;
	Cvor *lista3 = NULL;
	
	printf("Uneti prvu neopadajuce sortiranu listu:\n");
	lista1 = ucitaj_listu_v2(stdin);
    printf("Uneti drugu neopadajuce sortiranulistu:\n");
	ucitaj_listu(&lista2, stdin);

	lista3 = spoji(lista1, lista2);
	ispisi_listu(lista3, stdout);

	oslobodi_listu(lista3);
	return 0;
}