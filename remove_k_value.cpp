#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node* removeNodes(Node* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }

    // Remove nodes with value k from the beginning of the list
    while (head != nullptr && head->data == k) {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == k) {
            Node* deleteNode = current->next;
            current->next = deleteNode->next;
            delete deleteNode;
        } else {
            current = current->next;
        }
    }

    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "-1" << endl;
}

int main() {
    // Sample Input 1
    Node* head1 = new Node(2);
    head1->next = new Node(5);
    head1->next->next = new Node(7);
    head1->next->next->next = new Node(10);
    head1->next->next->next->next = nullptr;

    Node* head2 = new Node(4);
    head2->next = new Node(9);
    head2->next->next = new Node(10);
    head2->next->next->next = nullptr;

    // Remove nodes with value 7 and 3 from the linked lists
    head1 = removeNodes(head1, 7);
    head2 = removeNodes(head2, 3);

    // Sample Output 1
    printLinkedList(head1); // Output: 2 5 10 -1
    printLinkedList(head2); // Output: 4 9 10 -1

    return 0;
}
