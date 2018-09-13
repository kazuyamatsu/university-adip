#include <stdio.h>

int main() {

 double summe[] = { 10000.0, -1.0e-3/9, 25.0e2, 1.0e-3/7, -12.5e3};

 double erg;

 int i;
 for(i = 0; i < 5; i++) {
	erg +=  summe[i];
 }

 printf("Das Ergebnis ist: %lf ",erg);
 puts("");

}
