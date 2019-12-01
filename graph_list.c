#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct Vertex {
	int vertex;
	struct Vertex *next;
}Vertex;

typedef struct {
	Vertex *matrix[MAX];
	int visited[MAX];
}Graph;
//Stack
typedef struct tStackNode {
	int data;
	struct tStackNode *next;
} StackNode;

typedef struct {
	int count;
	StackNode *top;
} Stack;
//Queue
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;

typedef struct {
	struct QNode *front, *rear;
}Queue;

Queue* CreateQueue() {
	Queue *Q;
	Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

int isEmpty(Queue *Q) {
	if (Q->front == NULL) return 1;
	else return 0;
}

void enQueue(Queue *Q, int item) {

	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->next = NULL;
	if (Q->front == NULL) {
		Q->front = newNode;
		Q->rear = newNode;
	}
	else {
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
}

int deQueue(Queue *Q) {
	QNode *old = Q->front;
	int item;
	if (isEmpty(Q)) return 0;
	else {
		item = old->data;
		Q->front = Q->front->next;
		if (Q->front == NULL) Q->rear = NULL;
		free(old);
		return item;
	}
}

Graph* CreateGraph() {
	int i;
	Graph *graph;

	graph = (Graph*)malloc(sizeof(Graph));

	for (i = 0; i < MAX; i++) {
		graph->visited[i] = 0;
		graph->matrix[i] = NULL;
	}
	return graph;
}

void insertArc(Graph *graph, int from, int to) {
	Vertex *node;
	node = (Vertex*)malloc(sizeof(Vertex));
	node->vertex = to;
	node->next = graph->matrix[from];
	graph->matrix[from] = node;
}

Stack *CreateStack() {
	Stack *pStack = (Stack *)malloc(sizeof(Stack));
	if (pStack == NULL) return NULL;
	pStack->count = 0;
	pStack->top = NULL;
	return pStack;
}

void Push(Stack *pStack, int item) {
	StackNode *pNewNode = (StackNode *)malloc(sizeof(StackNode));
	if (pNewNode == NULL)
		return;

	pNewNode->data = item;
	pNewNode->next = pStack->top;
	pStack->top = pNewNode;
	pStack->count++;

}

int Pop(Stack *pStack) {
	int out;
	StackNode* temp;
	temp = pStack->top;
	out = pStack->top->data;
	pStack->top = pStack->top->next;
	free(temp);
	pStack->count--;
	return out;
}

int Top(Stack *pStack) {
	return pStack->top->data;
}

int IsEmptyStack(Stack *pStack) {
	if (pStack->count == 0)
		return 1;

	else return 0;

}

void DFS(Graph *graph, int data) {

	Stack *pStack = CreateStack();
	Vertex *node;
	Push(pStack, 0);
	Push(pStack, data);
	graph->visited[data] = 1;

	printf("%c", data + 'A');

	while (!IsEmptyStack(pStack)) {

		node = graph->matrix[data];

		while (node) {
			if (!graph->visited[node->vertex]) {
				Push(pStack, node->vertex);
				graph->visited[node->vertex] = 1;
				printf(" %c", node->vertex + 'A');
				data = node->vertex;
				node = graph->matrix[data];
			}
			else node = node->next;
		}
		data = Pop(pStack);
	}
}

void BFS(Graph *graph, int data) {
	Queue *Q = CreateQueue();
	int j;
	Vertex *node;

	for (j = 0; j < MAX; j++) graph->visited[j] = 0;

	graph->visited[data] = 1;
	enQueue(Q, data);

	while (!isEmpty(Q)) {

		data = deQueue(Q);
		printf("%c ", data + 'A');

		node = graph->matrix[data];

		while (node&&graph->visited[node->vertex] == 0) {
			enQueue(Q, node->vertex);
			graph->visited[node->vertex] = 1;
			node = node->next;
		}

	}
}

int main() {
	Graph *graph =CreateGraph();
	FILE *fp= fopen("Graph.txt", "r");
	char a;
	char c1, c2;
	fscanf(fp, "%c", &a);

	while ((fscanf(fp, " %c", &c1)) != EOF) {
		fscanf(fp, " %c ", &c2);
		insertArc(graph, (int)c1 - 'A', (int)c2 - 'A');
	}

	printf("Depth-first traversal :");
	DFS(graph, 0);
	printf("\n");

	printf("Breath-first traversal : ");
	BFS(graph, 0);
	printf("\n");
	return 0;

}