#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int>
#define Harry55 ios::sync_with_stdio(0),cin.tie(0);

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {} 
};

struct Tree{
    Node* root;
    Tree() : root(nullptr) {}
};

void inorder(Node* ptr){
    if(!ptr) return;
    inorder(ptr->left);
    if(ptr->val != 0) cout << ptr->val << " ";
    inorder(ptr->right);
}

void preorder(Node* ptr){
    if(!ptr) return;
    if(ptr->val != 0) cout << ptr->val << " ";
    preorder(ptr->left);
    preorder(ptr->right);
}

// void postorder(Node* ptr){
//     if(!ptr) return;
//     postorder(ptr->left);
//     postorder(ptr->right);
//     if(ptr->val != 0) cout << ptr->val << " ";
// }

Node* _stack[100005];
int top = -1;

void push(Node* ptr) {
    _stack[++top] = ptr;
}
Node* pop() {
    return _stack[top--];
}

void iter_postorder(Node* root) {
    Node* curr = root;
    Node* lastVisited = nullptr;
    while (top != -1 || curr != nullptr) {
        if (curr != nullptr) {
            push(curr);
            curr = curr->left;
        } else {
            Node* peekNode = _stack[top];
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                if(peekNode->val != 0) cout << peekNode->val << " ";
                lastVisited = pop();
            }
        }
    }
}

Node* findNode(Node* ptr, int x){
    if(!ptr) return nullptr;
    if(ptr->val == x) return ptr;
    Node* L = findNode(ptr->left, x);
    if(L) return L;
    return findNode(ptr->right, x);
}
void solve(){
    Tree tree;
    int n;
    cin >> n;
    int x, l, r;
    cin >> x >> l >> r;
    tree.root = new Node(x);
    tree.root->left = new Node(l);
    tree.root->right = new Node(r);
    int _max = -1;
    while(n--){
        int node, left, right;
        cin >> node >> left >> right;
        Node* parent = findNode(tree.root, node);
        if(parent){
            parent->left = new Node(left);
            parent->right = new Node(right);
        } 
    }
    inorder(tree.root);
    cout << "\n";
    preorder(tree.root);
    cout << "\n";
    iter_postorder(tree.root);
}

signed main(){
    Harry55
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}