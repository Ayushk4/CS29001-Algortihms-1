#include <iostream>

using namespace std;

struct node {
	int a;
	node * left, *right;
};

struct bst {
	node * top;
};

void insert(node **ptrt,int a)
{
	node *q=(node*)malloc(sizeof(node));
	q->left=NULL;
	q->right=NULL;
	q->a=a;
	
	if(*ptrt==NULL)
	{
		*ptrt=q;
		return;
	}

	node *ptr=*ptrt;

	while(1)
	{
		
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

node * search(node *ptr,int a)
{
	while(ptr!=NULL)
	{
		if(ptr->a==a)
		{
			cout<<"baam";
			return ptr;
		}
		if(ptr->a>a)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}

	cout<<"Not found";
	return NULL;
}

void minmax(bst b)
{
	node *ptr=b.top;
	int a=0;
	while(ptr!=NULL)
	{	a=ptr->a;
		ptr=ptr->left;	
	}

	cout<<"\nMinimum of binary tree is : "<<a;
	
	ptr=b.top;
	while(ptr!=NULL)
	{	a=ptr->a;
		ptr=ptr->right;
	}	
	cout<<"\nMaximum of binary tree is : "<<a;
}

void infix(node *ptr)
{
	if(ptr==NULL)
		return;
	
	infix(ptr->left);
	cout<<ptr->a<<" ";
	infix(ptr->right);
}

node * min(node *ptr)
{
	if(ptr==NULL|| ptr->left == NULL)
		return ptr;
	else
		return min(ptr->left);
}
		
node * del(node * ptr, int a)
{
	if(ptr==NULL)
		return ptr;
	
	if(ptr->a>a)
		ptr->left = del(ptr->left, a);
	else
		if(ptr->a<a)
			ptr->right = del(ptr->right, a);

		else
		{
			if(ptr->left == NULL)
			{
				node * tmp = ptr;
				free(ptr);
				return(tmp->right);
			}
			
			if( ptr->right ==NULL)
			{
				node * tmp = ptr;
				free(ptr);
				return (tmp->left);
			}
			

			node *tmp,* aa = min(ptr->right);
			
			ptr->a = aa->a;
			ptr->right = del(ptr->right,aa->a);
			free(aa);	
		}
	return ptr;
}

int depth(node * ptr, int a)
{
	if(ptr==NULL)
		return a;

	else
	{	a++;
		return max(depth(ptr->left,a),depth(ptr->right,a));
	}	

}

node * successor(node * ptr, node * n)
{
	if(n->right!=NULL)
		return min(n->right);

	node * r=NULL;
	while(ptr!=NULL)
	{
		if(ptr->a>n->a)
		{	r=ptr;
			ptr=ptr->left;
		}
		else if(ptr->a<n->a)
			ptr=ptr->right;
		else 
			break;
	}
	return r;
}

int main()
{
	int n;
	cin>>n;
	
	int a;
	bst b;

	b.top=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		insert(&b.top,a);
	}

	infix(b.top);
	minmax(b);


//	cin>>a;
//	search(b.top,a);
//	cout<<"\n";

//	cout<<"\nEnter the node to be deleted: ";

//	b.top = del(b.top, a);
//	cout<<"\n";
//	infix(b.top);
	while(1)
	{	cout<<"\n";
		cin>>a;
		node * s= successor(b.top,search(b.top,a));
		cout<<"\n\n\n"<<s->a<<"\n\n";
	}
}//height and depth
