#include <stdio.h>
//10.17
int gizem(unsigned int bits);

int main(void){
unsigned int x; 

puts("Tam sayi giriniz: ");
scanf("%u",&x);
printf("Sonuc: %d\n", gizem(x));
}

int gizem(unsigned int bits){
unsigned int i;
unsigned int mask = 1<<31;
unsigned int toplam=0;

for(i=0; i<=32; i++, bits<<=1){
	if((bits & mask)==mask){
	++toplam;
	printf("%u",toplam);
	}

}
return !(toplam%2) ? 1:0 ;
}
