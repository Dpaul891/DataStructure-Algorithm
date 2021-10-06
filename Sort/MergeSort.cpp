#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& data, vector<int>& tmpData, int L, int R, int rightEnd){
    int leftEnd = R - 1;
    int tmpIdx = L;
    int numElements = rightEnd - L + 1;
    while(L <= leftEnd && R <= rightEnd){
        if(data[L] <= data[R]){
            tmpData[tmpIdx++] = data[L++];
        }
        else
            tmpData[tmpIdx++] = data[R++];
    }
    while(L <= leftEnd){
        tmpData[tmpIdx++] = data[L++];
    }
    while(R <= rightEnd){
        tmpData[tmpIdx++] = data[R++];
    }
    for(int i=0; i<numElements; i++, rightEnd--){
        data[rightEnd] = tmpData[rightEnd];
    }
}

void MSort(vector<int>& data, vector<int>& tmpData, int L, int rightEnd){
    if(L < rightEnd){
        int center = (L + rightEnd) / 2;
        MSort(data, tmpData, L, center);
        MSort(data, tmpData, center+1, rightEnd);
        Merge(data, tmpData, L, center+1, rightEnd);
    }
}

void Merge_Sort(vector<int>& data, int n){
    vector<int> tmpData(n);
    MSort(data, tmpData, 0, n-1);
}
int main()
{
    vector<int> data{79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9};
    int n = data.size();
    vector<int> tmpData(n);
    Merge_Sort(data, n);
    for(int i=0; i<n; i++){
        cout << data[i] << ' ';
    }
    cout <<endl;
    return 0;
}