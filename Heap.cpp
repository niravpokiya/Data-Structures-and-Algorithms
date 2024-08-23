#include<bits/stdc++.h>
using namespace std;

//        max - heap

//        50 55 53 52 54

    //       55
    //      /  \
    //     54   53
    //    /  \
    //   50   52

    //  deletion from tree

    //       52
    //      /  \
    //     54   53
    //    /
    //   50

class Heap{
    public:
    vector<int> arr;
    int ind;
    Heap(int elem = 10){
        arr.assign(elem, 0);
        ind = 0;
    }
    void insert(int elem){
        ind++;
        arr[ind] = elem;
        int j = ind;
        while(j > 1 && arr[j] > arr[j/2]){
          swap(arr[j] , arr[j / 2]);
           j = j / 2;
        }
    }
    void deletefromheap(){
        if(ind == 0) {
             cout << "NOTHING" << endl;
             return;
        }
        arr[1] = arr[ind];
        ind--;
        int j = 1;
        while(j < ind && arr[j] < arr[2 * j] || arr[j] < arr[2 * j + 1]){
             if(arr[2 * j] > arr[2 * j + 1]){
                 swap(arr[j], arr[2 * j]);
                 j = 2 * j;
             }
             else{
                swap(arr[j], arr[2 * j + 1]);
                j = 2 * j + 1;
             }
        }
    }
};
int main(){
    Heap H(10);
    H.insert(50);
    H.insert(55);
    H.insert(53);
    H.insert(52);
    H.insert(54);
    H.deletefromheap();
    for(int i = 1; i <= H.ind; i++) cout << H.arr[i] << " ";
}