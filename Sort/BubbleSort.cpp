#include <iostream>
#include <vector>
using namespace std;

void Bubble_Sort(vector<int>& data, int n){
    for(int i=n-1; i>=0; i--){
        bool flag = true;
        for(int j=0; j<i; j++){
            if(data[j] > data[j+1]){
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                flag = false;
            }
        }
        if(flag == true)
            break;
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
    Bubble_Sort(data, n);
    for(int i=0; i<n; i++){
        cout << data[i] << ' ';
    }
    cout <<endl;
    return 0;
}