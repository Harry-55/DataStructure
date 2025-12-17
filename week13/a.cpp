#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

vector<int> edge[100005];
int vis[100005], _max = -1;
void dfs(int a){
    vis[a] = 1;
    cout << a << " ";
    for(auto x:edge[a]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

void solve(){
    int u, v;
    while(cin >> u >> v){
        edge[u].push_back(v);
        edge[v].push_back(u);
        _max = max(_max, max(u, v));
    }
    for(int i = 0 ; i <= _max ; i++){
        if(!vis[i]){
            dfs(i);
            cout << "\n";
        }
    }
}

signed main(){
    Harry55
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}