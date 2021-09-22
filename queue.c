#define MAX_QUEUE_LENGHT 10

typedef int elementType;
typedef struct {
	elementType elements[MAX_QUEUE_LENGHT];
	int front, frear;
}Queue;

void initQueue(Queue *Q){
	Q->front=-1;
	Q->frear=-1;
}

int emptyQueue(Queue *Q){
	return Q->front==-1;
}

void enQueue(Queue *Q, elementType e){
	if(((Q->frear+1)%MAX_QUEUE_LENGHT)!=Q->front){
		Q->frear = (Q->frear+1)%MAX_QUEUE_LENGHT;
		Q->elements[Q->frear] = e;
	}
	if(Q->front==-1) Q->front=0;
}

elementType front(Queue *Q){
	if(!emptyQueue(Q)) return Q->elements[Q->front];
	else return -999999999;
}

void deQueue(Queue *Q){
	if(Q->front==Q->frear) initQueue(Q);
	else Q->front = (Q->front+1)%MAX_QUEUE_LENGHT;
}

void printQueue(Queue *Q){
	int i;
	int flag = 0;
	if(emptyQueue(Q)) flag = 1;
	printf("\n");
	for(i=Q->front;!flag;i=(i+1)%MAX_QUEUE_LENGHT){
		printf("%d ",Q->elements[i]);
		if(i==Q->frear) flag = 1;
	}
	printf("\n");
}

