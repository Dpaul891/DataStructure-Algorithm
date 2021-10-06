#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffffff
#define MAXN 1005
class HeapStruct{
    public:
    vector<int> elements;
    int capacity;
    int size;
    HeapStruct(int maxSize) :elements(maxSize+1), capacity(maxSize), size(0){
        elements[0] = INF;
    }
};

bool IsFull(HeapStruct& H){
    return H.size == H.capacity;
}

bool IsEmpty(HeapStruct& H){
    return H.size == 0;
}

void Insert(HeapStruct& H, int val){
    if(IsFull(H)){
        cout << "The heap is FULL!" << endl;
        return;
    }
    int i = H.size + 1;
    H.size++;
    while(val > H.elements[i/2]){
        H.elements[i] = H.elements[i/2];
        i /= 2;
    }
    H.elements[i] = val;

}

int Delete(HeapStruct& H){
    int Parent, Child;
    if(IsEmpty(H)){
        cout << "The heap is EMPTY!" << endl;
        return 0;
    }
    int maxVal = H.elements[1];
    int tmp = H.elements[H.size];
    H.size--;
    for(Parent=1; Parent*2<=H.size; Parent=Child){
        Child = Parent * 2;
        if(Child!=H.size && H.elements[Child] < H.elements[Child+1]){
            Child++;
        }
        if(tmp >= H.elements[Child]) break;
        else
            H.elements[Parent] = H.elements[Child];
    }
    H.elements[Parent] = tmp;
    return maxVal;
}

void Build(HeapStruct& H, vector<int>& nums){
    int n = nums.size();
    for(int i=1; i<=n; i++){
        H.elements[i] = nums[i-1];
    }
    H.size = n;
    // Find the last element that has sons
    int ParentLast = 0;
    for(int i=n; i>=1; i--){
        if(2*i <= H.size){
            ParentLast = i;
            break;
        }
    }
    int Parent, Child;
    while(ParentLast > 0){
        int tmp = H.elements[ParentLast];
        for(Parent=ParentLast; Parent*2<=H.size; Parent=Child){
            Child = Parent * 2;
            if(Child!=H.size && H.elements[Child] < H.elements[Child+1]){
                Child++;
            }
            if(tmp >= H.elements[Child]) break;
            else
                H.elements[Parent] = H.elements[Child];
        }
        H.elements[Parent] = tmp;
        ParentLast--;
    }
}
int main()
{
    vector<int> nums{79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9};
    HeapStruct H(MAXN);
    Build(H, nums);
    for(int i=1; i<=H.size; i++)
        cout << H.elements[i] << ' ';
    cout << endl;
    //test Delete
    cout << Delete(H) << endl;
    for(int i=1; i<=H.size; i++)
        cout << H.elements[i] << ' ';
    cout << endl;

    //test Insert
    Insert(H, 23);
    for(int i=1; i<=H.size; i++)
        cout << H.elements[i] << ' ';
    cout << endl;
    return 0;
}