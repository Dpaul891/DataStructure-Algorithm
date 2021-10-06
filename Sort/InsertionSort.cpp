#include <iostream>
#include <vector>
using namespace std;

void Insertion_Sort(vector<int>& data, int n){
    for(int p=1; p<n; p++){
        int tmp = data[p];
        int i;
        for(i=p; i>0; i--){
            if(tmp >= data[i-1]){
                break;
            }
            data[i] = data[i-1];
        }
        data[i] = tmp;
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
    Insertion_Sort(data, n);
    for(int i=0; i<n; i++){
        cout << data[i] << ' ';
    }
    cout <<endl;
    return 0;
}