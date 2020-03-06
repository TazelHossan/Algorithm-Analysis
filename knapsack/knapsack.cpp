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
    ///priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
    int n,b,w ,c ;
    cout<< "\n Enter The Capacity::";
    cin>>c;
    priority_queue<pair<int, int> > pq;

    cout<< "\n Enter Number Of Items::";
    cin>>n;
    for(int i =0; i<n; i++)
    {
        //pq.push(make_pair(10, 200));
        //pq.push(make_pair(20, 100));
        //int x, y ;
        cout<< "\n Enter The Benefit::";
        cin>>b;
        cout<< "\n Enter The Weight::";
        cin>>w;
        pq.push(make_pair(b/w , w));
    }
    priority_queue<pair<int, int> >pq1 = pq;
    cout<< "\n Sorted data by value index::"<<endl;
    for(int i =0; i<n; i++)
    {
        pair<int, int>p = pq1.top();
        cout << p.second << " " << p.first<<endl;
        pq1.pop();

    }
    cout<< "\n result::"<<endl;

///priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>> >pq1 = pq;
    priority_queue<pair<int, int> >pq2 = pq;
    //cout<<pq.size();
    int totalBenifit=0;
    cout<< "\n Current Capacity::"<<c;
    for(int i = 0 ; i<pq.size(); i++)
    {
        pair<int, int>p1 =pq.top();
        if(p1.second <c && p1.second >0)
        {
            cout<< "\n Index Value::"<<p1.first;
            totalBenifit +=p1.first *p1.second ;
            c -=p1.second ;
            cout<< "\n Now Total Benefit::"<<totalBenifit;
            cout<< "\n Current Capacity::"<<c;


        }
        if(p1.second > c && c >0)
        //else
        {
            pq.pop();
            pair<int, int>p1 =pq.top();
            cout<< "\n Current Capacity::"<<c;
            cout<< "\n Index Value::"<<p1.first;
            totalBenifit +=c*p1.first;
            cout<< "\n Now Total Benefit::"<<totalBenifit;
            //pq.pop();

        }
        pq.pop();


    }
    cout<< "\n Total Benefit::"<<totalBenifit;


    return 0;
}
