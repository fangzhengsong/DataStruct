#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int coefficent;
	int index;
	struct Node *next;
}Node, *LinkList;

LinkList CreateList(Node **head,int i)
{
	LinkList J,R;
	int j = 0;
	char a, b;
	*head = (Node*)malloc(sizeof(Node));
	(*head)->next = NULL;
	R = *head;
	for (j = 0; j <= i;j++)
	{
		J = (Node*)malloc(sizeof(Node));
		R->next = J;
		R = J;
		scanf("%c%d,%d%c", &a, &J->coefficent, &J->index, &b);
	}
	J->next = NULL;

	return *head;
}
LinkList SortList(Node **head,int i)
{
	LinkList L;
	int m, n;
	int coefficent, index;
		for (m = 0; m <= i;m++)
		{
			for (n = 0, L = *head, L = L->next; n < i  - m; n++, L = L->next)
			{			
				if ((L->index)>(L->next->index))
				{
					coefficent = L->coefficent;
					index = L->index;

					L->coefficent = L->next->coefficent;
					L->index = L->next->index;

					L->next->coefficent = coefficent;
					L->next->index = index;
				}
			}
		}
	return *head;
}
void Display(Node **head)
{
	LinkList L;
	L = *head;
	L = L->next;
	int i = 0;
	while (L->next != NULL)
	{
		L = L->next;
		if (L->coefficent >0 && i!=0)
		{
			printf("+");
		}
		if (L->index==0)
		{
			printf("%d",L->coefficent);
		}
		else if (L->index == 1)
		{
			if (L->coefficent == 1)
			{
				printf("X", L->coefficent);
			}
			else if (L->coefficent == -1)
			{
				printf("-X", L->coefficent);
			}
			else
			{
				printf("%dX", L->coefficent);
			}
			
		}
		else
		{
			if (L->coefficent == 1)
			{
				printf("X^%d", L->index);
			}
			else if (L->coefficent == -1)
			{
				printf("-X^%d", L->index);
			}
			else
			{
				printf("%dX^%d", L->coefficent, L->index);
			}
			
		}
		i++;
	}
	printf("\n");
}
void main()
{
	Node *head,*L,*Q;
	int i = 0;
	scanf("%d",&i);
	L = CreateList(&head,i);
	Q = SortList(&L,i);
	Display(&Q);
}