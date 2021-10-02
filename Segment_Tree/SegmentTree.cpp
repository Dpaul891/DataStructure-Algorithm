#include<iostream>
#include<vector>
using namespace std;

#define MAX_LEN 1000 
// the size of tree should be 2 ^ (ceil【log(n)】+ 1) - 1;

void build_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    build_tree(arr, tree, left_node, start, mid);
    build_tree(arr, tree, right_node, mid+1, end);
    tree[node] = tree[left_node] + tree[right_node];
}

void update_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end, int idx, int val){
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    if(idx <= mid){
        update_tree(arr, tree, left_node, start, mid, idx, val);
    }
    else{
        update_tree(arr, tree, right_node, mid+1, end, idx, val);
    }
    tree[node] = tree[left_node] + tree[right_node];
}

int query_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end, int L, int R){
    if(R < start || L > end) return 0;
    if(L <= start && R >= end) return tree[node];
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    int sum_left = query_tree(arr, tree, left_node, start, mid, L, R);
    int sum_right = query_tree(arr, tree, right_node, mid+1, end, L, R);
    return sum_left + sum_right;
}
int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    vector<int> tree(MAX_LEN, 0);
    int size = arr.size();
    build_tree(arr, tree, 0, 0, size-1);
    for(int i=0; i<15; i++){
        cout << tree[i] << endl;
    }
    cout << endl;
    update_tree(arr, tree, 0, 0, size-1, 4, 6);
    for(int i=0; i<15; i++){
        cout << tree[i] << endl;
    }
    cout << endl;
    int s = query_tree(arr, tree, 0, 0, size-1, 2, 5);
    cout << s << endl;
    return 0;
}