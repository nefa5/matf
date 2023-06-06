#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int STUDENT = 15;

/* void insort(int *a, int n){
 *	int i,j;
 *	for(i = 0; i < n; i++){
 *		int el = a[i];
 *		for(j = i; j > 0 && el < a[j-1]; j--)
 *			niz[j] = niz[j-1];
 *		a[j] = el;
 *	}
 *
 * }
 */

typedef struct{
	char indeks[MAX];
	char ime[MAX],prezime[MAX];
}student;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void printtt(student *s, int n, int s1){
	for(int j = 0; j < n; j++){
		printf("itetation i = %d ,  %s %s %s\n", s1,s[j].indeks, s[j].ime, s[j].prezime);
	}

}

void insort(student *s, int n){
	int i,j;
	for(i = 0; i < n; i++){
		int el = atoi(s[i].indeks);
		char cp1[MAX],cp2[MAX],cp3[MAX];
		strcpy(cp1, s[i].indeks);
		strcpy(cp2,s[i].ime);
		strcpy(cp3,s[i].prezime);
		for(j=i; j > 0 && el <= atoi(s[j-1].indeks); j--){
			if(el == atoi(s[j-1].indeks)){
				int godina1, godina2;
				sscanf(s[j-1].indeks, "%*d / %d", &godina2);
				sscanf(s[i].indeks, "%*d / %d", &godina1);
				printf(" GODINA 1 = %d, GODINA 2 = %d\n", godina1, godina2);
				if(godina2 > godina1){
						strcpy(s[j].indeks, s[j-1].indeks);
						strcpy(s[j].ime, s[j-1].ime);
						strcpy(s[j].prezime, s[j-1].prezime);
						continue;
				}else{
					break;
				}
			}
			strcpy(s[j].indeks, s[j-1].indeks);
			strcpy(s[j].ime, s[j-1].ime);
			strcpy(s[j].prezime, s[j-1].prezime);
		}

		printf("cp1 = %s , cp2  = %s, cp3 =  %s\n", cp1, cp2 ,cp3);
		strcpy(s[j].indeks, cp1);
		strcpy(s[j].ime, cp2);
		strcpy(s[j].prezime, cp3);
		printtt(s,n,i);
	}


}

int main(){
	
	student *s = (student*)malloc(sizeof(student)*STUDENT);
	if(s == NULL){
		greska();
	}
	int i = 0;
	while(1){
		if(i >= STUDENT){
			STUDENT += i;
			s =(student*) realloc(s, sizeof(student)*(STUDENT));	
		}
		if(fscanf(stdin, "%s %s %s", s[i].indeks, s[i].ime, s[i].prezime) == EOF)
			break;
		i++;
	}
	insort(s, i);
	puts("\n");
//	for(int j = 0; j < i; j++){
//		printf("%s %s %s\n", s[j].indeks, s[j].ime, s[j].prezime);
//	}

}
