#include <stdio.h>

void swap(int *unsorted, int pos1, int pos2) {
 int tmp;
 tmp = unsorted[pos1];
 unsorted[pos1] = unsorted[pos2];
 unsorted[pos2] = tmp;
}

void insertSorted(int * unsorted, int insertPos) {
 int i;
 int swapped = 1;

 for(i = insertPos; i > 0; i--) {
	if(swapped == 0) break;
  swapped = 0;
  if(unsorted[i-1] > unsorted[i]) {
    swap(unsorted,i-1,i);
		swapped = 1;
  }
 }
}

void insertionSort(int * unsorted, int arraysize) {
int i;
int next = 1;

 for(i = 1; i < arraysize; i++) {
  insertSorted(unsorted,i);
 }
}



int main() {

 int i;
 int a[] = {3,1,2,10};
 insertionSort(a,4);
 puts("");
 for(i = 0; i < 4; i++) {
  printf("%i ",a[i]);
 }
 puts("");
}
