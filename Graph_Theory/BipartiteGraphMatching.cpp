// Hungary Algorithm
#include <iostream>
#include <vector>

using namespace std;

void addEdge(int u, int v, vector<vector<int>>& adj){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void init(int m, vector<vector<int>>& adj){
 
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        addEdge(u, v, adj);
    }
}
bool dfs(int u, vector<bool>& visit,vector<int>& match, vector<vector<int>>& adj){
    int size = adj[u].size();
    for(int i=0; i<size; i++){
        int v = adj[u][i];
        if(visit[v]) continue;
        visit[v] = true;
        if(match[v] == -1 || dfs(match[v], visit, match, adj)){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

void doIt(int n, vector<int>& match, vector<vector<int>>& adj, int& ans){
    for(int i=0; i<n; i++){
        vector<bool> visit(n, false);
        if(match[i] == -1){
            if(dfs(i, visit, match, adj))
                ans++;
        }
    }
}
int main()
{
    int n, m, ans = 0;
    cin >> n >> m; 
    vector<vector<int>> adj(n);
    vector<int> match(n, -1);
    init(m, adj);
    doIt(n, match, adj, ans);
    cout << ans << endl;
    return 0;
}