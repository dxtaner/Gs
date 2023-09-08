#include<stdio.h>
#include<math.h> 

int bul(int a,int b);

int main(){
	
	// Two random prime numbers 
    double p = 3; 
    double q = 7; 
  
    // First part of public key: 
    double n = p*q; 
  
    // Finding other part of public key. 
    // e stands for encrypt 
    double e = 2; 
    double fonk = (p-1)*(q-1); 
    while (e < fonk) 
    { 
        // e must be co-prime to phi and 
        // smaller than phi. 
        if (bul(e, fonk)==1) 
            break; 
        else
            e++; 
    } 
  
    // Private key (d stands for decrypt) 
    // choosing d such that it satisfies 
    // d*e = 1 + k * totient 
    int k = 2;  // A constant value 
    double d = (1 + (k*fonk))/e; 
  
    // Message to be encrypted 
    double msg = 20; 
  
    printf("Message data = %lf", msg); 
  
    // Encryption c = (msg ^ e) % n 
    double c = pow(msg, e); 
    c = fmod(c, n); 
    printf("\nEncrypted data = %lf", c); 
  
    // Decryption m = (c ^ d) % n 
    double m = pow(c, d); 
    m = fmod(m, n); 
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
