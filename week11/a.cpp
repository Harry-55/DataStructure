#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) ((n) == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!(n))

struct element {
    int key;
};

element heapArr[MAX_ELEMENTS];
int n = 0;

void push(element item, int *n) {
    int i;
    if (HEAP_FULL(*n)) {
        cout << "The heap is full.\n";
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heapArr[i / 2].key)) {
        heapArr[i] = heapArr[i / 2];
        i /= 2;
    }
    heapArr[i] = item;
}

element pop(int *n) {
    int parent, child;
    element item, temp;

    if (HEAP_EMPTY(*n)) {
        cerr << "The heap is empty\n";
        exit(EXIT_FAILURE);
    }

    item = heapArr[1];
    temp = heapArr[(*n)--];
    parent = 1;
    child = 2;

    while (child <= *n) {
        if (child < *n && heapArr[child].key < heapArr[child + 1].key)
            child++;

        if (temp.key >= heapArr[child].key)
            break;

        heapArr[parent] = heapArr[child];
        parent = child;
        child *= 2;
    }
    heapArr[parent] = temp;

    return item;
}

int main() {
    string line;
    element item;
    
    getline(cin, line);
    stringstream ss(line);
    
    int x;
    while (ss >> x) {
        item.key = x;
        push(item, &n);
    }

    int delTimes;
    cin >> delTimes;

    for (int i = 0; i < delTimes; i++)
        pop(&n);
    for (int i = 1; i <= n; i++) {
        cout << "(" << i << ", " << heapArr[i].key << ") ";
    }
    cout << "\n";

    return 0;
}
