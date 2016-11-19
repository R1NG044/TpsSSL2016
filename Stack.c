#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


struct node{
int value;
struct node *next;
};


struct node *top;


void Push(int v){
	struct node *p;
	if(( p = malloc(sizeof *p) ) == NULL){
		perror("Sin memoria");
		exit(EXIT_FAILURE);
	}
	p->next = top;
	top = p;
	p->value = v;
}

int Pop(void){
	int value = top->value;
	struct node *p = top;
	top = top->next;
	free(p);
	return value;
}