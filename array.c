
#include <iostream>

const int MAX_SIZE = 100; // Adjust the size according to your needs

class Node {
public:
    int data;
    int next; // Index of the next node

    Node(int value) : data(value), next(-1) {}
};

class LinkedList {
private:
    Node nodes[MAX_SIZE];
    int head;

public:
    LinkedList() : head(-1) {}

    bool isEmpty() {
        return head == -1;
    }

    void append(int value) {
        int newNodeIndex = findEmptyNode();
        if (newNodeIndex == -1) {
            std::cout << "Error: Linked list is full.\n";
            return;
        }

        nodes[newNodeIndex] = Node(value);

        if (isEmpty()) {
            head = newNodeIndex;
        } else {
            int current = head;
            while (nodes[current].next != -1) {
                current = nodes[current].next;
            }
            nodes[current].next = newNodeIndex;
        }
    }

    void display() {
        int current = head;
        while (current != -1) {
            std::cout << nodes[current].data << " -> ";
            current = nodes[current].next;
        }
        std::cout << "nullptr" << std::endl;
    }

private:
    int findEmptyNode() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (nodes[i].next == -1) {
                return i;
            }
        }
        return -1; // No empty nodes
    }
};

int main() {
    LinkedList linkedList;

    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);

    linkedList.display();

    return 0;
}
