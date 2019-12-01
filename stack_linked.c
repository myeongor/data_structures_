#include <stdio.h>
#include <stdlib.h>
typedef int Element;
typedef struct tStacknode{
	Element data;
	struct tStacknode*next;
}StackNode;//stacknode 만들기

typedef struct{
	int count;
	StackNode*top;
}Stack;
//head Stack만들기
Stack*CreatStack(int size){
	Stack*pStack=(Stack*)malloc(size*sizeof(Stack));
	if(pStack==NULL){
	puts("동적할당이 제대로 되지 않았습니다.");
	return NULL;
	}
	pStack->count = 0;
	pStack->top=NULL;
	return pStack;
}
void Push(Stack*pStack,Element item)
{
	StackNode *pNewNode=(StackNode*)malloc(sizeof(StackNode));
	if(pNewNode==NULL){
	puts("동적할당이 제대로 되지 않았습니다.");
	return;
	}
	pNewNode->data=item;
	pNewNode->next=pStack->top;
	pStack->top=pNewNode;
	++pStack->count;
}
Element Pop(Stack*pStack)
{
	Element item=0;
	StackNode*pOldTop=pStack->top;

	if(pStack->top==NULL){
	puts("꺼낼 정보가 없습니다.");
	return 0;
	}

	else{
	item = pOldTop->data;
	pStack->top=pOldTop->next;
	pStack->count--;
	return item;
	}

}
void DestroyStack(Stack*pStack){
	if(pStack->count>0)
		free(pStack->top);
	free(pStack);
}
int main(){
	Stack*pStack=CreatStack(100);
	int i=0,item=0;

	for(i=0;i<3;i++){
		printf("push:");
		item=0;
		scanf("%d",&item);
		Push(pStack,item);
	}

	printf("pop:");
	for(i=0;i<3;i++){
		item=0;
		item=Pop(pStack);
		printf("%d ",item);
	}
	DestroyStack(pStack);
return 0;
}