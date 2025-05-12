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
	unsigned char cIsLeft;
	TREENODE* pstNew;
	TREENODE* pstParent;
	TREENODE* pstForcus;

	
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

		// �擾�����e�̎q�Ɋ��蓖�Ă�
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