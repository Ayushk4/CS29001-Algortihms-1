#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
    int val;
    char color;
    node * right, * left, * parent;
};

node *NIL = new node;


node * left_rot(node * root, node * N)
{
	node * q = N;
	node * p = q-> right;
	
	if(q-> right ==NIL)
		return root;
	
	if(p->left!= NIL)
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

node * right_rot(node * root, node * N)
{
	node * q = N;
	node * p = q-> left;
	
	if(q-> left ==NIL)
		return root;
	
	if(p->right!= NIL)
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


node * fix(node *root, node *q)
{
    node * ptr= q;
    cout<<"a\n";
    while(ptr->parent->color == 'r')
    {            cout<<"a\n";
        if( ptr->parent->parent->left == ptr->parent)
        {
            node * y = ptr->parent->parent->right;
            if( y->color == 'r')
            {
                y->color = 'b';
                ptr->parent->color = 'b';
                ptr->parent->parent->color = 'r';
                ptr = ptr->parent->parent;
            }
            else
            {
                if(ptr->parent->right == ptr)
                {
                    ptr = ptr->parent;
                    root = left_rot(root,ptr);
                }
                ptr->parent->parent->color = 'r';
                ptr->parent->color = 'b';
                root = right_rot(root,ptr->parent->parent);
            }
            cout<<"a\n";
        }
        else
        {
            node * y = ptr->parent->parent->left;
            if( y->color == 'r')
            {
                y->color = 'b';
                ptr->parent->color = 'b';
                ptr->parent->parent->color = 'r';
                ptr = ptr->parent->parent;
            }
            else
            {
                if(ptr->parent->left == ptr)
                {
                    ptr = ptr->parent;
                    root = right_rot(root,ptr);
                }
                ptr->parent->parent->color = 'r';
                ptr->parent->color = 'b';
                root = left_rot(root,ptr->parent->parent);
            }
        }
        break;
    }
    if(root->color == 'r')
        root->color = 'b';
    return root;
}

node * insert(node *root, int val)
{
    node * newptr = new node;
    newptr->left = newptr->right = newptr->parent = NIL;
    newptr->val = val;
    newptr->color = 'r';

    if (root == NIL)
    {
        newptr->color = 'b';
        return newptr;
    }

    node *prev = NIL, * ptr = root;

    while(ptr!= NIL)
    {
        prev = ptr;
        if( ptr->val > val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if(prev->val > val)
        prev->left = newptr;
    else
        prev->right = newptr;

    newptr->parent = prev;
    
    root = fix(root, newptr);
    return root;
}

/*
node * minim(node * q)
{
    node * ptr = q, * prev = NIL;

    while(ptr!= NIL)
    {
        prev = ptr;
        ptr = ptr->right;
    }

    return prev;
}

node * succ( node * q)
{
    node * ptr = q;

    if( ptr->right != NIL)
        return (minim (ptr->right));
    
    while(ptr->parent!= NIL)
    {   if(ptr->parent->left == ptr)
            return ptr->parent;
        ptr = ptr->parent;
    }   

    return NULL;
}
*/

void inorder(node * root, int i=0)
{
    if( root == NIL)
        return;
    i++;

    inorder( root->right,i);

    for(int j=1;j<i;j++)
        cout<<"\t";

    cout<<root->val<<root->color<<"\n\n";

    inorder( root->left,i);
}

int main()
{
    NIL->parent = NIL->left = NIL->right = NIL;
    NIL->color = 'b';
    NIL->val = 0;

    int n;
    cin>>n;

    node * root = NIL;

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        root = insert(root,val);
        inorder(root);
        cout<<"\n\n\n\n";
    }

    
}