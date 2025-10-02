#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

int solve(int m, int n){
    if(m == 0) return n+1;
    if(n == 0) return solve(m-1, 1);
    return solve(m - 1, solve(m, n - 1));
}

signed main(){
    int n, m;
    cin >> m >> n;
    cout << solve(m, n);
}