#include <stdio.h>

void swap(int *unsorted, int pos1, int pos2) {
 int tmp;
 tmp = unsorted[pos1];
 unsorted[pos1] = unsorted[pos2];
 unsorted[pos2] = tmp;
}

int findMini(int *unsorted, int arraysize, int beginpos){
 int minipos = beginpos;
 int i;
 
 for(i = beginpos + 1; i < arraysize; i++) {
  if(unsorted[minipos] > unsorted[i]) {
    minipos = i;
  } 
 }
 return minipos;
}

void selectionSort(int *unsorted, int arraysize) {

 int min,next;
 for(next = 0; next < arraysize; next++) {
	min = findMini(unsorted,arraysize,next);
  swap(unsorted,min,next);
 }
}

int main() {

int i;
int a[] = {10,6,2,4};
selectionSort(a,4);
puts("");
for(i = 0; i < 4; i++) {
printf("%i ",a[i]);
}
puts("");


}
