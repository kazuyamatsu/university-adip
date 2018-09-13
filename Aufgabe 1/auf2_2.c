#include <stdio.h>

int main() {

 int n;
 int erg;

 while( 1 ) {

  scanf("%i",&n);
  if ( n < 1 ) {
	puts("Bitte geben Sie eine positive Zahl ein: \n");
	continue;
  } else {
	erg = (n*(n+1)*(2*n+1))/6;
	printf("Die Summe der Quadratzahlen von 1 bis %i ist %i.\n",n,erg);
	break;
  }
 }
 return 0;
}
