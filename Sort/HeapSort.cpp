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

void PercDown(vector<int>& A, int i, int N){
    int Parent, Child;
    int tmp = A[i];
    for(Parent=i; Parent*2+1<N; Parent=Child){
        Child = Parent * 2 + 1;
        if(Child!=N-1 && A[Child] < A[Child+1]){
            Child++;
        }
        if(tmp >= A[Child]) break;
        else
            A[Parent] = A[Child];
    }
    A[Parent] = tmp;
}
void HeapSort(vector<int>& data, int n){
    // Build heap
    for(int i=n/2-1; i>=0; i--){
        PercDown(data, i, n);
    }
    for(int i=n-1; i>0; i--){
        swap(data[0], data[i]);
        PercDown(data, 0, i);
    }
}
int main()
{
    vector<int> data{79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9};
    HeapSort(data, data.size());
    int n = data.size();
    for(int i=0; i<n; i++)
        cout << data[i] << ' ';
    cout << endl;
    return 0;
}