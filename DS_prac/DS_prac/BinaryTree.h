#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;
typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void); // 생성
BTData GetData(BTreeNode * bt); // data 추출
void SetData(BTreeNode * bt, BTData data); // data 삽입
BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data);
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void DeleteTree(BTreeNode * bt);

#endif