#include<iostream>

using namespace std;

struct node{
    int a;
    char color;
    node *left, *right, *parent;
};

node * NIL =(node* )malloc(sizeof(node));



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


node * l_rotate(node * root, node *q)
{
    if( q-> right == NIL)
        return root;

    if( root == q)
        root = q-> right;
    
    node * p = q-> right;

    if( q-> parent-> a > q->a)
        q->parent ->left = p;
    else
        q-> parent->right = p;
    if( p->left!=NIL)
        p->left-> parent = q;

    q-> right = p-> left ;

    p-> left = q;
    p-> parent = q-> parent;
    q-> parent = p; 
    return root;
}

node * r_rotate(node * root, node *q)
{
    if( q-> left == NIL)
        return root;

    if( root == q)
        root = q-> left;
    
    node * p = q-> left;

    if( q-> parent-> a > q->a)
        q->parent ->left = p;
    else
        q-> parent->right = p;

    if( p->right!=NIL)
        p->right-> parent = q;

    q-> left = p-> right ;

    p-> right = q;
    p-> parent = q-> parent;
    q-> parent = p; 
    return root;
}

node * fix(node* root, node * q)
{
    node * p;
    while(q->parent->color =='r')
    {
        if(q->parent->parent-> left == q-> parent)
        {
            p = q->parent->parent->right;
            if( p->color == 'r')
            {
                p-> color = 'b';
                p-> parent-> color = 'r';
                q-> parent-> color = 'b';
                q = q-> parent-> parent;
            }
            else
            {
                if( q-> parent-> right == q)
                {
                    q = q-> parent;
                    root = l_rotate(root,q);
                }

                q->parent->color = 'b';
                q->parent->parent->color = 'r';
                root = r_rotate(root,q->parent->parent);
                q = q-> parent-> parent;
            }
        }

        else
        {
            p = q->parent->parent->left;
            if( p->color == 'r')
            {
                p-> color = 'b';
                p-> parent-> color = 'r';
                q-> parent-> color = 'b';
                q = q-> parent-> parent;
            }
            else
            {
                if( q-> parent-> left == q)
                {
                    q = q-> parent;
                    root = r_rotate(root,q);
                }

                q->parent->color = 'b';
                q->parent->parent->color = 'r';
                root = l_rotate(root,q->parent->parent);
                q = q-> parent-> parent;
            }
        
        }
    }
    root->color = 'b';
    return root;
}

node  * insert( node* root, node* q)
{
    if(root == NIL)
    {
        q->color = 'b';
        return q;
    }

    node *tmp, *p =root;

    while( p!=NIL)
    {
        tmp = p;
        if( p->a == q->a)
            return root;

        if(p->a > q->a)
            p = p->left;
        else
            p = p-> right;
    }
    q-> parent = tmp;

    if( tmp->a > q-> a)
        tmp-> left = q;
    else
        tmp->right = q;

    q-> color = 'r';
    //print(root);
	//cout<<"\n\n\n";
    root =fix(root,q);
    return root;
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
    node * root = NIL;
    NIL->left = NIL->right = NIL-> parent = NIL;
    NIL->color = 'b';

    for(int i = 0;i<n;i++)
    {
        node *q = (node*)malloc(sizeof(node));
        q->left = q->right = q->parent = NIL;
        cin >> q->a;

        root = insert( root,q);
        //print(root);
	    //cout<<"\n\na\n\n";
    }

	cout<<"\n";
	inorder(root);
	cout<<"\n";
	print(root);
	cout<<"\n\n\n";
    //root = l_rotate(root,root);    root = l_rotate(root,root);    root = r_rotate(root,root);
    //print(root);
	//cout<<"\n\n\n";


}