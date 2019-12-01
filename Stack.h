#include <stdio.h>
#include <stdlib.h>

typedef int Element;//자료형 바꾸고 싶을 때 사용
//stack 구조체 생성
typedef struct
{
	Element*stack;//int형 stack 생성
	int size;
	int top;
}Stack;
//CreatStack
Stack*CreatStack(int size)
{
	Stack*pStack=(Stack*)malloc(sizeof(Stack));//stack 구조체 크기만큼 할당
	if(pStack==NULL)
	{
		puts("stack이 생성되지 않았습니다.");
	return NULL;
	}
	pStack->stack=(Element*)malloc(size*sizeof(Element));
	if(pStack->stack == NULL)
	{
		free(pStack);
		return NULL;
	}//stack 비어있으면 공간 반납
	
	pStack -> size = size;
	pStack -> top = -1;
	//stack에 정보 입력

	return pStack;
}
void Push(Stack*pStack,Element item)
{
	if(pStack->top==pStack->size-1)
	{
	puts("공간이 없습니다.");
	return;
	} //stack에 공간 있는지 check

	pStack->stack[++pStack->top]=item; //있으면 item넣기


}
Element Pop(Stack*pStack)
{
	if(pStack->top<0)
	{
	puts("꺼낼item이 없습니다.");
	return;
	}

	return pStack->stack[pStack->top--];

}
Element Top(Stack*pStack)
{
	if(pStack->top<0)
	{
	puts("top이 없습니다.");
	return 0;
	}
	return pStack->stack[pStack->top];
}
void DestroyStack(Stack*pStack)
{
	if(pStack->size>0){
		free(pStack->stack);

	free(pStack);
	}
}