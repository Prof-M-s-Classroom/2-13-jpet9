#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        //if list is empty, error message returned
        if (head == NULL) {
            cout<< "list is empty" << endl;
            return;
        }

        // //if index is out of bounds, error message returns
        if (index < 0 || index >= length) {
            cout << "index out of bounds" << endl;
            return;
        }

        //if index is 0, use delfirst to delete the first index Node
        if (index == 0) {
            delfirst();
            return;
        }
        //if index is last index in LinkedList, delete last node
        if (index == length - 1) {
            dellast();
            return;
        }

        Node<T> *temp = head;
        int counter = 0;
        //traverse the list to find node before given index
        while(temp->next != nullptr && counter < index-1){
            temp = temp->next;
            counter++;
        }
        //store target node
        Node<T> *targetNode = temp->next;
        //updating pointer to skip target node
        temp->next = targetNode->next;
        //delete target node
        delete targetNode;
        //shorten list length
        length--;
        }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        int counter = 0;

        //check if index is out of bounds, error message returns
        if (index < 0 || index >= length) {
            cout << "index out of bounds" << endl;
            return;
        }
        //check if list is empty
        if (head == nullptr) {
            cout << "list is empty" << endl;
            return;
        }
        //if index is 0, use addhead function to add to front of list
        if (index == 0) {
            addhead(value);
            return;
        }
        //if index is last index, use add function to add to end of list
        if (index == length - 1) {
            add(value);
            return;
        }

        //traverse to find node before target node
        while (temp->next != NULL && counter < index-1) {
            temp = temp->next;
            counter++;
        }
        //insert newNode to target index
        newNode->next = temp->next;
        //point previous node to newNode
        temp->next = newNode;
        //increase length of list
        length++;
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        Node<T>* next = nullptr;

        while (curr != NULL) {
            next = curr->next; //next node is assigned
            curr -> next = prev; //reverse currents next pointer
            prev = curr; //assign previous pointer to current head
            curr = next; //assign current to next node
        }
        head = prev; //swap head and tail nodes
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->insert(1, s2);
    ll->print();
    ll->deleteNode(1);
    ll->print();
    ll->reverselist();
    ll->print();
}