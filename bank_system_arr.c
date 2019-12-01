#include"Queue_arr.h"
#define NAME_MAX 20

int main(void){
	Queue*q=CreatQueue(100);
	int choice,i;
	char item[NAME_MAX]="";
	while(1){

		printf("=========은행서비스(arr)===========\n");
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
			i=0;
			for(i=q->front;i<q->rear;i++){
				printf("%s%d,",q->queue[i%q->size+1],i-q->front+1);
			}
			//printf("%s",QueueFront(q));
			printf("\b )\n");
			puts("");
		}	
	
		if(choice==1)
		{
			printf("Customer:%s \n",Dequeue(q));

			printf("The current status of Queue:( ");
			i=0;
			for(i=q->front;i<q->rear;i++){
				printf("%s%d,",q->queue[i%q->size+1],i-q->front+1);
			}
			printf("\b )\n");
			puts("");
		}	

		if(choice==2)
			return 0;

	}
}