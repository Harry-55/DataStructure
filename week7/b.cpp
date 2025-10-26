#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Harry55 ios::sync_with_stdio(0), cin.tie(0);

class poly {
public:
    double coef;
    int expon;
    poly *next;
    poly(double c, int e, poly *n = nullptr) : coef(c), expon(e), next(n) {}
};

class polyList {
    public:
        poly *head;
        poly *tail;
        int size;
        polyList(poly *h = nullptr, poly *t = nullptr) {
            this->head = h;
            this->tail = t;
            this->size = 0;
        }
        void push(poly *node);
};

void polyList::push(poly *node) {
    if (this->head == nullptr) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
    (this->size)++;
}

polyList *polyAdd(polyList *a, polyList *b) {
    polyList *ans = new polyList();
    poly *aTerm = a->head;
    poly *bTerm = b->head;

    while (aTerm != nullptr && bTerm != nullptr) {
        if (aTerm->expon > bTerm->expon) {
            ans->push(new poly(aTerm->coef, aTerm->expon));
            aTerm = aTerm->next;
        } else if (aTerm->expon < bTerm->expon) {
            ans->push(new poly(bTerm->coef, bTerm->expon));
            bTerm = bTerm->next;
        } else {
            double sum = aTerm->coef + bTerm->coef;
            if (fabs(sum) > 1e-9)
                ans->push(new poly(sum, aTerm->expon));
            aTerm = aTerm->next;
            bTerm = bTerm->next;
        }
    }
    while (aTerm != nullptr) {
        ans->push(new poly(aTerm->coef, aTerm->expon));
        aTerm = aTerm->next;
    }
    while (bTerm != nullptr) {
        ans->push(new poly(bTerm->coef, bTerm->expon));
        bTerm = bTerm->next;
    }
    return ans;
}

polyList *mul(polyList *a, polyList *b) {
    polyList *ans = new polyList();
    poly *aTerm = a->head;
    while (aTerm != nullptr) {
        poly *bTerm = b->head;
        polyList *tmp = new polyList();
        while (bTerm != nullptr) {
            tmp->push(new poly(aTerm->coef * bTerm->coef, aTerm->expon + bTerm->expon));
            bTerm = bTerm->next;
        }
        ans = polyAdd(ans, tmp);
        aTerm = aTerm->next;
    }
    return ans;
}

void solve() {
    int n;
    polyList *poly1 = new polyList();
    polyList *poly2 = new polyList();

    cin >> n;
    double carr[1000];
    int earr[1000];
    for (int i = 0; i < n; i++) cin >> carr[i];
    for (int i = 0; i < n; i++) cin >> earr[i];
    for (int i = 0; i < n; i++) poly1->push(new poly(carr[i], earr[i]));

    cin >> n;
    for (int i = 0; i < n; i++) cin >> carr[i];
    for (int i = 0; i < n; i++) cin >> earr[i];
    for (int i = 0; i < n; i++) poly2->push(new poly(carr[i], earr[i]));
    
    polyList *result = mul(poly1, poly2);
    int cnt = 0;
    cout << result->size << "\n";

    for (poly *t = result->head; t; t = t->next) cout << t->coef << " ";
    cout << "\n";
    for (poly *t = result->head; t; t = t->next) cout << t->expon << " ";
    cout << "\n";
}

signed main() {
    Harry55;
    solve();
}