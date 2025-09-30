#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);
#define MAX_TERMS 101

typedef struct
{
    int col;
    int row;
    int val;
} term;
term a[MAX_TERMS];
term b[MAX_TERMS];

void fast_transpose(term A[], term B[]){
    int row_term[MAX_TERMS], start_pos[MAX_TERMS];
    B[0].col = A[0].row; B[0].row = A[0].col; B[0].val = A[0].val;
    int num_col = A[0].col, num_term = A[0].val;
    if(num_term > 0){
        for(int i = 0 ; i < num_col ; i++) row_term[i] = 0;
        for(int i = 1 ; i <= num_term ; i++) row_term[A[i].col]++;
        start_pos[0] = 1;
        for(int i = 1 ; i < num_col ; i++) start_pos[i] = start_pos[i - 1] + row_term[i - 1];
        for(int i = 1 ; i <= num_term ; i++){
            int pos = start_pos[A[i].col]++;
            B[pos].row = A[i].col;
            B[pos].col = A[i].row;
            B[pos].val = A[i].val;
        }
    }
}

void solve(){
    int n, m, v;
    cin >> n >> m >> v;
    a[0].col = m;
    a[0].row = n;
    a[0].val = v;
    for(int i = 1 ; i <= a[0].val ; i++) cin >> a[i].row >> a[i].col >> a[i].val;
    fast_transpose(a, b);
    for(int i = 0 ; i <= b[0].val ; i++) cout << b[i].row <<" "<< b[i].col <<" "<< b[i].val<< '\n';

}

signed main(){
    Harry55
    solve();
}