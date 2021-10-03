#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffffff
struct Edge{
    int u;
    int v;
    int w;
};
int main()
{
    int n, m;
    int s = 0;
    bool negativeCircle = false;
    cin >> n >> m;
    vector<Edge> edge(m);
    vector<int> dist(n, INF);
    dist[s] = 0;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
    }
    for(int i=0; i<n-1; i++){
        bool flag = false;
        for(int j=0; j<m; j++){
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;
            if(dist[u] != INF && dist[v] > dist[u] + w){
                flag = true;
                dist[v] = dist[u] + w;
            }
        }
        if(!flag) break;
    }
    // check negative circle
    for(int j=0; j<m; j++){
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;
        if(dist[u] != INF && dist[v] > dist[u] + w){
            negativeCircle = true;
            break;
        }
    }
    if(negativeCircle) 
        cout << -1 << endl;
    else{
        for(int i=0; i<n; i++){
            cout << dist[i] << ' ';
        }
    }
    return 0;
}