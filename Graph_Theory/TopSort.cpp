#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int> inDgree(n);
    vector<vector<int>> edges(n);
    queue<int> q;
    vector<int> ans;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        inDgree[v]++;
    }
    for(int i=0; i<n; i++){
        if(inDgree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        cnt++;
        int size = edges[u].size();
        for(int j=0; j<size; j++){
            int v = edges[u][j];
            inDgree[v]--;
            if(inDgree[v] == 0)
                q.push(v);
        }
    }
    if(cnt != n)
        cout << "There is cycle!" << endl;
    else{
        int size = ans.size();
        for(int i=0; i<size; i++)
            cout << ans[i] << ' ';
    }
    return 0;
}