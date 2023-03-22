// ListasLigadasLiss.cpp : lisseth
//

#include <iostream>

class Node {
public:
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}

    int value;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    void selectNext() {
        if (current == nullptr) {
            current = head;
        }
        else if (current->next != nullptr) {
            current = current->next;
        }
    }

    void selectPrev() {
        if (current == nullptr) {
            current = tail;
        }
        else if (current->prev != nullptr) {
            current = current->prev;
        }
    }

    void printSelected() {
        if (current != nullptr) {
            std::cout << "Selected: " << current->value << std::endl;
        }
    }

private:
    Node* head;
    Node* tail;
    Node* current;
};

//navegar por el inventario 

int main() {
    DoubleLinkedList inventory;

    inventory.append(10);
    inventory.append(20);
    inventory.append(30);
    inventory.append(40);
    inventory.append(50);

    inventory.print();
    inventory.selectNext();
    inventory.printSelected();
    inventory.selectNext();
    inventory.printSelected();
    inventory.selectPrev();
    inventory.printSelected();
    inventory.selectPrev();
    inventory.printSelected();

    return 0;
}