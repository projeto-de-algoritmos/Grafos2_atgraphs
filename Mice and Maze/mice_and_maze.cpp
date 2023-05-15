#include <bits/stdc++.h>

using namespace std;

typedef struct Edge
{
    int begin;
    int end;
    int time;
}Edge;


struct CompareWeight {
    bool operator()(Edge const& e1, Edge const& e2)
    {
        return e1.time > e2.time;
    }
};

void add_edge(vector<Edge> g[], int a, int b, int time){
    Edge ed;
    ed.time = time;
    ed.begin = a;
    ed.end = b;
    g[a].push_back(ed);
} 

int djikstra(vector<Edge> g[], int origin, int dest, int n, int cd_timer, int result){
    bool visit[n+1];
    int min_dist[n+1];

    priority_queue<Edge, vector<Edge>, CompareWeight> pq;

    for (size_t i = 1; i <=n; i++)
    {
        visit[i] = false;
        min_dist[i] = INT_MAX;
    }
    
    visit[origin] = true;
    min_dist[origin] = 0;

    for(auto ed : g[origin]){
        pq.push(ed);
        min_dist[ed.end] = ed.time;
    }

    while (!pq.empty())
    {
        Edge path = pq.top();
        pq.pop();

        if (!visit[path.end])
        {
            visit[path.end] = true;
            min_dist[path.end] = path.time;
        }
        
        for(auto ed : g[path.end]){
            ed.time = ed.time + path.time;

            if(!visit[ed.end] and ed.time < min_dist[ed.end]){
                pq.push(ed);
                min_dist[ed.end] = ed.time;
            }
        }
    }

    if (min_dist[dest] <= cd_timer)
    {
        result = result + 1;
    }

    return result;
}

int main(){
    int n_cases, n, m, exit, cd_timer;
    int a, b, t;
    int result;

    cin >> n_cases;

    for (size_t i = 0; i < n_cases; i++)
    {
        result = 0;
        cin >> n >> exit >> cd_timer >> m;

        vector<Edge> g[n+1];

        for (size_t i = 0; i < m; i++)
        {
            cin >> a >> b >> t;
            add_edge(g, a, b, t);
        }
        
        for (size_t i = 1; i <= n; i++)
        {
            result = djikstra(g, i, exit, n, cd_timer, result);
        }
        
        cout << result << endl;
        if (i != n_cases - 1)
        {
            cout << endl;
        }
        
    }
    
    
return 0;
}