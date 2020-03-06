// C++ Program to perform 3 way Merge Sort
#include <bits/stdc++.h>
using namespace std;

/** Merge the sorted ranges [low, mid1), [mid1,mid2)
and [mid2, high) mid1 is first midpoint
index in overall range to merge mid2 is second
midpoint index in overall range to merge*/

void merge(int *arr, int p, int mid1,int mid2, int r, int *copyArr)
{
    int i = p, j = mid1, k = mid2, l = p;


    while ((i < mid1) && (j < mid2) && (k < r))
    {
        if(arr[i] < arr[j])
        {
            if(arr[i] < arr[k])
            {
                copyArr[l++] = arr[i++];
            }
            else
            {
                copyArr[l++] = arr[k++];
            }
        }
        else
        {
            if(arr[j] < arr[k])
            {
                copyArr[l++] = arr[j++];
            }
            else
            {
                copyArr[l++] = arr[k++];
            }
        }
    }


    while ((i < mid1) && (j < mid2))
    {
        if(arr[i] < arr[j])
        {
            copyArr[l++] = arr[i++];
        }
        else
        {
            copyArr[l++] = arr[j++];
        }
    }


    while ((j < mid2) && (k < r))
    {
        if(arr[j] < arr[k])
        {
            copyArr[l++] = arr[j++];
        }
        else
        {
            copyArr[l++] = arr[k++];
        }
    }


    while ((i < mid1) && (k < r))
    {
        if(arr[i] < arr[k])
        {
            copyArr[l++] = arr[i++];
        }
        else
        {
            copyArr[l++] = arr[k++];
        }
    }


    while (i < mid1)
        copyArr[l++] = arr[i++];


    while (j < mid2)
        copyArr[l++] = arr[j++];


    while (k < r)
        copyArr[l++] = arr[k++];
}

///mergeSort(arr2, 0, n, arr);
void mergeSort(int *copyArr, int p,int r, int *arr)
{

    if (r - p < 2)
    {
        return;
    }

    else
    {
        int mid1 = (2*p + r)/ 3 ;
        ///int mid1 = p + ((r - p) / 3);
        int mid2 = (p+ 2*r)/3;
        ///int mid2 = p + 2 * ((r - p) / 3);
        mergeSort(arr, p, mid1, copyArr);
        mergeSort(arr, mid1, mid2, copyArr);
        mergeSort(arr, mid2, r, copyArr);


        merge(arr, p, mid1, mid2, r, copyArr);
    }
}

void mergeSort3Way(int *arr, int n)
{
    int copyArr[n];

    for (int i = 0; i < n; i++)
        copyArr[i] = arr[i];

    mergeSort(copyArr, 0, n, arr);

    for (int i = 0; i < n; i++)
        arr[i] = copyArr[i];
}


int main()
{
    int arr[100],n ;
    cout<< "\n input size::";
    cin>>n;
    if(n<=0)
    {
        cout<< "\n Empty Size of this array!!!";
    }
    cout<< "\n insert the elements into the array::";
    for(int i =0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    mergeSort3Way(arr, n);
    cout<<"\n After Sorting The Array::";

    for(int i =0 ; i<n ; i++)
    {
        cout<<arr[i]<< " ";
    }


    return 0;
}

