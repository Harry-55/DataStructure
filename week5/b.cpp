#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Harry55 ios::sync_with_stdio(0), cin.tie(0);

const int MAX = 1e3+5; 
int n, m, start_x, start_y, end_x, end_y;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef struct {
    int x, y;
}Stack;

Stack path[MAX * MAX];
int top = -1;

bool isEmpty() { return top == -1; }
bool isFull() { return top >= MAX * MAX; }

void push(int x, int y) {
    if (!isFull()) path[++top] = {x, y};
}
void pop() { if (!isEmpty()) top--; }

bool check(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

int maze[MAX][MAX];
bool visited[MAX][MAX];
bool found = false;

void dfs(int x, int y) {
    if (found) return;

    visited[x][y] = true;
    push(x, y);

    if (x == end_x && y == end_y) {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny) && !visited[nx][ny] && maze[nx][ny] == 0) {
            dfs(nx, ny);
            if (found) return;
        }
    }
    pop();
    visited[x][y] = false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }

    cin >> start_x >> start_y >> end_x >> end_y;
    dfs(start_x, start_y);

    if (!found) {
        cout << "None";
        return;
    }

    for (int i = 0; i <= top; i++) {
        cout << "(" << path[i].x << ", " << path[i].y << ")";
        if (i < top) cout << " ";
    }
}

signed main() {
    Harry55
    solve();
}
