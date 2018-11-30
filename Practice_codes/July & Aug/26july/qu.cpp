#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct rm {
	int hInd;
	int vInd;
	} room;

typedef struct node {
	room data;
	struct node *next;
	} *list;
	
//*list;
list maze[20][20];

typedef struct {
node *front, *rear ;
} QUEUE ;

void init(QUEUE *qp)
{
	qp->front = NULL;
	qp->rear = NULL;
}

int isempty(QUEUE qp)
{
	if(qp.front==NULL)
		return 1;
	return 0;
}

void enqueue(QUEUE *qp, room data)
{
	if(qp->front==NULL)
	{
		qp->front = (node*)malloc(sizeof(node));
		qp->front->data.hInd=data.hInd;
		qp->front->data.vInd=data.vInd;
		qp->rear = qp->front;
		//return;	
	}

	else
	{
		node* tmp = (node*)malloc(sizeof(node));
		tmp->data.hInd = data.hInd;
		tmp->data.vInd = data.vInd;
		tmp->next = NULL;
		qp->rear->next = tmp;
		qp->rear = tmp;
	}	
}

room dequeue(QUEUE *qp)
{
	node *tmp=(node*)malloc(sizeof(node));

	tmp = qp->front;
	room data;
	data.hInd=tmp->data.hInd;
	data.vInd=tmp->data.vInd;
	
	qp->front = qp->front->next;
	
	free(tmp);
	return (data);
}
