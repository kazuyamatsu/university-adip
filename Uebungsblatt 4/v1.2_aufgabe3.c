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

void matrixMult(int *m1,int m1zeilenAnz,int m1spaltenAnz,int *m2,int m2zeilenAnz,int m2spaltenAnz,int *m3) {

 int i,j,m,*temp;
 temp = m3;
 *(m3+1) = 7; printf("%i\n\n",*(m3+1));
 *(m3+3) = 9; printf("%i\n\n",*(m3+3));
 for(i = 0; i < m1zeilenAnz*m2spaltenAnz; i++) {
  *m3++ = 0;
 }

/*
 for(i = 0; i < m1zeilenAnz; i++) {
  for(j = 0; j < m2spaltenAnz; j++) {
        m3[i][j]=0;    *m3 = 0;
	m3++;
  }
 } */

 m3 = temp;
int x,y,z;
 for(i=0; i < m1zeilenAnz; i++) {
  for(j=0; j < m2spaltenAnz; j++) {

   for(m = 0; m < m1spaltenAnz; m++) {
	x = i+j;
	y = i+m;
	z = m+j;
     *(m3+x) = *(m3+x) + ( *(m1+y) * *(m2+z) ); //m3[i][j] += (m1[i][m] * m2[m][j]);

   }
  }
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

int m1[m1ZeilenAnz][m1SpaltenAnz];
int m2[m2ZeilenAnz][m2SpaltenAnz];

puts("2. Schritt: Einlesen der Matrizen.");
readMatrix(&(m1[0][0]),m1ZeilenAnz,m1SpaltenAnz,"Die 1. Matrix: \nEs wird zeilenweise eingelesen: \n\n");
printMatrix(&(m1[0][0]),m1ZeilenAnz,m1SpaltenAnz);
readMatrix(&(m2[0][0]),m2ZeilenAnz,m2SpaltenAnz,"Die 2. Matrix: \nEs wird Zeilenweise eingelesen: \n\n");
printMatrix(&(m2[0][0]),m2ZeilenAnz,m2SpaltenAnz);

puts("\n3. Schritt: Ausgabe der Multiplikation.");

/*
int m3di1[m1ZeilenAnz];
int m3di2[m2SpaltenAnz];
int *m3[]={m3di1,m3di2};
*/
int m3[m1ZeilenAnz][m2SpaltenAnz];

matrixMult(&(m1[0][0]),m1ZeilenAnz,m1SpaltenAnz,&(m2[0][0]),m2ZeilenAnz,m2SpaltenAnz,&(m3[0][0]));

puts("Das Ergebnis ist folgende Matrix: \n");
printMatrix(&(m3[0][0]),m1ZeilenAnz,m2SpaltenAnz);

return 0;
}

