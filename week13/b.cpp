#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    int n;
    while(cin >> n) arr.push_back(n);
    int v = arr.back(); arr.pop_back();
    int u = arr.back(); arr.pop_back();
    int idx = 0;
    if(u > v) swap(u, v);
    while (idx < arr.size() && arr[idx] != -1) {
        int val = arr[idx];
        if (v < val) {
            idx = 2 * idx + 1;
        }
        else if (u > val) {
            idx = 2 * idx + 2;
        }
        else {
            cout << val << "\n";
            return 0;
        }
    }
}

// u, ans, v
