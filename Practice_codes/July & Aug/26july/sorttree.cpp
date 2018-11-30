#include <iostream>

using namespace std;

struct node {
	int a;
	node * left;
	node * right;
};

struct btree{
	node* top;
};

void init(btree *b)
{
	b->top=NULL;
}

void infix( node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		infix(ptr->left);
		cout<<ptr->a<<" ";
		infix(ptr->right);
	}
}

node * addnode(node * ptr,int a)
{
	
	
	if(ptr == NULL)
	{
		ptr = (node*)malloc(sizeof(node));
		ptr->a = a;
		ptr->left = NULL;
		ptr->right = NULL;
		return ptr;
	}

	if (ptr->a ==a)
		return ptr;
	else
	{
		if(a<ptr->a)
			ptr->left = addnode(ptr->left,a);
		else
			ptr->right = addnode(ptr->right,a);
	}		
	return ptr;
}



int search( node *ptr, int a)
{
	if(ptr == NULL)
		return 0;
	if(ptr->a == a)
		return 1;
	else
	{
		if(ptr->a>a)
			return (search(ptr->left,a));
		else
			return (search(ptr->right,a));
	}
}	
/*
node * deletenode (node* ptr, int a)
{
	if(ptr == NULL)
	{
		cout<<"Not found \n";
		return NULL; 
	}

	if(ptr->a == a)
	{
		if(ptr->left==NULL)
		{
			node *q = ptr->right;
			free(ptr);
			return(q);
		}

		if(ptr->right==NULL)
		{
			node *q = ptr->left;
			free(ptr);
			return(q);
		}

		if(ptr->left != NULL && ptr->right !=NULL)
		{
			node *tmp, *q = ptr->right;
			while(q->left!=NULL)
				q=q->left;

			ptr->
			q->left =NULL;


		delnode(ptr);
	}
	}
	if(ptr->a > a)
	{
		ptr->left = deletenode(ptr->left, a);
	{
	else
	{
		ptr->right = deletenode(ptr->right, a);
	}

}
*/
int minimum(node *ptr)
{
	if(ptr->left==NULL)
		return ptr->a;
	else
		return minimum(ptr->left);
}

int maximum(node *ptr)
{
	if(ptr->right ==NULL)
		return ptr->a;
	else
		return maximum(ptr->right);
}

int main()
{
	int n;

	cout<<"Enter the number of inputs: ";
	cin>>n;

	btree bst;
	init(&bst);
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		bst.top = addnode(bst.top,a);
	}

	infix(bst.top);
	int sarch;
	cin>>sarch;
	cout<<search(bst.top,sarch)<<"\n";
	cout<<"Minimum = "<<minimum(bst.top)<<"\n";
	cout<<"Maximum = "<<maximum(bst.top)<<"\n";
}

