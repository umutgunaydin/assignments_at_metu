#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &rhs);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);
    void mergeNodes(int sourceIndex, int destIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    head = NULL;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)
{   
    /* TODO */
    head = NULL;
    *this = rhs;
    size = rhs.size;
}

template<class T>
LinkedList<T>::~LinkedList()
{   
    /* TODO */
    size = 0;
    removeAllNodes();
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    if (this != &rhs) {
        removeAllNodes();

        Node<T> *r = rhs.head;
        while (r != NULL) {
            append(r->data);
            r = r->next;
        }
    }
    size = rhs.size;
    return *this;
}

template<class T>
int LinkedList<T>::getSize() const
{
    /* TODO */
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    /* TODO */
    if (head != NULL) {
        return false;
    } else {
        return true;
    }
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    /* TODO */
    Node<T> *current = head;

    while (current != NULL) {
        if ((current->data == node.data) && ((current->prev!=NULL && node.prev!=NULL) ? current->prev->data==node.prev->data : (current->prev==NULL && node.prev==NULL))
             &&  ((current->next!=NULL && node.next!=NULL) ? current->next->data==node.next->data : (current->next==NULL && node.next==NULL))) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if (isEmpty()) {
        return NULL;
    } else {
        return head;
    }
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    /* TODO */
    Node<T> *current = head;

    if (isEmpty()) {
        return NULL;
    }

    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    return current;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
    Node<T> *current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
    /* TODO */
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

template<class T>
void LinkedList<T>::append(const T &data)
{   
    /* TODO */
    if (head == NULL) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node<T>(data);
        current->next->prev = current;
    }
    size++;
}

template<class T>
void LinkedList<T>::prepend(const T &data)
{
    /* TODO */
    if (head == NULL) {
        head = new Node<T>(data);
    } else {
        Node<T> * newNode = new Node<T>(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    /* TODO */
    Node<T> *current = head;

    while (current != NULL) {
        if ((current->data == node->data) && ((current->prev!=NULL && node->prev!=NULL) ? current->prev->data==node->prev->data : (current->prev==NULL && node->prev==NULL))
             &&  ((current->next!=NULL && node->next!=NULL) ? current->next->data==node->next->data : (current->next==NULL && node->next==NULL))) {
            Node<T> *newNode = new Node<T>(data);
           
            newNode->next = current->next;
            if(current->next != NULL){
                current->next->prev = newNode;
            }
            newNode->prev = current;
            current->next = newNode;
            size++;
            return;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    /* TODO */
    Node<T> *current = head;

    if(head==NULL){
        Node<T> *newNode = new Node<T>(data);
        head = newNode;
        size++;
        return;
    }
    
    if (index == 0) {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
        return;
    }

    int i = 0;
    while (current != NULL) {
        if (i == index) {
            Node<T> *newNode = new Node<T>(data);
            newNode->next = current->next;
            
            if(current->next != NULL)
            current->next->prev = newNode;
            
            newNode->prev = current;
            current->next = newNode;
            size++;
            return;
        }
        current = current->next;
        i++;
    }
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    /* TODO */
    Node<T> *current = head;

    int i = 0;
    while (current != NULL) {
        if ((current->data == node.data) && ((current->prev!=NULL && node.prev!=NULL) ? current->prev->data==node.prev->data : (current->prev==NULL && node.prev==NULL))
             &&  ((current->next!=NULL && node.next!=NULL) ? current->next->data==node.next->data : (current->next==NULL && node.next==NULL))) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    /* TODO */
    if (currentIndex >= size || currentIndex < 0 || newIndex < 0 || currentIndex == newIndex || head == NULL) {
        return;
    }

    Node<T> *current = getNodeAtIndex(currentIndex);
    Node<T> *prev = current->prev;
    Node<T> *next = current->next;

    if (newIndex >= size) {
        if (prev) {
            prev->next = current->next;
            if(next!=NULL)
            next->prev=prev;
        } else {
            head = current->next;
            if(next!=NULL)
            next->prev=NULL;
        }

        Node<T> *last = getLastNode();

        last->next = current;
        current->next = NULL;
        current->prev = last;
    } else {
        
        Node<T> *newCurrent = getNodeAtIndex(newIndex);
        Node<T> *newPrev = newCurrent->prev;

        if (prev) {
                prev->next = current->next;
                if(next!=NULL)
                next->prev=prev;
        } else {
                head = current->next;
                if(next!=NULL)
                next->prev=NULL;
        }

        if(newIndex<currentIndex){
            if (newPrev) {
                newPrev->next = current;
                current->prev = newPrev;
            } else {
                head = current;
            }
    
            current->next = newCurrent;
            newCurrent->prev = current;
        }else{
            newPrev=newCurrent;
            newCurrent=newCurrent->next;
            if (newPrev) {
                newPrev->next = current;
                current->prev = newPrev;
            } else {
                head = current;
            }
    
            current->next = newCurrent;
            if(newCurrent!=NULL)
            newCurrent->prev = current;
        }
    }
}

template<class T>
void LinkedList<T>::mergeNodes(int sourceIndex, int destIndex)
{
    /* TODO */
    if (sourceIndex<0 || sourceIndex>=size || destIndex<0 || destIndex>=size) return;

    Node<T> *current1 = getNodeAtIndex(sourceIndex);
    Node<T> *prev1 = current1->prev;
    Node<T> *next1 = current1->next;

    Node<T> *current2 = getNodeAtIndex(destIndex);
    current2->data = current2->data + current1->data;
    if(prev1 != NULL)
    prev1->next=next1;
    if(next1 != NULL)
    next1->prev=prev1;
    
    delete current1;
    size--;
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{   
    /* TODO */
    Node<T> *current = head;

    while (current != NULL) {
        if ((current->data == node->data) && ((current->prev!=NULL && node->prev!=NULL) ? current->prev->data==node->prev->data : (current->prev==NULL && node->prev==NULL))
             &&  ((current->next!=NULL && node->next!=NULL) ? current->next->data==node->next->data : (current->next==NULL && node->next==NULL))) {
            Node<T> *prev = current->prev;
            Node<T> *next = current->next;
            
            if(current == head){
                head=current->next;
            }
            
            if(prev!=NULL)
            prev->next = next;
            if(next!=NULL)
            next->prev = prev;
            
            current->prev = NULL;
            current->next = NULL;
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{   
    /* TODO */
    Node<T> *current = head;
    
    while (current != NULL) {
        if (head->data == data){
            Node<T> *next = head->next;
            next->prev=NULL;
            delete head;
            head=next;
            current=head;
            size--;
            continue;
        }
        
        if (current->data == data) {
            Node<T> *prev = current->prev;
            Node<T> *next = current->next;
            prev->next = next;
            if (next!=NULL)
            next->prev = prev;
            current->prev = NULL;
            current->next = NULL;
            delete current;
            size--;
            current=next;
            continue;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    /* TODO */
    Node<T> *current = getNodeAtIndex(index);
    Node<T> *prev = current->prev;
    Node<T> *next = current->next;

    if(index == 0){
        head=next;
        
        if(next!=NULL)
        next->prev=NULL;
        
        current->prev = NULL;
        current->next = NULL;
        delete current;
        size--;
        return;
    }

    prev->next = next;
    
    if(next!=NULL)
    next->prev = prev;
    
    current->prev = NULL;
    current->next = NULL;
    delete current;
    size--;
}

template<class T>
void LinkedList<T>::removeAllNodes()
{   
    /* TODO */
    Node<T> *current = head;

     while (current != NULL) {
        Node<T> *next = current->next;
        current->prev = NULL;
        current->next = NULL;
        delete current;
        size--;
        current=next;
    }
    head=NULL;
}

template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    while(node)
    {
        std::cout << *node << std::endl;
        node = node->next;
    }

}

#endif //LINKEDLIST_H