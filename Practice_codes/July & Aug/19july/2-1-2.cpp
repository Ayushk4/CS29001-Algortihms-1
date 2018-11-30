#include <iostream>

using namespace std;

int main()
{
	int a[10],n;
	for(int i=0;i<10;i++)
		a[i]= 100 -(2*i);

	for(int i=8;i>=0;i--)
	{
		n=a[i];
		int j = i+1;
		while( j<=9 && a[j]<n)
		{
			a[j-1]=a[j];
			j++;
		}

		a[j-1]=n;
	}

	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";

}
