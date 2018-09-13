#include <stdio.h>


int * bubbleSort(int * unsortiert, int arraysize) {

 int swapped = 1;
 int i,tmp;
 int e = 1;

 while(swapped == 1) {
	swapped = 0;
	for(i = 0; i<(arraysize-e); i++){
	 if(unsortiert[i] > unsortiert[i+1]){
		tmp = unsortiert[i];
		unsortiert[i] = unsortiert[i+1];
		unsortiert[i+1]	= tmp;
	  	swapped = 1;
		
	 }
    }
	e++;
 }
 
}
