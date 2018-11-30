#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct treenode
{
	char word[100];
	struct treenode *leftchild;
	struct treenode *rightchild;
	struct treenode *parent;
}NODE, *NODEPTR, node;

NODEPTR insert(NODEPTR ptr)
{
	char w[100];
	cout<<"\nEnter a word:";
	cin>>w;
	
 	
	if(ptr==NULL)
	{
		ptr = (NODE *) malloc( sizeof(NODE));
		strcpy (ptr->word, w);
		ptr->leftchild =NULL;
		ptr->rightchild = NULL;
		ptr->parent = NULL;
		//cout<<ptr->word;
		return ptr;
	}

	NODEPTR q = (NODE *) malloc( sizeof(NODE)),tmp=NULL, root = ptr;
	strcpy (q->word, w);
	q->leftchild =NULL;
	q->rightchild = NULL;
	q->parent =NULL;

	while(ptr!=NULL)
	{
		tmp = ptr;
		//cout<<"e";
		if(strcmp(ptr->word,w)>0)
			ptr=ptr->leftchild;
		else
			if( strcmp(ptr->word,w)<0)
			ptr=ptr->rightchild;
		
		else
			return root;
	}
	
	ptr= q;
	ptr->parent = tmp;
	//cout<<ptr->word;
	if(strcmp(tmp->word, w)>0)
		tmp->leftchild = ptr;
	else
		tmp->rightchild =ptr;

	return root;
}
	
void inorder(NODEPTR node)
{
	if(node==NULL)
		return;
	
	inorder(node->leftchild);
	cout<<node->word<<" ";
	inorder(node->rightchild);
}
	

int main()
{
	int n;
	cout<<"Enter the number of words: ";
	cin>>n;
	NODEPTR root=NULL;

	//cout<<strcmp("zdgew\0","rege\0");
	
	for(int i=0;i<n;i++)
		root = insert(root);
		
	cout<<"\n\nInorder travelsal:\n";
	inorder(root);
}
	
	
