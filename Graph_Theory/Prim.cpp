#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffffff

int main()
{
    int n, m;
    int s = 0;
    int totalWeight = 0;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    vector<int> dist(n);
    vector<int> father(n);
    vector<bool> visit(n, false);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }
    // initialization
    visit[s] = true;
    for(int i=0; i<n; i++){
        father[i] = s;
        dist[i] = cost[s][i];
    }
    for(int i=0; i<n-1; i++){
        int MIN = INF;
        int u;
        for(int j=0; j<n; j++){
            if(!visit[j] && dist[j] < MIN){
                MIN = dist[j];
                u = j;
            }
        }
        visit[u] = true;
        totalWeight += dist[u];
        for(int v=0; v<n; v++){
            if(!visit[v] && dist[v] > cost[u][v]){
                dist[v] = cost[u][v];
                father[v] = u;
            }
        }
    }
    cout << totalWeight;
    return 0;
}