#include <bits/stdc++.h>
using namespace std;

vector <int> v[1000];
queue <int> q;

void graph_bfs(int visited[])
{
    int vertex;
    while (!q.empty())
    {
        cout<<"\nVisited status\n";
        for (int i=0; i<7; i++)
        cout<<visited[i]<<" ";
        cout<<endl;
        vertex = q.front();
        cout<<vertex<<" ";
        visited[vertex] = 1;
        q.pop();
        for (int i=0; i<v[vertex].size(); i++)
        {
            if (visited[v[vertex][i]] == 0){
            q.push(v[vertex][i]);
            visited[v[vertex][i]] = 1;
            }
        }
    }
}

int main()
{
    int vertices, edges, edge;
    cout<<"Enter number of vertex.\n";
    cin>>vertices;
    int visited[vertices]={0};
    // fill_n(visited, vertices, 0);
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
    cout<<"Breadth first search for the given graph is: \n";
    q.push(0);
    // visited[0] = 1;
    graph_bfs(visited);
    return 0;
}