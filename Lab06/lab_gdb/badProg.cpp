#include <vector>
using std::vector;
#include <string>
using std::string; using std::to_string;
#include <iostream>
using std::cout; using std::endl;

int find_and_return_max(vector<int> vector1, int max) {
    if (vector1.size() == 0)
        return -1;
    max = vector1[0];
    for (auto i = vector1.begin(); i != vector1.end(); ++i) {
        if (max < *i) {
            max = *i;
        }
    }
    return 0;
}

int main() {
    vector<int> myvec = {17, 21, 44, 2, 60};
    int max = myvec[0];
    if (find_and_return_max(myvec, max) != 0) {
        cout << "strange error" << endl;
        return -1;
    }
    cout << "max value in the vector is " << to_string(max) << endl;
    return 0;
}