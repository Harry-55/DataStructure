#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);
#define max(a, b) ((a) > (b) ? (a) : (b))

void solve(){
    int x[4];
    int y[4];
    for(int i = 0 ; i < 4 ; i++) cin >> x[i] >> y[i];
    int c = max(0, min(x[3] - x[0], x[1] - x[2]));
    int d = max(0, min(y[0] - y[3], y[2] - y[1]));
    cout << c * d;
}

signed main(){
    solve();
}