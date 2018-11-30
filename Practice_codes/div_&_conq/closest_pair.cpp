#include<iostream>
#include<math.h>
using namespace std;

struct point{
    int x,y;
};

float minval(float x, float y)
{
    if (x >y)
        return y;
    else
        return x;
}

float euc_dist(point p1, point p2)
{
    return(sqrt(float(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2) ))  );
}

float brute_min(point a[], int low, int high)
{
    float min = euc_dist(a[low],a[low+1]);

    for(int i=low;i<high;i++)
        for(int j=i+1;j<high;j++)
            if (euc_dist(a[i],a[j])<min)
                min = euc_dist(a[i],a[j]);

    return min;
}

float border_min(point a[], int low, int high ,float min)
{
    point strip[high-low+1];

    int j = 0;
    for (int i = low; i < high; i++)
        if (abs(a[i].x - a[(high+low)/2].x) < min)
        {   strip[j] = a[i];
            j++;
        }

//    cout<<"..........."<<j<<"...........";
    for (int i = 0; i < j; i++)
        for (int k = i+1; k < j; k++)
            if (euc_dist(strip[i],strip[k]) < min)
                min = euc_dist(strip[i], strip[k]);

    return min;
}

float closest_pair_dist(point a[], int low, int high)
{
    if(high <=low+1) return 1000.0;

    if( (high -low)<3)
        return (brute_min(a,low,high));

    float min,lmin=100,rmin = 100;
    lmin = closest_pair_dist(a,low, (high+low)/2);
    rmin = closest_pair_dist(a,(high+low)/2,high);

    min = minval(lmin,rmin);
    //cout<<min<<" : "<<low<<"," <<high<<"\n";

    min = minval( border_min(a,low,high,min), min);
    return min;
}

void swap(point *x, point *y)
{
    point tmp = *x;
    *x = *y;
    *y = tmp;
}
int partition(point a[], int low, int high)
{
    int pivot = low, i= low, j= high;

    while(i<j)
    {   while(a[pivot].x>=a[i].x && i <=high) i++;
        while(a[pivot].x<a[j].x) j--;
        if(i<j)
        {
            swap(&a[i],&a[j]);
            j--;
        }
    }
    swap(&a[j],&a[pivot]);
    return j;
}
void quicksort_x(point a[] , int low, int high, int n)
{
    if(high<=low)
        return;

    int parti = partition(a,low, high);

    quicksort_x(a,low,parti-1,n);
    quicksort_x(a,parti+1,high,n);
}
void sort_x(point p[],int n)
{    quicksort_x(p,0,n-1, n);
}

int main()
{
    int n;
    cin>>n;

    point *a =(point*)malloc(sizeof(point)*n);
    float shortest;

    for(int i=0;i<n;i++)
        cin>>a[i].x>>a[i].y;

    sort_x(a,n);

    for(int i=0;i<n;i++)
        cout<<"\n"<<a[i].x<<" , "<<a[i].y;

    cout<<"\n\n\n\n\n";
    shortest = closest_pair_dist(a,0, n);
    cout<<shortest<<"\n";
}

//sort p accord x
//pass ti fn
//base
//min l and r
//min across border
//min of mins
//<4 return brute force;