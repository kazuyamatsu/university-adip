#include <stdio.h>



int main( )
{
    
    

int n,i;
    
double newValue;
    
    

printf("Geben Sie die Größe des einzulesenden Arrays ein:\n");
    
scanf("%i",&n);
    
    
double array[n];
    
    

for (i = 0; i < n; i++) {
        
	printf("Geben Sie einen Wert für das Array ein.\n");
        
	scanf("%lf",&newValue);
        
	array[i] = newValue;
    
}
    
    

printf("Array fertig befüllt!\n");
    
 
   
double sum = 0.0;
    
for (i = 0; i < n; i++) {
        
	sum += array[i];
    
}
    
    

double arithmetic = sum/(double)n;
    
    
double sum2 = 0.0;
    
for (i = 0; i < n; i++) {
        
	sum2 += (array[i]-arithmetic)*(array[i]-arithmetic);
    
}
    
    

double stichprobenVarianz = sum2/((double)n-1.00);
    
    
    
printf("Das arithmetische Mittel ist %fl und die Stichprobenvarianz ist %fl.\n",arithmetic,stichprobenVarianz);
    

return 0;


}

