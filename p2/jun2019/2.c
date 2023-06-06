#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DUZINA_INDEKSA 10
#define DUZINA_IMENA 20
#define DUZINA_PREZIMENA 20
#define STUDENT 10

typedef struct{
	char indeks[DUZINA_INDEKSA];
	char ime[DUZINA_IMENA];
	char prezime[DUZINA_PREZIMENA];
} student;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void print(const int i,const student* student_){
	for(int j = 0; j < i; j++){
		printf("%s %s %s\n", student_[j].ime, student_[j].prezime, student_[j].indeks);
	}
}

void sortiraj(student *student_, int l){
	int i, j;
	for(i = 1; i < l; i++){
		int element;
		sscanf(student_[i].indeks, "%d", &element);
		char a[DUZINA_INDEKSA],b[DUZINA_IMENA],c[DUZINA_PREZIMENA];
		strcpy(a, student_[i].indeks); 
		
		strcpy(b, student_[i].ime); 

		strcpy(c,student_[i].prezime);

		for(j = i; j > 0; j--){
			int element2;
		
			sscanf(student_[j-1].indeks, "%d", &element2);
			if(element < element2){
				strcpy(student_[j].indeks, student_[j-1].indeks);
				strcpy(student_[j].ime, student_[j-1].ime);
				strcpy(student_[j].prezime,student_[j-1].prezime);
			} else if(element == element2){
				int godine1, godine2;
				sscanf(student_[i].indeks, "%*d/%d", &godine1);
				sscanf(student_[j-1].indeks, "%*d/%d", &godine2);
				if(godine1 < godine2){
					strcpy(student_[j].indeks, student_[j-1].indeks);
					strcpy(student_[j].ime, student_[j-1].ime);
					strcpy(student_[j].prezime,student_[j-1].prezime);
				}else{
					strcpy(student_[j-1].indeks, student_[j].indeks);
					strcpy(student_[j-1].ime, student_[j].ime);
					strcpy(student_[j-1].prezime,student_[j].prezime);
				}
	

			}else{
				break;
			}

		}
			strcpy(student_[j].indeks,a);
			strcpy(student_[j].ime, b);
			strcpy(student_[j].prezime,c);
	}
}

int main(){
	
	student* student_ = (student*) malloc(sizeof(student)*STUDENT);
	if(student_ == NULL){
		greska();
	}
	int i = 0;
	while(scanf("%s %s %s", student_[i].indeks, student_[i].ime, student_[i].prezime) != EOF){
		i++;
		if(i >= STUDENT){
			student_ = (student*) realloc(student_, sizeof(student)*(STUDENT+i));
		}
	
	}
	sortiraj(student_, i);
	print(i, student_);
//
	return 0;
}
