#ifdef utils_H
#else
#define utils_H

struct Node {
    // You can make a pointer to indicate the value of a node.
    int key;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    struct Node *parent = nullptr;
};

void Swap(int *A, int i, int j);
void CopyArray(int *A, int *B, int left, int right);

Node MakeNode(int key);
Node MakeNode(int key, Node* left, Node* right);
Node MakeNode(int key, Node* left, Node* right, Node* parent);
Node MakeNode(Node* origin);
Node MakeNode(Node origin);

void LinkNodes(Node* parent, Node* left, Node* right);

Node* DFSStep(Node* node);
#endif