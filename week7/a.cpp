#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Harry55 ios::sync_with_stdio(0), cin.tie(0);

struct List {
    int val;
    List* next;
    List(int x) : val(x), next(nullptr) {}
};

void solve() {
    int n;
    cin >> n;
    List* l = new List(n);
    List* now = l;

    while (cin >> n) {
        now->next = new List(n);
        now = now->next;
    }

    int x = now->val;
    
    List* prev = l;
    if (prev == now) {
        delete now;
        l = nullptr;
    } else {
        while (prev->next != now) prev = prev->next;
        prev->next = nullptr;
        delete now;
    }

    List *less = nullptr, *lnow = nullptr;
    List *great = nullptr, *gnow = nullptr;

    for (List* p = l; p; p = p->next) {
        if (p->val < x) {
            if (less) {
                less->next = new List(p->val);
                less = less->next;
            } else {
                less = new List(p->val);
                lnow = less; 
            }
        } else {
            if (great) {
                great->next = new List(p->val);
                great = great->next;
            } else {
                great = new List(p->val);
                gnow = great;
            }
        }
    }

    if (less) less->next = gnow;
    else lnow = gnow;

    for (List* p = lnow; p; p = p->next) {
        cout << p->val << " ";
    }
}

signed main() {
    Harry55
    solve();
}
