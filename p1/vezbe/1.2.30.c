#include <stdio.h>

int main(){
	int k,l,m,n;
	printf("unesi parove (k,l) i (m,n): ");
	scanf("%d %d %d %d", &k, &l, &m, &n);
	if((k+l)%2 == 0 && (m+n)%2 == 0){
		printf("iste su boje \n");
	}else if((k+l)%2 == 1 && (m+n)%2 == 1){
		printf("iste su boje \n");
	}else{
		printf("nisu iste boje\n");
	}
	
	if(l==n || k==m){
		printf("Kraljica ugrozava\n");
	}else if((k==l) && (m==n)){
		printf("Kraljica ugrozava\n");
	}else if(m<k && n<l){
		int loss = k-m;
		if(m+loss==k && n+loss==l){
			printf("Kraljica ugrozava\n");
		} else{
			printf("Kraljica ne ugrozava!!\n");
		}
	}else if(m>k && n>l){
		int loss = m-k;
		if(m-loss==k && n-loss==l){
			printf("Kraljica ugrozava\n");
		} else{
			printf("Kraljica ne ugrozava!!\n");
		}
	} else if(m<k && n>l){	
		int loss = n-l;
		if(m+loss==k && n-loss==l){
			printf("Kraljica ugrozava\n");
		}else {
			printf("Kraljica ne ugrozava\n");
		}
	
	}else if(m>k && n<l){
		int loss = m-k;
		if(m-loss==k && n+loss==l){
			printf("Kraljica ugrozena!!\n");
		} else{
			printf("Kraljica ne ugrozava\n");
		}

	} else {
		printf("Kraljica ne ugrozava!!\n");
	}
	if((m-2==k || m+2==k) && (n-1==l || n+1==l)){
		printf("Konj ugrozava!!\n");	
	} else if((m+1==k || m-1==k) && (n+2==l || n-2==l)){
		printf("Konj ugrozava!!\n");
	} else {
		printf("Konj ne ugrozava!!\n");
	}
	

	return 0;
}
