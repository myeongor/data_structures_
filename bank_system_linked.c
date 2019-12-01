#include"Queue_Linked_list.h"
#define SEAT 20

int main(void){
	Queue*q=CreateQueue();
	int choice,i;
	char item[20]="";
	int num=0;
	QueueNode*pPre;
	QueueNode*pLoc;
	while(1){

		printf("=========은행서비스===========\n");
		while(1)
		{
		printf("In(0), out(1), exit(2):");
		scanf("%d",&choice);
			if(choice==0||choice==1||choice==2)break;
			else{
				printf("[error] 0,1,2만 입력해주세요.");
			}
		}
	
		if(choice==0)
		{
			printf("Customer:");
			getchar();
			scanf("%[^\n]s",item);
			Enqueue(q,item);
			printf("The current status of Queue:( ");
			
			
			num=q->count;
			
			pPre=(QueueNode*)malloc(sizeof(QueueNode));
			pLoc=(QueueNode*)malloc(sizeof(QueueNode));
			
			
			pPre=NULL;
			pLoc=q->front;
			pPre=pLoc,pLoc=pLoc->next;
			printf("%s1,",pPre->data);

			while(num>1){
			pPre=pLoc,pLoc=pLoc->next;
			printf("%s%d,",pPre->data,q->count-num+2);
			num--;
			}
			printf("\b )\n");
			


			puts("");
		}	
	
		if(choice==1)
		{
			printf("Customer:%s \n",Dequeue(q));

			printf("The current status of Queue:( ");
		
			num=q->count;
			if(num<1)
				printf("NULL ");
			else{
				pPre=(QueueNode*)malloc(sizeof(QueueNode));
				pLoc=(QueueNode*)malloc(sizeof(QueueNode));
			
			
				pPre=NULL;
				pLoc=q->front;
				pPre=pLoc,pLoc=pLoc->next;
				printf("%s1,",pPre->data);

				while(num>1){
				pPre=pLoc,pLoc=pLoc->next;
				printf("%s%d,",pPre->data,q->count-num+2);
				num--;
				}
			}
			printf("\b )\n");
			

			puts("");
			
		}	

		if(choice==2)
			return 0;

	}
}