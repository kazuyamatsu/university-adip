#include <stdio.h>
#include <stdlib.h>

typedef struct doublenode {double data; struct doublenode *next;} doublenode ;

doublenode *insertfirst (doublenode *head , double c){
	doublenode *tmp;
	tmp= malloc (sizeof (doublenode));
	tmp->data = c;
	tmp->next = head;
	return tmp;
	
}


void printnode (doublenode *head
{
	doublenode *cursor= head;
	while (cursor->next != NULL){
		printf ("(%f)\n", cursor->data);
		cursor = cursor->next;
	}
}

doublenode *insertLast(doublenode *head, double d) //am Ende einfügen
{
	doublenode *tmp, *cursor;
	if (head==NULL)
		insertFirst(head,d);
	else
	{
		cursor=head;
		while (cursor->next != NULL){cursor =cursor->next;}
		tmp= malloc(sizeof(doublenode));
		tmp->data = d;
		tmp->next = NULL;
		cursor->next=tmp;
	}
}

IntNode *reverseListCon(doublenode *head) //konstruktives einfuegen
{
	doublenode *nh, *tmp, *cell, *ret;
	cell=head;
	while (cell != NULL)
	{
		tmp= malloc(sizeof(IntNode));
		tmp->data=cell->data;
		tmp->next=nh;
		nh=tmp;
		cell=cell->next;
	}
	ret=nh;
	return ret;
}

doublenode *reverseDoubleList(doublenode *head) //destruktives einfuegen
{
	doublenode *revChain, *chain, *cell;
	cell=head;
	revChain=NULL;
	while (cell != NULL)
	{
		chain=cell->next;
		cell->next=revChain;
		revChain=cell;
		cell=chain;
	}
	head=revChain;
}


int main () {
puts("L1 und L2 sind dieselbe Liste, welche sich nur einmal im Speicher befindet,\n"); 
puts("aber alle Eintraege beherbegt, die entweder L2 oder L2 hinzugefuegt wurden.\n");
	doublenode *head;
	head= malloc (3*sizeof(doublenode));
	printnode (head);
	head= insertfirst (head , 2.1);
	head = insertfirst (head, 3.3);
	head= insertfirst (head, 4.4);
	printnode (head);
	
	return 0;
}
	
