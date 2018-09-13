#include <stdio.h>
#include <stdlib.h>

void merge(int * unsorted, int start, int haelfte, int ende) {

 int pos1 = start; 
 int pos2 = haelfte + 1; 
 int i = 0;
 int m = ende-start+1;
 int *tmp = malloc(m * sizeof(int));
 
 while(pos1 <= haelfte || pos2 <= ende) {
	if(pos2 > ende) {
		 tmp[i++] = unsorted[pos1++];
	 } else if (pos1 > haelfte) {
		 tmp[i++] = unsorted[pos2++];
	 } else if (unsorted[pos1] < unsorted[pos2]) {
		 tmp[i++] = unsorted[pos1++];
	 } else {
		 tmp[i++] = unsorted[pos2++];
	 }
  }
 for(i=0; i< ende - start + 1; i++) {
  unsorted[start + i] = tmp[i];
 }
 free(tmp);
}


void mergeSort(int * unsorted, int start, int ende) {
 int haelfte;
 if(start != ende) {
		haelfte = (start + ende) / 2;
		mergeSort(unsorted,start,haelfte);
		mergeSort(unsorted,haelfte+1,ende);
		merge(unsorted,start,haelfte,ende);
 }

}

int main() {

 int i;
 int a[] = {7,5,2,1};
 mergeSort(a,0,3);
 puts("");
 for(i = 0; i < 4; i++) {
  printf("%i ",a[i]);
 }
 puts("");
}
