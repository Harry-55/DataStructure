#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define Harry55 ios::sync_with_stdio(0), cin.tie(0);
#define MAX_TERMS 100

typedef struct {
    float coef;
    int expon;
} poly;

poly terms[MAX_TERMS];
int avail = 0;

int COMPAIR(int x, int y) {
    if (x < y) return -1;
    if (x == y) return 0;
    return 1;
}

void attach(float coef, int expon) {
    terms[avail].coef = coef;
    terms[avail++].expon = expon;
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd) {
    float coefficient;
    *startd = avail;
    while (starta <= finisha && startb <= finishb) {
        switch (COMPAIR(terms[starta].expon, terms[startb].expon)) {
            case -1:
                attach(terms[startb].coef, terms[startb].expon);
                startb++;
                break;
            case 0:
                coefficient = terms[starta].coef + terms[startb].coef;
                if (coefficient) 
                    attach(coefficient, terms[starta].expon);
                starta++;
                startb++;
                break;
            case 1:
                attach(terms[starta].coef, terms[starta].expon);
                starta++;
                break;
        }
    }
    for (; starta <= finisha; starta++)
        attach(terms[starta].coef, terms[starta].expon);
    for (; startb <= finishb; startb++)
        attach(terms[startb].coef, terms[startb].expon);
    *finishd = avail - 1;
}

signed main() {
    Harry55
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> terms[i].coef;
    }
    for (int i = 0; i < m; i++) {
        cin >> terms[i].expon;
    }
    avail = m;
    
    int sa = 0, fa = m - 1;
    int n;
    
    while (cin >> n) {
        int sb = avail;
        int fb = sb + n - 1;
        
        for (int i = 0; i < n; i++) {
            cin >> terms[sb + i].coef;
        }
        for (int i = 0; i < n; i++) {
            cin >> terms[sb + i].expon;
        }
        avail = fb + 1;
        int msa, mfa, msb, mfb, sd, fd;
        msa = avail;
        for (int j = sb; j <= fb; j++) {
            attach(terms[sa].coef * terms[j].coef, terms[sa].expon + terms[j].expon);
        }
        mfa = avail - 1;
        for (int i = sa + 1; i <= fa; i++) {
            msb = avail;
            for (int j = sb; j <= fb; j++) {
                attach(terms[i].coef * terms[j].coef, terms[i].expon + terms[j].expon);
            }
            mfb = avail - 1;
            padd(msa, mfa, msb, mfb, &sd, &fd);
            msa = sd;
            mfa = fd;
        }
        sa = msa;
        fa = mfa;
    }
    cout << fa - sa + 1 << '\n';
    for (int i = sa; i <= fa; i++) {
        cout << terms[i].coef << " ";
    }
    cout << '\n';
    for (int i = sa; i <= fa; i++) {
        cout << terms[i].expon << " ";
    }
}