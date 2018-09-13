#include <stdio.h>

double fakultaet(double n) {
 if(n == 0) return 1;
 if(n == 1) return 1;
 return n * fakultaet(n-1);
}

double binominal(double n, double k) {

 if(k > n) return 0;
 return (fakultaet(n)/(fakultaet(k)*fakultaet(n-k)));

}

double lottoprob(double n, double k) {

 return (binominal(n,k)*fakultaet(k));
}

int main() {

 int in = -1;
 int ik = -1;
 int input = -1;
 double ergebnis;

 while(1){
  puts("Im folgenden Programm muessen Sie einen Buchstaben eingeben um einen Modus zu waehlen: \n");
  puts("1: Startet die Berechnung der Fakultaet.");
  puts("2: Startet die Berechung des Binominalkoeffizienten.");
  puts("3: Startet die Berechnung des Lottoproblems.");

  scanf("%i",&input);
  if(input == 1 || input == 2 || input == 3) break;
 }
 switch(input) {
  case 1:	while(in < 0) {
		 puts("Fakultaet erfordert eine natuerliche Zahl.");
		 printf("Gebe n ein: ");
		 scanf("%i",&in);
		}
		ergebnis = fakultaet(in);
		printf("%i! = %lf\n",in,ergebnis);

		return 0;

  case 2: 	while( (in < 0) || (ik < 0) ) {
	 	 puts("Binomialkoeffizient erfordert natuerliche Zahlen ein n und ein k.");
	 	 printf("Gebe n ein: ");
	 	 scanf("%i",&in);
	 	 printf("Gebe k ein: ");
	 	 scanf("%i",&ik);
		}
		ergebnis = binominal(in,ik);
		printf("%i ueber %i = %lf\n",in,ik,ergebnis);

		return 0;

  case 3: 	while( (in < 0) || (ik < 0) ) {
         	 puts("Das Lottoproblem erfordert natuerliche Zahlen n und k: ");
         	 printf("Gebe n ein: ");
         	 scanf("%i",&in);
         	 printf("Gebe k ein: ");
         	 scanf("%i",&ik);
        	}
        	ergebnis = lottoprob(in,ik);
        	printf("Bei %i Zahlen %i auszuwaehlen gibt es  %lf Moeglichkeiten.\n",in,ik,ergebnis);

		return 0;
 }
return 0;
}
