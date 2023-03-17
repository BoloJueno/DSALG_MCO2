/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

typedef struct {
	int n;
	int nCount;
	sNode *pTop;
} stack;

stack* createStack(int n) 
{
	stack *s = (stack *) malloc(sizeof(stack));

	s->n = n;
	s->nCount = 0;
	s->pTop = NULL;

	return s;
}

int stackEmpty(stack *s) 
{
	if(!(s->pTop)) {
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
	// // (*s)->pTop++;
	// // printf("world\n");
	// sNode *temp = (*s)->pTop;
	// if ((*s)->nCount < (*s)->n) {//overflow checker
	// 	printf("%p", (*temp).data);
	// 	printf("world\n");
	// 	// strcpy((*temp)->data, data);
	// 	printf("world\n");
	// 	(*s)->pTop->pLink++;
	// 	(*s)->nCount++;
	// } else {
	// 	printf("Stack overflow encountered\n");
	// }

	if (!stackFull(*s)) {//overflow checker
			sNode *temp = (sNode *) malloc(sizeof(sNode));
			temp->data = data;
			temp->pLink = (*s)->pTop;
			(*s)->pTop = temp;
			(*s)->nCount++;
		} else {
			printf("Stack overflow encountered\n");
		}
	
}

char* pop(stack **s) 
{
	char *temp = (*s)->pTop->data;

	if ((*s)->nCount == 0) {//underflow checker
		(*s)->pTop->pLink--;
		(*s)->nCount--;
	} else {
		printf("Stack underflow encountered\n");
	}

	return temp;

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
			printf ("%c ", *(temp->data));
			temp = temp->pLink;
		}
		printf ("\n");
	}
}

char* top(stack *s) {
	return s->pTop->data;
}
