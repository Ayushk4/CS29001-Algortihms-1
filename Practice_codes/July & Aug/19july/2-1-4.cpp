#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the size :";
	cin>>n;

	int a[n],b[n],c[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];

	int carry=0;
	for(int i=n;i>0;i--)
	{	
		c[i]=carry;
		carry=(c[i] + a[i-1]+b[i-1])/2;
		cout << carry <<" ";

		c[i]=(c[i]+a[i-1]+b[i-1])%2;
	}

	c[0]=carry;
	cout<<"\n\n\n";

	for(int i=0;i<n+1;i++)
		cout<<c[i]<< " ";
}
