#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

bool check(int arr[]){
    int stack[20], top = -1, index = 0;
    for (int k = 0; k < 4; k++) {
        int i = arr[k];
        while (index < 4 && (top == -1 || stack[top] != i)) {
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
    int arr[4] = {0, 1, 2, 3};
    do{
        if(!check(arr)){
            for(auto i : arr) cout << i << " ";
            cout << '\n';
        }
    }while(next_permutation(arr, arr+4));
}
signed main(){
    solve();
}