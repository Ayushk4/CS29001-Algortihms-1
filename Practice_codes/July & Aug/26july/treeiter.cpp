#include<iostream>

using namespace std;

struct node {
	int a;
	node * left;
	node * right;
};

void insert(node **ptrt,int a)
{
	node * q = (node*)malloc(sizeof(node)), *ptr = *ptrt;
	q->left = NULL;
	q->right =NULL;
	q->a =a;
	
	while(1)
	{
		if(ptr==NULL)
			*ptrt = q;
		if(ptr->a==a)
			return;
		if(ptr->a>a)
		{
			if(ptr->left==NULL)
			{
				ptr->left = q;
				return;
			}			
			else
				ptr = ptr->left;
		}
		else
		{
			if(ptr->right ==NULL)
			{
				ptr->right =q;
				return;
			}
			else
				ptr = ptr->right;	
		}
	}
}

void infix(node *ptr)
{

	if(ptr==NULL)
		return;
	
	infix(ptr->left);
	cout<<ptr->a<<" ";
	infix(ptr->right);
}

int main()
{
	int n;
	cout<<"Enter the no of nodes: ";
	cin>>n;

	node *bst =(node*) malloc(sizeof(node));
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		insert(&bst,a);
	}
	cout<<"wgewgre \n";
	infix(bst);

}


struct stacknode{
	node* my, *next;
};

struct stack{
	stacknode * top;
};

void init(stack *s)
{
	s->top=NULL;
}

int isempty(stack s)
{
	if(s.top==NULL)
		return 1;
	return 0;
}

void push(stack *s,node *ptr)
{
	stacknode *sn=(stacknode*)malloc(sizeof(stacknode));
	sn->my=ptr;
	sn->next=(node *)s->top;
	s->top=sn;
}

stacknode * pop(stack *s)
{
	stacknode *sn =s->top;
	s->top=(stacknode *)s->top->next;
	return (sn);
}

