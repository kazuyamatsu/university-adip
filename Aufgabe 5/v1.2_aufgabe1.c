#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *next;
  double data;
 } DoubleNode;


DoubleNode *insertFirst(DoubleNode *head, double c) {
DoubleNode *tmp = malloc(sizeof(DoubleNode));

  tmp->data = c;
  tmp->next = head;
  return tmp;
}

void printList(DoubleNode *head) {

 if(head == NULL) puts("Die Liste ist leer.");

 DoubleNode *tmp = head;

 printf("( ");
 while(tmp != NULL) {
  printf("%lf ",tmp->data);
  tmp = tmp->next;
 }
 printf(")\n\n");
}

double get(DoubleNode *list, int i) {

 int j;
 DoubleNode *pointer = list;

 for(j = 0; j < i; j++) {
  pointer = pointer->next;
  if(pointer == NULL) break;
 }
 if(i>j) {
  printf("Die Liste ist nur %i Eintraege lang. Eine 0 wird zurueckgegben.\n",j+1);
  return 0;
 }
 else return pointer->data;

}

DoubleNode* deleteElement(DoubleNode *list,int i) {

 int j;
 DoubleNode *beforeNode;
 DoubleNode *NextNode;
 DoubleNode *currentNode;

 if(list == NULL) {
 // puts("Die Liste ist leer.");
  return NULL;
 }
 //puts("Alles Okay !0");
 if(i == 0) {
  list = list->next;
  return list;
 }
 //puts("Alles Okay !1 ");

 beforeNode = list;
 currentNode = list->next;
 j = 1;
 while((j < i) && (currentNode->next != NULL)) {
  beforeNode = beforeNode->next;
  currentNode = currentNode->next;
  j++;
 // puts("Alles Okay !2");
 // printf("i = %i und j = %i\n",i,j);
 }

 if( i == j ) {
  beforeNode->next = currentNode->next;
 // puts("Alles Okay !3");
 }
 else printf("Die Liste ist nur %i Eintraege lang.",j+1);

 return list;
}

void requestFunc(int *request, char *desc) {
 *request = -1;
 while( !(*request == 0) && !(*request == 1) ) {
  printf("%s",desc);
  scanf("%i",request);
 }
}

DoubleNode *insertElement(DoubleNode *list, double input, int i) {

 if(i == 0) {
  return insertFirst(list,input);
 }

 DoubleNode *beforeNode = list;
 DoubleNode *currentNode = list->next;
 DoubleNode *tmp = malloc(sizeof(DoubleNode));
 tmp->data = input;

 int j = 1;

 while((j < i) && (beforeNode->next != NULL)) {
  beforeNode = beforeNode->next;
  currentNode = currentNode->next;
  j++;
 }

 if (i == j) {
  beforeNode->next = tmp;
  tmp->next = currentNode;
  return list;
 }
 else {
  printf("Die Liste hat nur %i Eintraege.\n",j+1);
  return list;
 }
}


void readElement(int *input, char *descr) {

  *input = -1;
 while(*input < 0) {
  printf("%s",descr);
  scanf("%i",input);
 }
}


int main() {

int request = -1;
double input;

DoubleNode *Liste = NULL;

 puts("Dieses Programm verkettet Gleitkomma-Datenelemente. Jedes neue Element, welches hinzugefuegt wird, wird an den Kopf der Liste gehaengt.\n\nMithilfe von Zahlen waehlen Sie im folgenden Programm.\n");

//Liste erstellen?
 requestFunc(&request,"Moechten Sie eine Liste erstellen? [Ja|1] [Nein|0]: ");
 if(request == 0) {
 puts("Das Programm wird beendet");
 return 0;
 }

 // Elemente einfuegen
 requestFunc(&request,"\n\nDie Liste ist derzeit noch leer. \nMoechten Sie ein Datenelement einfuegen? [Ja|1] [Nein|0]: ");

 while(request != 0) {
  printf("\nGeben Sie das Datenelement ein: ");
  scanf("%lf",&input);
  Liste = insertFirst(Liste,input);
  requestFunc(&request,"Moechten Sie ein weiteres Datenelement einfuegen? [Ja|1] [Nein|0]: ");
 }

 //ausgeben?
 requestFunc(&request,"Moechten Sie die Liste ausgeben? [Ja|1] [Nein|0]: ");
 if(request == 1) printList(Liste);

 // bestimmtes Element ausgeben?
 requestFunc(&request,"Moechten Sie ein bestimmtes Element ausgeben? [Ja|1] [Nein|0]: ");
 if(request == 1) {
  readElement(&request,"Geben Sie die Nummer des Elementes ein(>=1): ");
  printf("%lf\n",get(Liste,request));
 }

 //ein Element wieder loeschen?
 requestFunc(&request,"Moechten Sie ein Listenelement wieder loeschen? [Ja|1] [Nein|0]: ");
 if(request == 1)
 {
  readElement(&request,"Welches Element soll geloescht werden(>=1)?: ");
  Liste = deleteElement(Liste,request);
  puts("Ein Element wurde geloescht. Die Liste hat die derartige Gestalt");
  printList(Liste);
 }

 //nachtraeglich Element einfuegen?
 requestFunc(&request,"Moechten Sie nachtraeglich ein Element an einer gewuenschten Stelle einfuegen? [Ja|1] [Nein|0]: ");
 if(request == 1) {
  readElement(&request,"Geben Sie die Position an dem das Datenelement eingefuegt werden soll: ");
  printf("Geben Sie den Wert an der eingfuegt werden soll: ");
  scanf("%lf",&input);
  Liste = insertElement(Liste,input,request);
 }

 puts("Die Liste sieht am Ende wie folgt aus:");
 printList(Liste);

 return 0;
}
