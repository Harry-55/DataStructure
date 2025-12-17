#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

int arr[1000][1000];
int _max = -1;
struct Node{
    int v;
    Node *next;
    Node(int x){v = x; next = nullptr;}
};

struct Link{
    Node *head;
    Node *tail;
    int size;
    Link(Node *h = nullptr, Node *t = nullptr){
        this->head = h;
        this->tail = t;
        this->size = 0;
    }
    void push(Node *x);
};

void Link::push(Node *x){
    if(this->head == nullptr){
        this->head = x;
        this->tail = x;
    }
    else{
        this->tail->next = x;
        this->tail = x;
    }
    (this->size)++;
}

Link *adj[1000];

void solve(){
    cout << "Adjacency matrix:\n";
    for(int i = 0 ; i < _max + 1 ; i++){
        for(int j = 0 ; j < _max + 1 ; j++) cout << arr[i][j] << " ";
        cout << '\n';
    }

    cout << "\nAdjacency list:\n";
    for(int i = 0 ; i < _max + 1 ; i++){
        if(adj[i]) { 
            cout << i << ": ";
            Node *cur = adj[i]->head;
            while(cur){
                cout << cur->v << " -> ";
                cur = cur->next;
            }
            cout << "end\n";
        }
    }
}

signed main(){
    Harry55;
    int u, v;
    
    while(cin >> u >> v){
        _max = max(_max, max(u, v));
        
        arr[u][v] = 1;
        arr[v][u] = 1;
        
        if(adj[u] == nullptr) adj[u] = new Link();
        if(adj[v] == nullptr) adj[v] = new Link();
        
        adj[u]->push(new Node(v));
        adj[v]->push(new Node(u));
    }
    solve();
    return 0;
}