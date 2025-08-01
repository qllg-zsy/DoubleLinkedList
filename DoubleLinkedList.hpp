#include <iostream>

template<class T>
class doubleLinkedListNode {
public:
    doubleLinkedListNode() {
        prior = NULL;
        next = NULL;
    }

    doubleLinkedListNode(T data, doubleLinkedListNode<T>* prior = NULL, doubleLinkedListNode<T>* next = NULL) :
        data(data), prior(prior), next(next) {
    }

    ~doubleLinkedListNode() {
        prior = NULL;
        next = NULL;
    }

    doubleLinkedListNode<T>* prior;
    doubleLinkedListNode<T>* next;
    T data;

};

template <class T>
class doubleLinkedList {
public:
    doubleLinkedList() {
        head = new doubleLinkedListNode<T>();
        length = 0;
    }

    doubleLinkedList(doubleLinkedListNode<T>* head) : head(head) {
        length = 0;
    }

    ~doubleLinkedList() {
        delete head;
    }

    // Inserting a node (tail)
    bool insertNodeBytail(T node);

    // print List
    void printLinkedList();

private:
    doubleLinkedListNode<T>* head;
    int length;
};

template<class T>
bool doubleLinkedList<T>::insertNodeBytail(T node) {
    doubleLinkedListNode<T>* newNode = new doubleLinkedListNode<T>(node);
    if (newNode == NULL) {
        std::cout << "fail to construct a new node" << std::endl;
        return false;
    }

    // find the last node
    doubleLinkedListNode<T>* lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // adjust the pointer
    lastNode->next = newNode;
    newNode->prior = lastNode;
    return true;
}

template<class T>
void doubleLinkedList<T>::printLinkedList() {

    // print node from the second node
    doubleLinkedListNode<T>* pMove = head->next;
    while (pMove) {
        std::cout << pMove->data << " ";
        pMove = pMove->next;
    }
    std::cout << std::endl;
}
