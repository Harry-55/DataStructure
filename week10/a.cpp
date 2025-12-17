#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

int arr[(1 << 16) - 1];

void solve(){
    int n;
    cin >> n;
    int x, l, r;
    cin >> x >> l >> r;
    arr[0] = x;
    arr[1] = l;
    arr[2] = r;
    int _max = -1; 
    while(n--){
        int node, left, right;
        cin >> node >> left >> right;
        for(int i = 0 ; i < (1 << 16) - 1; i++){
            if(arr[i] == node){
                arr[2 * i + 1] = left;
                arr[2 * i + 2] = right;
                _max = max(_max, 2 * i + 2);
                break;
            }
        }
    }
    for(int i = 0 ; i <= _max ; i++){
        cout << arr[i] << " ";
    }
}

signed main(){
    Harry55
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}