#include<iostream>

using namespace std;

struct node
{
	int a;
	node* left, *right;
};


struct binarytree
{
	node * top;
};

void init(binarytree *bst)
{
	bst->top=NULL;
}

void prefix(node *ptr)
{
	if(ptr==NULL)
		return;

	else
	{
		cout<<ptr->a<<" ";
		prefix(ptr->left);		
		prefix(ptr->right);
	}
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

void postfix(node *ptr)
{
	if(ptr==NULL)
		return;

	else
	{
		postfix(ptr->left);
		postfix(ptr->right);
		cout<<ptr->a<<" ";
	}
}


node * create(int a[],int n)
{
	node* ptr = (node*)malloc(sizeof(node));
	ptr->left = NULL;
	ptr->right = NULL;
	
	if(n==0)
		return NULL;

	if(n==1)
	{
		ptr->a = a[0];
	}

	else
	{
		ptr->a = a[int(n/2)];
		ptr->left = create(a,int(n/2));
		ptr->right = create(a+int(n/2)+1,int((n-1)/2));
	}

	return ptr;
}

void del(node *ptr)
{
	if(ptr==NULL)
		return;
	if(ptr->left==NULL&&ptr->right==NULL)
	{	cout<<ptr->a<<" ";
		free(ptr);
		return;
	}
	del(ptr->left);
	del(ptr->right);
	cout<<ptr->a<<" ";
}

node * deletetree(binarytree *bst)
{	del(bst->top);
	return NULL;
}

int main()
{
	int n;
	cout<<"Enter the number of input: ";
	cin>>n;

	binarytree bst;
	init(&bst);

	int a[n];
	for(int i=0;i<n;i++)
	{	cin>>a[i];
	}

	bst.top = create(a,n);

	infix(bst.top);
	cout<<"\n";
	postfix(bst.top);
	cout<<"\n";
	bst.top = deletetree(&bst);
}
