#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Element;
#define false 0
#define true  1
#define bool int
typedef struct tTreeNode{
	Element data;
	struct tTreeNode *left,*right;
}TreeNode;

TreeNode*CreateTree(TreeNode*left,Element item,TreeNode*right){

	TreeNode*pNewNode=(TreeNode*)malloc(sizeof(TreeNode));
	char temp[100];
	if(pNewNode==NULL)
		return NULL;
	pNewNode->data=item;
	pNewNode->left=left;
	pNewNode->right=right;

	return pNewNode;
}
bool IsEmpty(TreeNode*node){
	if(!node)
		return true;
	else 
		return false;
}
TreeNode*LeftTree(TreeNode*node){
	if(IsEmpty(node->left))
		return NULL;
	else return node->left;
}
TreeNode*RightTree(TreeNode*node){
	if(IsEmpty(node->right))
		return NULL;
	else return node->right;
}
Element TreeData(TreeNode*node){
	if(IsEmpty(node))
		return NULL;
	else node->data;
}
void DestroyTree(TreeNode*root){
	if(root==NULL)
		return;
	if(root->left)
		DestroyTree(root->left);
	if(root->right)
		DestroyTree(root->right);
	free(root);
}