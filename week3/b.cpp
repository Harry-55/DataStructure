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
term d[MAX_TERMS];
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
void storeSum(term d[], int *totalD, int row, int column, int *sum) {
    if (*sum) {
        if (*totalD < MAX_TERMS) {
            d[++*totalD].row = row;
            d[*totalD].col = column;
            d[*totalD].val = *sum;
            *sum = 0;
        } else {
            fprintf(stderr, "Numbers of terms in product exceeds %d\n",
            MAX_TERMS);
            exit(1);
        }
    }
}

int COMPARE(int a, int b){
    if(a < b) return -1;
    if(a == b) return 0;
    return 1;
}
void mat_mult(term A[], term B[], term D[]){
    int totalA = A[0].val, totalB = B[0].val, totalD = 0;
    int rowA = A[0].row, colA = A[0].col, colB = B[0].col;
    int row_begin = 1, row = A[1].row, sum = 0;
    term newB[MAX_TERMS];
    fast_transpose(b, newB);
    A[totalA+1].row = rowA;
    newB[totalB+1].row = colB;
    newB[totalB+1].col = -1;
    for(int i = 1 ; i <= totalA ; ){
        int col = newB[1].row;
        for(int j = 1 ; j <= totalB+1 ; ){
            if(A[i].row != row){
                storeSum(D, &totalD, row, col, &sum);
                i = row_begin;
                for (; newB[j].row == col; j++);
                col = newB[j].row;
            }
            else if(newB[j].row != col){
                storeSum(D, &totalD, row, col, &sum);
                i = row_begin;
                col = newB[j].row;
            }
            else{
                switch (COMPARE(A[i].col, newB[j].col))
                {
                    case -1:
                        i++;
                        break;
                    case 0:
                        sum += A[i++].val * newB[j++].val;
                        break;
                    case 1:
                        j++;
                }
            }
        }
        for (; A[i].row == row; i++);
        row_begin = i;
        row = A[i].row;
    }
    D[0].row = rowA;
    D[0].col = colB;
    D[0].val = totalD;
}

void solve(){
    int n, m, val;
    cin >> n >> m >> val;
    a[0].row = n, a[0].col = m, a[0].val = val;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i].row >> a[i].col >> a[i].val;
    }
    cin >> n >> m >> val;
    b[0].row = n, b[0].col = m, b[0].val = val;
    for(int i = 1 ; i <= n ; i++)
        cin >> b[i].row >> b[i].col >> b[i].val;
    mat_mult(a, b, d);
    for(int i = 0 ; i <= d[0].val ; i++) cout << d[i].row <<" "<< d[i].col <<" "<< d[i].val<< '\n';
}

signed main(){
    solve();
}