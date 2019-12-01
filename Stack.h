#include <stdio.h>
#include <stdlib.h>

typedef int Element;//�ڷ��� �ٲٰ� ���� �� ���
//stack ����ü ����
typedef struct
{
	Element*stack;//int�� stack ����
	int size;
	int top;
}Stack;
//CreatStack
Stack*CreatStack(int size)
{
	Stack*pStack=(Stack*)malloc(sizeof(Stack));//stack ����ü ũ�⸸ŭ �Ҵ�
	if(pStack==NULL)
	{
		puts("stack�� �������� �ʾҽ��ϴ�.");
	return NULL;
	}
	pStack->stack=(Element*)malloc(size*sizeof(Element));
	if(pStack->stack == NULL)
	{
		free(pStack);
		return NULL;
	}//stack ��������� ���� �ݳ�
	
	pStack -> size = size;
	pStack -> top = -1;
	//stack�� ���� �Է�

	return pStack;
}
void Push(Stack*pStack,Element item)
{
	if(pStack->top==pStack->size-1)
	{
	puts("������ �����ϴ�.");
	return;
	} //stack�� ���� �ִ��� check

	pStack->stack[++pStack->top]=item; //������ item�ֱ�


}
Element Pop(Stack*pStack)
{
	if(pStack->top<0)
	{
	puts("����item�� �����ϴ�.");
	return;
	}

	return pStack->stack[pStack->top--];

}
Element Top(Stack*pStack)
{
	if(pStack->top<0)
	{
	puts("top�� �����ϴ�.");
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