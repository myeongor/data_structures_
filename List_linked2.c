#include "List_linked.h"
int main(){
	List*list=CreateList();
	int i,choice,item=0;
		while(1){

		while(1)
		{
		printf("In(0), Search(1), Out(2), Exit(3):");
		scanf("%d",&choice);
			if(choice==0||choice==1||choice==2||choice==3)break;
			else{
				printf("[error] 0,1,2,3만 입력해주세요. \n");
			}
		}
	
		if(choice==0)
		{
			printf("In:");
			scanf("%d",&item);
			InsertList(list,item);
			printf("The current status of List: ");
			
			PrintList(list);
			/*
			for(i=0;i<list->count;i++){
				printf("%d,",list->list[i]);
			}	
			*/
			printf("\b \n");
			puts("");
			
		}	
	
		if(choice==1)
		{
			printf("Search:");
			scanf("%d",&item);
			
			if(SearchList(list,item)==TRUE)
				printf("My list has %d\n",item);
			else 
				printf("My list does not have %d\n",item);
			printf("The current status of List: ");
			
			PrintList(list);
			/*
			for(i=0;i<list->count;i++){
				printf("%d,",list->list[i]);
			}	
			*/
			printf("\b \n");
			puts("");
		}	
		if(choice==2)
		{
			
			
			printf("Out:");
			scanf("%d",&item);
			RemoveList(list,item);
			printf("%d was removed.\n",item);
			printf("The current status of List: ");
			PrintList(list);
			/*
			for(i=0;i<list->count;i++){
				printf("%d,",list->list[i]);
			}	
			*/
			printf("\b \n");
			puts("");
			
		}	
		if(choice==3)
			return 0;

	}
}