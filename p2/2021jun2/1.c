#include <stdio.h>
#include <stdlib.h>

#define MAXNAME 50

typedef struct{
	char name[MAXNAME];
	int broj;
}posta_;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int binarno(posta_* posta, int trazeni, int l, int d){
	int s;
	while(l < d){
		s = l + (d-l)/2; 
		if(posta[s].broj == trazeni){
			return s;
		}else if(posta[s].broj < trazeni){
			d = s-1;
		}else{
			l = s+1;
		}
		
	}
	return -1;
	
}

int main(int argc, char** argv){
	if(argc != 3){
		greska();
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		greska();
	}
	int size = atoi(argv[2]);
	if(size <= 0){
		greska();
	}
	posta_ posta[size];	
	for(int i =0; i< size; i++){
		fscanf(fp, "%s %d", posta[i].name, &posta[i].broj);
	}
	int trazeni;
	scanf("%d", &trazeni);
	int a = binarno(posta, trazeni, 0, size-1);	
	if( a == -1){
		printf("-1\n");
	}else{
		printf("%s\n", posta[a].name);	
	}
	return 0;
}
