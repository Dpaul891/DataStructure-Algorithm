#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    bool ans = true;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool> vis(n, false);
    vector<int> Set(n);
    int st = 0;
    queue<int> q;
    vis[st] = true;
    q.push(st);
    Set[st] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int size = edges[u].size();
        for(int i=0; i<size; i++){
            int v = edges[u][i];
            if(vis[v] == false){
                vis[v] = true;
                q.push(v);
                Set[v] = 1 - Set[u];
            }
        }
    }
    for(int u=0; u<n; u++){
        int size = edges[u].size();
        for(int j=0; j<size; j++){
            int v = edges[u][j];
            if(Set[u] == Set[v]){
                ans = false;
                break;
            }
        }
        if(ans == false)
            break;
    }
    cout << ans << endl;
    return 0;
}