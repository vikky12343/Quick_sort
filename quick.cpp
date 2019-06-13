#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


clock_t t;
void generate (int *a,int n)
{
int i;
for(i=0;i<n;i++)
a[i]=rand();
}


int part(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=part(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}


int main()
{
    int a[500000],n,i;
    cout<<"Enter the size of array:";
    cin>>n;
    generate(a,n);

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
   t=clock();
    quick_sort(a,0,n-1);
    cout<<"\nArray after sorting:";

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    t=clock()-t;
     cout<<"\ntime is :"<<t;

    return 0;
}



