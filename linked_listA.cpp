#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int countIterative(Node* head) {
    int count = 0;
    while(head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

int countRecursive(Node* head) {
    if(head == nullptr) {
        return 0;
    }
    return 1 + countRecursive(head->next);
}

void insertAtBeggining(Node*& head, int newData) {
    Node* newNode = new Node{newData, head};
    head = newNode;
}

void removeElement(Node*& head, int value) {
    while(head && head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* current = head;
    while(current && current->next) {
        if(current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* head = nullptr;
    cout << "Pusta lista: ";
    printList(head);

    insertAtBeggining(head, 3);
    insertAtBeggining(head, 2);
    insertAtBeggining(head,1);
    cout << "Lista po wstawieniu elementow: ";
    printList(head);

    cout << "Liczba elementow (iteracyjnie)" << countIterative(head) << endl;
    cout << "Liczba elementow (rekursyjnie)" << countRecursive(head) << endl;

    removeElement(head, 2);
    cout << "Lista elementow po usunieciu wartrosci 2: ";
    printList(head);

    return 0;
}
