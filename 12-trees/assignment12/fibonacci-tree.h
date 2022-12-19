#ifndef __fibonacci_tree__
#define __fibonacci_tree__

enum NodeType {Const, Branch};

unsigned int fibonacci(unsigned int n);

class FibonacciTree {
public:
    FibonacciTree(unsigned int value);

    FibonacciTree(NodeType type, FibonacciTree *left,
                                 FibonacciTree *right);

    ~FibonacciTree(); // Destructor

    unsigned int size();   // Size of the tree
    unsigned int height(); // Height of the tree
    unsigned int leaves(); // Number of leaves/constants in the tree
    void traversePre();    // Print nodes in pre-order (prefix notation)
    void populate();       // Evaluate the tree and store the result in 'value'

private:
    NodeType type;  // This is either Const, Add or Multiply
    int value;      // If the node is a leaf (type == Const), this is its value
    FibonacciTree *left;  // Pointer to left sub-expression tree
    FibonacciTree *right; // pointer to right sub-expression tree
};

#endif // __fibonacci_tree__