#include <stdio.h>

int collatz(int n, int zaehler) {
 if(n == 1) {
	printf("%i\n",n);
	return zaehler;
 }
 if(n%2 == 0) {
	printf("%i, ",n);
	return collatz(n/2,zaehler+1);
 }
 if(n%2 != 0) {
	printf("%i, ",n);
	return collatz(3*n+1, zaehler+1);
 }
}

int main() {

 int eingabe;
 while(1) {
  puts("Dieses Programm berechnet die Anzahl der Folgeglieder der Collatz'schen Folge ausgehend von einem Glied n.");
  puts("Die Zahl n muss eine natuerliche Zahl groesser als 0 sein.");
  printf("Bitte geben Sie die Zahl ein und bestaetigen Sie mit Enter: ");
  scanf("%i[\n]", &eingabe);
  if(eingabe < 0) {
	puts("Die Zahl ist nicht groesser als 0.\n");
	continue;
  }
  else break;
 }
 printf("Die laenge der Folge ist %i.\n\n",collatz(eingabe,1));
}

