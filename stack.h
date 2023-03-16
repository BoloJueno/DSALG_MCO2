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

stack* createStack(int n) 
{
	stack *s;

	s->n = n;
	s->nCount = 0;

	return s;
}

int stackEmpty(stack *s) 
{
	if(s->pTop == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int stackFull(stack *s) 
{
	if(s->nCount == s->n) {
		return 1;
	} else {
		return 0;
	}
}

void push(stack **s, char *data) 
{
	(*s)->pTop->data = data;
	(*s)->pTop->pLink++;
	(*s)->nCount++;
}

char* pop(stack **s) 
{
	*s.nCount.pLink--;
	*s.nCount--;
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
