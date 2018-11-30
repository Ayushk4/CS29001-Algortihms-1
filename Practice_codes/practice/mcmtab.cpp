#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
	int l,r;
};


int mcm(node a[], int n)
{

	int **m = new int*[n];

	for (int i=0;i<n;i++)
		m[i] = new int[n];

	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			m[i][j] = 0;

/*	if( i<0||j<0)
		return 0;
	if( j<=i)
		return	0; 
	if(m[i][j]>0)
		return m[i][j];
*/

	for (int len = 1; len<=(n-1);len++)
	{	for(int i=0;i<(n-len);i++)
		{
			int j=i+len;
			m[i][j] =100000000;
			for(int k=i;k<j;k++)
			{
				int call = m[i][k] + m[k+1][i+len] + a[i].l * a[k].r * a[i + len].r;
				if (call < m[i][i+len])
					m[i][i+len] = call;		
			}


		}
	}

	for (int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
			cout<<m[i][j]<<"\t";
		cout<<"\n";
	}		

	return m[0][n-1];
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

	cout<<mcm(a,n)<<"\n";

}

