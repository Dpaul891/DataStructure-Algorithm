#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffffff
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> P(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for(int i=0; i<n; i++)
        dist[i][i] = 0;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}