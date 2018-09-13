#include <stdio.h>

int main() {

 float summe[] = { 10000.0, -1.0e-3/9, 25.0e2, 1.0e-3/7, -12.5e3};

 float  erg;
 float s=0.0;
 float sa=0.0;
 float d=0.0;

 int i;
 for(i = 0; i < 5; i++) {
  sa = s;
  s = s + summe[i];
  d = d + (summe[i]-(s-sa));
 }
 erg = d + s;
 printf("Das Ergebnis ist: %f ",erg);
 puts("");

}
