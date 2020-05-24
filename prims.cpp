#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void oku();
int dizi[4][4];
void algoritma(int dizi[4][4]);
int yazdir(int ana[],int dizi[4][4]);
int kisayol(int key[], bool ziyaret[]);

int main(){

	oku();
	algoritma(dizi);
	
	return 0;
}

void oku()
{
    int i=0;
    FILE *dosya = fopen("prims.txt", "r");
 
    while(fscanf(dosya,"%d %d %d %d",&dizi[i][0],&dizi[i][1],&dizi[i][2],&dizi[i][3])!=EOF) {
        i+=1;
    }
}

int yazdir(int ana[], int dizi[4][4])
{
   int i;
   printf("KENAR \tAGIRLIGI\n"); 
   for (i=1; i<4; i++){
   	 printf("%d - %d  \t%d \n", ana[i], i,dizi[i][ana[i]]);
   }
     
}

void algoritma(int dizi[4][4])
{
    int i,j,k;
    int key[4];
    int ana[4];
    bool ziyaret[4];
    
    for(i=0; i<4; i++){
        ziyaret[i]=false;
        key[i]=999;
    }
 
    key[0]=0;
    ana[0]=-1;
 
    for(j=0; j<4; j++)
	{
        int enkisayol=kisayol(key,ziyaret);
        ziyaret[enkisayol]=true;
 
        for(k=0; k<4; k++)
        {
            if(dizi[enkisayol][k] && ziyaret[k]==false && dizi[enkisayol][k]<key[k])
            {
                key[k]=dizi[enkisayol][k];
                ana[k]=enkisayol;
            }
        }
    }
    yazdir(ana,dizi);
 
}

int kisayol(int key[], bool ziyaret[])
{
    int min=999;
    int minIndex, i;
    for( i=0; i<4; i++){
        if(ziyaret[i]==false && key[i]<min)
        {
            minIndex=i;
			min=key[i];    
        }
    }
    return minIndex;
}


