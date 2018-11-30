#include<iostream>
#include<stdlib.h>

using namespace std;

int max(int a,int b)
{
	if( a>b)
		return a;
	else
		return b;
}

int lcs(char a1[], char a2[], int i, int j, int m[][10000], int p[][10000])
{
	if(i<0)
		return 0;
	if(j<0)
		return 0;
	if(m[i][j] != -1)
		return m[i][j];

	if( a1[i] == a2[j])
	{
		m[i][j] = 1 + lcs(a1,a2,i-1,j-1,m,p);
		p[i][j] = 0;
	}
	else
	{	int up = lcs(a1,a2,i-1,j,m,p), left =lcs(a1,a2,i,j-1,m,p);
		if (up>left)
		{
			m[i][j] = up;
			p[i][j] = 1;
		}
		else
		{
			m[i][j] = left;
			p[i][j] = -1;
		}
	}

	return m[i][j];
}

int main()
{
    int n1,n2;
    cin>>n1>>n2;

    char a1[n1+2], a2[n2+2];
    cin>>a1>>a2;

    int m[n1+1][10000], p[n1+1][10000] ;
    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++)
	{    
		m[i][j] = -1;
		p[i][j] = -2;
	}
    cout<<lcs(a1,a2,n1-1,n2-1,m,p)<<"\n";

/*    for(int i=0;i<n1;i++)
	{    
		for(int j=0;j<n2;j++)
			cout<<m[i][j]<<"\t";
		cout<<"\n";
	}
cout<<"\n\n";
    for(int i=0;i<n1;i++)
	{    
		for(int j=0;j<n2;j++)
			cout<<p[i][j]<<"\t";
		cout<<"\n";
	}
*/

	int i= n1-1, j =n2 -1;

	while(i >=0 && j>=0)
	{
		if( p[i][j] == -1)
			j--;
		else if ( p[i][j] == 1)
			i--;
		else if ( p[i][j] == 0)
		{
			cout<<a1[i];
			i--;
			j--;
		}
		else
			cout<<"nnmknnjkjnjknkk";			
	}
}



























