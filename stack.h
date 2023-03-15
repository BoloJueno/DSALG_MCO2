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

	s.n = n;
	s.nCount = 0;

	return s;
}

int stackEmpty(stack *s) 
{
	if(pTop == 0)
		return 1;
	else
		return 0;
}

int stackFull(stack *s) 
{
	if(pTop == n)
		return 1;
	else
		return 0;
}
void push(stack **s, char *data) {
	*s.data = data;
	*s.nCount.pLink++;
	*s.nCount++;
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
