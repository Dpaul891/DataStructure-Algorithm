#include <iostream>
#include <vector>
using namespace std;

int Median3(vector<int>& data, int left, int right){
    int center = (left + right) / 2;
    if(data[left] > data[center])
        swap(data[left], data[center]);
    if(data[left] > data[right])
        swap(data[left], data[right]);
    if(data[center] > data[right])
        swap(data[center], data[right]);
    swap(data[center], data[right-1]);
    // Only need to consider data[left+1]...data[right-2];
    return data[right-1];
}
void QuickSort(vector<int>& data, int left, int right){
    if(left == right) return; // 
    int pivot = Median3(data, left, right);
    if(right - left <= 2) return; // median3 has done the sort!
    int i = left;
    int j = right - 1;
    while(true){
        while(data[++i] < pivot) { }
        while(data[--j] > pivot) { }
        if(i < j){
            swap(data[i], data[j]);
        }
        else break;
    }
    swap(data[i], data[right-1]);
    QuickSort(data, left, i-1);
    QuickSort(data, i+1, right);
}

void Quick_Sort(vector<int>& data, int n){
    QuickSort(data, 0, n-1);
}
int main()
{
    vector<int> data{79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9};
    int n = data.size();
    vector<int> tmpData(n);
    Quick_Sort(data, n);
    for(int i=0; i<n; i++){
        cout << data[i] << ' ';
    }
    cout <<endl;
    return 0;
}