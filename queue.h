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

	createdQueue -> n = n;

	return createdQueue;
}

int queueEmpty(queue *q) {
	// Your code here
}

int queueFull(queue *q) {
	// Your code here
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


