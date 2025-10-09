#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

int front = 0, rear = 0, n;
typedef struct{
    int x;
}query;

bool isEmpty(){
    return front == rear;
}
bool isFull(){
    return front == (rear + 1) % n;
}

void push(int x, query q[]){
    if(!isFull()){
        rear = (rear + 1) % n;
        q[rear].x = x;
    }
    else {
        cout << "FULL\n";
        for(int i = 0 ; i < n ; i++){
            cout << q[i].x << " ";
        }
        cout << '\n';
    }
}
int pop(query q[]){
    if(!isEmpty()){
        front = (front + 1) % n;
        return q[front].x;
    }
    else {
        cout << "EMPTY\n";
        return -1;
    }
}


void solve(){
    cin >> n;
    query arr[n];
    int key, value;
    cin >> key;
    if(key == 1) cin >> value;
    while(key != -1){
        if(key == 1){
            push(value, arr);
        }
        else{
            value = pop(arr);
            if(value != -1) cout << value << '\n';
        }
        cin >> key;
        if(key == 1) cin >> value;
    }
}

signed main(){
    Harry55
    solve();
}
/*
4
1 5
1 6
0
1 7
1 8
1 9
0
0
0
0
-1
*/