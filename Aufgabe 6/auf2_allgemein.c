#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *next;
  double <T>;
 } <Node>;



<T> get(<Node> *list, int i) {

 int j;
 <Node> *pointer = list;

 for(j = 0; j < i; j++) {
  pointer = pointer->next;
  if(pointer == NULL) break;
 }
 if(i>j) {
  printf("Die Liste ist nur %i Eintraege lang. Eine <T> wird zurueckgegben.\n",j+1);
  return <T>;
 }
 else return pointer->data;

}



<Node>* deleteElement(<Node> *list,int i) {

 int j;
 <Node> *beforeNode;
 <Node> *NextNode;
 <Node> *currentNode;

 if(list == NULL) {
  return NULL;
 }

 if(i == 0) {
  list = list->next;
  return list;
 }


 beforeNode = list;
 currentNode = list->next;
 j = 1;
 while((j < i) && (currentNode->next != NULL)) {
  beforeNode = beforeNode->next;
  currentNode = currentNode->next;
  j++;
 }

 if( i == j ) {
  beforeNode->next = currentNode->next;
  free(currentNode);
 }
 else printf("Die Liste ist nur %i Eintraege lang.",j+1);

 return list;
}




<Node> *insertElement(<Node> *list, <T> input, int i) {

 if(i == 0) {
  return insertFirst(list,input);
 }

 <Node> *beforeNode = list;
 <Node> *currentNode = list->next;
 <Node> *tmp = malloc(sizeof(<Node>));
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

int main() {

}
