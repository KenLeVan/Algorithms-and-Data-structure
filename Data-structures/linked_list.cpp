class Node {
public:
    Node* previous;
    Node* next;
    int value;

    Node() {
        previous = nullptr;
        next = nullptr;
        value = 0;
    }
    Node(int x) : value(x) {
        previous = nullptr;
        next = nullptr;
    }
};

class Linked_list {
private:
    Node* root;
public:
    Linked_list() : root(nullptr) { }

    ~Linked_list() {
        Node* current = root;
        while(current != nullptr) {
            Node* temp = current->next;
            delete(current);
            current = temp;
        }
    }

    bool find(int val) {
        Node* current = root;
        while (current != nullptr) {
            if (current->value == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void node_append(Node* val, Node* pos) {
        if (val == nullptr || pos == nullptr) { return; }

        val->previous = pos;
        val->next = pos->next;

        if (pos->next != nullptr) {
            pos->next->previous = val;
        }

        pos->next = val;
    }

    void node_remove(Node* val) {
        if (val == nullptr) { return; }

        if (val->previous != nullptr) {
            val->previous->next = val->next;
        }
        else {
            root = val->next;
        }

        if (val->next != nullptr) {
            val->next->previous = val->previous;
        }

        delete(val);
    }

    void push_front(Node* val) {
        if (val == nullptr || val->next != nullptr || val->previous != nullptr) { return; }

        if (root == nullptr) {
            root = val;
            return;
        }

        val->next = root;
        root->previous = val;
        root = val;
    }
};