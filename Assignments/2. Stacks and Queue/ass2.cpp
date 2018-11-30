#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct rm {
	int hInd;
	int vInd;
	} room;

typedef struct node {
	room data;
	struct node *next;
	} *list;
	
//*list;
list maze[20][20];

typedef struct{
	node *head;
}STACK;


void init(STACK *s)//initializes the head pointer
{
	s->head=NULL;
}

int isempty(STACK s)//prints 1 if the stack is empty, 0 otherwise
{
	if(s.head==NULL)
		return 1;
	else
		return 0;
}

void push(STACK *s,room data)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));

	ptr->data.hInd=data.hInd;
	ptr->data.vInd=data.vInd;

	ptr->next = s->head;
	s->head=ptr;
}
void pop(STACK *s)
{
	node *ptr;
	ptr =s->head;
	s->head=s->head->next;
}
void addnode(node **ptr, int i,int j)
{
	
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data.hInd = i;
	tmp->data.vInd = j;
	tmp->next =NULL;
		
	if(*ptr==NULL)
		*ptr=tmp;
	else
	{
		tmp->next = *ptr;
		*ptr = tmp;
		//(*ptr)->next=ptrt; 
	}
}	
void print_room_data(node *room_to_print)
{
	node *ptr = room_to_print;
	while(ptr!=NULL)
	{
		cout<<"-->"<<"("<<ptr->data.hInd<<","<<ptr->data.vInd<<")";
		ptr=ptr->next;
	}
}








void createmaze(list maze[][20], int n, int H[][20], int V[][20])
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	maze[i][j]=NULL;
		
			if (H[i][j]==1)
				addnode( &maze[i][j],i-1,j);
			if (H[i+1][j]==1)
				addnode( &maze[i][j],i+1,j);
			if (V[i][j]==1)
				addnode( &maze[i][j],i,j-1);
			if (V[i][j+1]==1)
				addnode( &maze[i][j],i,j+1);
			
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"\n("<<i<<","<<j<<")"<<"::";
			print_room_data(maze[i][j]);
		}
	}


}
void printmaze(int H[][20],int V[][20], int n)
{	
	int i,j;
	cout<<"\nThe maze looks like:\n";
	cout<<"\n\n";
	for(i=0;i<(2*n)+1;i++)
	{
		if(i%2==0)
		{	for ( j=0;j<2*n+1;j++)
			{	if(j%2==0)
					cout<<"+";
				else
				{
					if(H[i/2][j/2]==0)
						cout<<"-";
					else
						cout<<" ";
				}
			}
		}
		else
		{	
			for ( j=0;j<2*n+1;j++)
			{	if(j%2!=0)
					cout<<" ";
				else
					if(V[i/2][j/2]==0)
						cout<<"|";
					else
						cout<<" ";
			}
		}
	
		cout<<"\n";
	}	

}



int main()
{
	int n;
	
	cout<<"\nEnter the value of n\n";
	cin>>n;

	int i,j,H[20][20],V[20][20];

	cout<<"Enter the horizontal door H\n";
	for(i=0;i<=n;i++)
		for(j=0;j<n;j++)
			cin>>H[i][j];

	cout<<"Enter the vertical doors V\n";
	for(i=0;i<n;i++)
		for(j=0;j<=n;j++)
			cin>>V[i][j];
	j=0;
	
	
	for(j=0;j<n;j++)
	{	H[0][j]=0;
		H[n][j]=0;	
	}


	for(j=0;j<n;j++)
	{	V[j][0]=0;
		V[j][n]=0;	
	}
	
	
	for(i=0;i<=n;i++)
	{cout<<"\n";
		for(j=0;j<n;j++)
			cout<<H[i][j]<< " ";
	}
	cout<<"\n";
	for(i=0;i<n;i++)
	{cout<<"\n";
		for(j=0;j<=n;j++)
			cout<<V[i][j]<< " ";
	}
	

	int s,t,u,v;
	
	cout<<"Enter the indices of the start of room s,t\n";
	cin>>s>>t;
		
	cout<<"Enter the indices of the start of the room\n";
	cin>>u>>v;
	
	printmaze(H,V,n);
	createmaze(maze,n,H,V);
	cout<<"\n";
	STACK S;
	init(&S);
	
	
	
}
