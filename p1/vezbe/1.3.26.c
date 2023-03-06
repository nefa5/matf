#include <stdio.h>


int power(int eksponent, int baza){
	int rezultat = 1;
	while(eksponent--){
		rezultat = rezultat * baza;
	}
	return rezultat;
}

int main(){
	int broj;
	scanf("%d", &broj);
	if (broj < 0){
		printf("Greska: neispravan unos\n");
	}
	if((broj>=0 && broj<10) || (broj>=10 && broj<100)){
		printf("%d\n", broj);
	} else{
		int broj_cifara=0;
		int kopija = broj;
		while(kopija){
			kopija/=10;
			broj_cifara++;		
		}
		kopija = broj;
		for(int i = 1; i < broj_cifara-1; i++){
			//if(((int)(broj/pow(i,10))%10) == ((kopija/(int)pow(i+1,10))%10)+((kopija/(int)(pow(i-1,10)))%10)){
			//	broj = (broj/(int)pow(i+1,10))*(int)pow(i,10)+(broj%(int)pow(i,10)); 
			if((broj/power(i,10))%10 == ((kopija/power(i+1,10))%10) + ((kopija/power(i-1,10))%10)){
				broj = broj/power(i+1,10) * power(i,10) + broj%power(i,10);
 
			}
		}
		printf("broj je: %d \n", broj);
		printf("power funkcija: %d\n", power(3,10));
		
	}

	
	return 0;
}
