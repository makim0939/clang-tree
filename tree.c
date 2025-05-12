#include  <stdlib.h>
#include "tree.h"


int makeTree(int iSize, int* paiArray);
typedef struct TREENODE {
	int iData;
	struct TREENODE* pstLeftChild;
	struct TREENODE* pstRightChild;
}TREENODE;

static TREENODE* pstRoot;

int iTree()
{
	int aiArray[9] = { 8, 3, 6, 7, 9, 1, 2, 5, 0 };

	makeTree(9, aiArray);

	return 0;
}
int makeTree(int iSize, int* paiArray)
{
	
	int iCount;		// 配列を数え上げる
	int iData;
	TREENODE* pstNew;
	TREENODE** ppstParentPtr;
	
	// 木構造の初期化
	pstRoot = NULL;
	
	// 配列の要素を木構造に割り当てる
	for (iCount = 0; iCount < iSize; iCount++)
	{
		// 新葉用のメモリを確保してデータを格納
		iData = *(paiArray + iCount);
		pstNew = malloc(sizeof(TREENODE));
		if (pstNew == NULL) 
		{
			return 1;
		}
		(*pstNew).iData = iData;
		(*pstNew).pstLeftChild = NULL;
		(*pstNew).pstRightChild = NULL;

		if (pstRoot == NULL)
		{
			pstRoot = pstNew;
			continue;
		}

		// 木構造をたどって、新葉の親を取得
		ppstParentPtr = &pstRoot;
		while (*ppstParentPtr != NULL)
		{
			if (iData < (**ppstParentPtr).iData)
			{
				ppstParentPtr = &(**ppstParentPtr).pstLeftChild;
			}
			else 
			{
				ppstParentPtr = &(**ppstParentPtr).pstRightChild;
			};
		}

		// 取得した親の子に割り当てる
		*ppstParentPtr = pstNew;
	}

	return 0;
}