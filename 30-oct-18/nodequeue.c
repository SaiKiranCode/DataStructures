#define MAXSIZE 100
struct queue
{
	NODE **arr;
	int front;
	int rear;
};
typedef struct queue QUEUE;
QUEUE *createqueue()
{
	QUEUE *queue;
	queue=(QUEUE *)malloc(sizeof(QUEUE));
	if(queue==NULL)
	{
		printf("memory not allocated\n");
		exit(0);
	
	}
	queue->arr=(NODE **)malloc(MAXSIZE*sizeof(NODE *));
	queue->front=-1;
	queue->rear=-1;
	return queue;

}


void enqueue(NODE *temp,QUEUE *queue)
{
	queue->rear++;
	queue->arr[queue->rear]=temp;
}

NODE *dequeue(QUEUE *queue)
{
	
	queue->front++;
	return queue->arr[queue->front];



}
_Bool isempty(QUEUE *queue)
{
	if(queue->front==queue->rear)
	{
		return 0;
	}
	else
	{
		return 1;
	}



}





