#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 0xffffff

struct cmp{
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};
int main()
{
    int n, m;
    int s = 0;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n, INF));
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
    for(int i=0; i<m; i++){
        int u, v, dis;
        cin >> u >> v >> dis;
        mat[u][v] = dis;
    }
    vector<int> dist(n, INF);
    vector<bool> visit(n, false);
    vector<int> father(n);
    for(int i=0; i<n; i++){
        dist[i] = mat[s][i];
        father[i] = s;
    }
    dist[s] = 0;
    for(int i=0; i<n; i++){
        pq.push({i, dist[i]});
    }
    for(int i=0; i<n; i++){
        int u;
        while(true){
            pair<int, int> node = pq.top();
            pq.pop();
            if(!visit[node.first]){
                u = node.first;
                break;
            }
        }
        visit[u] = true;
        for(int v=0; v<n; v++){
            if(!visit[v] && dist[v] > dist[u] + mat[u][v]){
                dist[v] = dist[u] + mat[u][v];
                father[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}