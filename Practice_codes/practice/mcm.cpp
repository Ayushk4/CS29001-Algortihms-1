#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
	int l,r;
};


int mcm(node a[], int i, int j, int **m)
{
	if( i<0||j<0)
		return 0;
	if( j<=i)
		return	0; 
	if(m[i][j]>0)
		return m[i][j];

	m[i][j] = mcm(a,i,i,m) + mcm(a,i+1,j,m) + a[i].l * a[i].r * a[j].r;

	for(int l=i+1;l<j;l++)
	{
		int call = mcm(a,i,l,m) + mcm(a,l+1,j,m) + a[i].l * a[l].r * a[j].r;
		if( call<m[i][j])
			m[i][j] = call;
	}
	
	return m[i][j];
}

int main()
{
	int n;
	cin>>n;
	
	node *a = new node[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i].l>>a[i].r;

	for(int i=0;i<n;i++)
		cout<<a[i].l<<" "<<a[i].r<<"\n";

	int **m = new int*[n];
	for (int i=0;i<n;i++)
		m[i] = new int[n];

	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			m[i][j] = 0;

	cout<<mcm(a,0,n-1,m)<<"\n";

	for (int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
			cout<<m[i][j]<<"\t";
		cout<<"\n";
	}		
}
