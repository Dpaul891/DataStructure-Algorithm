#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0xffffff
struct Edge{
    int v;
    int w;
};
int main()
{
    int n, m;
    int s = 0;
    bool negativeCircle = false;
    cin >> n >> m;
    vector<vector<Edge>> adj(n);
    vector<int> dist(n, INF);
    queue<int> q;
    vector<bool> visit(n);
    vector<int> count(n);
    q.push(s);
    count[s]++;
    visit[s] = true;
    dist[s] = 0;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge;
        edge.v = v;
        edge.w = w;
        adj[u].push_back(edge);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visit[u] = false;
        int m = adj[u].size();
        for(int j=0; j<m; j++){
            int v = adj[u][j].v;
            int w = adj[u][j].w;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(!visit[v]){
                    q.push(v);
                    count[v]++;
                    visit[v] = true;
                    if(count[v] == n){
                        negativeCircle = true;
                        break;
                    }
                }
            }
        }
        if(negativeCircle)
            break;
    }
    if(negativeCircle)
        cout << -1 << endl;
    else{
        for(int i=0; i<n; i++)
            cout << dist[i] << ' ';
        cout << endl;
    }
    return 0;
}