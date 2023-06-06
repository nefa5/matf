#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100
#define MAX_NAUCNIK 10

typedef struct{
	char ime[MAX],prezime[MAX];
	int godina;

}naucnik;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}


int binaran(naucnik *_naucnik, int n, int levi, int desni){
	
	int l = 0;
	int d = n-1;
	int s;
	while(l <= d){
		s= l + (d-l)/2;
		if((_naucnik[s].godina >= levi) && (_naucnik[s].godina <= desni)){
			while(_naucnik[s].godina >= levi){
				s--;
			}
			return s+1;
		}else if(_naucnik[s].godina < levi){
			l = s+1;
		}else{
			d = s+1; 
		}

		
	}
	return -1;
}

int main(int argc, char **argv){


	if (argc != 3){
		greska();
	}

	naucnik *_naucnik= (naucnik*) malloc(sizeof(naucnik)*MAX_NAUCNIK);
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		greska();
	}
	int i = 0;
	while(fscanf(fp,"%s %s %d", _naucnik[i].ime, _naucnik[i].prezime, &_naucnik[i].godina) != EOF){
		if(i >= MAX_NAUCNIK){
			_naucnik = (naucnik*)realloc(_naucnik, sizeof(naucnik)*(MAX_NAUCNIK+i));
		}	
		i++;
	}
	int det = binaran(_naucnik, i, (atoi(argv[2])*100)-99, (atoi(argv[2])*100));
	if(det == -1){
		greska();
	}
	for(int j = det; j < i && _naucnik[j].godina <= (atoi(argv[2])*100); j++){
		
		printf("%s %s\n", _naucnik[j].ime, _naucnik[j].prezime);

	}

	return 0;
}
