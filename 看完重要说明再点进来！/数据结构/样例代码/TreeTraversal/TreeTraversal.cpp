#include "BinaryTree.h"
#include <stdio.h>

void main()
{
	treePointer pt = Create();
	inorder(pt);
	printf("the iterative inorder version:");
	iter_inorder (pt);
}
