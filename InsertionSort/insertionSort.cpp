#include<iostream>
#include<time.h>
using namespace std;
void InsertionSort(int* arr , int n)
{


    for(int i = 1 ; i<n ; i++)
    {
        int key = arr[i] ;
        int j = i-1 ;

        while(j>=0  && arr[j]>key)
        {
            arr[j+1] = arr[j];
             j= j-1 ;

        }
        arr[j+1] = key  ;


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

    InsertionSort(arr , n);

    for(int i = 0 ; i<n ; i++)
    {
        cout<< arr[i] << " ";
    }



    return 0;
}

