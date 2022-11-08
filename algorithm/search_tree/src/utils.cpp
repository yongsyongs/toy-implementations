#include <iostream>
#include "utils.h"


void Swap(int *A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void CopyArray(int *A, int *B, int left, int right) {
    for(int i = left; i <= right; i++)
        B[i] = A[i];
}

Node MakeNode(int key) {
    Node node;
    node.key = key;
    return node;
}

Node MakeNode(int key, Node* left, Node* right) {
    Node node;
    node.key = key;
    node.left = left;
    node.right = right;
    return node;
}

Node MakeNode(int key, Node* left, Node* right, Node* parent) {
    Node node;
    node.key = key;
    node.left = left;
    node.right = right;
    node.parent = parent;
    return node;
}

Node MakeNode(Node* origin) {
    Node node = MakeNode(
        origin->key,
        origin->left,
        origin->right,
        origin->parent
    );
    return node;
}

Node MakeNode(Node origin) {
    Node node = MakeNode(
        origin.key,
        origin.left,
        origin.right,
        origin.parent
    );
    return node;
}

void LinkNodes(Node* parent, Node* left, Node* right) {
    if(left) {
        parent->left = left;
        left->parent = parent;
    }
    else parent->left = nullptr;
    if(right) {
        parent->right = right;
        right->parent = parent;
    }
    else parent->right = nullptr;
}

Node* _dfsStep(Node* node, bool isDownstream, bool fromLeft) {
    if(node != nullptr) {
        if(isDownstream) {
            if(node->left) return node->left;
            else if(node->right) return node->right;
            else if(node->parent) return _dfsStep(node->parent, false, node->parent->left->key == node->key);
        }
        else {
            if(fromLeft && node->right != nullptr) return node->right;
            else if(node->parent) return _dfsStep(node->parent, false, node->parent->left->key == node->key);
        }
    }
    return nullptr;
}

Node* DFSStep(Node* node) {
    if(node == nullptr) return nullptr;
    return _dfsStep(node, true, false);
}