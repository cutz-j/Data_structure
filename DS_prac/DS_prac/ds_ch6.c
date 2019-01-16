#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InFixToPostfix.h"

int main(void) {
	//q6_1_1();
	q6_1_3();
	
	return 0;
}

//int q6_1_1(void) {
//	Stack_c Stack;
//	StackInit_c(&Stack);
//	for (int i = 1; i < 6; i++) {
//		SPush_c(&Stack, i);
//	}
//	while (!SIsEmpty_c(&Stack))
//		printf("%d ", SPop_c(&Stack));
//	return 0;
//}

int getOpPrec(char op) {
	switch (op) {
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = getOpPrec(op1);
	int op2Prec = getOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}
void ConvToRPNExp(char exp[]) {
	Stack_lb stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popop;

	memset(convExp, 0, sizeof(char)*expLen + 1);
	StackInit_lb(&stack);
	for (i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			convExp[idx++] = tok;
		}
		else {
			switch (tok) {
			case '(':
				SPush_lb(&stack, tok);
				break;
			case ')':
				while (1) {
					popop = SPop_lb(&stack);
					if (popop == '(')
						break;
					convExp[idx++] = popop;
				}
				break;
			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty_lb(&stack) && WhoPrecOp(SPeek_lb(&stack), tok) >= 0)
					convExp[idx++] = SPop_lb(&stack);
				SPush_lb(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty_lb(&stack))
		convExp[idx++] = SPop_lb(&stack);
	strcpy(exp, convExp);
	free(convExp);
}

int EvalRPNExp(char exp[]) {
	Stack_lb stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit_lb(&stack);
	for (i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			SPush_lb(&stack, tok-'0');
		}
		else {
			op2 = SPop_lb(&stack);
			op1 = SPop_lb(&stack);
			
			switch(tok) {
			case '+':
				SPush_lb(&stack, op1 + op2);
				break;
			case '-':
				SPush_lb(&stack, op1 - op2);
				break;
			case '*':
				SPush_lb(&stack, op1 * op2);
				break;
			case '/':
				SPush_lb(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop_lb(&stack);
}

q6_1_3(void) {
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s = %d \n", exp1, EvalRPNExp(exp1));
	printf("%s = %d \n", exp2, EvalRPNExp(exp2));
	printf("%s = %d \n", exp3, EvalRPNExp(exp3));
	return 0;
}

