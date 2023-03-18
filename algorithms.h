/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

void infixToPostfix(char *infix, char *postfix) {

	int i, j, x, stackSize = 0, tokOpLevel, topOpLevel, b;
	char tokensArr[100][10];
	char *token = strtok(infix, " ");
	stack *s = (stack *) malloc(sizeof(stack));

	char operatorOrder[6][4][3] = {
		{"||"},
		{"&&"},
		{"==", "!="},
		{"<", "<=", ">", ">="},
		{"+", "-"},
		{"*", "/", "%"}
	};
	
	for (i = 0; token != NULL; i++) {
		strcpy(tokensArr[i], token);

		if (!(*token >= 48 && *token <= 57)) {
			stackSize++;
		}
		token = strtok(NULL, " ");
	}

	s = createStack(stackSize);

	for(i = 0; strcmp(tokensArr[i], "\0") != 0; i++) {
		if (tokensArr[i][0] >= 48 && tokensArr[i][0] <= 57) { //if token is operand
			printf("%s ", tokensArr[i]);
		} else { //if operator
			if (stackEmpty(s) || tokensArr[i][0] == '(' || *(top(s)) == '(') { 
				//stack is empty or operator is a ( or top is a (
				push(&s, tokensArr[i]);
			} else {
				b = 1;
				
				while (b) {//keeps looping until token is pushed
					for (j = 0; j < 6; j++) {
						for (x = 0; x < 4; x++) {
							//gets level of precedence of token
							if (strcmp(tokensArr[i], operatorOrder[j][x]) == 0) {
								tokOpLevel = j;
							}

							//gets level of precedence of top
							if (strcmp(top(s), operatorOrder[j][x]) == 0) {
								topOpLevel = j;
							}
						}//for
					}//for

					// printf("\n\ntoken: %s - %d\n", tokensArr[i], tokOpLevel);
					// printf("top: %s - %d\n\n", top(s), topOpLevel);

					if (tokOpLevel > topOpLevel) {
						push(&s, tokensArr[i]);
						b = 0;
					} else {
						printf("%s ", pop(&s));
						
					}//if
				}//while
				
			} //if	
			
		} //if
	}//for

	while (!(stackEmpty(s))) {
		printf("%s ", pop(&s));
	}

	printf("\n\n");

}

int evaluatePostfix(char *postfix) {
	
	return 0;

}
