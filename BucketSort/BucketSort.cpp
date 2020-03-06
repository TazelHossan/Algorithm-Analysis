#include<iostream>
#include<vector>    /// for vector
#include<algorithm> /// for using sort() function
using namespace std;

void BucketSort(float* arr, int n)
{
    vector<float>Bucket[n]; /// create a Bucket
    int index;
    for(int i = 0 ; i<n ; i++)
    {
        index = int(n*arr[i]);
        Bucket[index].push_back(arr[i]);

    }

    for(int i = 0 ; i<n ; i++)
    {
        sort(Bucket[i].begin(),Bucket[i].end());
    }

    int arr_index = 0;
    for(int i = 0; i<n; i++)
    {
        while(!Bucket[i].empty())
        {
            arr[arr_index++] = *(Bucket[i].begin());
            Bucket[i].erase(Bucket[i].begin());
        }

    }

}
int main()
{
    float arr[80] ;
    int n ;
    cin>>n ;
    for(int i = 0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    BucketSort(arr, n);

    for(int i = 0 ; i<n ; i++)
    {
        cout<<arr[i]<< " ";
    }



    return 0;
}
