#include <stdio.h>

int collatz(int n, int zaehler) {
 if(n == 1) {
//	printf("%i\n",n);
	return zaehler;
 }
 if(n%2 == 0) {
//	printf("%i, ",n);
	return collatz(n/2,zaehler+1);
 }
 if(n%2 != 0) {
//	printf("%i, ",n);
	return collatz(3*n+1, zaehler+1);
 }
}

int main() {

 int maximum = 1;
 int i;
 int n;

 for(i=1;i<1000;i++){
	if(collatz(i,1) > maximum){
	 maximum = collatz(i,1);
	 n = i;
	}
 }

 printf("Die Zahl %i hat die groesste Anzahl Folgeglieder: %i.\n\n",n,maximum);
 return 0;
}

