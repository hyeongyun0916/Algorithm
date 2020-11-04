#include <bits/stdc++.h>

using namespace std;

struct Node {
    char value;
    Node *left;
    Node *right;
    Node(char _value)
     : value(_value), left(NULL), right(NULL) {}
    bool operator < (const Node &rhs) const {
        return value < rhs.value;
	}
    bool operator > (const Node &rhs) const {
        return value > rhs.value;
	}
};

void preOrder(Node *node) {
    if (node == NULL) return;
    cout << node->value;
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->value;
    inOrder(node->right);
}

void postOrder(Node *node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    map<char, Node*> nodes;
    cin >> n;

    char x,y,z;
    cin >> x >> y >> z;
    Node *root = new Node(x);
    nodes[x] = root;
    if (y != '.') nodes[y] = root->left = new Node(y);
    if (z != '.') nodes[z] = root->right = new Node(z);

    for (int i = 0; i < n-1; i++) {
        cin >> x >> y >> z;
        Node *tempRoot = NULL; 

        if (nodes.find(x) == nodes.end()) {
            nodes[x] = tempRoot = new Node(x);
        } else {
            tempRoot = nodes[x];
        }

        if (y != '.') {
            if (nodes.find(y) == nodes.end()) {
                nodes[y] = tempRoot->left = new Node(y);
            } else {
                tempRoot->left = nodes[y];
            }
        }

        if (z != '.') {
            if (nodes.find(z) == nodes.end()) {
                nodes[z] = tempRoot->right = new Node(z);
            } else {
                tempRoot->right = nodes[z];
            }
        }

    }

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);


    return 0;
}