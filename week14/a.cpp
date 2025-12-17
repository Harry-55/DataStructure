#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

const int N=1e5+5;
int timer = 0, in[N], low[N], visited[N];
vector<int> parent(N, -1);
vector<int> edge[N];
int iscut[N];

void dfs(int root){
    visited[root] = 1;
    in[root] = low[root] = timer++;
    int child_cnt = 0;
    for(auto child: edge[root]){
        if(!visited[child]){
            parent[child] = root;
            child_cnt++; 
            dfs(child);
            low[root] = min(low[root], low[child]);
            if(parent[root] != -1 && low[child] >= in[root])
                iscut[root] = 1;
        }
        else if(child != parent[root]){
            low[root] = min(low[root], in[child]);
        }
    }
    if(parent[root] == -1 && child_cnt >= 2)
        iscut[root] = 1;
}


void solve(){
    int u, v, _max = -1;
    while(cin >> u >> v){
        edge[u].push_back(v);
        edge[v].push_back(u);
        _max = max({_max, u, v});
    }
    for(int i = 0 ; i <= _max ; i++){
        if(!visited[i] && !edge[i].empty()){
            dfs(i);
        }
    }
    vector<int> ans;
    for(int i = 0 ; i <= _max ; i++){
        if(iscut[i]) ans.push_back(i);
    }
    for(int x : ans) cout << x << " ";
    cout << "\n";
}

signed main(){
    Harry55
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
