#include<iostream>
#include<vector>
using namespace std;

#define MAX_LEN 1000

struct Node{
    int left, right;
    int sum;
};
Node tree[MAX_LEN];

void build_tree(int node, int left, int right){
    tree[node].left = left;
    tree[node].right = right;
    tree[node].sum = 0;
    if(left == right) return;
    int mid = (left + right) / 2;
    int left_node = 2 * node;
    int right_node = 2 * node + 1;
    build_tree(left_node, left, mid);
    build_tree(right_node, mid+1, right);
}

void insert(int node, int left, int right){
    if(tree[node].sum == tree[node].right - tree[node].left + 1) return;
    if(left > tree[node].right || right < tree[node].left) return;
    if(left <= tree[node].left && right >= tree[node].right){
        tree[node].sum = tree[node].right - tree[node].left + 1;
        return;
    }
    int left_node = 2 * node;
    int right_node = 2 * node + 1;
    insert(left_node, left, right);
    insert(right_node, left, right);
    tree[node].sum = tree[left_node].sum + tree[right_node].sum;
}

// int count_tree(int node){
//     if(tree[node].cover == 1) 
//         return tree[node].right - tree[node].left + 1;
//     if(tree[node].left == tree[node].right) return 0;
//     return count_tree(node * 2) + count_tree(node * 2 + 1);
// }
int main()
{
    int Min, Max, n;
    cin >> Min >> Max >> n;
    build_tree(1, Min, Max);
    for(int i=0; i<n; i++){
        int left, right;
        cin >> left >> right;
        insert(1, left, right);
    }
    cout << tree[1].sum << endl;
    return 0;
}