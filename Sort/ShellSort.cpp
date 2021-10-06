#include <iostream>
#include <vector>
using namespace std;

void Origin_Shell_Sort(vector<int>& data, int n){
    for(int D=n/2; D>0; D/=2){
        for(int p=D; p<n; p++){
            int tmp = data[p];
            int i;
            for(i=p; i>=D; i-=D){
                if(tmp >= data[i-D]){
                    break;
                }
                data[i] = data[i-D];
            }
            data[i] = tmp;
        }
    }
}
// Change the {D} sequence, can make it faster!
// For example: Hibbard, Sedgewick
int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i=0; i<n; i++){
        cin >> data[i];
    }
    Origin_Shell_Sort(data, n);
    for(int i=0; i<n; i++){
        cout << data[i] << ' ';
    }
    cout <<endl;
    return 0;
}