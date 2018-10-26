#include <iostream>
#include <map>

using namespace std;
#define MAX 100
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partion(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;
    for(int i = s; i <= e-1;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(&arr[pIndex],&arr[i]);
            pIndex++;
        }
    }
    swap(&arr[pIndex],&arr[e]);
    return pIndex;
}
void qsort(int arr[], int s, int e)
{
    if(s<e)
    {
        int pIndex = partion(arr, s, e);
        qsort(arr, s, pIndex - 1);
        qsort(arr, pIndex + 1, e);
    }
}
int main(int argc, char **argv)
{
	int arr[MAX], n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nqSort"<<endl;
    qsort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    map <string, int> m;
    m.insert(pair<string, int>("hi",1));
    m.insert(pair<string, int>("hello",2));
    
    map<string, int>::iterator it = m.find("hello");
    cout<<it->second;
}