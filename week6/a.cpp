#include<bits/stdc++.h>
using namespace std;
#define int long long

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum{
    PLUS, MINUS, TIMES, DIVIDE, EOS, OPERAND
} precedence;

precedence Stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top;

int isp[] = {12, 12, 13, 13, 0};
int icp[] = {12, 12, 13, 13, 0};

precedence get_token(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch (*symbol) {
        case '+': return PLUS;
        case '-': return MINUS;
        case '*': return TIMES;
        case '/': return DIVIDE;
        case '\0': return EOS;
        default: return OPERAND;
    }
}

void push(precedence item) { Stack[++top] = item; }
precedence pop() { return Stack[top--]; }

char postfix_arr[MAX_EXPR_SIZE];
int len = 0;

char token_char(precedence token) {
    switch (token) {
        case PLUS: return '+';
        case MINUS: return '-';
        case TIMES: return '*';
        case DIVIDE: return '/';
        default: return ' ';
    }
}

void postfix() {
    int n = 0;
    char c;
    top = 0;
    Stack[0] = EOS;
    precedence token;
    for(token = get_token(&c, &n); token != EOS ; token = get_token(&c, &n)) {
        if(token == OPERAND) {
            postfix_arr[len++] = c;
        } else {
            while(isp[Stack[top]] >= icp[token]) {
                postfix_arr[len++] = token_char(pop());
            }
            push(token);
        }
    }
    while(top > 0) {
        postfix_arr[len++] = token_char(pop());
    }
}

int eval() {
    int s[MAX_STACK_SIZE];
    int t = -1;
    for(int i = 0; i < len; i++) {
        char c = postfix_arr[i];
        if(isdigit(c)) {
            s[++t] = c - '0';
        } else {
            int op2 = s[t--];
            int op1 = s[t--];
            switch(c) {
                case '+': s[++t] = op1 + op2; break;
                case '-': s[++t] = op1 - op2; break;
                case '*': s[++t] = op1 * op2; break;
                case '/': s[++t] = op1 / op2; break;
            }
        }
    }
    return s[t];
}

void solve() {
    string s;
    getline(cin, s);
    int idx = 0;
    for(char c : s) if(c != ' ') expr[idx++] = c;
    expr[idx] = '\0';
    postfix();
    for(int i = 0; i < len; i++) {
        cout << postfix_arr[i] << " ";
    }
    cout << "\n";
    cout << eval() << "\n";
}

signed main() {
    solve();
}
