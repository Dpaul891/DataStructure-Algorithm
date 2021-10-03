#include <iostream>
#include <vector>
using namespace std;
#define INF 0xffffff
int main()
{
    int n, m;
    int s = 0;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n, INF));
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
    visit[s] = true;
    for(int i=0; i<n-1; i++){
        int MIN = INF;
        int u = 0;
        for(int j=0; j<n; j++){
            if(!visit[j] && dist[j] < MIN){
                MIN = dist[j];
                u = j;
            }
        }
        visit[u] = true;
        for(int v=0; v<n; v++){
            if(!visit[v] && dist[v] > dist[u] + mat[u][v]){
                dist[v] = dist[u] + mat[u][v];
                father[v] = u;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}