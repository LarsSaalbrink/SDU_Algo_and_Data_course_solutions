#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

template <typename T>
class Singly_linked_list {
public:
    Singly_linked_list();
    ~Singly_linked_list();
    unsigned int size() const;
    void print_content() const;
    bool is_present(T value) const;
    void insert(T value);
    void remove(T value);

private:
    struct Node {
        T value;
        Node* next;
    };
    Node* head;
};

template <typename T>
Singly_linked_list<T>::Singly_linked_list() {
    head = nullptr;
}

template <typename T>
Singly_linked_list<T>::~Singly_linked_list() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
unsigned int Singly_linked_list<T>::size() const {
    unsigned int size = 0;
    Node* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

template <typename T>
void Singly_linked_list<T>::print_content() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool Singly_linked_list<T>::is_present(T value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

//No duplicates allowed
template <typename T>
void Singly_linked_list<T>::insert(T value) {
    if (head == nullptr) {
        head = new Node{value, nullptr};
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        if (current->value == value) {  //Check for duplicates during traversal
            return;
        }
        current = current->next;
    }
    if (current->value == value) {  //Check for duplicate at the end
        return;
    }
    current->next = new Node{value, nullptr};
}

template <typename T>
void Singly_linked_list<T>::remove(T value) {
    if (head == nullptr) {
        return;
    }
    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->value == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

#endif // SINGLY_LINKED_LIST_H
