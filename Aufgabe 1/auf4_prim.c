#include <stdio.h>

int main() {

 int n;
 int prim = 1;
 int testvar = 2;


 puts("Bitte geben Sie eine Zahl größer als 0 ein: ");
 scanf("%i",&n);

 if(n < 1) {
	puts("Fehler: Zahl ist kleiner als 1. Das Programm wird beendet.");
   	return 0;
 } else if ( n == 1 ) {
	puts("Nein.");
	return 0;
 }


 while( testvar < n ) {

  if(n % testvar == 0) {
	puts("Nein.");
	return 0;
  }
  testvar++;
 }

 puts("Ja.");
 return 0;
}
