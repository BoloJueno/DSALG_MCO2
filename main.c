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
	
	queue q = *(createQueue(10));
	queue* qPtr = &q;
	queue** ptrPtr = &qPtr;

	printf("helo\n");
	printf("%d", queueFull(&q));
	enqueue(ptrPtr, "1");
	printf("helo\n");
	printf("%d", queueEmpty(&q));
	
	return 0;
}

