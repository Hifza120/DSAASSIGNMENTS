#include"LinkeList.h"
template<typename T>
class myLL : public LinkedList<T> {

public:
	 void insertathead(T value);
	void insertattail(T value);
	 T deleteFromHead();
	 T deleteFromTail();
	 void display();
	 void mergetwoLinkedList(myLL<T> & List1, myLL<T> & List2);
	 void sort();
	  bool isEmpty();

};
template <typename T>
void myLL<T>::sort() {
	Node<T>* temp1 = LinkedList<T>::head; 


	while (temp1 != nullptr) {
		Node<T>* N1 = temp1->next;       
		Node<T>* n = temp1;             

		while (N1 != nullptr) {
			if (N1->data < n->data) {
				n = N1; 
			}
			N1 = N1->next;
		}

		if (n != temp1) {
			T tempData = temp1->data;
			temp1->data = n->data;
			n->data = tempData;
		}

		temp1 = temp1->next;
	}
}
template<typename T>
bool myLL<T>::isEmpty() {
	return LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr;
}
template<typename T>
void myLL<T>::insertathead(T value) {
	Node<T>* nn = new Node<T>;
	nn->data = value;
	nn->next = nullptr;
	if (isEmpty()) {
		LinkedList<T>::head = nn;
		LinkedList<T>::tail = nn;
	}
	else if (LinkedList<T>::head == LinkedList<T>::tail) {
		nn->next = LinkedList<T>::head;
		LinkedList<T>::head = nn;

	}
	else {
		nn->next = LinkedList<T>::head;
		LinkedList<T>::head = nn;
	}
}

template<typename T>
void myLL<T>::mergetwoLinkedList(myLL<T>& List1, myLL<T>& List2) {
	if (List1.isEmpty() && List2.isEmpty()) {
		cout << " Both Linked Lists is Empty";
	}
	else if (List2.isEmpty()) {
		while (!List1.isEmpty()) {
			insertattail(List1.deleteFromHead());
		}
	}
	else if (List1.isEmpty()) {
		while (!List2.isEmpty()) {
			insertattail(List2.deleteFromHead());
		}
	}
	else {
		List1.sort();
		List2.sort();
		Node < T>* t1 = List1.head;
		Node<T>* t2 = List2.head;
		while (t1 != nullptr && t2 != nullptr) {
			if (t1->data <= t2->data) {
				insertattail(t1->data);
				t1 = t1->next;
			}
			else {
				insertattail(t2->data);
				t2 = t2->next;
			}
		}
		while (t1 != nullptr) {
			insertattail(t1->data);
			t1 = t1->next;
		}
		while (t2 != nullptr) {
			insertattail(t2->data);
			t2 = t2->next;
		}

	}
}
template<typename T>
void myLL<T>::insertattail(T value) {
	Node<T>* nn = new Node<T>;
	nn->data = value;
	nn->next = nullptr;
	if (isEmpty()) {
		LinkedList<T>::head = nn;
		LinkedList<T>::tail = nn;
	}
	else if (LinkedList<T>::head == LinkedList<T>::tail) {
		LinkedList<T>::tail->next = nn;
		LinkedList<T>::tail = nn;
	}
	else {
		LinkedList<T>::tail->next = nn;
		LinkedList<T>::tail = nn;
	}
}
template<typename T>
T myLL<T>::deleteFromHead() {
	if (isEmpty()) {
		cout << "It was an Empty LinkeList" << endl;
		return T();
	}
	else if (LinkedList<T>::head == LinkedList<T>::tail) {
		T value = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return value;
	}
	else {
		T value = LinkedList<T>::head->data;
		Node<T>* headNext = LinkedList<T>::head->next;
		delete LinkedList<T>::head;
		LinkedList<T>::head = headNext;
		return value;
	}
}
template<typename T>
T myLL<T>::deleteFromTail() {
	if (isEmpty()) {
		cout << "It was an Empty LinkeList" << endl;
		return T();

}
	else if (LinkedList<T>::head == LinkedList<T>::tail) {
		T value = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return value;
	}
	else {
		T value = LinkedList<T>::tail->data;
		Node<T>* t = LinkedList<T>::head;
		while (t->next != LinkedList<T>::tail) {
			t = t->next;
		}
		delete LinkedList<T>::tail;
		t->next = nullptr;
		LinkedList<T>::tail = t->next;
		return value;

	}

}
template<typename T>
void  myLL<T>::display() {
	Node<T>* t = LinkedList<T>::head;
	while (t!= nullptr) {
		cout << t->data << "  ";
		t = t->next;
	}
}