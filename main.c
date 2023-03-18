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

	fgets(infix, 100, stdin);

	while (strcmp(infix, "QUIT") != 0) {
		infixToPostfix(infix, postfix);

		fgets(infix, 100, stdin);
	}
	
	return 0;
}

