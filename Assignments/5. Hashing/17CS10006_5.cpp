//Name - Ayush Kaushal
//Roll number - 17CS10006

#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef struct _wordR { 
  char word[100]; 
  double x, y; 
} wordR, worddata;
 
typedef struct _node{ 
  wordR w; 
  struct _node *next; 
} node, *nodePointer, nodeptr; 

typedef nodePointer **hashTable; 

int hash(int m,double x)
{
	return (floor(m*x));
}



int inbounds(int m, int i, int j)
{
	if( i>=0 && i <m && j< m && j>=0)
		return 1;
	
	return 0;
}

double eucdist ( worddata w, worddata in)
{
	return ( sqrt((w.x - in.x)*(w.x - in.x) +(w.y - in.y)* (w.y - in.y)));
}


node * findclosenode(wordR w, node * ptr, node * min)
{
	while(ptr!=NULL)
	{
		if(strcmp(ptr->w.word,w.word) == 0)
		{
			//cout<<w.word<<" "<<ptr->w.word<<"\n";
		}
		else
		{	if( min ==NULL)
				min = ptr;
			
			else
				if( eucdist(w, ptr->w) < eucdist(min->w, w))
					min = ptr;
		}
		
		ptr = ptr->next;
	}
	return min;

}

void findNN (hashTable H, int m, wordR w)
{
	int i, j, r = 0;
	i = hash(m,w.x);
	j = hash(m,w.y);

	node *ptr = NULL, * min = NULL;
	
	for( r =0;r< m;r++)
	{
		//top row
		for ( int k = -1 *r; k<=r;k++)
		{
			if( inbounds(m, i + k,j + r))
			{
				ptr =H[i + k][j + r];
				min = findclosenode(w, ptr, min);
			}
		}

		//bottom row
		for ( int k = -1*r; k<=r;k++)
		{
			if( inbounds(m, i + k,j - r))
			{
				ptr =H[i + k][j - r];
				min = findclosenode(w, ptr, min);
			}
		}
		
		//right row
		for ( int k = -1 *r + 1; k<r;k++)
		{
			if( inbounds(m, i + r,j + k))
			{
				ptr = H[i + r][j + k];
				min = findclosenode(w, ptr, min);
			}
		}
		
		//left row
		for ( int k = -1 *r + 1; k<r;k++)
		{
			if( inbounds(m, i - r,j + k))
			{
				ptr =H[i - r][j + k];
				min = findclosenode(w, ptr, min);
			}
		}
		
		if (min !=NULL)
			break;
	}


	//Step 3:
	int radius = ceil(eucdist(w, min->w));

	//Check the top part	
	for( int k = i - radius; k <= i - r ; k++)
	{	if(k>=0 &&k<m)
		{	for(int l = j - radius; l <=radius +j; l++)
			{	if(inbounds(m, k, l))
				{	ptr =H[k][l];
					min = findclosenode(w, ptr, min);
				}
			}
		}
	}
	//Check the bottom part	
	for( int k = i + r; k <= i + radius ; k++)
	{	if(k>=0 &&k<m)
		{	for(int l = j - radius; l <=radius +j; l++)
			{	if(inbounds(m, k, l))
				{	ptr =H[k][l];
					min = findclosenode(w, ptr, min);
				}
			}
		}
	}


	//Check the left part	
	for( int l = j - radius; l <= j - r ; l++)
	{	if(l>=0 &&l<m)
		{	for(int k = i -radius; k <=radius +i; k++)
			{	if(inbounds(m, k, l))
				{	ptr =H[k][l];
					min = findclosenode(w, ptr, min);
				}
			}
		}
	}


	//Check the right part	
	for( int l = j + r; l <= j + radius ; l++)
	{	if(l>=0 &&l<m)
		{	for(int k = i -radius; k <=radius +i; k++)
			{	if(inbounds(m, k, l))
				{	ptr =H[k][l];
					min = findclosenode(w, ptr, min);
				}
			}
		}
	}
	cout<<"\nThe correct result is ("<<min->w.word<< ","<<min->w.x<< ", "<<w.y<<")\n";
}








void insertH(hashTable H, int m, wordR w)
{
	int i,j;
	i = hash(m,w.x);
	j = hash(m,w.y);
	
	node *ptr = (node * )malloc(sizeof(node));
	ptr->w = w;
	ptr->next = H[i][j];
	H[i][j] = ptr;
}
void printH(hashTable H, int m, ofstream * fout)
{
	int i,j;
	node * ptr = NULL;

	for(i=0;i<m;i++)
	{
		
		for(j = 0;j <m;j++)
		{
			*fout<<"["<<i<<","<<j<<"]::(";
			
			ptr = H[i][j];
			while(ptr!=NULL)
			{	*fout<<ptr->w.word<<" ";
				ptr = ptr->next;
			}
			*fout<<")\n";
		}
	}
}
void outputhash(hashTable H, int m, int n)
{
	ofstream fout;
	fout.open("output.txt",ios::out);
	printH(H, m, &fout);
}


int main()
{
	int n;
	ifstream fin;
	fin.open("input.txt",ios::in);
	if (!fin) {
		cout<< "Error openingin input file input.txt\n"; 
		return -1; 
	} 
	fin>>n;	
	cout<<"Number of words to be inserted in the hashtable are "<<n<<"\n";
	
	int m = ceil(sqrt(n));
	cout<<"Size of the hashtable is : " <<m<<" X "<<m<<"\n";
	
	int i, j; 
	hashTable H; 
	H = (nodePointer **)malloc(m * sizeof(nodePointer *));
	for (i=0; i<m; i++) { 
		H[i] = (nodePointer *)malloc(m * sizeof(nodePointer)); 
		
		for (j=0; j<m; ++j) 
			H[i][j] = NULL; 
	}
	
	//Insert into hash table
	worddata w;
	
	for(i = 0;i< n; i++)
	{	fin>>w.word>>w.x>>w.y;
		insertH(H,m,w);
	}
	cout<<"Finished inserting the elements in the hashtable\n";

	
	outputhash(H,m,n);
	cout<<"Finished printing the elements in the hashtable\n";
	
	
	int numberofquery;
	cout<<"Enter the number of words to search : ";
	cin>>numberofquery;

	cout<<"\n";
	for( i=0;i<numberofquery;i++)
	{
		cout<<"\nEnter the word tuple "<<i+1<<" : ";
		cin>>w.word>>w.x>>w.y;

		findNN(H,m,w);
	}
	
}
