#include<iostream>
#include<time.h>
using namespace std;
int MAximum(int* arr , int n)
{
    int max = arr[0];
    for(int i = 1 ; i<n ; i++)
    {
        if(arr[i]>max)
        {
            swap(arr[i] , max);
        }
    }
    return max;
}

void CountSort(int*arr , int n , int d)
{

    //range + = 1;
    int C[10] , A[n],i;


    for(i = 0 ; i<10; i++)
        C[i] =0;

    for(i=0 ; i<n ;i++)
        {C[ (arr[i]/d ) % 10  ] ++;}

    for(i = 1 ; i<10 ; i++)
        {C[i] = C[i-1] + C[i];}

    for(i =n-1 ; i>=0 ; i--)
        {A[ -- C[(arr[i]/d ) % 10 ] ] = arr[i];}

    for(i =0 ; i<n ; i++)
        {arr[i] = A[i];}

}

void RadixSort(int*arr  , int n)
{
    int max = MAximum(arr , n);
    for(int d = 1 ;(max/d) >0 ; d = d*10 )
    {
        CountSort(arr , n , d);
    }

}



int main()
{
    int arr[80], n ;
    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {

        arr[i]= rand( )%10 +1 ;
    }

    RadixSort(arr , n);

    for(int i =0 ; i<n ; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<<endl;


    return 0;

}

