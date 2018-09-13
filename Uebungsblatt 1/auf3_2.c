#include <stdio.h>

int fibonacci(int n) {

 if(n == 0) return 0;
 if(n == 1) return 1;
 return fibonacci(n-1) + fibonacci(n-2);
}

int main() {

 int n;

 puts("Geben Sie eine Zahl größer gleich 0 ein: ");
 read: scanf("%i[\n]",&n);
 if(n < 0) {
	puts("Fehler: Bitte geben Sie eine positive Zahl ein: ");
	goto read;
 }
 printf("Das Ergebnis ist: %i.\n",fibonacci(n));
}
