#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *unsorted, int pos1, int pos2) {
 int tmp;
 tmp = unsorted[pos1];
 unsorted[pos1] = unsorted[pos2];
 unsorted[pos2] = tmp;
}

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

quickSort(int *unsorted,int arraysize,int l, int r, int pivotpos) {

 switch(pivotpos) {
  case 0: 

	case 1:

	case 2:

	default:  
  
 }

 int i = l;
 int j = r-1;

 if(l >= r) return;
 int pivot = unsorted[pivotpos];

 while(unsorted[i] < pivot) i++;
 while( j>=l && unsorted[j] >= pivot) j--;

 while( i < j ) {
  swap(unsorted,i,j);
  while(unsorted[i] < pivot) i++;
  while(unsorted[j] >=pivot) j--;
 }
 swap(unsorted,i,r);
 
 quickSort(unsorted,arraysize,l,i-1,);
 quickSort(unsorted,arraysize,i+1,r,);
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

void generateRandomNumbers(int *array, int beginPos, int arraysize) {

 int i;
 
 for(i = beginPos; i < arraysize; i++) {
  array[i] = (rand() % (arraysize))+1;
 }

}

void generateSuccessiveNumbers(int *array, int arraysize) {

 int i;

 for(i = 0; i < arraysize; i++) {
  array[i] = i+1;
 }
}

void copyArray(int *array1,int *array2,int arraysize) {
 int i;

 for(i = 0; i < arraysize; i++) {
 		array2[i] = array1[i];
 }
}

void printTime(time_t start, time_t ende, char * name) {
 printf("| %s: benoetigte Zeit %ld s.\n",name,ende-start);
}


int main() {
 srand(time(NULL));
 time_t start,ende;
 
 int array[40500];
 int arrayC[40500];
 generateSuccessiveNumbers(array,40000);
 generateRandomNumbers(array,40000,40500);

 printf(
	  "\n^________________________________________________^\n"
        "|                                                |\n"
		"|           *<| Start des Programms |>*          |\n"
        "|________________________________________________|\n"           
        "#------------------------------------------------#\n"
        "|                                                |\n"
		"| Dieses Programm vergleicht die Laufzeiten von  |\n"
		"| Bubble-, Selection-, Insertion-, Quick- und    |\n"
		"| Mergesort als Arrayimplementierung. Die Lauf-  |\n"
		"| zeiten werden je nach Rechner unterschiedlich  |\n"
		"| ausfallen. Wenn die Laufzeit 0 Sekunden betr-  |\n"
		"| aegt, dann belaeuft sich diese unter 0 Sekund- |\n"
		"| en.(Also Millilsekunden)                       |\n"
		"| Die Besonderheit bei diesem Vergleich besteht  |\n"
        "| darin, das dieses mal 40500 Elemente sortiert  |\n"
		"| werden. Die ersten 40.000 sind sortiert und    |\n"
        "| die restlichen 500 sind unsortiert.            |\n"
        "|                                                |\n"
		"v------------------------------------------------v\n"
		"|                                                 \n"
		"| \n"
		"| Druecken Sie eine beliebige Enter zum starten:"
				
 );
 getchar();
 printf("|\n| Folgende Ergebnisse werden erreicht:\n"
	    "|\n"
 );

 //Bubblesort
 start = time(0);
 bubbleSort(array,40500); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Bubblesort");
 
 //Insertionsort
 start = time(0);
 insertionSort(array,40500); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Insertionsort");

 //Selectionsort
 start = time(0);
 selectionSort(array,40500); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Selectionsort");

 //Quicksort
 start = time(0);
 quickSort(array,40500,0,40500,40499); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Quicksort");

 //Mergesort
 start = time(0);
 mergeSort(array,0,40500); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Mergesort");
 
 printf("|\n"
				"#------------------------------------------------#\n"
        "^________________________________________________^\n"
        "|                                                |\n"
		"|  *<| Ende des ersten Teiles des Programmes |>* |\n"
        "|________________________________________________|\n"
		"v------------------------------------------------v\n"
		"|                                                |\n"
		"| Nun wird die Laufzeit von Quicksort ueber-     |\n"
		"| prueft, wenn das Pivotelement das erste, das   |\n"
		"| mittlere oder das letzte Element des Arrays    |\n"
		"| ist.                                           |\n"
		"#------------------------------------------------#\n"
		"|\n"          
 );
 printf("| Pivot links: ");
 //Quicksort
 start = time(0);
 quickSort(array,40500,0,40500,0); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Quicksort");
 
 printf("| Pivot mitte: ");
 //Quicksort
 start = time(0);
 quickSort(array,40500,0,40500,20250); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Quicksort");

 printf("| Pivot rechts: ");
 //Quicksort
 start = time(0);
 quickSort(array,40500,0,40500,40499); 
 ende = time(0);
 copyArray(arrayC,array,40500);
 printTime(start,ende,"Quicksort");

 printf("|\n"
		"#------------------------------------------------#\n"
        "^________________________________________________^\n"
        "|                                                |\n"
		"|           *<| Ende des Programms |>*           |\n"
        "|________________________________________________|\n"           
 );

}
