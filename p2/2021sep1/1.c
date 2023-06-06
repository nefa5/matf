#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXREC 20

typedef struct{
	char ime[MAXREC], boja[MAXREC];
	int povrsina;
}geometrija;


void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int poredi(const void *a, const void *b){
	geometrija geo1 = *(geometrija*)a;
	geometrija geo2 = *(geometrija*)b;
	if(strcmp(geo1.ime, geo2.ime) < 0){
		return 1;
	}else if(strcmp(geo1.ime,geo2.ime) == 0 && strcmp(geo1.boja, geo2.boja) > 0){
		return 1;
	}else if((strcmp(geo1.ime,geo2.ime) == 0 && strcmp(geo1.boja, geo2.boja) == 0)){
		return geo2.povrsina-geo1.povrsina;
	}else{
		return -1;
	}
}

int main(int argc, char** argv){
	if(argc != 2){
		greska();
	}
	
	FILE *fp = fopen(argv[1], "r");

	if(fp == NULL){
		greska();
	}
	int n;
	fscanf(fp, "%d", &n);
	geometrija geo[n];
	if(n < 0)
		greska();
	for(int i = 0; i<n;i++){
		fscanf(fp,"%s %s %d", geo[i].ime, geo[i].boja, &geo[i].povrsina);
	}

	qsort(geo, n, sizeof(geometrija), poredi);
	for(int i = 0; i < n; i++){
		printf("%s %s %d\n", geo[i].ime, geo[i].boja, geo[i].povrsina);
	}
	return 0;
}
