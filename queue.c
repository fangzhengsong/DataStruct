#include <stdio.h>
#define MAXSIZE 50
typedef struct
{
	int Array[MAXSIZE];

	int front;
	int rear;
}SeqQueue;


int CreateQueue(SeqQueue *Q)
{
	Q->front = Q->rear = 0;
	return 0;
}

int EnterQueue(SeqQueue *Q,int x)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)
	{
		return 0;
	}
	Q->Array[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}

int DeteleQueue(SeqQueue *Q,int *x)
{
	if (Q->front == Q->rear)
	{
		return 0;
	}
	*x = Q->Array[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

int main()
{
	SeqQueue Q;
	int i, j;
	CreateQueue(&Q);
	for (i = 0; i < 50;i++)
	{
		EnterQueue(&Q,i);
	}
	for (j = 0; j < 50;j++)
	{
		DeteleQueue(&Q,&j);

		printf("%d\n",j);
	}
	return 0;
}