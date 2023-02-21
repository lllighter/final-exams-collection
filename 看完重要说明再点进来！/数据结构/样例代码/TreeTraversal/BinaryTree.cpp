#include "BinaryTree.h"
#include "arrayStack.h"
#include <stdio.h>
#include <stdlib.h>
treePointer Create ()
{
     treePointer bt;
     char ch;
     scanf("%c",&ch);
     if (ch == '#') bt = NULL;
     else {
	     bt = (treePointer)malloc(sizeof(struct  node));
	     bt->data= ch;                   //create root
	     bt->left_child = Create();         //create left subtree of root
	     bt->right_child = Create();       //create right subtree of root
     }
     return bt;
}//Create

void  inorder ( treePointer  ptr )
{  if  ( ptr )   {
        inorder ( ptr->left_child );
        printf ( "%c", ptr->data );
        inorder ( ptr->right_child );
   }
}

void  iter_inorder ( treePointer  node )
{ 
	stack s = Create(100);
  for ( ; ; )  {
     for ( ; node; node = node->left_child )
        Push ( &s, node ) ;
     node = Pop ( &s );
     if ( !node )  break;
     printf ( "%c", node->data );
     node = node->right_child;   
  }
}


