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
	// sNode *temp = (*s)->pTop;
	// char *tempString = temp->data;

	if (!stackEmpty(*s)) {//underflow checker

		sNode *temp = (*s)->pTop;
		char *tempString = temp->data;
		(*s)->pTop = temp->pLink;
		(*s)->nCount--;

		return tempString;

	} else {
		printf("Stack underflow encountered\n");
		
		return NULL;
	}

	// return tempString;

}

void displayStack(stack *s) {

	int i;
	sNode* temp;

	if (stackEmpty(s))
	{
		printf ("\nStack is empty\n");
	}
	else
	{
		temp = s->pTop;
		printf ("\nStack: ");

		for (i = 0; i < s->nCount; i++)
		{
			printf ("%s ", temp->data);
			temp = temp->pLink;
		}
		printf ("\n");
	}
}

char* top(stack *s) {
	return s->pTop->data;
}
