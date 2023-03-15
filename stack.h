/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include "node.h"
#include <stdio.h>

typedef struct {
	int n;
	int nCount;
	sNode *pTop;
} stack;

stack* createStack(int n) {
	// Your code here
}

int stackEmpty(stack *s) {
	// Your code here
}

int stackFull(stack *s) {
	// Your code here
}

void push(stack **s, char *data) {
	// Your code here
}

char* pop(stack **s) {
	// Your code here
}

void displayStack(stack *s) {

	int i;
	sNode* temp;

	if (s->nCount == 0)
	{
		printf ("Stack is empty\n");
	}
	else
	{
		temp = s->pTop;
		printf ("Stack: ");

		for (i = 0; i < s->nCount; i++)
		{
			printf ("%c ", temp->data);
			temp = temp->pLink;
		}
		printf ("\n");
	}
}

char* top(stack *s) {
	return s->pTop->data;
}
