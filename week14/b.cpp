#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

struct Edge{
    int v, w;
};

vector<vector<Edge>> graph(1000);
vector<int> is_visit(1000, 0);
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq; // w, u, v

void solve(){
    int start; 
    cin >> start;

    int u, v, w, _max = -1;

    while(cin >> u >> v >> w){
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        _max = max({_max, u, v});
    }

    for(auto &i: graph[start])
        pq.push({i.w, start, i.v});

    is_visit[start] = 1;
    int weight = 0;

    while(!pq.empty()){
        auto [w, u, v] = pq.top();
        pq.pop();

        if(is_visit[v]) continue;

        cout << "(" << u << " " << v << ") ";

        is_visit[v] = 1;
        weight += w;

        for(auto &i: graph[v]){
            if(!is_visit[i.v]){
                pq.push({i.w, v, i.v});
            }
        }
    }
    cout << "\n" << weight << "\n";
}

signed main(){
    Harry55
    solve();
    return 0;
}
