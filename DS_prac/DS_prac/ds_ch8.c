#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "ExpressionTree.h"

int ds_ch8_c(void) {
	//BTmain();
	//expMain();
	return 0;
}

void ShowIntData(int data) {
	printf("%d \n", data);
}

int BTmain(void) {
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode * bt5 = MakeBTreeNode();
	BTreeNode * bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	//DeleteTree(bt1);
	//InorderTraverse(bt1, ShowIntData);

	return 0;
}

int expMain(void) {
	
	char exp[] = "327*+";
	BTreeNode * eTree = MakeExpTree(exp);

	ShowPrefixTypeExp(eTree); printf("\n");
	ShowInfixTypeExp(eTree); printf("\n");
	ShowPostfixTypeExp(eTree); printf("\n");
	printf("%d ", EvaluateExpTree(eTree));


	return 0;
}







