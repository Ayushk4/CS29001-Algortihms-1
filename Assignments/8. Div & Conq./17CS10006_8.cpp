//Ayush Kaushal
//17CS10006
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef struct score
{
	int mscore;
	int escore;
}score, *scorelist;

typedef struct set2
{
	int mscore;
	int escore;
	int sect;
}score_2, *scorelist_2;



int dist (score p1, score p2)
{
	return ( abs(p1.mscore - p2.mscore) + abs(p1.escore - p2.escore) );
}

void merge(scorelist t, int low, int mid, int high)
{
	int i= low, j = mid, k=0;
	score tmp[high-low];
	
	while(i<mid &&j< high)
	{
		if(t[i].mscore > t[j].mscore)
		{	tmp[k] = t[j];
			j++;
		}
		else
		{	tmp[k] = t[i];
			i++;
		}
		k++;
	}
	while(i<mid)
	{	tmp[k] = t[i];
		i++;
		k++;
	}
	while(j<high)
	{	tmp[k] = t[j];
		j++;
		k++;
	}
	for(int i=0;i<k;i++)
		t[low+i] = tmp[i];
}
void sort_merge(scorelist t,int low, int high)
{
	if( (high - low) <=1)
		return;
	
	int mid = (low+high)/2;
	sort_merge(t,low,mid);
	sort_merge(t,mid,high);
	merge(t,low,mid,high);	
}





void set_to_min(score *prev_min1, score *prev_min2,score new_1, score new_2)
{
	if( dist(*prev_min1,*prev_min2) < dist (new_1, new_2) )
		return;	
	
	*prev_min1 = new_1;
	*prev_min2 = new_2;
}





void min_base_case(scorelist t, int low, int high, score *score1,score *score2)
{
	int i,j;
	for(i =low;i<high;i++)
		for(j = i+1;j<high;j++)	
			if( dist(t[i],t[j]) < dist(*score1,*score2))
				set_to_min(score1,score2,t[i],t[j]);
}



void border_min(scorelist t, int low, int high, score * score1, score* score2)
{
	score *border= (score*)malloc(sizeof(score) * (high-low) );

	int i,j,k=0, minim = dist(*score1,*score2), mid =(high +low)/2;
	
	for(i =low; i< mid;i++)
	{	if(abs(t[i].mscore- t[mid].mscore)<=minim)
		{	border[k] =t[i];
			k++;
		}
	}

	for(i =mid; i< high;i++)
		if(abs(t[i].mscore- t[mid-1].mscore)<=minim)
		{	border[k] =t[i];
			k++;
		}

	for( i=0;i<k;i++)
		for(j =i+1;j<k;j++)
			if( dist(border[i],border[j]) < dist(*score1,*score2))
				set_to_min(score1,score2,border[i],border[j]);

}

void find_closest(scorelist t, int n,int low, int high, score * score1, score *score2)
{

	if( (high - low) <=1)
		return ;
	if( (high - low) <=2)
	{
		min_base_case(t, low, high ,score1, score2);
		return;
	}

	find_closest(t, n,low, (low+high)/2 ,score1,score2);
	find_closest(t, n,(low+high)/2 ,high, score1,score2);

	border_min(t,low,high,score1,score2);
	
	return;
}
int NearestProfiles(scorelist t, int n, score *score1, score *score2 )
{
	sort_merge(t,0,n); //wrt mscore;
	//for(int i=0;i<n;i++)
	//	cout<<t[i].mscore<<" "<<t[i].escore<<"\n";
	//cout<<"\n\n\n";
	find_closest(t,n,0,n,score1,score2);
}





/*

int dist_2 (score_2 p1, score_2 p2)
{
	return ( abs(p1.mscore - p2.mscore) + abs(p1.escore - p2.escore) );
}

void merge_2(scorelist_2 t, int low, int mid, int high)
{
	int i= low, j = mid, k=0;
	score_2 tmp[high-low];
	
	while(i<mid &&j< high)
	{
		if(t[i].mscore > t[j].mscore)
		{	tmp[k] = t[j];
			j++;
		}
		else
		{	tmp[k] = t[i];
			i++;
		}
		k++;
	}
	while(i<mid)
	{	tmp[k] = t[i];
		i++;
		k++;
	}
	while(j<high)
	{	tmp[k] = t[j];
		j++;
		k++;
	}
	for(int i=0;i<k;i++)
		t[low+i] = tmp[i];
}
void sort_merge_2(scorelist_2 t,int low, int high)
{
	if( (high - low) <=1)
		return;
	
	int mid = (low+high)/2;
	sort_merge_2(t,low,mid);
	sort_merge_2(t,mid,high);
	merge_2(t,low,mid,high);	
}





void set_to_min_2(score_2 *prev_min1, score_2 *prev_min2,score_2 new_1, score_2 new_2)
{
//////////////////////////////Only this line was changed//////////////////
	if(new_1.sect == new_2.sect)
		return;
	if( dist_2(*prev_min1,*prev_min2) < dist (new_1, new_2) )
		return;	
	
	*prev_min1 = new_1;
	*prev_min2 = new_2;
}





void min_base_case_2(scorelist_2 t, int low, int high, score_2 *score1,score_2 *score2)
{
	int i,j;
	for(i =low;i<high;i++)
		for(j = i+1;j<high;j++)	
			if( dist(t[i],t[j]) < dist(*score1,*score2))
				set_to_min(score1,score2,t[i],t[j]);
}



void border_min_2(scorelist_2 t, int low, int high, score_2 * score1, score_2* score2)
{
	score_2 *border= (score_2*)malloc(sizeof(score_2) * (high-low) );

	int i,j,k=0, minim = dist(*score1,*score2), mid =(high +low)/2;
	
	for(i =low; i< mid;i++)
	{	if(abs(t[i].mscore- t[mid].mscore)<=minim)
		{	border[k] =t[i];
			k++;
		}
	}

	for(i =mid; i< high;i++)
		if(abs(t[i].mscore- t[mid-1].mscore)<=minim)
		{	border[k] =t[i];
			k++;
		}

	for( i=0;i<k;i++)
		for(j =i+1;j<k;j++)
			if( dist(border[i],border[j]) < dist(*score1,*score2))
				set_to_min(score1,score2,border[i],border[j]);

}

void find_closest_2(scorelist_2 t, int n,int low, int high, score_2 * score1, score_2 *score2)
{

	if( (high - low) <=1)
		return ;
	if( (high - low) <=2)
	{
		min_base_case_2(t, low, high ,score1, score2);
		return;
	}

	find_closest_2(t, n,low, (low+high)/2 ,score1,score2);
	find_closest_2(t, n,(low+high)/2 ,high, score1,score2);

	border_min_2(t,low,high,score1,score2);
	
	return;
}


int ClusterDist(scorelist section1, int n, scorelist section2, int m, score *score1, score *score2)
{
	scorelist_2 t[n+m];
	int k =0;
	for(int i=0;i<n;i++)
	{
		t[k]->mscore = section1[i].mscore;
		t[k]->escore = section1[i].escore;
		t[k]->sect = 1;
		k++;
	}
	for(int i=0;i<m;i++)
	{
		t[k]->mscore = section2[i].mscore;
		t[k]->escore = section2[i].escore;
		t[k]->sect = 0;
		k++;
	}
	
	sort_merge_2(t,0, n+m);
	scorelist sc1,sc2;
	find_closest_2(t,n+m,0,n+m,&sc1,&sco2);
}

*/
int main()
{
	int n;
	cout<<"Enter the number of students:";
	cin>>n;

	scorelist t;
	t= (scorelist)malloc( n * sizeof(score));
	
	for(int i =0;i<n;i++)
	{
		cout<<"\nEnter the maths and english scores:"; 
		cin>>t[i].mscore>>t[i].escore;
	}
	cout<<"\n\n\n";


	score *score1 =(score*)malloc(sizeof(score));
	score *score2 =(score*)malloc(sizeof(score));
	score1->mscore = 1000;score1->escore = 1000;
	score2->mscore = 2000;score2->escore = 2000;
	
	NearestProfiles(t,n,score1,score2);

	cout<<"\n\nClosest points are "<<score1->mscore<<","<<score1->escore;
	cout<<" and "<<score2->mscore<<","<<score2->escore;
	cout<<"\nDistance = "<<dist(*score1,*score2);
	cout<<"\n";
	free(score1);
	free(score2);
	free(t);
}
