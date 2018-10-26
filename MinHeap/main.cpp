#include <iostream>
using namespace std;
#define MAX 10
#define INT_MAX 65535
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
class MinHeap
{
public:
    int heapSize;
    int cap;
    int *arr;

    MinHeap(int cap)
    {
        this->cap = cap;
        arr = new int(cap);
        heapSize = 0;
    }
    int parent(int i)
    {
        if(i==0)
            return 0;
        return (i-1)/2;
    }
    int left(int i)
    {
        return i*2+1;
    }
    int right(int i)
    {
        return i*2+2;
    }
    void insetKey(int k)
    {
        int i;
        if(heapSize>=cap)
        {
            cout<<"Over Heap Capacity";
            return;
        }
        i = heapSize;
        arr[heapSize++]=k;
        while(i!=0&&arr[parent(i)]>arr[i])
        {
            swap(&arr[parent(i)],&arr[i]);
            i=parent(i);
        }
    }
    void minHeapify(int root)
    {
        int l, r, smallest = root;
        l=left(root);
        r=right(root);
        if(l < heapSize &&arr[l] < arr[root])
        {
            smallest = l;
        }
        if(r < heapSize && arr[r] < arr[smallest])
        {
            smallest = r;
        }
        if(smallest != root)
        {
            swap(&arr[root],&arr[smallest]);
            minHeapify(smallest);
        }
    }
    int getroot()
    {
        int root = arr[0];
        arr[0]=INT_MAX;
        minHeapify(0);
        arr[heapSize]=0;
        heapSize--;
        return root;
    }
    void disHeap()
    {
        int i;
        cout<<endl<<"Heap Capacity : "<<cap<<endl;
        for(i=0;i<heapSize;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(int argc, char **argv)
{
    int n, i, temp;
	cin>>n;
    MinHeap h(n);
    for(i=0;i<n;i++)
    {
        cin>>temp;
        h.insetKey(temp);
    }
    h.disHeap();
    cout<<"\nExtract Min : "<<h.getroot();
	h.disHeap();
    cout<<"\nExtract Min : "<<h.getroot();
	h.disHeap();
    return 0;
}