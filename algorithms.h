/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

void infixToPostfix(char *infix, char *postfix) {

	int i, j, x, stackSize = 0, tokOpLevel, topOpLevel, b;
	char tokensArr[200][200];
	char *token = strtok(infix, " ");
	stack *s;

	char operatorOrder[8][4][3] = {
		{"("},
		{"||"},
		{"&&"},
		{"==", "!="},
		{"<", "<=", ">", ">="},
		{"+", "-"},
		{"*", "/", "%"},
		{"!"}
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
			// printf("%s ", tokensArr[i]);
			// printf("%s ", );
			strcat(postfix, tokensArr[i]);
			strcat(postfix, " ");
		} else { //if operator
			if ((tokensArr[i][0] == '-') && (tokensArr[i][1] >= 48 && tokensArr[i][1] <= 57)) {
				//do nothing when token is a - and next token is an operator (negative numbers)
				// printf("%s ", tokensArr[i] + 1);
				strcat(postfix, tokensArr[i] + 1);
				strcat(postfix, " ");
			} else if (stackEmpty(s) || tokensArr[i][0] == '(' || *(top(s)) == '(') { 
				//stack is empty or operator is a ( or top is a (
				// printf("%s ", tokensArr[i]);
				push(&s, tokensArr[i]);
			} else if (strcmp(tokensArr[i], ")") == 0) {//if token is a )
				while (strcmp(top(s), "(") != 0) {
					// printf("%s ", pop(&s));
					strcat(postfix, pop(&s));
					strcat(postfix, " ");
				}

				pop(&s);//pops (
			} else {
				// printf("%s ", tokensArr[i]);
				b = 1;
				
				while (b) {//keeps looping until token is pushed
					for (j = 0; j < 8; j++) {
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
					// displayStack(s);

					if (tokOpLevel > topOpLevel) {
						push(&s, tokensArr[i]);
						b = 0;
					} else {
						// printf("%s ", pop(&s));
						strcat(postfix, pop(&s));
						strcat(postfix, " ");

						if (stackEmpty(s)) {
							push(&s, tokensArr[i]);
							b = 0;
						}
					}//if
				}//while
				
			} //if	
			
		} //if
	}//for

	while (!(stackEmpty(s))) {
		// printf("%s ", pop(&s));
		strcat(postfix, pop(&s));
		strcat(postfix, " ");
	}

	// printf("\nworld\n");
	// displayStack(s);

	for (i = 0; i < 200; i++) {
		strcpy(tokensArr[i], "\0");
	}

}

int evaluatePostfix(char *postfix) {
	
	stack *s;

	int i, stackSize;
	int op1, op2, ans;
	char buffer[200];
	char tokensArr[200][200];
	char *token = strtok(postfix, " ");

	for (i = 0; token != NULL; i++) {
		
		strcpy(tokensArr[i], token);

		if (isdigit(*token)) {
			stackSize++;
		}

		token = strtok(NULL, " ");
	}

	s = createStack(stackSize);

	for (i = 0; strcmp(tokensArr[i], "\0") != 0; i++)
	{
		// printf("start");
		// displayStack(s);
		// strcpy(buffer, "\0");	
		
		if (tokensArr[i][0] >= 48 && tokensArr[i][0] <= 57) {	
			push(&s, tokensArr[i]);
		} else { 
			if (strcmp(tokensArr[i], "!") == 0) {
				op2 = atoi(pop(&s));
			} else {
				// displayStack(s);
				op2 = atoi(pop(&s));
				op1 = atoi(pop(&s));
				// displayStack(s);
			}			

			if (strcmp(tokensArr[i], "+") == 0) {//arithmetic operators
				ans = op1 + op2;
			} else if (strcmp(tokensArr[i], "-") == 0) {
				ans = op1 - op2;
			} else if (strcmp(tokensArr[i], "*") == 0) {
				ans = op1 * op2;
			} else if (strcmp(tokensArr[i], "/") == 0) {
				if (op2 != 0) {//division by 0
					ans = op1 / op2;
				} else {
					strcpy(postfix, "Division by zero error!");
					return 0;
				}				
			} else if (strcmp(tokensArr[i], "%") == 0) {
				ans = op1 % op2;
			} else if (strcmp(tokensArr[i], "!") == 0) {//not operator
				ans = !op2;
				// printf("!%d = %d\n", op2, ans);
			} else if (strcmp(tokensArr[i], "<") == 0) {//relational operators
				ans = op1 < op2;
			} else if (strcmp(tokensArr[i], "<=") == 0) {
				ans = op1 <= op2;
			} else if (strcmp(tokensArr[i], ">") == 0) {
				ans = op1 > op2;
			} else if (strcmp(tokensArr[i], ">=") == 0) {
				ans = op1 >= op2;
			} else if (strcmp(tokensArr[i], "==") == 0) {
				ans = op1 == op2;
			} else if (strcmp(tokensArr[i], "!=") == 0) {
				ans = op1 != op2;
			} else if (strcmp(tokensArr[i], "&&") == 0) {//logical operators
				ans = op1 && op2;
			} else if (strcmp(tokensArr[i], "||") == 0) {
				ans = op1 || op2;
			}

			itoa(ans, buffer, 10);
			push(&s, buffer);

		}//if else
	}//for

	strcpy(postfix, pop(&s));

	for (i = 0; i < 200; i++) {
		strcpy(tokensArr[i], "\0");
	}

	return 1;
}
