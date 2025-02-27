#include"Node.h"
template<typename T>
class LinkedList {
protected:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	virtual bool isEmpty()=0;
	virtual void insertathead(T value) = 0;
	virtual void insertattail(T value) = 0;
	virtual T deleteFromHead() = 0;
	virtual T deleteFromTail() = 0;
	virtual void display() = 0;
	virtual void sort() = 0;
	~LinkedList() {
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			Node<T>* temp2 = temp->next;
			delete[] temp;
			temp = temp2;
		}
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
};