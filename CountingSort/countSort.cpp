#include<iostream>
using namespace std;
int Maximum(int* arr , int n)
{
    int  max = arr[0];
    for(int i = 1; i<n ; i++ )
    {
        if(arr[i]> max)
        {
            max = arr[i];
        }
    }
    //cout<< "\MAXXXXXXXXXXX"<<max;
    return max ;
}



void countSort(int * arr , int size)
{
    int  A[size] ;
    ///C[n].id = {0};
    int  range= Maximum(arr , size);
    int C[range+1];
    for(int i = 0 ;i<=range ; i++)
    {
         C[i] = 0 ;
    }

    for(int i = 0 ; i<size ; i++)
    {
        C[arr[i]]  ++ ;

    }

    for(int i = 1 ; i<=range ; i++)
    {
        C[i] += C[i-1] ;
    }

    for(int i = size-1 ; i>=0 ; i--)
    {
        A[--C[arr[i]]] = arr[i];

        //C[ arr[i] ] -=1;
    }

    for(int i = 0 ; i<size ; i++)
    {
       arr[i]= A[i];
    }

}



int main()
{

    int arr[100] , n ;
    cin>>n ;
    for(int i = 0 ; i<n ; i++)
        cin>>arr[i];

    countSort(arr , n );
    for(int i = 0 ; i<n ; i++)
        cout<<arr[i]<< " ";

}
