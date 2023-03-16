/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

typedef struct {
	int n;
	int nCount;
	sNode *pHead;
	sNode *pTail;
} queue;

queue* createQueue(int n) {
	queue temp;

	temp.n = n;
	temp.nCount = 0;

	queue *q = &temp;

	return q;
}

int queueEmpty(queue *q) {

	if (q->pHead || q->pTail) {
		return 1;
	} else {
		return 0;
	}
	
}

int queueFull(queue *q) {
	
	return q->nCount == q->n - 1;

}

void enqueue(queue **q, char *data) {
	
	if (queueFull(*q) == 1) {//checks overflow
		if ((*q)->nCount == 0) {//if queue is empty
			(*q)->pHead->data = data;
			(*q)->pHead->pLink = (*q)->pHead->pLink + 1;
		} else {
			(*q)->pTail->data = data;
			(*q)->pTail->pLink = (*q)->pTail->pLink + 1;

			(*q)->nCount++;
		}
	} else {
		printf("Queue overflow encountered\n");
	}

}

char* dequeue(queue **q) {

	char *temp = (*q)->pHead->data;

	if (queueEmpty(*q) == 1) {//underflow checker
		(*q)->pHead->data = (*q)->pHead->data + 1;
		(*q)->pHead->pLink = (*q)->pHead->pLink + 1;

		(*q)->nCount--;
	} else {
		printf("Queue underflow encountered\n");
	}

	return temp;
    
}

void displayQueue(queue *q) {
	int i;
	sNode* temp;

	if (q->nCount == 0)
	{
		printf ("Queue is empty\n");
	}
	else
	{
		temp = q->pHead;
		for (i = 0; i < q->nCount; i++)
		{
			printf ("%c\n", *(temp->data));
			temp = temp->pLink;
		}
	}

}

char* head(queue *q) {
	return q->pHead->data;
}

char* tail(queue *q) {
	return q->pTail->data;
}


