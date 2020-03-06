#include<iostream>
using namespace std;
void Merge(int*copyArr, int LB, int mid1, int mid2, int mid3,int UB, int*arr)
{
    int i = LB, j = mid1, k = mid2, l= mid3, n = LB;

    while(i<mid1 && j <mid2 && k<mid3 && l<UB)
    {
        if(copyArr[i]< copyArr[j])
        {
            if(copyArr[i] < copyArr[k])
            {
                if(copyArr[i]<copyArr[l])
                {
                    arr[n++] = copyArr[i++];
                }
                else
                {
                    arr[n++] = copyArr[l++];
                }
            }

            else
            {
                if(copyArr[k] < copyArr[l])
                {
                    arr[n++] = copyArr[k++];
                }
                else
                {
                    arr[n++] = copyArr[l++];
                }
            }
        }
        else
        {
            if(copyArr[j]<copyArr[k])
            {
                if(copyArr[j] < copyArr[l])
                {
                    arr[n++] = copyArr[j++];
                }
                else
                {
                    arr[n++] = copyArr[l++];
                }
            }
            else
            {
                if( copyArr[k] < copyArr[l] )
                {
                    arr[n++] = copyArr[k++];
                }
                else
                {
                    arr[n++] = copyArr[l++];
                }
            }
        }
    }


    while ((i < mid1) && (j < mid2) && (k < mid3))
    {
        if(copyArr[i] < copyArr[j])
        {
            if(copyArr[i] < copyArr[k])
            {
                arr[n++] = copyArr[i++];
            }
            else
            {
                arr[n++] = copyArr[k++];
            }
        }
        else
        {
            if(copyArr[j] < copyArr[k])
            {
                arr[n++] = copyArr[j++];
            }
            else
            {
                arr[n++] = copyArr[k++];
            }
        }
    }
    /////////////////////////////////////
    while ((i < mid1) && (j < mid2) && (l < UB))
    {
        if(copyArr[i] < copyArr[j])
        {
            if(copyArr[i] < copyArr[l])
            {
                arr[n++] = copyArr[i++];
            }
            else
            {
                arr[n++] = copyArr[l++];
            }
        }
        else
        {
            if(copyArr[j] < copyArr[l])
            {
                arr[n++] = copyArr[j++];
            }
            else
            {
                arr[n++] = copyArr[l++];
            }
        }
    }



    while ((j < mid2) && (k < mid3) && (l < UB))
    {
        if(copyArr[j] < copyArr[k])
        {
            if(copyArr[j] < copyArr[l])
            {
                arr[n++] = copyArr[j++];
            }
            else
            {
                arr[n++] = copyArr[l++];
            }
        }
        else
        {
            if(copyArr[k] < copyArr[l])
            {
                arr[n++] = copyArr[k++];
            }
            else
            {
                arr[n++] = copyArr[l++];
            }
        }
    }




    while ((i < mid1) && (j < mid2))
    {
        if(copyArr[i] < copyArr[j])
        {
            arr[n++] = copyArr[i++];
        }
        else
        {
            arr[n++] = copyArr[j++];
        }
    }


    while ((j < mid2) && (k < mid3))
    {
        if(copyArr[j] < copyArr[k])
        {
            arr[n++] = copyArr[j++];
        }
        else
        {
           arr[n++] = copyArr[k++];
        }
    }

    while ((k < mid3) && (l < UB))
    {
        if(copyArr[k] < copyArr[l])
        {
           arr[n++] = copyArr[k++];
        }
        else
        {
           arr[n++] = copyArr[l++];
        }
    }


    while ((i < mid1) && (k < mid3))
    {
        if(copyArr[i] < copyArr[k])
        {
            arr[n++] = copyArr[i++];
        }
        else
        {
            arr[n++] = copyArr[k++];
        }
    }

    while ((j < mid2) && (l < UB))
    {
        if(copyArr[j] < copyArr[l])
        {
            arr[n++] = copyArr[j++];
        }
        else
        {
            arr[n++] = copyArr[l++];
        }
    }

    while ((i < mid1) && (l < UB))
    {
        if(copyArr[i] < copyArr[l])
        {
            arr[n++] = copyArr[i++];
        }
        else
        {
            arr[n++] = copyArr[l++];
        }
    }



    while (i < mid1)
        arr[n++] = copyArr[i++];


    while (j < mid2)
        arr[n++] = copyArr[j++];


    while (k < mid3)
        arr[n++] = copyArr[k++];

    while (l < UB)
        arr[n++] = copyArr[l++];


}
void miniSort(int*arr,int LB, int UB)
{
    int i=LB,j,temp;
    for( i = LB ; i<UB-1 ; i++)
    {
        for( j = LB ; j<UB-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                {temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;}
        }
    }
    //for( i = LB ; i<UB-1 ; i++)
        //copyArray[i] = arr[i];



}

void mergeSort(int* copyArray, int LB, int UB,int * arr)
{
    if(UB - LB +1 <4)
    {
        //cout<< "\mini Sort\n";
        //miniSort(arr,LB,UB) ;
        return;

    }


        int mid1,mid2, mid3;
        mid2 = (UB+LB)/2 ;
       ///mid1 = (UB+3*LB)/4 ;
        mid1 = (LB + mid2)/2;
        ///mid2 = (LB+UB)/2;
        mid3 = (UB+mid2)/2;
       ///mid3 = (3*UB + LB)/4;

        mergeSort(arr, LB, mid1,copyArray);
        mergeSort(arr, mid1, mid2,copyArray);
        mergeSort(arr, mid2, mid3 ,copyArray);
        mergeSort(arr, mid3, UB,copyArray);

        Merge(arr, LB, mid1,mid2,mid3,UB,copyArray);

}


void mergeSort4Way(int*arr, int n)
{
    int copyArray[80];
    for(int i =0 ; i<n ; i++)
    {
        copyArray[i] = arr[i];
    }

    mergeSort(copyArray, 0, n, arr);

    cout<< "\n XXXXXXXXXXXXXXX";
    for(int i =0 ; i<n ; i++)
    {
        arr[i] = copyArray[i];
    }


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

    mergeSort4Way(arr, n);
    cout<<"\n After Sorting The Array::";

    for(int i =0 ; i<n ; i++)
    {
        cout<<arr[i]<< " ";
    }


    return 0;
}

