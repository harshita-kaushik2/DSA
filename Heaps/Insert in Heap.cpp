#include <bits/stdc++.h>
using namespace std;

class heap {
    public:
    int arr[100];
    int size = 0;
}
heap () {
    arr[0] = -1;
    size = 0;
}

void insert(int val) {
    size = size+ 1;
    int index = size;
    arr[index] = val;

    while(index > 1) {  //for 1-based indexing
        int parent = index/2;
        if(arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            parent = index;
        }
        else return;
    }

    void print() {

    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(20);
    return 0;
}