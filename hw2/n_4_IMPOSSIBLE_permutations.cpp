#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

bool check(int arr[]){
    int stack[3], top = -1, index = 0;
    for (int k = 0; k < 4; k++) {
        int i = arr[k];
        while (index < 4 && (top == -1 || stack[top] != i) && top < 2) {
            stack[++top] = index;
            index++;
        }
        if (stack[top] == i)
            top--;
        else
            return false;
    }
    return true;
}   
void solve(){
    int arr[24][4] = {
        {0, 1, 2, 3},{0, 1, 3, 2},{0, 2, 1, 3},{0, 2, 3, 1},
        {0, 3, 1, 2},{0, 3, 2, 1},{1, 0, 2, 3},{1, 0, 3, 2},
        {1, 2, 0, 3},{1, 2, 3, 0},{1, 3, 0, 2},{1, 3, 2, 0},
        {2, 0, 1, 3},{2, 0, 3, 1},{2, 1, 0, 3},{2, 1, 3, 0},
        {2, 3, 0, 1},{2, 3, 1, 0},{3, 0, 1, 2},{3, 0, 2, 1},
        {3, 1, 0, 2},{3, 1, 2, 0},{3, 2, 0, 1},{3, 2, 1, 0}
    };
    for(int i = 0 ; i < 24 ; i++){
        if(!check(arr[i])){
            for(auto j : arr[i]) cout << j << " ";
            cout << '\n';
        }
    }
}
signed main(){
    solve();
}