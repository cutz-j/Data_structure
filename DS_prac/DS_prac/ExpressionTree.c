#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListBaseStack.h"
#include "ExpressionTree.h"

BTreeNode * MakeExpTree(char exp[]) {
	Stack_lb stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);

	StackInit_lb(&stack);
	for (int i = 0; i < expLen; i++) {
		pnode = MakeBTreeNode();
		if (isdigit(exp[i])) {
			SetData(pnode, exp[i] - '0');
		}
		else {
			MakeRightSubTree(pnode, SPop_lb(&stack));
			MakeLeftSubTree(pnode, SPop_lb(&stack));
			SetData(pnode, exp[i]);
		}
		SPush_lb(&stack, pnode);
	}
	return SPop_lb(&stack);
}

void ShowNodeData(int data) {
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt) {
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt) {
	if (bt == NULL)
		return;
	if (bt->left != NULL || bt->right != NULL)
		printf("(");
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);
	if (bt->left != NULL || bt->right != NULL)
		printf(")");

}

void ShowPostfixTypeExp(BTreeNode * bt) {
	PostorderTraverse(bt, ShowNodeData);
}

int EvaluateExpTree(BTreeNode * bt) {
	int op1, op2;
	if (GetLeftSubTree(bt) == NULL || GetRightSubTree(bt) == NULL)
		return GetData(bt);
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
	return 0;
}