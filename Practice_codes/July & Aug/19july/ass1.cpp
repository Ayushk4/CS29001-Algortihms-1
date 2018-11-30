#include <iostream>

using namespace std;

struct node{

	int a;
	node * xorr;

};


void traverse_from_front_to_end(node * head)
{
	node * ptr = head, *q=NULL;
	long unsigned int z;

	while(ptr!=NULL)
	{
		cout<<ptr->a<<" ";
		z = (long unsigned int) q ^ (long unsigned int) ptr->xorr;
		q = ptr;
		ptr = (node *) z;
	}
}

void traverse_from_end_to_front(node * head)
{
	node * ptr = head, *q=NULL;
	long unsigned int z;

	while(ptr!=NULL)
	{
		z = (long unsigned int) q ^ (long unsigned int) ptr->xorr;
		q = ptr;
		ptr = (node *) z;
	}

	ptr = q;
	q=NULL;

	while(ptr!=NULL)
	{
		cout<<ptr->a<<" ";
		z = (long unsigned int) q ^ (long unsigned int) ptr->xorr;
		q = ptr;
		ptr = (node *) z;
	}

}

void reverse (node **head, node** tail)
{
	node *temp = *head;
	*head = *tail;
	*tail = temp;

}

void split(node **head, node **tail, node **l, node **r)
{
	node * p = *head,*p2 = *head, *q= NULL, *q2=NULL;
	long unsigned int z;

	while(1)
	{

	

		z = (long unsigned int) q2 ^ (long unsigned int) p2->xorr;
		q2 = p2;
		p2 = (node *) z;
	
		if(p2==NULL)
			break;

		z = (long unsigned int) q2 ^ (long unsigned int) p2->xorr;
		q2 = p2;
		p2 = (node *) z;

		if(p2==NULL)
			break;

		z = (long unsigned int) q ^ (long unsigned int) p->xorr;
		q = p;
		p = (node *) z;	
	}

	z = (long unsigned int) q ^ (long unsigned int) p->xorr;
	p2 =(node *) z;
	*r=p2;

	z = (long unsigned int) p ^ (long unsigned int) p2->xorr;
	p2->xorr = (node *) z;
	
	*l=p;
	p->xorr = q;

		

}

void merge(node **head,node **r,node **tail)
{
	
	node * p1 = *head,*q1 =NULL,*p2 = *r,*q2 =NULL,*pmain =NULL, *qmain=NULL;
	long unsigned int z,z1;

	if( p1->a < p2->a)
	{
		pmain = p1;
		q1 = p1;
		p1 = p1->xorr;
	}
	else
	{
		pmain = p2;
		q2 = p2;
		p2 = p2->xorr;
	}
	
	*head = pmain;
	
	while(1)
	{

		z = (long unsigned int) qmain ^ (long unsigned int) NULL;
		pmain->xorr = (node *) z;
		qmain = pmain;
	
		if(p1==NULL)
		{
			pmain = p2;
			z = (long unsigned int) pmain ^ (long unsigned int) qmain->xorr;
			qmain->xorr = (node *) z;
			break;
		}


		if(p2==NULL)
		{
			pmain = p1;
			z = (long unsigned int) pmain ^ (long unsigned int) qmain->xorr;
			qmain->xorr = (node *) z;
			break;
		}

		
		if( p1->a > p2->a)
		{
			
			pmain =p2;
			z = (long unsigned int) q2 ^ (long unsigned int) p2->xorr;
			q2 = p2;
			p2 = (node *) z;
		}

		else
		{
			pmain =p1;
			z = (long unsigned int) q1 ^ (long unsigned int) p1->xorr;
			q1 = p1;
			p1 = (node *) z;
		}
		
		z = (long unsigned int) pmain ^ (long unsigned int) qmain->xorr;
		qmain->xorr = (node *) z;

	}

	while(pmain!=NULL)
	{
		z = (long unsigned int) qmain ^ (long unsigned int) pmain->xorr;
		qmain = pmain;
		pmain = (node *) z;
		cout<<"ekthieskf;";
	}

	*tail = qmain;
}
int i=0;
void sort(node **head,node **tail)
{	
	if((*head)->xorr==NULL)
		return;

	node * l, *r;

	split(head,tail,&l,&r);
	cout<<"\n";
	traverse_from_front_to_end(*head);
	cout<<"\n";
	traverse_from_front_to_end(r);
	i++;
	cout<<"\n"<<i<<"\n\n";
	
	sort(head, &l);
	sort(&r, tail);

	merge(head,&r,tail);
	//cout<<"\njeiureutir\n";

}


int main()
{
	int n;
	cout<<"Enter the no. of nodes : ";
	cin>>n;

	node *head=NULL,*ptr, *q = NULL, *tail;
	long unsigned int z;
	for(int i=0;i<n;i++)
	{
		ptr = (node *) malloc(sizeof(node));
		ptr->a = rand() % 101;
		
		z = (long unsigned int) q ^ (long unsigned int) NULL;
		ptr->xorr = (node *) z;	

		if(q!=NULL)		
		{	z = (long unsigned int) q->xorr ^ (long unsigned int) ptr;
			q->xorr = (node *) z;		
		}

		if(head == NULL)
			head = ptr;
		
		q = ptr;
	}

	tail = q;
	
	traverse_from_front_to_end(head);
	//reverse(&head,&tail);
	cout<<"\n";
	//traverse_from_end_to_front(head);
	sort(&head,&tail);
	//traverse_from_front_to_end(head);
}
