#include<iostream>
using namespace std;
int Partition(int* arr , int LB , int UB)
{
    int pivot = arr[LB] ; /// pivot as a first Element
    int i = UB +1 ;
    int j ;
    for(j = UB ; j>LB ; j--)
    {
        if(arr[j]>=pivot)
        {
            i--;
            swap(arr[j] ,arr[i] );
        }
    }
    swap(arr[i-1] ,arr[LB]);
    return i-1;
}

void QuickSort(int *arr , int LB , int UB)
{
    if(LB<UB)
    {int q = Partition(arr , LB ,UB);
    QuickSort(arr , LB ,q-1);
    QuickSort(arr  ,q+1 , UB);

    }


}
int main()
{
    int arr[80] , n ;
    cout<< "\n Enter The Size::";
    cin>>n ;
    for(int i = 0 ; i<n ; i++)
    {
        arr[i] = rand()%10 +1;
    }
    for(int i = 0 ; i<n ; i++)
        cout<<arr[i]<< " ";
        cout<<"\n===================================================\n";
    QuickSort(arr , 0 , n-1);

    for(int i = 0 ; i<n ; i++)
        cout<<arr[i]<< " ";



    return 0;
}
