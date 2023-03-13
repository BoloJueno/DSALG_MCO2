/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include <stdio.h>
#include "node.h"

typedef struct {
	int n;
	int nCount;
	sNode *pHead;
	sNode *pTail;
} queue;

queue* createQueue(int n) {
	queue *q;

	q->n = n;
	q->nCount = 0;

	return q;
}

int queueEmpty(queue *q) {

	// // if (!(q -> pHead) && !(q -> pTail)) {
	// // if (q -> pHead == 0 && q -> pHead == 0) {
	// 	return 1;
	// } else {
	// 	return 0;
	// }

	if (q->pHead || q->pTail) {
		return 0;
	} else {
		return 1;
	}
	
}

int queueFull(queue *q) {
	
	return q->nCount == q->n - 1;

}

void enqueue(queue **q, char *data) {
	
	if (!((*q)->pHead)) {
		(*q)->pHead->data = data;
		(*q)->pHead->pLink = (*q)->pHead->pLink + 1;
	}

	(*q)->pTail->data = data;
	(*q)->pTail->pLink = (*q)->pTail->pLink + 1;

	(*q)->nCount++;

}

char* dequeue(queue **q) {
    (*q)->pHead->data = (*q)->pHead->data + 1;
	(*q)->pHead->pLink = (*q)->pHead->pLink + 1;

	(*q)->nCount--;
}

void displayQueue(queue *q) {
	int i;
	sNode* temp;

	if (q->pHead == q->pTail)
	{
		printf ("Queue is empty\n");
	}
	else
	{
		temp = q->pHead;
		for (i = 0; i < q->nCount; i++)
		{
			printf ("%c\n", temp->data);
			temp = temp->pLink;
		}
	}

}

char* head(queue *q) {
	return q->pHead->data;
}

char* tail(queue *q) {
	return q->pTail->data
}


