#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *next;
  double data;
 } DoubleNode;


DoubleNode *insertFirst(DoubleNode *head, double c) {

DoubleNode *tmp = malloc(sizeof(DoubleNode));

 if (head == NULL) {
  tmp->data = c;
  tmp->next = NULL;
  return tmp;
 }

 (*tmp).next = head;
 (*tmp).data = c;
 return tmp;
}

void printList(DoubleNode *head) {

 if(head == NULL) puts("Die Liste ist leer.");

 DoubleNode *tmp = head;
 int i = 1;
 while(tmp != NULL) {
  printf("Listenelement %i: %lf \n",i++,tmp->data);
  tmp = tmp->next;
 }
 puts("");
}

void request(int *request, char *desc) {

 while( !(*request == 0) && !(*request == 1) ) {
  printf("%s",desc);
  scanf("%i",request);
 }

}
int main() {

int request = -1;
double input;

 puts("Dieses Programm verkettet Gleitkomma Datenelemente. Jedes neue Element, welches hinzugefuegt wird, wird am Kopf der Liste gehaengt.\n Mithilfe von Zahlen waehlen Sie im folgenden Programm.");
 request(&request,"Moechten Sie eine Liste erstellen? [Ja|1] [Nein|0]: ");
 if(request == 0) {
 puts("Das Programm wird beendet"); 
 return 0;
 }

  request(&request,"Die Liste ist derzeit noch leer. Moechten Sie ein Datenelement einfuegen? [Ja|1] [Nein|0]: ");

 while(request != 0) {
  printf("\nGeben Sie das Datenelement ein: ");
  scanf("%lf",input);
  Liste = insertFirst(Liste,input);
  request(&request,"Die Liste ist derzeit noch leer. Moechten Sie ein Datenelatenelement einfuegen? [Ja|1] [Nein|0]: ");
 }

 request(&request,"Moechten Sie die Liste ausgeben? [Ja|1] [Nein|0]: ");

 if(request == 1) printList(Liste);
 free(Liste);

 return 0;
}
