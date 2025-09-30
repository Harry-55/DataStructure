#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Harry55 ios_base::sync_with_stdio(0), cin.tie(0);

int f(string &s, int l, int r){
    if(l >= r) return 1;
    if(s[l] != s[r]) return 0;
    return f(s, l+1, r-1);
}

signed main(){
    Harry55
    string s;
    cin >> s;
    cout << f(s, 0, s.length()-1);
}