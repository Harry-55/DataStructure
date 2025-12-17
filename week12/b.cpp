#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);
int n;
int arr[1000][1000];
int vis[1000];
void dfs(int u){
    vis[u] = 1;
    for(int i = 0 ; i < n ; i++){
        if(arr[u][i] && !vis[i]) dfs(i);
    }
}

signed main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++) cin >> arr[i][j];
    dfs(0);
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            cout << -1;
            return 0;
        }
    }
    cout << 1;
}