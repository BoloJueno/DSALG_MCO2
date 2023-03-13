/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include "node.h"

typedef struct {
	int n;
	int nCount;
	sNode *pHead;
	sNode *pTail;
} queue;

queue* createQueue(int n) {
	queue *createdQueue;

	createdQueue->n = n;

	return createdQueue;
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
	// Your code here
}

char* dequeue(queue **q) {
    // Your code here
}

void displayQueue(queue *q) {
	// Your code here
}

char* head(queue *q) {
	// Your code here
}

char* tail(queue *q) {
	// Your code here
}


