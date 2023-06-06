#include <stdio.h>
#include "liste.h"
#include <stdlib.h>


void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}	

int main(int argc, char** argv){

	if(argc != 3){
		greska();
	}
	Cvor *lista = NULL;
	

	return 0;
}
