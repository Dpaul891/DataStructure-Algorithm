#include <iostream>
#include <vector>
using namespace std;

void Merge1(vector<int>& data, vector<int>& tmpData, int L, int R, int rightEnd){
    int leftEnd = R - 1;
    int tmpIdx = L;
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
}

void Merge_pass(vector<int>& data, vector<int>& tmpData, int n, int length){
    int i;
    for(i=0; i<=n-2*length; i+=2*length){
        Merge1(data, tmpData, i, i+length, i+2*length-1);
    }
    if(i + length < n){
        Merge1(data, tmpData, i, i+length, n-1);
    }
    else{
        for(int j=i; j<n; j++) tmpData[j] = data[j];
    }
}

void Merge_Sort(vector<int>& data, int n){
    vector<int> tmpData(n);
    int length = 1;
    while(length < n){
        Merge_pass(data, tmpData, n, length);
        length *= 2;
        Merge_pass(tmpData, data, n, length);
        length *= 2;
    }
}

int main()
{
    vector<int> data{79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9, 10};
    int n = data.size();
    vector<int> tmpData(n);
    Merge_Sort(data, n);
    for(int i=0; i<n; i++){
        cout << data[i] << ' ';
    }
    cout << endl;
    return 0;
}