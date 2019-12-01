#include <stdio.h>
#include <stdlib.h>
#include "Boolean.h"
typedef int Element;


typedef struct tListnode{
   Element data;
   struct tListnode *next;
}ListNode;

typedef struct{
   int count;
   ListNode*head;
}List;

List*CreateList()
{
List*pNewList=(List*)malloc(sizeof(List));
if(pNewList==NULL){
   return NULL;
   }
   pNewList->count = 0;
   pNewList->head=NULL;
   return pNewList;
}
void RemoveList(List*pList,Element data){
	ListNode*pLoc=(ListNode*)malloc(sizeof(ListNode));
	ListNode*pPre=(ListNode*)malloc(sizeof(ListNode));	
	int count=pList->count;
   //head에 붙어있는거
	pPre=pList->head;
	pLoc=pPre->next;
	if(pPre->data==data){
		
		pList->head=pLoc;
		//free(pPre);
		count--;
		pList->count--;
	}
	else{
		count--;
		pLoc=pLoc->next;
		while(1){
			if(pPre->next->data==data){
				count--;
				pList->count--;
				pPre->next=pLoc;
				if(count>2){
				count--;
				pLoc=pLoc->next->next;
				pPre=pPre->next;
				}
				else break;
				//free(pLoc);
				

				
			}
			else if(count>3){
				pPre=pPre->next;
				pLoc=pLoc->next;
				count--;
				
			}
			else
				break;
		}
		if(count==3){
			pPre=pPre->next;
			pLoc=pLoc->next;
				if(pPre->next->data==data){
					pPre->next=pLoc;
					//free(pLoc);
					pList->count--;
				}
				else {
					pPre=pPre->next;
					count--;
				}
		}
		if(count==2){
			if(pPre->next->data==data){
				pPre->next=NULL;
				free(pLoc);
					pList->count--;
				}
		}
	}
		
	
}
void InsertList(List*pList,Element data){
   int i;
   ListNode*pNewNode=(ListNode*)malloc(sizeof(ListNode));
   ListNode*cur=(ListNode*)malloc(sizeof(ListNode));
   Element tmp=0;
   if(pList->head==NULL){
      pList->head=pNewNode;
      pNewNode->data=data;
      pList->count++;

   }
   else{
      cur=pList->head;
      //새로운 노드 추가
      pNewNode->next=pList->head;
      pList->head=pNewNode;
      pNewNode->data=data;
      pList->count++;
      //순서배열
   }
   cur=pList->head;
   for(i=0;i<pList->count-1;i++){
      if(cur->data>cur->next->data){
      tmp=cur->next->data;
      cur->next->data=cur->data;
      cur->data=tmp;
      }
      cur=cur->next;
   }
}


Boolean IsEmptyList(List*pList){
   if(pList->head==NULL)
      return TRUE;
   
   else
      return FALSE;
}
Boolean SearchList(List*pList,Element data)
{   
   int i=0;
   ListNode*cur=(ListNode*)malloc(sizeof(ListNode));
   if(IsEmptyList(pList)==TRUE)
   {
      printf("List is empty.\n");
      return;
   }
   else
   {
   cur=pList->head;
      for(i=0;i<pList->count-1;i++){
          cur=cur->next;
          if(cur->data==data)
             return TRUE;   
      }
      return FALSE;
   }
}
void PrintList(List*pList)
{
   int i=0;
   ListNode*cur=(ListNode*)malloc(sizeof(ListNode));
   if(IsEmptyList(pList)==TRUE)
   {
      printf("List is empty.\n");
      return;
   }
   else
   {
   cur=pList->head;
   printf("%d ",cur->data);
      for(i=0;i<pList->count-1;i++){
          cur=cur->next; 
		  printf("%d ",cur->data);
      }
	  puts("");
   }
}