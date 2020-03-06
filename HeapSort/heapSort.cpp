#include<iostream>
using namespace std;
void MaxHeapify(int* arr,int n, int i)
{
    int left, right,largest,temp;
    left = (2*i) ;
    right = (2*i) + 1 ;

    if(left<=n && arr[left]>=arr[i])
        largest = left ;
    else
        largest = i;
    if(right<=n && arr[right]>=arr[largest])
        largest=right;

    if(largest!=i)
    {
        temp = arr[largest];
        arr[largest]= arr[i];
        arr[i] = temp;
        MaxHeapify(arr,n,largest);
    }


}
void BuildmaxHeap(int * arr,int n)
{
    int heapSize = n;
    int heapArray[heapSize];
    for(int i = heapSize/2 ; i>=1 ; i--)
    {

        MaxHeapify(arr,n,i);
    }

}
void HeapSort(int * arr,int n)
{
    int temp;
    int heap_size = n;
    for(int i = n ; i>=2 ; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;

        heap_size = heap_size - 1;
        MaxHeapify(arr,heap_size,1);

    }
}
int main()
{
    int arr[100],n;
    cout<< "\n Enter a size of the array::";
    cin>>n ;
    cout<< "\n Insert The Element Into The Array::";
    for(int i = 1 ; i<=n ; i++)
        cin>>arr[i];
    cout<< "\n The Max-Heap is::";
    BuildmaxHeap(arr,n);
    for(int i = 1 ; i<=n ; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    cout<< "\n After The Sorting Array ::";

    HeapSort(arr,n);
    for(int i = 1 ; i<=n ; i++)
        cout<<arr[i]<<" ";
    cout<<"\n-----------------------------------------------------------";
    return 0;
}
