#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

typedef struct Queue
{
	int data[MAXSIZE];
	int front;
	int rear;
}Queue;

int CreateQueue(Queue *Q)
{
	Q->front = Q->rear = 0;
	return 0;
}

int EnterQueue(Queue *Q,int x)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)
	{
		return 0;
	}
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}

int DeleteQueue(Queue *Q,int *x)
{
	if (Q->front == Q->rear)
	{
		return 0;
	}
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}
int GetHead(Queue *Q)
{
	return(Q->data[Q->front]);
}
void YangHuiTangle()
{
	int a, b;
	int x,temp;
	Queue *Q;
	CreateQueue(Q);

	EnterQueue(Q,1);//�����һ��Ԫ�ء�

	for (a = 2; a <=MAXSIZE;a++)
	{
		EnterQueue(Q,1);//��N�еĵ�һ��Ԫ��
		for (b = 1; b <= a - 2;b++)
		{
			DeleteQueue(Q,&temp);
			x = GetHead(Q);
			printf("%d", temp);
			temp = x + temp;
			EnterQueue(Q,temp);
		}
		DeleteQueue(Q,&x);
		printf("%d",x);
		EnterQueue(Q,1);//��N�е����һ��Ԫ��
	}
}

int main()
{
	YangHuiTangle();
}