#include<bits/stdc++.h>
#define WHITE -1
#define GRAY -2
int vertices;
using namespace std;

void breadthFirstSearch(vector< list< int > > adjacencyList, int source)
{
    int visited[vertices] ;
    for(int i = 0; i < vertices; i++)
    {
        visited[i] = WHITE; /// Mark all the vertices as not visited
    }

    queue<int> q;/// Create a queue for BFS

    visited[source] = GRAY;/// Mark the current node is visited
    q.push(source);/// and enqueue it

    /// 'itr' will be used to get all adjacent
    /// vertices of a vertex
    list<int>::iterator itr;
    while(!q.empty())
    {
        /// Dequeue a vertex from queue and print it
        source = q.front();
        cout << source << " ";
        q.pop();
        /// Get all adjacent vertices of the dequeued
        /// vertex s. If a adjacent has not been visited,
        /// then mark it visited and enqueue it
        for (itr = adjacencyList[source].begin(); itr != adjacencyList[source].end(); itr++)
        {
            if (visited[*itr]!=GRAY)
            {
                visited[*itr] = GRAY;
                q.push(*itr);
            }
        }
    }
}

int main()
{
    int  edges, v1, v2;

    cout<<"\n Enter the Number of Vertices::";
    cin>>vertices;

    cout<<"\n Enter the Number of Edges::";
    cin>>edges;

    /// Adjacency List is a vector of lists.
    vector< list<int> > adjacencyList(vertices + 1);
    list<int>::iterator itr;
    cout<<"\n Enter the Edges V1 -> V2 ::\n";

    for (int i = 0; i < edges; i++)
    {
        cin>>v1>>v2;

        /// Adding Edges on a undirected graph
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
    }

    cout<<"\n The Adjacency List Is::\n";
    for (int i = 1; i < adjacencyList.size(); i++)
    {
        cout<<"adjacencyList["<<i<< "]";
        for(itr=adjacencyList[i].begin(); itr!=adjacencyList[i].end(); itr++)
        {
            cout<<" -> "<< *itr;
        }
        cout<<endl;
    }

    int source;
    cout<< "\n Enter A Source Node::";
    cin>>source;

    breadthFirstSearch(adjacencyList,source);



    return 0;
}
