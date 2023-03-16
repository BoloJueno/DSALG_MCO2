/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

#include <stdio.h>
#include "node.h"
#include "queue.h"
#include "stack.h"
// #include "algorithms.h"

int main() {
	
	queue q = *(createQueue(10));

	printf("helo\n");
	printf("%d", queueEmpty(&q));
	
	return 0;
}

