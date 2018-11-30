#include<iostream>

using namespace std;

struct node 
{
	int a;
	char color;
	node * left, * right, * parent;
};

node * NIL = (node *) malloc(sizeof(node));

node * left_r(node *root, node *q)
{
	node * p= q->right;
	q->right = p->left;

	if( p->left != NIL)
		p->left->parent = q;

	p->parent = q->parent;

	if( root == q)
		root = p;
	else if(q->parent->left == q)
		q->parent->left = p;
	else
		q->parent->right = p;

	p->left = q;
	q->parent = p;
}

node * right_r(node *root, node *q)
{
	node * p= q->left;
	q->left = p->right;

	if( p->right != NIL)
		p->right->parent = q;

	p->parent = q->parent;

	if( root == q)
		root = p;
	else if(q->parent->left == q)
		q->parent->left = p;
	else
		q->parent->right = p;

	p->right = q;
	q->parent = p;
}

node * left_rotate(node * root, node * upper)
{
	if( upper-> right == NIL)
		return root;
	
	node * p = upper-> right;

	if( root == upper)
		root = upper-> right;
	else if (upper == upper->parent->left)
		upper->parent->left = upper -> right;
	
	else
		upper->parent->right = upper-> right;

	//node * p = upper-> right;
	p-> parent = upper-> parent;
	upper-> right = p-> left;
	upper-> parent = p;
	p-> left = upper;
	return root;
}

node * right_rotate(node * root, node * upper)
{
	if( upper-> left == NIL)
		return root;
	
	node * p = upper-> left;

	if( root == upper)
		root = upper-> left;
	else if (upper == upper->parent->left)
		upper->parent->left = upper -> left;
	
	else
		upper->parent->right = upper-> left;

	//node * p = upper-> right;
	p-> parent = upper-> parent;
	upper-> left = p-> right;
	upper-> parent = p;
	p-> right = upper;
	return root;
}

node * fix(node * root, node * q)
{
	node * p = NIL;

	while(q->parent->color == 'r')
	{
		if (q->parent == q->parent->parent->left)
		{
			p = q->parent->parent->right;
			if( p->color == 'r')
			{
				p->color = 'b';
				q->parent->color = 'b';
				q->parent->parent->color = 'r';
				q = q->parent->parent;
			}
			else
			{
				if( q= q->parent-> right)
				{
					q = q->parent;
					root = left_r(root,q->parent);
				}
				q->parent->color = 'b';
				q->parent->parent->color = 'r';
				root = right_r(root, q->parent->parent);
			}
		}
		else
		{
			p = q->parent->parent->left;
			if( p->color == 'r')
			{
				p->color = 'b';
				q->parent->color = 'b';
				q->parent->parent->color = 'r';
				q = q->parent->parent;
			}
			else
			{
				if( q= q->parent->left)
				{
					q = q->parent;
					root = right_r(root,q->parent);
				}
				q->parent->color = 'b';
				q->parent->parent->color = 'r';
				root = left_r(root, q->parent->parent);
			}
		}
	}
	//cout<<""<<q->a<<q->color<<p->a<<p->color<<"\n";
	root->color ='b';
	return root;
}

node * insert ( node * root, node * q)
{
	if( root == NIL)
	{	q->color = 'b';
		return q;
	}
	node * tmp = NIL, *p=root;
	while(p!=NIL)
	{
		tmp = p;
		if( p-> a == q->a)
			return root ;

		if(p->a > q->a)
			p = p->left ;
		else
			p = p->right;
	}

	q->parent = tmp;

	if( q->a < tmp->a )
		tmp->left = q;
	else
		tmp->right = q;

	q->color = 'r';
	fix(root,q);
	return root;
}

void print(node* root,int i = 0)
{
    if(root ==NIL)
        return;

    int j=i;

    i++;
    print(root->right,i);
    
    cout<<"\n\n\n";
    while(j--)
        cout<<"\t\t";
    cout<<root->a<<root->color;

    print(root->left ,i);
}

void inorder(node * root)
{
	if( root != NIL)
	{
		inorder ( root->left);
		cout<<root->a<<" ";
		inorder ( root->right);
	}
}

int main()
{
	int n;
	cin>>n;
	int a,i;
	node * root =NIL, *q =NIL;
	NIL->left = NIL-> right = NIL-> parent = NIL;
	NIL->color = 'b';
	for(i=0;i<n;i++)
	{
		q= (node*)malloc(sizeof(node));
		q->left = q->right = q->parent = NIL;		
		cin>>q->a;
		root = insert(root, q);
		print(root);
		cout<<"\n\n\n\n";
	}

	cout<<"\n";
	//inorder(root);
	cout<<"\n";
	print(root);
	cout<<"\n\n\n";
	//root = right_rotate(root,root->left);
	//print(root);
	//cout<<"\n\n\n";

}
