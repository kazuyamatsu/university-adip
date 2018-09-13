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

void requestFunc(int *request, char *desc) {
 *request = -1;
 while( !(*request == 0) && !(*request == 1) ) {
  printf("%s",desc);
  scanf("%i",request);
 }

}
int main() {

int request = -1;
double input;
DoubleNode *Liste;

 puts("Dieses Programm verkettet Gleitkomma-Datenelemente. Jedes neue Element, welches hinzugefuegt wird, wird an den Kopf der Liste gehaengt.\n\nMithilfe von Zahlen waehlen Sie im folgenden Programm.\n");
 requestFunc(&request,"Moechten Sie eine Liste erstellen? [Ja|1] [Nein|0]: ");
 if(request == 0) {
 puts("Das Programm wird beendet");
 return 0;
 }

 requestFunc(&request,"\n\nDie Liste ist derzeit noch leer. \nMoechten Sie ein Datenelement einfuegen? [Ja|1] [Nein|0]: ");

 while(request != 0) {
  printf("\nGeben Sie das Datenelement ein: ");
  scanf("%lf",&input);
  Liste = insertFirst(Liste,input);
  requestFunc(&request,"Die Liste ist derzeit noch leer. \nMoechten Sie ein Datenelatenelement einfuegen? [Ja|1] [Nein|0]: ");
 }

 requestFunc(&request,"Moechten Sie die Liste ausgeben? [Ja|1] [Nein|0]: ");

 if(request == 1) printList(Liste);

 return 0;
}
