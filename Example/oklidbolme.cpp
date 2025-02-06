#include<stdio.h>
//dxtaner	

int bul(int a,int b);

int main(){
	
	int sayi1,sayi2;
	int d;
	
	printf("sayi1 :");
	scanf("%d",&sayi1);
	
	printf("sayi2 :");
	scanf("%d",&sayi2);
	
	d=bul(sayi1,sayi2);
	printf("bulunan deger (eboblari) :%d",d);
	
	return 0;
	
}

int bul(int a,int b){
	if(b==0){
	 return a;	
	}
	int kalan=a%b;
	int c=a/b;
	printf("%d = %d X %d + %d\n",a,c,b,kalan);
	a=b;
	b=kalan;
	return bul(a,b);
	
}
