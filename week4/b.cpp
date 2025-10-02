#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[9][9];
bool a = false;
bool check(int n,int p){
    for (int i=0;i<9;i++) {
		int x=n/9;
		if (arr[x][i] == p) {
			return false;
		}
	}
	for (int i=0;i<9;i++) {
		int x=n%9;
		if (arr[i][x] == p) {
			return false;
		}
	}
	int x=n/9/3*3;
	int y=n%9/3*3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (arr[i][j] == p) {
				return false;
			}
		}
	}
	return true;
}
void solve(int n){
    if(n == 81){
        a = true;
        return;
    }
    if(arr[n/9][n%9])solve(n+1);
    for(int i=1;i<10;i++){
        if(check(n,i)){
            arr[n/9][n%9]=i;
            solve(n+1);
            if(a) return;
            arr[n/9][n%9]=0;
        }
    }
    return;
}

signed main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> arr[i][j];
        }
    }
    solve(0);
    for(int i=0;i<9;i++){
        if(i && i % 3 == 0) cout << "- - - - - - - - -\n"; // 每三行加分隔線
        for(int j=0;j<9;j++){
            if(j && j % 3 == 2) cout <<arr[i][j]<< "|"; // 每三列加?線
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

2 0 4 0 5 0 0 0 0
3 0 0 0 9 0 1 0 2
0 7 0 8 1 0 0 0 0
1 3 0 0 0 5 9 0 4
6 0 0 0 0 0 0 0 3
4 0 5 9 0 0 0 6 1
0 0 0 0 4 1 0 5 0
8 0 2 0 3 0 0 0 7
0 0 0 0 2 0 6 0 9
*/