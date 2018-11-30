#include<iostream>

using namespace std;

struct node
{
    int a;
    char color;
    node * left, * right, * parent;
};

node * NIL = ( node*)malloc( sizeof(node));

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

node * l_rot( node* root, node *q)
{
    node * p = q-> right;
    if( p == NIL)
        return root ;

    if( p-> left != NIL)
        p-> left -> parent = q;

    if( root == q)
        root =p;
    else if( q->parent -> left ==q)
        q->parent-> left = p;
    else
        q->parent-> right = p;

    p-> parent = q->parent;
    q-> right = p-> left;
    p-> left = q;
    q-> parent = p;

    return root;
}

node * r_rot( node* root, node *q)
{
    node * p = q-> left;
    if( p == NIL)
        return root ;

    if( p-> right != NIL)
        p-> right -> parent = q;

    if( root == q)
        root =p;
    else if( q->parent-> left ==q)
        q->parent-> left = p;
    else
        q->parent-> right = p;

    p-> parent = q->parent;
    q-> left  = p-> right;
    p-> right = q;
    q-> parent = p;

    return root;
}

node* fix(node* root, node* q)
{
    node *y= NIL;
    while ( q->parent->color == 'r')
    {
        if( q-> parent == q-> parent ->parent->left)
        {
            y = q-> parent->parent->right;
            if( y-> color == 'r')
            {
                y->color ='b';
                q->parent->color = 'b';
                y-> parent->color = 'r';
                q = q->parent->parent;
            }
            else
            {
                if( q-> parent -> right == q)
                {
                    q = q-> parent;
                    root = l_rot(root,q);
                }
                    q->parent->color = 'b';
                    q->parent->parent->color = 'r';
                    root = r_rot(root, q->parent->parent);
                    //q = q-> parent-
            }
        }
        else
        {
            y = q-> parent->parent->left;
            if( y-> color == 'r')
            {
                y->color ='b';
                q->parent->color = 'b';
                y-> parent->color = 'r';
                q = q->parent->parent;
            }
            else
            {
                if( q-> parent -> left == q)
                {
                    q = q-> parent;
                    print(root);
                    root = r_rot(root,q);
                        
                    cout<<"\n\n\n";
                break;
                }
                    q->parent->color = 'b';
                    q->parent->parent->color = 'r';
                    root = l_rot(root, q->parent->parent);
            
            }
        }
    }
    
    root-> color = 'b';
    return root;
}

node * insert( node* root, node* q)
{
    if(root ==NIL)
    {
        q->color = 'b';
        return q;
    }
    node * tmp, *p = root;

    while( p!=NIL)
    {
        tmp = p;
        if(p-> a == q->a)
            return root;

        if( p->a >q->a)
            p = p-> left;
        else
            p = p-> right;
    }

    q-> parent = tmp;

    if( tmp-> a > q-> a)
        tmp-> left = q;
    else
        tmp-> right = q;

    q-> color  = 'r';

    //print(root);
    //cout<<"\n\nasdfg\n";

    root = fix(root, q);
    return root;
}

void inorder ( node  *root)
{
    if( root !=NIL)
    {
        inorder(root->left);
        cout<<root-> a <<" ";
        inorder(root-> right);
    }
}

int main()
{
    int n;
    cin>>n;
    node *root =NIL;
    NIL-> left = NIL-> right = NIL -> parent = NIL;
    NIL-> color ='b';
    node *q;
    for(int i =0 ;i<n ;i++)
    {
        q = (node* )malloc(sizeof(node));
        q-> left =q->right =q-> parent =NIL;

        cin>>q->a;
        root = insert(root,q);
        //print(root);
        //cout<<"\n\n\n\n\n";
    }

    //inorder(root);
    cout<<"\n";
    //print(root);
    cout<<"\n\n\n";
}