#include<iostream>

using namespace std;

struct node {
	int a;
	node *left;
	node *right;
};

struct btree {
	node *top;
};

node * insert(node * ptr,int a)
{
	if(ptr == NULL)
	{
		ptr = (node*)malloc(sizeof(node));
		ptr->a = a;
		ptr->left = NULL;
		ptr->right = NULL;
		return ptr;
	}

	if(ptr->a==a)
		return ptr;
	else
	{
		if (ptr->a>a)
			ptr->left =insert(ptr->left,a);
		else
			ptr->right =insert(ptr->right,a);
	}
	return ptr;
}

void infix(node *ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		infix(ptr->left);
		cout<<ptr->a<<" ";
		infix(ptr->right);
	}
}

void init(btree *b)
{
	b->top=NULL;
}

int max(node *ptr)
{
	if(ptr==NULL)
	{	cout<<" ksajigskael";
		return 344343;
	}	
	if(ptr->right !=NULL)
		return (max(ptr->right));
	else
		return (ptr->a);
}

int main()
{
	int n;
	cin>>n;
	
	btree b;
	init(&b);
	int a;

	for(int i=0;i<n;i++)
	{
		cin>>a;
		b.top = insert(b.top,a);
	}

	infix(b.top);
	cout<<"\n"<<max(b.top);
}

