#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct
{
	int count;
	struct vertex* first;
	int matrix[SIZE][SIZE];
	int visit[SIZE];
}Graph;

typedef struct vertex {
	struct vertex *pNextVertex;
	char data;
}Vertex;
Graph*CreateGraph(){
	int i,j;
	Graph*newGraph=(Graph*)malloc(sizeof(Graph));
	newGraph->count=0;
	newGraph->first=NULL;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			newGraph->matrix[i][j]=0;
		}
	}
		return newGraph;
}
void InsertArc(Graph *pGraph, char pStart, char pEnd) {
	pGraph->matrix[pStart - 'A'][pEnd - 'A']++; //if start is 'A' -> [0] 
}
Vertex *InsertVertex(Graph *pGraph, char data) {

	Vertex *newVertex = (Vertex*)malloc(sizeof(Vertex));
	Vertex *root = pGraph->first;
	newVertex->data = data;
	if (root == NULL) root = newVertex;

	return newVertex;
}
//Queue
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;

typedef struct {
	struct QNode *front, *rear;
}Queue;

Queue* CreateQueue() {
	Queue *pQueue;
	pQueue = (Queue*)malloc(sizeof(Queue));
	pQueue->front = NULL;
	pQueue->rear = NULL;
	return pQueue;
}

int isEmpty(Queue *pQueue) {
	if (pQueue->front == NULL) 
		return 1;
	else return 0;
}

void enQueue(Queue *pQueue, char item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->next = NULL;
	if (pQueue->front == NULL) {
		pQueue->front = newNode;
		pQueue->rear = newNode;
	}
	else {
		pQueue->rear->next = newNode;
		pQueue->rear = newNode;
	}
}

char deQueue(Queue *pQueue) {
	QNode *pPre = pQueue->front;
	int item;
	if (isEmpty(pQueue)) return 0;
	else {
		item = pPre->data;
		pQueue->front = pQueue->front->next;
		if (pQueue->front == NULL) pQueue->rear = NULL;
		free(pPre);
		return item;
	}
}

void DFT(Graph *pGraph, char pstart) {
	int i;
	printf("%c ", pstart);
	pGraph->visit[pstart - 'A'] = 1;
	for (i = 0; i < SIZE; i++) {
		if (pGraph->matrix[pstart - 'A'][i] > 0 && pGraph->visit[i] == 0) {
			DFT(pGraph, i + 'A');
		}
	}

}
void BST(Graph* graph, char vertex){
	Queue* queue = CreateQueue();
	int i=0,num=graph->count;
	enQueue(queue, vertex);
	while(num>0){
		vertex = deQueue(queue);
			for(i=vertex; i<graph->count; i++)
			{
			if(!graph->visit[i] && graph->matrix[vertex][i] == 0){
			graph->visit[i] = 1;
			enQueue(queue, i);
			printf("%c ", i+'A'); 
			}
		}
		num--;
	}
}

int main(void) {
	int i, j;
	Queue*q=CreateQueue();
	Graph *NewGraph = CreateGraph();
	char start,a, b;
	FILE*file = fopen("graph.txt", "r");

	fscanf(file, "%c ", &start);

	while (1) {

		if (fscanf(file, "%c %c ", &a, &b) == EOF) {
			break;
		}
		
		if(NewGraph->visit[a-'A']==0){
			NewGraph->visit[a-'A']++;
		InsertVertex(NewGraph, a);
		}
		if(NewGraph->visit[b-'A']==0){
			NewGraph->visit[b-'A']++;
		InsertVertex(NewGraph, b);
		}
		InsertArc(NewGraph, a, b);
	}
	fclose(file);
	for (i = 0; i < SIZE; i++) {
		NewGraph->visit[i] = 0;
	}
	printf("depth-first traversal: ");
	DFT(NewGraph, start);
	printf("\n");

	for (i = 0; i < SIZE; i++) {
		NewGraph->visit[i] = 0;
	}

	printf("breath-first traversal: ");
	printf("%c ",start);
	BST(NewGraph,start);
	printf("\n");

	free(NewGraph);

	return 0;
}
