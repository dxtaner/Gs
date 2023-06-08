#include<stdio.h>
 int Topla(int x, int y);
 
 	
//int dTest = 5;
//msg(dTest);
//dTest = Topla(10, 5);
//msg(dTest);

int main(){
	int a=5;
	printf("%d",a);
	a=Topla(10,5);
	printf("%d",a);
}

int Topla(int x, int y) { return x+y;}
