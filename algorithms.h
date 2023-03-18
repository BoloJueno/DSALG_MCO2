/*****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
*****************************************************/

void infixToPostfix(char *infix, char *postfix) {

	int i, j, x, stackSize = 0, tokOpLevel, topOpLevel, b = 1;
	char tokensArr[100][10];
	char *token = strtok(infix, " ");
	stack *s = (stack *) malloc(sizeof(stack));

	char operatorOrder[6][4][3] = {
		{"*", "/", "%"},
		{"+", "-"},
		{"<", "<=", ">", ">="},
		{"==", "!="},
		{"&&"},
		{"||"},
	};
	
	for (i = 0; token != NULL; i++) {
		strcpy(tokensArr[i], token);

	while (!(stackEmpty(s))) {
		printf("%s ", pop(&s));
	}
}

int evaluatePostfix(char *postfix) {
	
	return 0;

}
