#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

int initfunc(vector<int> myvec, int len) {
    int i;
    for (i=1; i <= len; i++) {
        myvec[i] = i;
    }
    return 0;
}

int func(vector<int> myvec, int len, int max) {
    int i;
    max = myvec[0];
    for (i=1; i <= len; i++) {
        if(max < myvec[i]) { 
            max = myvec[i];
        }
    }
    return 0;
}

int main() {
    vector<int> vec;
    int max = 6;

    if (initfunc(vec, 100) != 0) {
        cout << "init error" << endl;
        return -1;
    }

    if (func(vec, 100, max) != 0) {
        cout << "func error" << endl;
        return -1;
    }

    cout << "max value in the array is " << max << endl;
    return 0;
}