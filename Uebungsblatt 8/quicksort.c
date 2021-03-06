#include <stdio.h>


void swap(int *unsorted, int pos1, int pos2) {
 int tmp;
 tmp = unsorted[pos1];
 unsorted[pos1] = unsorted[pos2];
 unsorted[pos2] = tmp;
}

quickSort(int *unsorted,int arraysize,int l, int r) {

 int i = l;
 int j = r-1;

 if(l >= r) return;
 int pivot = unsorted[r];

 while(unsorted[i] < pivot) i++;
 while( j>=l && unsorted[j] >= pivot) j--;

 while( i < j ) {
  swap(unsorted,i,j);
  while(unsorted[i] < pivot) i++;
  while(unsorted[j] >=pivot) j--;
 }
 swap(unsorted,i,r);
 
 quickSort(unsorted,arraysize,l,i-1);
 quickSort(unsorted,arraysize,i+1,r);
}

int main() {

 int i;
 int a[] = {4,9,2,1};
 quickSort(a,4,0,3);
 puts("");
 for(i = 0; i < 4; i++) {
  printf("%i ",a[i]);
 }
 puts("");
}
