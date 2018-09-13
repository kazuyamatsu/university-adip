#include <stdio.h>


void testAufEigenschaft(int input,int teilersumme) {

 if(teilersumme == input) printf("%i ist vollkommen.\n",input);
 else
	if(input > teilersumme) printf("%i ist defizient.\n",input);
  		else printf("%i ist weder vollkommen noch defizient.\n",input);
}


int ermittleTeilersumme(int input, int ausgabeRechnung, int ausgabeEig) {

 int i;
 int teilersumme = 0;
 for(i = input - 1; i>1; i--) {
  if( input%i == 0 ) teilersumme += i;
  if ( ausgabeRechnung ) printf("%i mod %i: teilersumme = %i\n",input,i,teilersumme);
 }

 teilersumme += 1; // 1 ist Teiler von jeder positiven Natuerlichen Zahl
 if ( ausgabeRechnung ) printf("%i mod %i: teilersumme = %i\n\n",input,1,teilersumme);

 if( ausgabeEig ) testAufEigenschaft(input,teilersumme);

 if( input == teilersumme ) return 1;
 else return 0;
}


void gebeVollkommeneZahlen(int r) {
 int zaehler = 0;
 int i;
 for(i = 1; i < r; i++) {
   zaehler += ermittleTeilersumme(i,0,1);
 }
}
int main() {

 int input = -1;

 puts("\nDieses Programm testet eine natuerliche Zahl ob sie vollkommen oder defizient ist.");
 while( input < 0 ) {
  printf("Bitte geben Sie eine natuerliche Zahl ein: ");
  scanf("%i[\n]",&input);
 }
 ermittleTeilersumme(input,1,1);
 puts("\nEnde des Programms.");

 return 0;
}

