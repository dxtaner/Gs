#include <stdio.h>
#include <stdlib.h>

void siralama(int sayi[], int size){
	int i,j,temp,temp2;
	int index;
	int dizi[4];	

	printf("\n");
	for(j=1; j <4; j++)
       {
           for (i=0;i<4-1;i++)
           {
           if (sayi[i]<sayi[i+1])
           {
               temp=sayi[i];
               sayi[i]=sayi[i+1];
               sayi[i+1]=temp;
               index=i;
       		 }
       		 
           }
           dizi[i]=index;
       }
	  
	  for (i=0;i<4;i++)
      {
          printf("%d. aday ",dizi[i]);
      }		
	
      printf("\nsiralamalar");	
      for (i=0;i<4;i++)
      {
          printf("%d-",sayi[i]);
      }
	
}

void agirlik_hesapla(){
	float a,b,c,d;
	int toplam[4];
	int A,B,C,D;
	int i;
	float sonuc;
	printf("a agirlik:"); scanf("%f",&a);
    printf("b agirlik:"); scanf("%f",&b);
	printf("c agirlik:"); scanf("%f",&c);
	printf("d agirlik:"); scanf("%f",&d);
	for(i<0;i<4;i++){
	printf("\n%d. aday\n",(i+1));	
    printf("A:"); scanf("%d",&A);
    printf("B "); scanf("%d",&B);
	printf("C "); scanf("%d",&C);
	printf("D "); scanf("%d",&D);
	sonuc=A*a+B*b+C*c+D*d;
	toplam[i]=sonuc;
	printf("%d adayin toplam degeri %.2f",(i+1),sonuc);	
	}
	
	siralama(toplam,4);

	
}

int main(void)
{
    agirlik_hesapla();
}

