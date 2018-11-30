#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int a;
	node *next;
};

struct qu {
	node *front, *rear;
};

void enqu(qu *q,int a)
{
	node * tmp = (node*) malloc(sizeof(node));
	tmp->a=a;

	if(q->front==NULL)
		q->front = tmp;
	else
		q->rear->next=tmp;

	q->rear=tmp;
	q->rear->next=q->front;
}

void dequ(qu *q)
{
	node *tmp;
	tmp = (node*) malloc (sizeof(node));
	tmp = q->front;
	q->front = q->front->next;
	
	cout<<tmp->a;
}

int main()
{
	int n;

	cout<<"Enter the number of inputs : ";
	cin>>n;

	int a;
	qu *q;
	q = (qu*) malloc (sizeof(qu));

	for (int i=0;i<n;i++)
	{	
		cin>>a;
		enqu(q,a);
	}

	dequ(q);
dequ(q);
dequ(q);
dequ(q);
dequ(q);dequ(q);

}
