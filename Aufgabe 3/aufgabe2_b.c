#include <stdio.h>

void untprog1(int z) {

 unsigned int mask = 01 << 31;
 int i;
// for( i=31; i>=0; i--) {
 i = 31;
 while( i>=0 ){
  if ((z&mask) != 0)
	printf("1");
  else printf("0");

  if((i%8 == 0) && mask != 1) printf(".");

  mask >>= 1;
  i--;
 }
printf("\n");
}


int main() {

 int input;

 puts("\nDieses Programm gibt die eingegebene Zahl als Binaerzahl aus.");
 printf("Bitte geben Sie eine Zahl ein: ");

 scanf("%i[\n]",&input);
 untprog1(input);
 puts("Ende des Programms.");

 return 0;
}
