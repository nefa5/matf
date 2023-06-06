#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXREC 20
#define M 10000

typedef struct{
	char ime[MAXREC];
	float prosecna_g, br_gl_o, ocena_k;
}filmovi;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void selection_sort_rev(filmovi *f, float *prosecna, int n){

	int i,j,poz_min;

	char privremena[MAXREC];
	for(i = 0; i < n; i++){
		poz_min = i;
		for(j = i +1; j < n; j++){
			if(strcmp(f[j].ime, f[poz_min].ime) < 0){
				poz_min = j;
			}else if(strcmp(f[j].ime, f[poz_min].ime) == 0 && prosecna[poz_min] < prosecna[j]){
				poz_min = j;
			
			}
		}
		strcpy(privremena, f[i].ime);
		strcpy(f[i].ime, f[poz_min].ime);
		strcpy(f[poz_min].ime, privremena);
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
	if(fscanf(fp, "%d", &n) != 1){
		greska();	
	}
	filmovi f[n];
	float prosecna[n];
	for(int i = 0; i < n; i++){
		fscanf(fp, "%s %f %f %f", f[i].ime, &f[i].prosecna_g, &f[i].br_gl_o, &f[i].ocena_k);
		if(f[i].ime < 0 || f[i].prosecna_g < 0 || f[i].br_gl_o < 0){
			greska();
		}
		prosecna[i] = ((f[i].br_gl_o*f[i].prosecna_g)+(10000*f[i].ocena_k))/(10001);
	}
	
	selection_sort_rev(f,prosecna,n);
	FILE *kp = fopen("vrednosti.txt", "w");
	if(kp == NULL){
		greska();
	}
	for(int i = 0; i < n; i++){
		fprintf(kp, "%s %f\n", f[i].ime, prosecna[i]);
	}

	
	

	
	return 0;
}
