#include "Stack.h"
void main()
{
	int i =0;
	int item=0;

	Stack*pStack=CreatStack(100);

	
	for(i=0;i<10;i++){
		printf("push:");
		scanf("%d",&item);
		Push(pStack,item);
	}
	printf("pop:");
	while(pStack->top>=0){
		item=Pop(pStack);
		printf("%d ",item);
	}

	DestroyStack(pStack);

	pStack=NULL;
}