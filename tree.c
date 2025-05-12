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
	unsigned char cIsLeft;
	TREENODE* pstNew;
	TREENODE* pstParent;
	TREENODE* pstForcus;

	
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
		pstForcus = pstRoot;
		pstParent = NULL;
		cIsLeft = 0;
		while (pstForcus != NULL)
		{
			pstParent = pstForcus;
			if (iData < (*pstForcus).iData)
			{
				pstForcus = (*pstForcus).pstLeftChild;
				cIsLeft = 1;
			}
			else 
			{
				pstForcus = (*pstForcus).pstRightChild;
				cIsLeft = 0;
			}
		}

		// 取得した親の子に割り当てる
		if (cIsLeft) 
		{
			(*pstParent).pstLeftChild = pstNew;
		}
		else 
		{
			(*pstParent).pstRightChild = pstNew;
		}
	}

	return 0;
}