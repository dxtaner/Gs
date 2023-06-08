#include<stdio.h>

int main(){
	
	char *aranan="devam";
	char *aranacak="beni bul ve aramaya devam et beni arabul";
	char *aranan_index,*temp_arama;
	int sayac=0; int kontrol;
	
	while(*aranacak){
		aranan_index=aranan;
		//printf("%c",aranan_index);
		kontrol=0;
		if(*aranacak == *aranan_index){
			aranan_index++;
			temp_arama=aranacak++;
			while(*aranan_index && *temp_arama){
				if(*temp_arama != *aranan_index){
					kontrol=1;
					break;	
				}
				temp_arama++;
				aranan_index++;
			}
			if(kontrol==0 && !*aranan_index){
				sayac++;
			}
			aranacak++;
		}
	}
	
	printf("%d",sayac);
}
