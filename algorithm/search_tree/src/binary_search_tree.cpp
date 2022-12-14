#include <iostream>
#include "utils.h"

using namespace std;

class BinarySearchTree {
    private:
    Node* rootNode = nullptr;
    Node* iterNode = nullptr;
    uint len = 0;
    int iterIdx = 0;

    Node* _search(Node* node, int key) {
        if(node == nullptr || node->key == key) return node;

        Node* child = node->key > key ? node->left : node->right;
        return _search(child, key);
    }

    void _insert(Node* tree, Node* node) {
        if(tree->key > node->key) {
            if(tree->left != nullptr) _insert(tree->left, node);
            else LinkNodes(tree, node, tree->right);
        }
        else {
            if(tree->right != nullptr) _insert(tree->right, node);
            else LinkNodes(tree, tree->left, node);
        }
    }

    Node* _delete(Node* target) {
        if(target->left == nullptr && target->right == nullptr) return nullptr;
        else if(target->left != nullptr && target->right == nullptr) return target->left;
        else if(target->left == nullptr && target->right != nullptr) return target->right;
        else {
            Node* parent = nullptr;
            Node* substitute = target->right;
            while(substitute->left != nullptr) {
                parent = substitute;
                substitute = substitute->left;
            }
            target->key = substitute->key;

            if(substitute->key == target->right->key) LinkNodes(target, target->left, substitute->right);
            else LinkNodes(parent, substitute->right, parent->right);

            return target;
        }

    }

    public:
    BinarySearchTree() { }
    BinarySearchTree(Node root) { 
        *(this->rootNode) = root;
        len++;
    }
    BinarySearchTree(int rootKey) { 
        Node node = MakeNode(rootKey, nullptr, nullptr);
        *(this->rootNode) = node;
        len++;
    }
    ~BinarySearchTree() { }

// { getters
    Node* root() {
        return this->rootNode;
    }
    
    int length() {
        return len;
    }
// }

// { basics
    bool Search(int key) {
        Node* res = _search(this->rootNode, key);
        return res != nullptr;
    }

    bool Search(int key, Node*& result) {
        Node* res = _search(this->rootNode, key);
        if(res == nullptr) return false;
        else {
            result = res;
            return true;
        }
    }

    void Insert(Node* node) {
        if(Search(node->key)) return;

        if(this->rootNode == nullptr) this->rootNode = node;
        else _insert(this->rootNode, node);
        len++;
    }

    bool Delete(int key, Node& result) {
        Node* target;
        if(!Search(key, target)) return false;
        result = MakeNode(target);


        if(this->rootNode != nullptr && this->rootNode->key == key) {
            Node* alter = _delete(target);
            // TODO: ?????? ??????????????? ?????? ???????????? ?????????? ?????????????
            // delete this->rootNode; -----> ????????? "munmap_chunk(): invalid pointer"
            if(alter) this->rootNode = alter;
            else this->rootNode = nullptr;
        }
        else {
            Node* alter = _delete(target);
            if(alter) {
                if(target->parent->left->key == target->key) LinkNodes(target->parent, alter, nullptr);
                else LinkNodes(target->parent, nullptr, alter);
            }
            else {
                if(target->parent->left->key == target->key) target->parent->left = nullptr;
                else target->parent->right = nullptr;
            }
        }
        // TODO ?????? ?????? ????????? ??????...
        // delete target; --> ????????? ??????
        len--;
        return true;
    }
// }

// { functions
Node* IterDFS() {
    if(iterIdx >= length()) iterIdx = 0;
    if(iterIdx == 0) iterNode = rootNode;
    else iterNode = DFSStep(iterNode);
    iterIdx++;
    return iterNode;
}
//}
};


void PrintTree(BinarySearchTree* tree) {
    cout << "Print Tree" << endl;
    for(int i = 0; i < tree->length(); i++) {
        Node* node = tree->IterDFS();
        printf(
            "\tcurr: %d --> left: %d --> right: %d\n", 
            node->key, 
            (node->left != nullptr) ? node->left->key : -1,
            (node->right != nullptr) ? node->right->key : -1
        );
    }
}

void TestSearch(BinarySearchTree* tree, int* keyList, int N) {
    cout << "------------------------------------------------------------------" << endl;
    cout << "Test Search" << endl;

    for(int i = 0; i < tree->length(); i++) {
        Node* currNode = tree->IterDFS();
        Node* searchResult;
        int key = currNode->key;
        bool ret = tree->Search(key, searchResult);
        if(ret) {
            printf(
                "\tSUCCESS curr: %d --> left: %d --> right: %d\n", 
                currNode->key, 
                (currNode->left != nullptr) ? currNode->left->key : -1,
                (currNode->right != nullptr) ? currNode->right->key : -1
            );
        }
        else cout << "FAIL " << key << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}

void TestDelete(BinarySearchTree* tree, int key, int* keyList, int N) {
    cout << "------------------------------------------------------------------" << endl;
    cout << "Test Delete" << endl;

    Node result;
    tree->Delete(key, result);
    printf(
        "Call Delete(%d) --> %s\n", 
        key, 
        (key == result.key) ? "SUCCESS" : "FAIL"
    );
    PrintTree(tree);
    cout << "------------------------------------------------------------------" << endl;
}

int main() {
    BinarySearchTree* tree = new BinarySearchTree;
    int keyList[8] = {30, 20, 25, 40, 10, 35, 23, 21};
    Node nodes[8];
    
    // Test Insert
    for(int i = 0; i < sizeof(keyList) / sizeof(int); i++) {
        nodes[i] = MakeNode(keyList[i], nullptr, nullptr);
        tree->Insert(&nodes[i]);
    }
    PrintTree(tree);

    // Test Search
    TestSearch(tree, keyList, sizeof(keyList) / sizeof(int));
    cout << endl;

    // Test Delete
    TestDelete(tree, 21, keyList, sizeof(keyList) / sizeof(int));
    cout << endl;
    TestDelete(tree, 30, keyList, sizeof(keyList) / sizeof(int));
    cout << endl;
    TestDelete(tree, 23, keyList, sizeof(keyList) / sizeof(int));
}