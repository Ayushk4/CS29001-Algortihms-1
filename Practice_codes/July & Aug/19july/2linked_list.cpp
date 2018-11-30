#include <iostream>

using namespace std;

struct node {

	int a;
	node *next;
};


void print_list(node *head)
{
	node * ptr = head;

	while(ptr!=NULL)
	{
		cout<<ptr->a;
		ptr=ptr->next;
	}

}


void splitlist(node **head, node **a, node **b)
{
	node * ptr1 = *head, *ptr2= *head;

	while(ptr2!=NULL)
	{
		ptr2 = ptr2->next;
		
		if (ptr2 != NULL)
		{
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}

	}

	*b = ptr1->next;
	ptr1->next = NULL;	
	*a = *head;

}

void sortedmerge(node *a, node*b)
{

	node first;


void mergesort(node **head)
{
	if(*head==NULL||*head->next==NULL)
		return;
	
	node *a, *b;

	splitlist(head,&a,&b);

	mergesort(&a);
	mergesort(&b);

	* head = sortedmerge(a,b);

	return;
}


int main()
{

	int n;
	cout<<"Enter the number of data";
	cin>>n;

	node * ptr=NULL, *head = NULL, *q;

	for(int i=0;i<n;i++)
	{	q = ptr;
		ptr = (node *) malloc (sizeof(node *));
		cin>>ptr->a;
		
		if(head ==NULL)
			head = ptr;
		
		
		else
			q->next = ptr;
		
	}

	print_list(head);
	return 0;
}	
	
		
		
