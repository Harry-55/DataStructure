#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define vi vector<int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);
const int MAX  = 1e5+5;
int solve(int n){
    int arr[MAX] = {0};
    int top = 0;
    int x, ans = 0;
    arr[top] = n;
    while(top >= 0){
        x = arr[top--];
        if(x == 1) ans+=1;
        else if(x == 0) ans+=0;
        else{
            arr[++top] = x - 1;
            arr[++top] = x - 2;
        }
    }
    return ans;
}

signed main(){
    Harry55
    int n;
    cin >> n;
    cout << solve(n);
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