// C++ program to create a priority queue of pairs.
// C++ program to create a priority queue of pairs.
// By default a max heap is created ordered
// by first element of pair.
#include <bits/stdc++.h>

using namespace std;

// Driver program to test methods of graph class
int main()
{
    // By default a max heap is created ordered
    // by first element of pair.
    priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
    for(int i =0; i<11; i++)
    {
        //pq.push(make_pair(10, 200));
        //pq.push(make_pair(20, 100));
        int x, y ;
        cin>>x>>y;
        pq.push(make_pair(y,x));
    }
    cout<< "\n Sorted data::"<<endl;
    priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>> >pq1 = pq;
    for(int i =0; i<11; i++)
    {
        pair<int, int>p = pq1.top();
        cout << p.second << " " << p.first<<endl;
        pq1.pop();

    }
    cout<< "\n result::"<<endl;
    priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>> >pq2 = pq;
    pair<int, int> x =pq.top();
    cout<< x.second << " "<<x.first<<endl;
    for( ; !pq.empty();)
    {
        pair<int, int> x =pq.top();
        for(; !pq2.empty();)
        {
            pq2.pop();
            pair<int, int>p = pq2.top();
            if(x.first <p.second)
            {

                //}
                //else
                x =pq2.top();
                //{
                cout<< p.second << " "<<p.first<<endl;
            }


        }
        pq.pop();

    }


    return 0;
}
