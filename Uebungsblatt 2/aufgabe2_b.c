#include <stdio.h>

double potenzieren(double basis, int exponent) {

 if(exponent == 0) return 1.0;
 double erg;
 int i;

 for(i = 1; i < exponent; i++) {
  if(i%2 == 0) erg = basis * basis;
  if(i%2 == 1) erg = basis * basis * basis;
 }
 //printf("Benoetigte Schritte zur Berechnung:  %i.\n",schrittzaehler);
 return erg;
}



int main() {

 double basis;
 int exponent;

 puts("\nDieses Programm berechnet die Potenz einer Zahl: b^e");
 puts("b ist eine reelle Zahl und e ist eine Natuerliche Zahl (inklusive 0).\n");


 printf("Gebe Basis an mit Dezimalpunkt: ");
 scanf("%lf[/n]",&basis);

 while(1) {
  printf("Gebe Exponent an: ");
  scanf("%i[\n]",&exponent);
  if(exponent < 0) {
	puts("Der Exponent ist keine Natuerliche Zahl");
	continue;
  }
  else break;
 }

 printf("%lf^%i = %lf\n",basis,exponent,potenzieren(basis,exponent));
}
