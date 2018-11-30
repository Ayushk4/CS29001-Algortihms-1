#include<iostream>

using namespace std;

struct node 
{
    int a;
    char color;
    node * left, *right , *parent; 
};

node * NIL =(node* ) malloc(sizeof(node));

void print (node * root, int i=0)
{
    if( root!= NIL)
    {
        i++;
        print(root-> right,i);

        int j = i-1;

        while(j--)
            cout<<"\t\t";
        
        cout<<root->a <<root->color<<"\n\n";

        print(root->left, i);
    }
}

node * lrot(node * root,node * q)
{
    if( q-> right ==NIL)
        return root;
    
    node * p = q->right;

    if( root == q)
        root = p;
    else if (q-> parent -> left ==q)
        q->parent -> left =p;
    else
        q->parent->right = p;

    if( p->left !=NIL)
        p->left ->parent = q;

    p-> parent= q->parent;
    q->parent = p;
    q-> right = p-> left;
    p-> left = q;

    return root;
}

node * rrot(node * root,node * q)
{
    if( q-> left == NIL)
        return root;
    
    node * p = q->left;

    if( root == q)
        root = p;
    else if (q-> parent -> left ==q)
        q->parent -> left =p;
    else
        q->parent->right = p;

    if( p->right !=NIL)
        p->right ->parent = q;

    p-> parent= q->parent;
    q->parent = p;
    q-> left = p-> right;
    p-> right = q;

    return root;
}

node * fix( node * root, node* q)
{
    node * y= NIL;
    while( q-> parent->color =='r')
    {
        if( q->parent == q->parent->parent-> left )
        {   
            y = q->parent->parent->right;
            if( y->color == 'r')
            {
                y->color = 'b';
                y->parent->color = 'r';
                q-> parent-> color = 'b';
                q = q->parent->parent;
            }
            else
            {
                if(q->parent-> right == q)
                {
                    q= q->parent;
                    root =lrot(root, q);
                }

                    q->parent->parent->color = 'r';
                    q->parent->color = 'b';
                    root = rrot(root, q->parent->parent);
            }

        }

        else
        {   y = q->parent->parent->left;
            if( y->color == 'r')
            {
                y->color = 'b';
                y->parent->color = 'r';
                q-> parent-> color = 'b';
                q = q->parent->parent;
            }
            else
            {
                if(q->parent-> left == q)
                {
                    q= q->parent;
                    
                    root =rrot(root, q);
                    print(root);
                    cout<<"\n\n\n\n";
                    break;

                }

                    q->parent->parent->color = 'r';
                    q->parent->color = 'b';
                    root = lrot(root, q->parent->parent);
                    cout<<"\n\n\n\n";
                    //
            }

        }
    }
    root->color = 'b';
    return root;
}

node * insert(node* root, node * q)
{
    if( root == NIL)
    {
        q->color = 'b';
        return q;
    }
    node * p= root, * tmp;

    while( p!=NIL)
    {
        tmp = p;
        if( p-> a == q->a)
            return root;

        if( p-> a > q-> a)
            p = p-> left;
        else
            p = p->right;
    }
    
    q-> parent = tmp;

    if( tmp-> a > q->a)
        tmp-> left = q;
    else
        tmp-> right =q;

    q-> color = 'r';
    root = fix(root,q);

    return root;
}

void inorder(node * root)
{
    if( root != NIL)
    {
        inorder( root -> left);
        cout<<root->a<<" ";
        inorder(root->right);
    }
}

int main()
{
    int i,n;
    cin>>n;

    node* root =NIL;
    NIL-> left = NIL->right =NIL-> parent = NIL;
    NIL-> color = 'b';

    for( i=0;i< n;i++)
    {
        node * q = (node * ) malloc(sizeof(node));
        q->left = q-> parent= q-> right = NIL;
        cin>>q->a;

        root = insert(root ,q);
    }

    //inorder(root);
    cout<<"\n\n\n\n";
    print(root);

    //root = rrot(root,root);
  //  cout<<"\n\n\n\n";
//    print(root);
    
}