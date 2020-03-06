#include<iostream>
#include<fstream>
#define SIZE 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
int adj[SIZE][SIZE];
int color[SIZE];
int parent[SIZE];


void dfs(int vertex);
void dfsVisit(int u ,int vertex);

    //ofstream outfile;
    //ifstream infile;
    //outfile.open("input.txt");
    fstream file;


int main()
{

    //ofstream outfile;
    //ifstream infile;
    file.open("input.txt", ios::out | ios::in |ios::app);
    int count=0;
    int vertex;
    int edge;

    cout<< "\n Enter a vertex::";
    cin>>vertex;
    file<<"\n Enter a Vertex::"<< vertex << endl;
    //cin.ignore();
    //file<<vertex<<endl;

    cout<< "\n Enter a Edge::";
    cin>>edge;
    //file <<"\n Enter an Edge::"<< edge << endl;
    file<<edge<<endl;
    //outfile.close();

    //infile.open("input.txt");
    //file.close();
    //infile>>vertex;
    file>>vertex;
    cout<< " Vertex is ::"<<vertex<<endl;

    //infile>>edge;
    file>>edge;
    cout<< " Edge is ::"<<edge<<endl;

    int node1 , node2 ;
    for(int i =0 ; i<edge; i++)
    {
        cout<< "\n Enter Two Adjacent Nodes::";
        cin>>node1>>node2;
        file<<"\n Enter Two Adjacent Nodes::"<<node1<<" "<<node2;

        adj[node1][node2]=1;
        adj[node2][node1]=1;
    }
    /*for(int i = 0; i<vertex; i++)
    {
        for(int j = 0 ; j<vertex; j++)
        {
            cin>>adj[i][j];
        }
        cout<<endl;
    }*/
    cout<< "\n The Adjacent Matrix is::"<<endl;
    file<<"\n The Adjacent Matrix is::"<<endl;
    for(int i = 0; i<vertex; i++)
    {
        for(int j = 0 ; j<vertex; j++)
        {
            cout<<"\t"<<adj[i][j] << " ";
            file<<"\t"<<adj[i][j] << " ";
        }
        cout<<endl;
        file<<endl;
    }


    dfs(vertex);
file.close();
    return 0;
}

void dfs(int vertex)
{
    //file.open("input.txt", ios::out | ios::in |ios::app);
    int count=0;
    for(int i =0; i<vertex; i++)
    {
        color[i]=WHITE; /// initializing the color array to 0

    }

    cout<< "\n DFS IS ::";
    file<< "\n DFS IS ::";

    for(int i =0 ; i<vertex; i++)
    {
        if(color[i]==WHITE) ///color[i]==0? visited or not?
        {
            dfsVisit(i , vertex);
            count++;
        }
    }
    cout<<endl;

    cout<< "\n Connected component is ::"<<count;
    file<< "\n Connected component is ::"<<count;
    //file.close();

}


void dfsVisit(int u , int vertex)
{
    //file.open("input.txt", ios::out | ios::in |ios::app);
    color[u] = GRAY; ///color[u]=1 (visited)
    for(int i = 0 ; i<vertex; i++)
    {
        if(adj[u][i]==1 && color[i]==WHITE)
        {
            //parent[i]=u;
            dfsVisit(i , vertex);
        }
    }
    color[u]=BLACK; /// 2 , no child of this indexed node
    cout<<u<< " "; /// each vertex index
    file<<u<< " ";
    //file.close();
}
