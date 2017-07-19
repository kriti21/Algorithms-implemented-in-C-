#include <bits/stdc++.h>
using namespace std;

vector <int> v[1000];

void graph_dfs(int vertices, int vertex, int visited[])
{
    if (visited[vertex] == 1)
    return;
    cout<<vertex<<" ";
    visited[vertex] = 1;
    for (int i=0; i<v[vertex].size(); i++)
    {
        graph_dfs(vertices, v[vertex][i], visited);
    }
}

int main()
{
    int vertices, edges, edge;
    cout<<"Enter number of vertex.\n";
    cin>>vertices;
    int visited[vertices];
    fill_n(visited, vertices, 0);
    for (int i=0; i<vertices; i++)
    {
        cout<<"Enter no. of edges for vertex "<<i<<endl;
        cin>>edges;
        for (int j=0; j<edges; j++)
        {
            cin>>edge;
            v[i].push_back(edge);
        }
        sort(v[i].begin(), v[i].end());
    }
    cout<<"Depth first search for the given graph is: \n";
    graph_dfs(vertices, 0, visited);
    return 0;
}