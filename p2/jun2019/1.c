#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define SIZEMAX 15
#define SIZEMAXPISMO 200

extern int errno;

typedef struct{
	char ime[SIZEMAX];
	char pismo[SIZEMAXPISMO];
} file;

void greska(){
	fprintf(stderr, "VALUE OF ERRNOR: %d\n ERROR OPENING FILE : %s\n", errno, strerror(errno));
	exit(EXIT_FAILURE);
}

int main(){
	
	FILE *fp = fopen("fajlovi.txt", "r");
	if(fp == NULL){
		greska();
	}

	file* file_p = (file*)malloc(sizeof(file)*10);

	if(file_p == NULL){
		greska();
	}
	char stream[SIZEMAXPISMO];
	int i = 0;
	while(fscanf(fp, "%s", stream) != EOF){
		char* a = strtok(stream, ":");
		char *b = strtok(NULL, ":");
		if(b == NULL){
			strcpy(file_p[i].ime, a);
			strcpy(file_p[i].pismo, "");
		}else{
			strcpy(file_p[i].ime, a);
			strcpy(file_p[i].pismo,b);
		}
		i++;
	}
	for(int j = 0; j < i; j++){
		FILE *new = fopen(file_p[j].ime, "a+");
		if(new == NULL){
			greska();
		}
		fprintf(new, "%s", file_p[j].pismo);
	}


	return 0;
}	
