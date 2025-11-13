#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

int arr[14];

void solve(){
    for(int i = 1 ; i < 14 ; i++){
        for(int j = i + 1 ; ; j++){
            int pos = 0;
            bool check = 1;
            for(int k = 2 * i ; k > i ; k--){
                pos = (pos - 1 + j) % k;
                if(pos < i) {check = 0; break;}
            }
            if(check) {arr[i] = j;break;}
        }
    }
}

signed main(){
    Harry55
    int k;
    solve();
    while(cin >> k && k) cout << arr[k] << '\n';
}