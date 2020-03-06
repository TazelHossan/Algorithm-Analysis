#include<iostream>
#include<time.h>
using namespace std;
void BubbleSort(int* arr , int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0 ; j<n-i-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main()
{
    int arr[80] , n ;
    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {

        arr[i]= rand( ) % 10 +1 ;
    }

    BubbleSort(arr , n);

    for(int i = 0 ; i<n ; i++)
    {
        cout<< arr[i] << " ";
    }



    return 0;
}
