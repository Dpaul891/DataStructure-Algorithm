#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1005

vector<int> tree(MAXN, 0);
int n;
int sum(int i){
    int s = 0;
    while(i > 0){
        s += tree[i];
        i -= i & (-i);
    }
    return s;
}

void update(int i, int val){
    while(i <= n){
        tree[i] += val;
        i += i & (-i);
    }
}

int getSingle(int i){
    return sum(i) - sum(i-1);
}

int getInterval(int i, int j){
    return sum(j) - sum(i-1);
}

void init(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int val;
        cin >> val;
        update(i, val);
    }
}
int main()
{
    init();
    cout << getInterval(2,n) << endl;
    update(3, 5);
    cout << getInterval(2,n) << endl;
    return 0;
}