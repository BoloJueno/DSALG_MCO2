/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

#include <stdio.h>
#include <string.h>
#include "node.h"
#include "queue.h"
#include "stack.h"
// #include "algorithms.h"

int main() {

	char string[10] = "hi";
	
	// queue q = *(createQueue(10));
	// queue* qPtr = &q;
	// queue** qPtrPtr = &qPtr;

	stack s = *(createStack(10));
	stack* sPtr = &s;
	stack** sPtrPtr = &sPtr;

	printf("helo\n");
	// printf("%d", queueFull(&q));
	// enqueue(qPtrPtr, "1");
	// printf("helo\n");
	// printf("%d", queueEmpty(&q));

	printf("%d", stackFull(sPtr));
	push(sPtrPtr, string);
	printf("helo\n");
	
	return 0;
}

