#include <stdio.h>
/*
void matrixEinlesen(int matrix[][], int zeilenAnz, int spaltenAnz) {

 int i;
 int j;
 puts("Es wird Zeilenweise eingelesen: ");

 for(i = 0; i < zeilenAnz; i++) {
  for(j = 0; j < spaltenAnz; j++) {
   printf("%i. Zeile, %i. Zahl: ",i+1,j+1);
   scanf("%i",matrix[i][j]);
  }
 }

 for(i = 0; i < zeilenAnz; i++) {
  printf("Zeile %i: ",i+1);
  for(j = 0; j < spaltenAnz; j++) {

   printf("%i ",matrix[i][j]);
  }
  puts("");
 }

}
/*

int matrixMult(int m1[][],int m1ZeiAnz,int m1SpaAnz, int m2[][], int m2ZeiAnz, int m2SpaAnz) {


}
*/

int main() {

 int m1ZeilenAnz = -1;
 int m1SpaltenAnz = -1;
 int m2ZeilenAnz = -1;
 int m2SpaltenAnz = -1;

puts("\nDieses Programm berechnet die Multiplikation zweier Matrizen.");
puts("1. Schritt: Festlegen der Matrixgrenzen.");
puts("2. Schritt: Einlesen der Matrizen.");
puts("3. Schritt: Ausgabe der Multiplikation.");

puts("\n\n1. Schritt: Festlegen der Matrixgrenzen.");

puts("Beachten Sie dass die Spaltenanzahl der 1. Matrix mit der Zeilenanzahl der 2. Matrix uebereinstimmen muss.");
puts("");

while(m1ZeilenAnz < 0) {
 printf("Geben Sie die Anzahl der Zeilen(>0) der 1. Matrix an: ");
 scanf("%i",&m1ZeilenAnz);
}

while(m1SpaltenAnz < 0) {
printf("Geben Sie die Anzahl der Spalten(>0) der 1. Matrix an: ");
 scanf("%i",&m1SpaltenAnz);
}

while(m2ZeilenAnz < 0) {
printf("Geben Sie die Anzahl der Zeilen(>0) der 2. Matrix an: ");
 scanf("%i",&m2ZeilenAnz);
}

if(m1SpaltenAnz != m2ZeilenAnz) {
	puts("Die Spaltenanzahl der 1. Matrix muss mit der Zeilenanzahl der 2. Matrix uebereinstimmen, wenn sie multiplizieren wollen.");
	puts("Starten Sie das Programm erneut.");
	return 0;
}

while(m2SpaltenAnz < 0) {
printf("Geben Sie die Anzahl der Spalten(>0) der 2. Matrix an: ");
 scanf("%i",&m2SpaltenAnz);
}
puts("");

int m1[m1ZeilenAnz][m1SpaltenAnz];
int m2[m2ZeilenAnz][m2SpaltenAnz];

//matrixEinlesen(m1,m1ZeilenAnz,m1SpaltenAnz);

puts("2. Schritt: Einlesen der Matrizen.");

 int i;
 int j;
 puts("Die 1. Matrix: ");
 puts("Es wird Zeilenweise eingelesen: ");

 for(i = 0; i < m1ZeilenAnz; i++) { 		// einlesen
  for(j = 0; j < m1SpaltenAnz; j++) {
   printf("%i. Zeile, %i. Zahl: ",i+1,j+1);
   scanf("%i",&m1[i][j]);
  }
 }

 for(i = 0; i < m1ZeilenAnz; i++) {		//ausgeben
  printf("Zeile %i: | ",i+1);
  for(j = 0; j < m1SpaltenAnz; j++) {

   printf("%i ",m1[i][j]);
  }
  printf("|");
  puts("");
 }
puts("");

 puts("Die 2. Matrix: ");
 puts("Es wird Zeilenweise eingelesen: ");

 for(i = 0; i < m2ZeilenAnz; i++) {		//einlesen
  for(j = 0; j < m2SpaltenAnz; j++) {
   printf("%i. Zeile, %i. Zahl: ",i+1,j+1);
   scanf("%i",&m2[i][j]);
  }
 }

 for(i = 0; i < m2ZeilenAnz; i++) {		//ausgeben
  printf("Zeile %i: | ",i+1);
  for(j = 0; j < m2SpaltenAnz; j++) {

   printf("%i ",m2[i][j]);
  }
  printf("|");
  puts("");
 }

puts("\n3. Schritt: Ausgabe der Multiplikation.");

int m3[m1ZeilenAnz][m2SpaltenAnz];

 for(i = 0; i < m1ZeilenAnz; i++) {  //Init
  for(j = 0; j < m2SpaltenAnz; j++) {
	m3[i][j] = 0;
  }
 }


int m;

for(i=0; i < m1ZeilenAnz; i++) {		//rechnen
 for(j=0; j < m2SpaltenAnz; j++) {

  for(m = 0; m < m1SpaltenAnz; m++) {

    m3[i][j] = m3[i][j] + (m1[i][m] * m2[m][j]);
  }
 }
}

puts("Das Ergebnis ist folgende Matrix: \n");

 for(i = 0; i < m1ZeilenAnz; i++) {		//ausgeben
  printf("Zeile %i: | ",i+1);
  for(j = 0; j < m2SpaltenAnz; j++) {

   printf("%i ",m3[i][j]);
  }
  printf("|");
  puts("");
 }


return 0;
}

