#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	long long br;
	double zbir;
}fiks;

int cmp(const void* a, const void* b){
       	fiks a1 = *(fiks*)a;
	fiks b1 = *(fiks*)b;
	if(a1.br < b1.br){
		return 1;
	}else if(a1.br > b1.br){
		return -1;
	}else{
		return 0;
	}
}
int cmp1(const void*a, const void*b){
	double a1 = *(double*)a;
	double a2 = *(double*)b;
	if(a1 > a2){
		return 1;
	}else if(a1 < a2){
		return -1;
	}else{
		return 0;
	}
	
	
}

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	if(argc != 3){
		greska();
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		greska();
	}
	int sizeof_fiks = 10;
	fiks *fiks_ = (fiks*)malloc(sizeof(fiks)*sizeof_fiks);
	if(fiks_ == NULL){
		greska();
	}	

	// ucitaj
	int i = 0;
	while(1){
		if(i >= sizeof_fiks){
			sizeof_fiks+=sizeof_fiks;
			fiks_=(fiks*)realloc(fiks_, sizeof(fiks)*sizeof_fiks);
			if(fiks_ == NULL){
				greska();
			}
		}
		if(fscanf(fp, "%lld %lf", &fiks_[i].br, &fiks_[i].zbir) == EOF){
			break;	
		}
		i++;
		for(int j =0; j < i-1; j++){
			if(fiks_[i-1].br == fiks_[j].br){
				fiks_[j].zbir += fiks_[i-1].zbir;
				i--;
				break;
			}
		}
	}
	printf("%d\n", i);
	for(int j = 0; j < i; j++){
		printf("%lld %lf\n", fiks_[j].br, fiks_[j].zbir);
	}
	if(strcmp(argv[2], "-kartica") == 0){
		qsort(fiks_,i,sizeof(fiks), cmp);
	}else if(strcmp(argv[2], "-suma") == 0){
		qsort(fiks_, i, sizeof(fiks), cmp1);
	}else{
		greska();
	}
	printf("POSLE\n");
	for(int j = 0; j < i; j++){
		printf("%lld %lf\n", fiks_[j].br, fiks_[j].zbir);
	}
	return 0;
}
