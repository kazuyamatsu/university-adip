#include <stdio.h>

void readBorder(int *border, char *descr) {

	*border = -1;
	printf("%s",descr);
	while(*border < 0) {
	 scanf("%i",border);
	}
}

void readMatrix(int *m,int zeilenAnz,int spaltenAnz,char *descr) {

 printf("%s",descr);
 int i,j;

 for(i = 0; i < zeilenAnz; i++) {
  for(j = 0; j < spaltenAnz; j++) {
   printf("%i. Zeile, %i. Zahl: ",i+1,j+1);
   scanf("%i",m);
   m++;
  }
 }

}

void printMatrix(int *m,int zeilenAnz,int spaltenAnz) {

 int i,j;

 for(i = 0; i < zeilenAnz; i++) {
  printf("Zeile %i: | ",i+1);
  for(j = 0; j < spaltenAnz; j++) {

   printf("%i ",*m);
   m++;
  }
  printf("|");
  puts("");
 }
puts("");



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


int m1[m1ZeilenAnz][m1SpaltenAnz];
int m2[m2ZeilenAnz][m2SpaltenAnz];

puts("2. Schritt: Einlesen der Matrizen.");

readMatrix(&(m1[0][0]),m1ZeilenAnz,m1SpaltenAnz,"Die 1. Matrix: \nEs wird zeilenweise eingelesen: \n\n");
printMatrix(&(m1[0][0]),m1ZeilenAnz,m1SpaltenAnz);

readMatrix(&(m2[0][0]),m2ZeilenAnz,m2SpaltenAnz,"Die 2. Matrix: \nEs wird Zeilenweise eingelesen: \n\n");
printMatrix(&(m2[0][0]),m2ZeilenAnz,m2SpaltenAnz);

puts("\n3. Schritt: Ausgabe der Multiplikation.");

int m3[m1ZeilenAnz][m2SpaltenAnz];
int i,j;

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
printMatrix(&(m3[0][0]),m1ZeilenAnz,m2SpaltenAnz);

return 0;
}

