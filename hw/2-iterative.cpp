#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define vi vector<int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);
const int MAX  = 1e9+5;

int solve(int m, int n){
    int arr[MAX];
    int top = 0;
    arr[0] = m;
    while(top >= 0){
        m = arr[top--];
        if(m == 0){
            n += 1;
        }
        else if(n == 0) {
            arr[++top] = m - 1;
            n = 1;
        }
        else {
            arr[++top] = m - 1;
            arr[++top] = m;
            n--;
        }
    }
    return n;
}

signed main(){
    Harry55
    int m, n;
    cin >> m >> n;
    //cout << solve(m, n);
}

/*
m, n
m = 0, n + 1
n = 0, A(m - 1, 1)
else A(m - 1, A(m, n - 1))

const int mxn = 1e7 + 5;
int aa[mxn];
int bb[mxn];
void solve(){
    int M,N;
    cin >> M >> N;
    for(int i = 0; i < mxn; ++i) aa[i] = i + 1;
    for(int m = 1; m <= M; ++m){
        bb[0] = aa[1];
        for(int n = 1; n < mxn; ++n){
            bb[n] = aa[bb[n-1]];
        }
        for(int i = 0; i < mxn; ++i) swap(aa[i],bb[i]);
    }
    cout << aa[N] << '\n'; 
}
*/