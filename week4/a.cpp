#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);
#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

int f[MAX_PATTERN_SIZE];
char s[MAX_STRING_SIZE];
char p[MAX_PATTERN_SIZE];

void fail(const char *s, int *pi){
    int len = strlen(s);
    pi[0] = 0;
    for(int i = 1, j = 0 ; i < len ; i++){
        j = pi[i - 1];
        while(j && (p[j] != p[i])) j = pi[j - 1];
        if(s[j] == s[i]) j++;
        pi[i] = j;
    }
}

int KMP(char *s, char *p){
    int i = 0, j = 0;
    int n = strlen(s), m = strlen(p);
    while(i < n && j < m){
        if(s[i] == p[j])i++, j++;
        else if(j == 0) i++;
        else j = f[j-1];
    }
    return (j == m) ? (i - m) : -1;
}
/*
s = "ababa baca" 
p = "  aba baca"
    0 0 1 2 3 0 1

*/
void solve(){
    cin >> s >> p;
    fail(p, f);
    cout << KMP(s, p);
}

signed main(){
    Harry55
    solve();
}