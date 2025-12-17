#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* treePointer;


treePointer modifiedSearch(treePointer node, int k) {
    treePointer parent = NULL;

    while (node != NULL) {
        parent = node;
        if (k == node->key) 
            return NULL; 
        else if (k < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return parent;
}

void insert(treePointer &node, int k) {
    treePointer temp = modifiedSearch(node, k);

    if (temp == NULL && node != NULL)
        return;

    treePointer ptr = new Node;
    ptr->key = k;
    ptr->left = ptr->right = NULL;

    if (node == NULL) {
        node = ptr; 
    } else {
        if (k < temp->key)
            temp->left = ptr;
        else
            temp->right = ptr;
    }
}

void inorder(treePointer t) {
    if (!t) return;
    inorder(t->left);
    cout << t->key << " ";
    inorder(t->right);
}

void preorder(treePointer t) {
    if (!t) return;
    cout << t->key << " ";
    preorder(t->left);
    preorder(t->right);
}

int main() {
    int n;
    cin >> n;
    // cin.ignore();

    treePointer root = NULL;

    // string line;
    // getline(cin, line);
    // stringstream ss(line);

    int x;
    for(int i = 0 ; i < n ; i++)
        cin >> x, insert(root, x);

    inorder(root);
    cout << "\n";

    preorder(root);
    cout << "\n";

    return 0;
}
