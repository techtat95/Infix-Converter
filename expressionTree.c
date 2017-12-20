#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"
#include "scanner.h"

#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) {
	Token y = nextToken(s);
	if(y.type == T_EOF)
	{
	return NULL;
	}
	if(y.type == T_VAL)
	{
	return buildTreeNode(y);
	}
	if(y.type == T_LPAREN)
	{
	TreeNode * left = buildExpressionTree(s);
	y = nextToken(s);
	TreeNode * right = buildExpressionTree(s);
	TreeNode * parent = buildTreeNode(y);
	parent -> right = right;
	parent -> left = left;
	y = nextToken(s);
	return parent;
	}
	return NULL;
}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {
	if(t == NULL)
	{
	return;
	}
	makePostFix(t->left, fptr);
	makePostFix(t->right, fptr);
	
	if(t->t.type == T_VAL)
	{
	fprintf(fptr, "%f ", t->t.value);
	}
	else{
	fprintf(fptr, "%c ", t->t.type);
	}
	return;
}

#endif
