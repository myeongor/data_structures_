#include <stdio.h>
#include <stdlib.h>
#include "Boolean.h"

#define LIST_LEN 6

typedef int Element;

typedef struct _ArrayList
{
	Element *list;
	int count;
	int cur;//데이터 참조위치 기록
}List;

List*CreateList()
{
	List*pList=(List*)malloc(sizeof(List));
	if(pList==NULL)
		return;
	pList->list = (Element*)malloc(sizeof(Element)*LIST_LEN);

	if(pList->list == NULL)
	{
		free(pList);
		return NULL;
	}//비어있으면 공간 반납
	
	pList -> count = 0;
	pList -> cur = -1;


	return pList;
}
Boolean IsEmptyList(List*pList)
{
	if(pList->count==0)
		return TRUE;
	else return FALSE;
}
Boolean IsFullList(List*pList)
{
	if(pList->count>=LIST_LEN)
		return TRUE;
	else return FALSE;
}
void Insert(List*pList,Element data)
{
	int i=0,j=0;
	Element tmp=0;
	for(i=0;i<pList->count;i++){
		if(pList->list[i]>=data){
			for(j=pList->count;j>i;j--){
				pList->list[j]=pList->list[j-1];
			}
			pList->list[i]=data;
			pList->count++;
			return;
		}
	}
	pList->list[pList->count]=data; //Element char면 바꾸기
	pList->count++;
}
void Remove(List*pList,Element data){
	int i=0,j;
	while(1){
		if(pList->list[i]==data){
			for(j=i;j<pList->count-1;j++){
				pList->list[j]=pList->list[j+1];
			}
			pList->count--;
			i--;
		}
		else i++;
		if(pList->count==i)return;
	}
}

Boolean Search(List*pList,Element data)
{
	int i;
	if(pList->count==0)
		return FALSE;//저장된 데이터 없다
	for(i=0;i<pList->count;i++){
		if(pList->list[i]==data) //Element char면 바꾸기
			return TRUE;
	}
	return FALSE;
}
void Destroy(List*pList)
{
	if(pList->count>0){
		free(pList->list);

	free(pList);
	}
}