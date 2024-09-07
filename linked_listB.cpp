#include <iostream>

using namespace std;

struct  Node {
    int data;
    Node* next;
    Node* prev;
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

void insertAtBeggining(Node* head, int newData) {
    Node* newNode = new Node{newData, newNode, nullptr};
    if(head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void removeElement(Node* head, int value) {
    while(head && head->data == value) {
        Node* temp = head;
        head = head->next;
        if(head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }
    Node* current = head;
    while(current && current->next) {
        if(current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            if(current->next != nullptr) {
                current->next->prev = current;
            }
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

    cout << "Lista po dodaniu elementow: ";
    insertAtBeggining(head, 3);
    insertAtBeggining(head, 2);
    insertAtBeggining(head, 1);
    printList(head);

    cout << "Liczenie elementow listy (iteracyjnie): ";
    countIterative(head);
    cout << "Liczenie elementow listy (rekurencyjnie): ";
    countRecursive(head);

    cout << "Lista elementow po usunieciu elementu 3: ";
    removeElement(head, 3);
    printList(head);

    return 0;
}
