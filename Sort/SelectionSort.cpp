#include <iostream>
#include <vector>
using namespace std;

void Selection_Sort(vector<int>& data, int n){
    for(int i=0; i<n; i++){
        int MIN = 0xffffff;
        int k;
        for(int j=i; j<n; j++){
            if(data[j] < MIN){
                MIN = data[j];
                k = j;
            }
        }
        swap(data[i], data[k]);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i=0; i<n; i++){
        cin >> data[i];
    }
    Selection_Sort(data, n);
    for(int i=0; i<n; i++){
        cout << data[i] << ' ';
    }
    cout <<endl;
    return 0;
}