//Ayush Kaushal
//17CS10006

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_SIZE 100 
typedef struct _job { 
	int jobid; 
	int starttime; 
	int joblength;
	int remlength; 
} job;

typedef struct _heap { 
	job list[MAX_SIZE]; 
	int numjobs; 
    int index[MAX_SIZE];
} heap, newheap;

typedef struct _jobPair {
	int jobid_from;
	int jobid_to;
} jobpair;

void initHeap(heap *H)
{
	H->numjobs = 1;	
//    for(int i =0;i<100;i++)
//        H->index[i] = -1;
}

void sift_up(heap *H,int i)
{
	int big_valindex = i;
    H->index[H->list[i].jobid] = i;
	if( (i>1) && (H->list[i/2].remlength >H->list[i].remlength)) 
		big_valindex = i/2;
	
	if (big_valindex == i)
	{	if(i>1)
		{	if(H->list[i/2].remlength == H->list[i].remlength)
				if( H->list[i/2].jobid > H->list[i].jobid)
					big_valindex = i/2;
		
		}
	}

	if (big_valindex == i)
        return;
	job tmp = H->list[i];
	H->list[i] = H->list[big_valindex];
	H->list[big_valindex]  = tmp;
    H->index[H->list[i].jobid] = i;
    H->index[H->list[big_valindex].jobid] = big_valindex;
	
	sift_up(H,big_valindex);
}

void insertJob(heap *H, job j)
{
	H->list[H->numjobs] = j;
	H->list[H->numjobs].remlength = H->list[H->numjobs].joblength;

	sift_up(H,H->numjobs);
	H->numjobs++;
}

void sift_down(heap *H,int i)
{
	int small_ind = i;
	int n =H->numjobs;
    H->index[H->list[i].jobid] = i;

	if( (2*i <n) &&( (H->list[2*i].remlength<H->list[small_ind].remlength)|| ( (H->list[2*i].remlength==H->list[small_ind].remlength) && (H->list[2*i].jobid < H->list[small_ind].jobid))))
		small_ind = 2*i;
	if( (2*i+1 <n) &&( (H->list[2*i+1].remlength < H->list[small_ind].remlength)|| ( (H->list[2*i+1].remlength==H->list[small_ind].remlength) && (H->list[2*i+1].jobid < H->list[small_ind].jobid))))
		small_ind = 2*i+1;
	
	if(small_ind == i)
		return;

	job tmp = H->list[i];
	H->list[i] = H->list[small_ind];
	H->list[small_ind]  = tmp;
    H->index[H->list[i].jobid] = i;
    H->index[H->list[small_ind].jobid] = small_ind;

	sift_down(H,small_ind);

}

int extractMinJob(heap *H, job *j)
{
	if(H->numjobs <1)
	{	
		return -1;
	}
	*j = H->list[1];
    int job_Id = j->jobid;

	H->list[1] = H->list[H->numjobs-1];
	H->numjobs--;

	sift_down(H,1);
    H->index[job_Id] = 0;

    return 0;
}


void mergearr(job a[], int l, int mid, int h)
{
	int i = l, j = mid, p =0;
	job tmp[h-l+1];
	while( (i < mid) && (j < h))
	{
		if( a[i].starttime < a[j].starttime)
		{	tmp[p] = a[i];
			i++;
		}

		else
		{	tmp[p] = a[j];
			j++;
		}
		p++;
	} 
	while( i<mid)
	{
		tmp[p] = a[i];
		p++;
		i++;
	}
	while( j<h)
	{
		tmp[p] = a[j];
		p++;
		j++;
	}
	for(int i =0 ;i<p;i++)
		a[i+l] = tmp[i];
}
void sortarr(job a[],int l, int h)
{
	if( (h-l)<=1)
		return;
	
	int mid = l+h;
	mid= mid/2;
	
	sortarr(a,l,mid);
	sortarr(a,mid,h);

	mergearr(a,l,mid,h);
}

void decreaseKey(newheap *H, int jid)
{
    if(H->index[jid] >0)
        if( H->list[H->index[jid]].remlength == H->list[H->index[jid]].joblength)
        {
            H->list[H->index[jid]].remlength = (H->list[H->index[jid]].remlength) / 2;
			H->list[H->index[jid]].joblength = (H->list[H->index[jid]].joblength) / 2;

            sift_up(H,H->index[jid]);
        }
}

int del_key(newheap *H, jobpair jpair[], int m, job *j, job joblist[], int index_in_array[])
{
    int job_id = H->list[1].jobid;
    int ii = extractMinJob(H,j);
	
    for(int i=0;i<m;i++)
    {
        if(jpair[i].jobid_from == job_id)
        {   decreaseKey(H,jpair[i].jobid_to);
			joblist[index_in_array[H,jpair[i].jobid_to]].joblength/=2;
			joblist[index_in_array[H,jpair[i].jobid_to]].remlength/=2;
		}
	}
    return ii;
}




void newscheduler(job jobList[], int n, jobpair pairList[], int m) 
{
	heap *h;
	h = (heap*)malloc(sizeof(heap));
	initHeap(h);
	int index_in_array[MAX_SIZE];

	for(int i=0;i<n;i++)
		index_in_array[jobList[i].jobid] = i;


	int jobindex=0, maxtime = jobList[n-1].starttime, time =0, turnaround = 0;
	job j;
	cout<<"Jobs schedules at each timestep are: \n";



	while(time<=maxtime)
	{
		while(jobList[jobindex].starttime == time)
		{
			insertJob(h,jobList[jobindex]);
			jobindex++;
		}

		if( h->numjobs== 1)
			cout<<" 0 ";
		else
		{
			while(h->numjobs>1 && h->list[1].remlength == 0)
				del_key(h,pairList,m,&j,jobList,index_in_array);

			if(h->list[1].remlength == h->list[1].joblength)
				turnaround += time - h->list[1].starttime;

			cout<<" "<<h->list[1].jobid<<" ";
			h->list[1].remlength = h->list[1].remlength-1;

			while(h->numjobs>1 && h->list[1].remlength == 0)
				del_key(h,pairList,m,&j,jobList,index_in_array);
		}

		time++;
	}
	
	while(h->numjobs>1)
	{
		while(h->numjobs>1 && h->list[1].remlength == 0)
            del_key(h,pairList,m,&j,jobList,index_in_array);
		
		if(h->list[1].remlength == h->list[1].joblength)
			turnaround += time - h->list[1].starttime;
			
		cout<<" "<<h->list[1].jobid<<" ";
		h->list[1].remlength = h->list[1].remlength-1;
			
		while(h->numjobs>1 && h->list[1].remlength == 0 )
            del_key(h,pairList,m,&j,jobList,index_in_array);

		time++;
	}
	
	double turnaround_avg = float(turnaround)/float(n);
	cout<<"\nAverage Turnaround Time is : "<<turnaround_avg<<"\n";
	free(h);
}




int main()
{
	cout<<"Enter the number of jobs: \n";
	int n;
	cin>>n;

	cout<<"Enter the jobs: \n";
	job *arr;
	arr= (job *)malloc(n* sizeof(job));
	for(int i=0;i<n;i++)
	{	cin>>arr[i].jobid>>arr[i].starttime>>arr[i].joblength;
		arr[i].remlength = arr[i].joblength;
	}
    sortarr(arr,0,n);

	int m;
	cin>>m;

	jobpair *arr_pair;
	arr_pair = (jobpair *)malloc(sizeof(jobpair)*m);
	for(int i=0; i<m;i++)
		cin>>arr_pair[i].jobid_from>>arr_pair[i].jobid_to;



	newscheduler(arr,n,arr_pair,m);


    free(arr_pair);
	free(arr);

}
/*
	job j;
	
	cout<<"\n\n\n\n";
	for(int jj=0;jj<n;jj++)
	{		
		 cout<<extractMinJob(h,&j)<<" ::: \n";

		cout<<j.jobid<<" "<<j.starttime<<" "<<j.joblength<<" "<<j.remlength;

	cout<<"\n";
	}	




	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<arr[i].jobid<<" "<<arr[i].starttime<<" "<<arr[i].joblength;
	}
	


void sift_down(heap *H,int i)
{
	int small_ind = i;
	int n =H->numjobs;

	if( (2*i <n) &&( (H->list[2*i].remlength<H->list[small_ind].remlength)|| ( (H->list[2*i].remlength==H->list[small_ind].remlength) && (H->list[2*i].jobid < H->list[small_ind].jobid))))
		small_ind = 2*i;
	if( (2*i+1 <n) &&( (H->list[2*i+1].remlength < H->list[small_ind].remlength)|| ( (H->list[2*i+1].remlength==H->list[small_ind].remlength) && (H->list[2*i+1].jobid < H->list[small_ind].jobid))))
		small_ind = 2*i+1;
	
	if(small_ind == i)
		return;

	job tmp = H->list[i];
	H->list[i] = H->list[small_ind];
	H->list[small_ind]  = tmp;
	
	sift_down(H,small_ind);

}

int extractMinJob(heap *H, job *j)
{
	if(H->numjobs <1)
	{	
		return -1;
	}
	*j = H->list[1];
	
	H->list[1] = H->list[H->numjobs-1];
	H->numjobs--;
	
	sift_down(H,1);
	
	return 0;
}


	job j;
	cout<<"\n\n\n\n";
	for(int jj=0;jj<n;jj++)
	{		
        cout<<extractMinJob(h,&j)<<" ::: \n";
		cout<<j.jobid<<" "<<j.starttime<<" "<<j.joblength<<" "<<j.remlength<<"\n\n";

        for(int i=1;i<h->numjobs;i++)
            cout<<h->list[i].jobid<<" "<<h->list[i].starttime<<" "<<h->list[i].joblength<<" "<<h->list[i].remlength<<"\n";
    
        //cout<<"\n";

        for(int i=0;i<10;i++)
            cout<<h->index[i]<<" ";
    cout<<"\n---------------------------------------\n\n";
	}


    heap *h = (heap*)malloc(sizeof(heap));
    initHeap(h);

    for(int i=0;i<n;i++)
        insertJob(h,arr[i]);

    for(int i=1;i<=n;i++)
        cout<<h->list[i].jobid<<" "<<h->list[i].starttime<<" "<<h->list[i].joblength<<" "<<h->list[i].remlength<<"\n";
    
    //cout<<"\n";

    for(int i=0;i<10;i++)
        cout<<h->index[i]<<" ";
    heap *h = (heap*)malloc(sizeof(heap));
    initHeap(h);

    for(int i=0;i<n-1;i++)
        insertJob(h,arr[i]);

    for(int i=1;i<=n;i++)
        cout<<h->list[i].jobid<<" "<<h->list[i].starttime<<" "<<h->list[i].joblength<<" "<<h->list[i].remlength<<"\n";
    
    for(int i=0;i<10;i++)
        cout<<h->index[i]<<" ";




	job j;
	cout<<"\n\n\n\n";
	for(int jj=0;jj<n-1;jj++)
	{		
        cout<<del_key(h,arr_pair,m,&j)<<" ::: \n";
		cout<<j.jobid<<" "<<j.starttime<<" "<<j.joblength<<" "<<j.remlength<<"\n\n";

        for(int i=1;i<h->numjobs;i++)
            cout<<h->list[i].jobid<<" "<<h->list[i].starttime<<" "<<h->list[i].joblength<<" "<<h->list[i].remlength<<"\n";
    
        //cout<<"\n";

        for(int i=0;i<10;i++)
            cout<<h->index[i]<<" ";
    cout<<"\n---------------------------------------\n\n";
	}


*/
//If  there  are  two  jobs  with  the  same  remlength  value,  the  one  with  the  lower  job  id  is  to  be  chosen. 
