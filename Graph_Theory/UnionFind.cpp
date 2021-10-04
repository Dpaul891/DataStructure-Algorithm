#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0xffffff

int find_root(int x, vector<int>& parent){
    while(parent[x]!=-1){
        x = parent[x];
    }
    return x;
}
int union_vertex(int x, int y, vector<int>& parent, vector<int>& rank){
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root == y_root)
        return 0;
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
        return 1;
    }
}

int main()
{
    int n, m;
    bool hasCycle = false;
    cin >> n >> m;
    vector<int> parent(n, -1);
    vector<int> rank(n, 0);
    vector<vector<int>> edges(m, vector<int>(2));
    for(int i=0; i<m; i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    for(int i=0; i<m; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        if(union_vertex(x, y, parent, rank) == 0){
            hasCycle = true;
            break;
        }
    }
    if(hasCycle) 
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl; 
    return 0;
}