#include <stdio.h>

int main(){
	
	int sayi1,sayi2;
	int say=0;
	int i=0;
	printf("sayi girin");
	scanf("%d",&sayi1);
	sayi2=sayi1;
	
	int bassayisi=0;
	
	while(sayi1>0){
		sayi1=sayi1/10;
		bassayisi++;
	}
	
	printf("sayi basamagi %d \n",bassayisi);
		
	while(i<bassayisi){
		printf("sayi %d \n",sayi2);
		if(sayi2%10==7){
			printf("sagdan bas. %d \n",i+1);
		}
		sayi2=sayi2/10;
		i++;
	}
	
	
}
