#include <stdio.h>

void readBorder(int *border, char *descr) {

	*border = -1;
	printf("%s",descr);
	while(*border < 0) {
	 scanf("%i",border);
	}
}

int main() {

 int m1ZeilenAnz;
 int m1SpaltenAnz;
 int m2ZeilenAnz;
 int m2SpaltenAnz;

puts("\nDieses Programm berechnet die Multiplikation zweier Matrizen.");
puts("1. Schritt: Festlegen der Matrixgrenzen.");
puts("2. Schritt: Einlesen der Matrizen.");
puts("3. Schritt: Ausgabe der Multiplikation.");
puts("\n\n1. Schritt: Festlegen der Matrixgrenzen.");
puts("Beachten Sie dass die Spaltenanzahl der 1. Matrix mit der Zeilenanzahl der 2. Matrix uebereinstimmen muss.");
puts("");

readBorder(&m1ZeilenAnz,"Geben Sie die Anzahl der Zeilen(>0) der 1. Matrix an: ");
readBorder(&m1SpaltenAnz,"Geben Sie die Anzahl der Spalten(>0) der 1. Matrix an: ");
readBorder(&m2ZeilenAnz,"Geben Sie die Anzahl der Zeilen(>0) der 2. Matrix an: ");

if(m1SpaltenAnz != m2ZeilenAnz) {
	puts("Die Spaltenanzahl der 1. Matrix muss mit der Zeilenanzahl der 2. Matrix uebereinstimmen, wenn sie multiplizieren wollen.");
	puts("Starten Sie das Programm erneut.");
	return 0;
}

readBorder(&m2SpaltenAnz,"Geben Sie die Anzahl der Spalten(>0) der 2. Matrix an: ");
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

