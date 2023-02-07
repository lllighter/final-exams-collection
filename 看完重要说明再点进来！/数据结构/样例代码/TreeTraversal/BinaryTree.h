#ifndef __BINARYTREE__
#define __BINARYTREE__

typedef  struct  node  *treePointer ;
typedef  struct  node   {
        int            data ;
        treePointer   left_child, right_child ;
};
treePointer Create ();
void  inorder ( treePointer  ptr );
void  iter_inorder ( treePointer  node );
#endif