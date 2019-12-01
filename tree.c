#include "Tree.h"
//Depth-first traversal
void Preorder(TreeNode *node) {
	if (node == NULL) return;

	printf("%c", node->data);
	Preorder(node->left);
	Preorder(node->right);
}

void Inorder(TreeNode *node) {
	if (node == NULL) return;

	Inorder(node->left);
	printf("%c", node->data);
	Inorder(node->right);
}

void Postorder(TreeNode *node) {
	if (node == NULL) return;

	Postorder(node->left);
	Postorder(node->right);
	printf("%c", node->data);
}

//breadth-first traversal
typedef struct tQueueNode{
	TreeNode*tNode;
	struct tQueueNode* next;

}QueueNode;
typedef struct {
	int count;
	QueueNode *front;
	QueueNode *rear;
}Queue;

Queue *CreateQueue() {
	Queue *pQueue = (Queue *)malloc(sizeof(Queue));
	if (pQueue == NULL) 
		return NULL;

	pQueue->count = 0;
	pQueue->front = pQueue->rear = NULL;

	return pQueue;
}

void Enqueue(Queue *pQueue, TreeNode*tnode) {
	
	QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
	if (node == NULL) return;
	
	node->tNode=tnode;
	node->next = NULL;

	if (pQueue->count<=0){
		pQueue->front = pQueue->rear = node;
	}
	else {
		pQueue->rear->next = node;
		pQueue->rear = node;
	}
	pQueue->count++;
}

TreeNode*Dequeue(Queue*pQueue)
{
	QueueNode*pFront=NULL;
	TreeNode*tnode;
	if(pQueue->count<=0){
		puts("Queue is empty");
		return ; 
	}
	pFront=pQueue->front;
	tnode=pFront->tNode;
	
	if(pQueue->count==1){
		pQueue->front=pQueue->rear=NULL;
	}
	else{
		pQueue->front=pFront->next;
	}
	free(pFront);
	pQueue->count--;

	return tnode;
}

void LevelOrder(TreeNode*node){
	Queue*q=CreateQueue();
	if(IsEmpty(node))
		return;
	while(node){
		printf("%c",node->data);
		if(node->left)
			Enqueue(q,node->left);
		if(node->right)
			Enqueue(q,node->right);
		if(q->count>0)
			node = Dequeue(q);
		else
			node=NULL;
	}

}
//complete_binary_tree
TreeNode *Insert(TreeNode *root, TreeNode *NewNode) {
	if (root == NULL) return NewNode;

	if (root->left == NULL && root->right == NULL) {
		 root->left = Insert(root->left, NewNode);
		return root;
	}
	else if (root->left != NULL && root->right != NULL) {
		if(root->left->left==NULL||root->left->right==NULL){
			root->left = Insert(root->left, NewNode);
			return root;
		}
		else{
			root->right = Insert(root->right, NewNode);
			return root;
		}
	}
	else if (root->left != NULL && root->right == NULL) {
		root->right = Insert(root->right, NewNode);
		return root;
	}


}

int main(){

	char str[100]="";
	int i=0;
	char tmp=NULL;
	TreeNode*root=NULL;
	TreeNode*node[100];
	printf("문자열을 입력하세요 : ");
	scanf("%s",&str);

	while(strlen(str)>i){
		tmp=str[i];
		node[i]=CreateTree(NULL,tmp,NULL);
		root=Insert(root,node[i]);
		i++;
	}

	printf("Breath First Traversal : \n");
	puts("");
	LevelOrder(root);
	puts("");
	puts("");
	printf("Depth First Traversal : \n");
	puts("");
	printf("*preorder \n");
	Preorder(root);
	puts("");
	puts("");
	printf("*Inorder \n");
	Inorder(root);
	puts("");
	puts("");
	printf("*Postorder \n");
	Postorder(root);
	puts("");

	return 0;
}