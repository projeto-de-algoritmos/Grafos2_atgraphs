#include <bits/stdc++.h>

using namespace std;

typedef struct Edge
{
    int begin;
    int end;
    int weight;
}Edge;


struct CompareWeight {
    bool operator()(Edge const& e1, Edge const& e2)
    {
        return e1.weight > e2.weight;
    }
};

void add_edge(vector<Edge> g[], int e1, int e2, int weight){
    Edge ed;
    ed.weight = weight;
    ed.begin = e1;
    ed.end = e2;
    g[e1].push_back(ed);
} 

void print_path(vector<int>& result,int *short_path, int dest){
    if (dest != 0)
    {
        result.push_back(dest);
        print_path(result, short_path, short_path[dest]);
    }
}

void djikstra(vector<Edge> g[], int origin, int dest, int n){
    bool visit[n+1];
    int min_dist[n+1];
    int short_path[n+1];
    vector<int> result;

    priority_queue<Edge, vector<Edge>, CompareWeight> pq;

    for (size_t i = 1; i <=n; i++)
    {
        visit[i] = false;
        min_dist[i] = INT_MAX;
        short_path[i] = 0;
    }
    
    visit[origin] = true;
    min_dist[origin] = 0;
    short_path[origin] = 0;

    for(auto ed : g[origin]){
        pq.push(ed);
        min_dist[ed.end] = ed.weight;
        short_path[ed.end] = ed.begin;
    }

    while (!pq.empty())
    {
        Edge path = pq.top();
        pq.pop();

        if (!visit[path.end])
        {
            visit[path.end] = true;
            min_dist[path.end] = path.weight;
            short_path[path.end] = path.begin; 
        }
        
        for(auto ed : g[path.end]){
            ed.weight = ed.weight + path.weight;

            if(!visit[ed.end] and ed.weight < min_dist[ed.end]){
                pq.push(ed);
                min_dist[ed.end] = ed.weight;
                short_path[ed.end] = ed.begin;
            }
        }
    }
    
    if (!visit[dest])
    {
        cout << -1;
    }else
    {
        print_path(result, short_path, dest);
        cout << result.back();
        result.pop_back();

        while (!result.empty())
        {
            cout << " " << result.back();
            result.pop_back();
        }
        
    }
}

int main(){
    int n, m;
    int e1, e2, weight;

    cin >> n >> m;

    vector<Edge> g[n+1];


    for (size_t i = 0; i < m; i++)
    {
        cin >> e1 >> e2 >> weight;
        add_edge(g, e1, e2, weight);
        add_edge(g, e2, e1, weight);
    }
    
    djikstra(g, 1, n, n);

return 0;
}