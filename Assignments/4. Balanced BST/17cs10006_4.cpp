// Name - Ayush Kaushal
// Roll no - 17CS10006

#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
	struct node *parent;
}NODE, *NODEPTR;

NODEPTR left_rot(NODEPTR root, NODEPTR N)
{
	node * q = N;
	node * p = q-> right;
	
	if(q-> right ==NULL)
		return root;
	
	if(p->left!= NULL)
		p->left-> parent = q;
	
	if( root == q)
		root = p;
	else if (q-> parent -> left == q)
		q-> parent->left = p;
	else
		q->parent ->right = p;
	
	q->right = p->left;
	p-> parent = q-> parent;
	q-> parent = p;
	p-> left = q;
	
	return root;
}	

NODEPTR right_rot(NODEPTR root, NODEPTR N)
{
	node * q = N;
	node * p = q-> left;
	
	if(q-> left ==NULL)
		return root;
	
	if(p->right!= NULL)
		p->right-> parent = q;
	
	if( root == q)
		root = p;
		
	else if (q-> parent -> left == q)
		q-> parent->left = p;
	else
		q->parent ->right = p;
	
	q-> left = p->right;
	p-> parent = q-> parent;
	q-> parent = p;
	p-> right = q;
	
	return root;
}	

void print(node* root, int i=0)
{
	if( root !=NULL)
	{
		i++;
		print(root->right, i);
		
		int j = i -1;
		cout<<"\n\n";
		while(j--)
			cout<<"\t\t";
		cout<<root->value<<"\n";
		print(root->left, i);
	}
}

NODEPTR makeRoot(NODEPTR root, NODEPTR N)
{
	if( root->left == N)
		return (right_rot(root,root));
	else
		return (left_rot(root,root));
	
}		
		
NODEPTR sameOrientation(NODEPTR root, NODEPTR N)
{
	if( N == N->parent->left)
	{
		root = right_rot(root,N->parent->parent);
		return (right_rot(root,N->parent));
	}
	else
	{
		root = left_rot(root,N->parent->parent);
		return (left_rot(root,N->parent));
	}	
		
}

NODEPTR oppositeOrientation(NODEPTR root, NODEPTR N)
{
	if( N == N->parent->right)
	{
		root = left_rot(root, N->parent);
		return(right_rot(root, N->parent));
	}
	else
	{
		root = right_rot(root, N->parent);
		return(left_rot(root, N->parent));
	}
}



NODEPTR lift(NODEPTR root, NODEPTR N)
{
	while( N!= root)
	{
		if( N->parent == root)
			root = makeRoot(root,N);
		
		else if ( N->parent == N->parent->parent->left)
			{
				if( N == N->parent->left)
					root = sameOrientation(root, N);
				else
					root = oppositeOrientation(root, N);
			}
		else
			{
				if( N == N->parent->right)
					root = sameOrientation(root, N);
				else
					root = oppositeOrientation(root, N);
			}
			
	}
	return N;
}



NODEPTR insert(NODEPTR root, int key)
{
	node *q =(node *)malloc(sizeof(node));
	q->left = q->right = q->parent = NULL;
	q->value =key;
	if(root ==NULL)
		return q;
		
	node * prev, * trav = root;
	
	while( trav!= NULL)
	{
		prev = trav;
		if( trav->value == q-> value)
			return root;
		
		if( trav->value > q->value)
			trav = trav->left;
		else
			trav = trav->right;
	}
	
	q->parent = prev;
	
	if( prev->value > q->value)
		prev->left =q;
	else
		prev->right = q;
	
	root = lift(root,q);
	print(root);
	cout<<"\n\n\n\n\n";
	return root;
}

void preOrder(node *root)
{
	if( root!=NULL)
	{
		cout<<root->value<<" ";
		preOrder( root->left);
		preOrder( root-> right);
	}
}

void inOrder(node *root)
{
	if( root!=NULL)
	{
		inOrder( root->left);
		cout<<root->value<<" ";
		inOrder( root-> right);
	}
}
 
int main()
{
	int n,i,a;
	node *root = NULL;
	cout<<"\nEnter the numbers to insert: ";
	cin>>n;

	cout<<"\n\nEnter numbers to insert: ";
	for(i=0;i<n;i++)
	{
		cin>>a;
		
		root = insert(root, a);
	}
	
	cout<<"\n\npreorder traversal: ";
	preOrder(root);	
	cout<<"\n";	
	cout<<"\ninorder traversal: ";
	inOrder(root);
	cout<<"\n\n\n";

	print(root);

}
