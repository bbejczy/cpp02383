#include <iostream>
#include "fibonacci-tree.h"

using namespace std;



void printNode(int value) {
    cout << value;
}

// leaf
FibonacciTree::FibonacciTree(unsigned int value) {
    this->type = Const;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

// branch
FibonacciTree::FibonacciTree(NodeType type, FibonacciTree *left,
                             FibonacciTree *right) {
    if (type == Const) {
        throw logic_error("BUG: this constructor is for Branch nodes!");
    }
    if ((left == nullptr) || (right == nullptr)) {
        throw logic_error("BUG: Branch nodes must have 2 descendants!");
    }
    this->type = type;
    this->left = left;  
    this->right = right;
    this->value = 0;

}

FibonacciTree::~FibonacciTree() {
    // Uncomment the following line see the order in which nodes are destroyed
    // cout << "Destroying: "; printNode(this->type, this->value); cout << endl;
    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->right != nullptr) {
        delete this->right;
    }
}

unsigned int FibonacciTree::size() {
    if (this->type == Const) {
        return 1;
    } else {
        return 1 + this->left->size() + this->right->size();
    }
}

unsigned int FibonacciTree::height() {
    if (this->type == Const) {
        return 1;
    } else {
        return 1 + max(this->left->height(), this->right->height());
    }
}

unsigned int FibonacciTree::leaves() {
    if (this->type == Const) {
        return 1;
    } else {
        return this->left->leaves() + this->right->leaves();
    }
}

void FibonacciTree::traversePre() {
    printNode(this->value);
    if (this->type == Branch) {
        cout << " ";
        this->left->traversePre();
        cout << " ";
        this->right->traversePre();
    }
}

unsigned int fibonacci(unsigned int n) {
    if (n <= 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

