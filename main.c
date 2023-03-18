/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "queue.h"
#include "stack.h"
#include "algorithms.h"

int main() {

	char infix[100], postfix[100];

	// stack s = *(createStack(2));
	// stack* sPtr = &s;
	// stack** sPtrPtr = &sPtr;

	scanf("%s", infix);

	while (strcmp(infix, "QUIT\n") != 0) {
		infixToPostfix(infix, postfix);
	}
	
	return 0;
}

