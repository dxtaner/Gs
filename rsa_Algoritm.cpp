#include<stdio.h>
#include<math.h> 
#include<string.h>
#include<stdlib.h>

int bul(int a,int b);
int asalmi(int sayi);


int main(){
	int p,q,n,totient,e;
	
	printf("Birinci asal sayi :");
	scanf("%d",&p);
	
	if(asalmi(p)==0){
		printf("asal sayi girmediniz!");
		exit(1);
	}
	
	printf("ikinci asal sayi :");
	scanf("%d",&q);
	
	if(asalmi(q)==0 || q==p){
		printf("sayiniz asl deðil ve ya p degeri ile ayni ");
		exit(1);	
	}
	
	n=p*q;
	totient=(p-1)*(q-1);
	e=2;
		while(e<totient){
			if(bul(e,totient)==1){
			break;
			}	
			else{
				e++;
			}
		} 
 	
	int k = 2; 
    double d = (1 + (k*totient)/e);
 
    double msg = 20;
 
    printf("Message data = %lf", msg);
 
    //Þifreleme
    double c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted data = %lf", c);
 
    // Deþifreleme  
    m = bul(m, n);
    printf("\nOriginal Message Sent = %lf", m);		
	
return 0;	
}

int bul(int a,int b){
	if(b==0){
	 return a;	
	}
	int kalan=a%b;
	int c=a/b;
	a=b;
	b=kalan;
	return bul(a,b);	
}

int asalmi(int sayi){
	int i,temp=sayi;
	for(i=2 ; i<=sayi/2 ; i++){
		if(sayi%i==0)
		{
			return 0;
		}
	}
	return 1;
}
