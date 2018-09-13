#include <stdio.h>

int  ermittleTeilersumme(int input) {

 int i;
 int teilersumme = 0;
 for(i = input - 1; i>1; i--) {
  if( input%i == 0 ) teilersumme += i;
  //printf("%i mod %i: teilersumme = %i\n",input,i,teilersumme);
 }

 teilersumme += 1; // 1 ist Teiler von jeder positiven Natuerlichen Zahl
 //printf("%i mod %i: teilersumme = %i\n\n",input,1,teilersumme);

 if(input > teilersumme) return 1;
 else return 0;
}


void AnzahlDefiziente(int r) {
 int zaehler = 0;
 int i;
 for( i = 1; i < r; i++) {
  zaehler += ermittleTeilersumme(i);
 }
 printf("Die Summe aller defizienten Zahlen unter %i: %i.\n",r,zaehler);
}

int main() {

 int input = -1;

 puts("\nDieses Programm gibt die Anzahl der defzienten Zahlen unter einer Zahl r an: ");
 while( input < 0 ) {
  printf("Bitte geben Sie eine natuerliche Zahl ein: ");
  scanf("%i[\n]",&input);
 }
 AnzahlDefiziente(input);
 puts("\nEnde des Programms.");

 return 0;
}

