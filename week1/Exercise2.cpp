#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Harry55 ios_base::sync_with_stdio(0), cin.tie(0);

void print(int arr[], int ch[], int l){
    bool check = 0;
    for(int i = 0 ; i < l ; i++){
        if(ch[i] == 1){ 
            cout << arr[i] << " ";
            check = 1;
        }
    }
    if(check == 0) cout << "EMPTY-SET";
    else cout << '\n';
}

void f(int num[], int n, int i, int c[]){
    if(i == n){
        print(num, c, n);
        return;
    }
    c[i] = 1;
    f(num, n, i+1, c);
    c[i] = 0;
    f(num, n, i+1, c);
}

signed main(){
    Harry55
    int num[20], c[20], i = 0;
    while(cin >> num[i]){
        i++;
    }
    f(num, i, 0, c);
}
