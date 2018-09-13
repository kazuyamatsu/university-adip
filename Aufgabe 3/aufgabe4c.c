#include <stdio.h>

int ermittleTeilersumme(int input) {

 int i;
 int teilersumme = 0;
 for(i = input - 1; i>0; i--) {
  if( input%i == 0 ) teilersumme += i;
  // printf("%i mod %i: teilersumme = %i\n",input,i,teilersumme);
 }

 // 1 ist Teiler von jeder positiven Natuerlichen Zahl
 // printf("%i mod %i: teilersumme = %i\n\n",input,1,teilersumme);

 if( input ==  teilersumme )  printf("%i ist vollkommen.\n",input);
}


void gebeVollkommeneZahlen(int r) {
 int i;
 for(i = 1; i < r; i++) {
   ermittleTeilersumme(i);
 }
}
int main() {

 int input = -1;

 puts("\nDieses Programm gibt bis zu einem r alle Zahlen kleiner als r aus die vollkommen sind.");
 while( input < 0 ) {
  printf("Bitte geben Sie eine natuerliche Zahl ein: ");
  scanf("%i[\n]",&input);
 }
 gebeVollkommeneZahlen(input);
 puts("\nEnde des Programms.");

 return 0;
}

