#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0xffffff
struct Edge{
    int u;
    int v;
    int w;
};
bool cmp(Edge e1, Edge e2){
    return e1.w < e2.w;
}
int find_root(int x, vector<int>& parent){
    while(parent[x]!=-1){
        x = parent[x];
    }
    return x;
}
void union_vertex(int x, int y, vector<int>& parent, vector<int>& rank){
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root == y_root)
        return;
    else{
        if(rank[x_root] < rank[y_root]){
            parent[x_root] = y_root;
        }
        else if(rank[x_root] > rank[y_root]){
            parent[y_root] = x_root;
        }
        else{
            parent[y_root] = x_root;
            rank[x_root]++;
        }
    }
}
int main()
{
    int n, m;
    int totalWeight = 0;
    cin >> n >> m;
    vector<Edge> edge(m);
    vector<int> ans(n-1);
    vector<int> parent(n, -1);
    vector<int> rank(n, 0);
    for(int i=0; i<m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge.begin(), edge.end(), cmp);
    int edgeNum = 0;
    int idx = 0;
    while(edgeNum < n-1){
        int u = edge[idx].u;
        int v = edge[idx].v;
        int w = edge[idx].w;
        if(find_root(u, parent) != find_root(v, parent)){
            totalWeight += w;
            union_vertex(u, v, parent, rank);
            ans[edgeNum] = idx;
            edgeNum++;
        }
        idx++;
    }
    cout << totalWeight << endl;
    return 0;
}




