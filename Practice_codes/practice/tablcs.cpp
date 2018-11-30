#include<iostream>
#include<stdlib.h>

using namespace std;

int max(int a, int b)
{
	if( a>b)
		return a;
	else
		return b;
}

void lcs(char a1[], char a2[], int n1, int n2)
{
	int m[n1][n2];

	for(int i=0;i<n1;i++)
		for(int j=0;j<n2;j++)
			m[i][j] = 0;

	for(int j=0;j<n2;j++)
		if( a1[0] == a2[j])
			m[0][j] = 1;

	for(int i=0;i<n1;i++)
		if( a1[i] == a2[0])
			m[i][0] = 1;

	for(int i=1;i<n1;i++)
		for(int j = 1;j<n2;j++)
		{
			if( a1[i] == a2[j])
				m[i][j] = 1 + m[i-1][j-1];
			else
				m[i][j] = max(m[i-1][j], m[i][j-1]);
		}

	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
			cout<<m[i][j]<<" ";

		cout<<"\n";
	}

	cout<<"\n";	
}


int main()
{
	int n1,n2;
	cin>>n1>>n2;

	char a1[n1+2],a2[n2+2];
	cin>>a1>>a2;

	lcs(a1,a2,n1,n2);
}
