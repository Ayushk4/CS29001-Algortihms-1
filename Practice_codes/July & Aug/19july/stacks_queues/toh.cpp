#include <iostream>

using namespace std;

struct node {
	int a;
	node *next;
};

struct qu{
	int n;
	node *front;
	node *rear;
}

void init(qu q)
{
	q->n=0;
	q->front=NULL;
	q->rear=NULL;
}

void isempty(qu q)
{
	if(q->rear ==NULL)
		cout<<"\nEmpty";

	else
		cout<<"\nNot empty";
}

void enqu(qu q)
{
	node *ptr = (node *) malloc(sizeof(node));
	

int main()
{
	qu q;
	init(q);

}
