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
	
	int iCount;		// �z��𐔂��グ��
	int iData;
	TREENODE* pstNew;
	TREENODE** ppstParentPtr;
	
	// �؍\���̏�����
	pstRoot = NULL;
	
	// �z��̗v�f��؍\���Ɋ��蓖�Ă�
	for (iCount = 0; iCount < iSize; iCount++)
	{
		// �V�t�p�̃��������m�ۂ��ăf�[�^���i�[
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

		// �؍\�������ǂ��āA�V�t�̐e���擾
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

		// �擾�����e�̎q�Ɋ��蓖�Ă�
		*ppstParentPtr = pstNew;
	}

	return 0;
}