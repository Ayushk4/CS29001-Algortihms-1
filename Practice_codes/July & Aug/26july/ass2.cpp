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

typedef struct {
node *front, *rear ;
} QUEUE ;

void init(QUEUE *qp)
{
	qp->front = NULL;
	qp->rear = NULL;
}

int isempty(QUEUE qp)
{
	if(qp.front==NULL)
		return 1;
	return 0;
}

void enqueue(QUEUE *qp, room data)
{
	if(qp->front==NULL)
	{
		qp->front = (node*)malloc(sizeof(node));
		qp->front->data.hInd=data.hInd;
		qp->front->data.vInd=data.vInd;
		qp->rear = qp->front;
		//return;	
	}

	else
	{
		node* tmp = (node*)malloc(sizeof(node));
		tmp->data.hInd = data.hInd;
		tmp->data.vInd = data.vInd;
		tmp->next = NULL;
		qp->rear->next = tmp;
		qp->rear = tmp;
	}	
}

room dequeue(QUEUE *qp)
{
	node *tmp=(node*)malloc(sizeof(node));

	tmp = qp->front;
	room data;
	data.hInd=tmp->data.hInd;
	data.vInd=tmp->data.vInd;
	if(qp->front==qp->rear)
		qp->rear=NULL;
	
	qp->front = qp->front->next;
	
	free(tmp);
	return (data);
}

int strategy2(list maze[][20], int n, room start, room end)
{
	QUEUE qu;
	int a[20][20];
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			a[i][j] = 0;

	node *ptr;
	room now;
	now.hInd=start.hInd;
	now.vInd=start.vInd;
	init(&qu);
	
	enqueue(&qu,now);

	while(!isempty(qu))
	{
		
		ptr = maze[qu.front->data.hInd][qu.front->data.vInd];
		
		while(ptr!=NULL)
		{
			if(a[ptr->data.hInd][ptr->data.vInd] ==0)
			{
				enqueue(&qu,ptr->data);
				a[ptr->data.hInd][ptr->data.vInd] =1;			
			}
			ptr=ptr->next;
		}
		//cout<<qu.front->data.hInd<<" "<<qu.front->data.vInd<<"\n";
		if(qu.front->data.hInd==end.hInd && qu.front->data.vInd==end.vInd)
			return 1;
		
		dequeue(&qu);
	}
	
	return 0;
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
	room start,end;
	start.hInd = s;
	start.vInd = t;
	end.hInd = u;
	end.vInd = v;

	printmaze(H,V,n);
	createmaze(maze,n,H,V);
	cout<<"\n";
	int r2=strategy2(maze, n, start, end);
	if(r2==1)
		cout<<"A path is found using strategy 2 from ("<<start.hInd<<","<<start.vInd<<") to ("<<end.hInd<<","<<end.vInd<<")\n";
	else
		cout<<"No path using strategy 2";	
}
