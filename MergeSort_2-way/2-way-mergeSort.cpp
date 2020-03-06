#include<iostream>
#include <chrono>
#include<stdlib.h>
#include<time.h>
using namespace std;
using namespace std::chrono;
void Merge(int* arr, int LB, int mid,int UB)
{
    int n1,n2,i,j,k,L[10000],R[100000];
    n1 = mid-LB+1 ;
    n2 = UB - mid;
    for(i=1 ; i<=n1 ; i++)
    {
        L[i] = arr[LB + i -1];

    }
    for(j = 1 ; j<= n2 ; j++)
    {
        R[j] = arr[mid+j];
    }
    L[n1+1] = 10000;
    R[n2+1] = 10000;
    i = j =1;
    for(k = LB ; k<=UB ; k++)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }

}
void MergeSort(int * arr,int LB, int UB)
{
    if(LB<UB)
    {
        int mid = (LB+UB)/2;
        MergeSort(arr,LB,mid);
        MergeSort(arr,mid+1,UB);

        Merge(arr,LB,mid,UB);
    }

}

int main()
{
    int arr[100000], n ;
    srand(time(NULL));
    auto start = high_resolution_clock::now();
    cout<<"\nEnter the input size:: ";
    cin>>n;
    for(int i = 1 ; i<=n ; i++)
    {
        arr[i] = rand()%10 + 1;
    }
    for(int i = 1 ; i<= n ; i++)
        cout<<arr[i]<<" ";
    cout<<"\n=========================================================================="<<endl;
    MergeSort(arr,1,n);

    for(int i = 1 ; i<= n ; i++)
        cout<<arr[i]<<" ";
 cout<<endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
