#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);
const int MAX = 1e7;
double arr[MAX];
void solve(){

}

signed main(){
    Harry55
    double n;
    int i = 0;
    while(cin >> n){
        arr[i++] = n;
    }
    double x = arr[i - 1];
    double ans = arr[0];
    for(int j = 1 ; j < i - 1 ; j++){
        ans = ans * x + arr[j];
    }
    cout << ans;
}