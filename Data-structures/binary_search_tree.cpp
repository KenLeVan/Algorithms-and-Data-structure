#include <string>

class Node {
public:
    Node* parent = nullptr;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    int value = 0;

    Node(int val) : value(val) { }
};

class BST {
private:
    Node* root = nullptr;

    void node_remove_recursive(Node* node) {
        if (node == nullptr) return;

        node_remove_recursive(node->left_child);
        node_remove_recursive(node->right_child);
        delete node;
    }
public:
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    ~BST() {
        node_remove_recursive(root);
    }

    void node_remove(Node* node) {
        if (node == nullptr) return;

        if (node->left_child == nullptr || node->right_child == nullptr) {
            Node* child = (node->left_child != nullptr) ? node->left_child : node->right_child;

            if (node->parent == nullptr) {
                root = child;
                if (child != nullptr) {
                    child->parent = nullptr;
                }
            }
            else {
                if (node == node->parent->left_child) {
                    node->parent->left_child = child;
                }
                else {
                    node->parent->right_child = child;
                }

                if (child != nullptr) {
                    child->parent = node->parent;
                }
            }

            delete node;
            return;
        }

        Node* successor = node->right_child;
        while (successor->left_child != nullptr) {
            successor = successor->left_child;
        }

        node->value = successor->value;
        node_remove(successor);
    }

    void node_append(Node* node) {
        if (node == nullptr || node->left_child != nullptr || node->right_child != nullptr || node->parent != nullptr) return;

        if (root == nullptr) {
            root = node;
            return;
        }

        Node* current = root;
        Node* previous = nullptr;

        while(current != nullptr) {
            if (node->value == current->value) {
                return;
            }

            previous = current;
            if (node->value < current->value) {
                current = current->left_child;
            }
            else {
                current = current->right_child;
            }
        }

        if (node->value < previous->value) {
            previous->left_child = node;
        }
        else {
            previous->right_child = node;
        }
        node->parent = previous;
    }
};