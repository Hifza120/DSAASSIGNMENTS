#include"Stack.h"
template<typename T>
class myStack :public Stack<T> {
public:
	myStack(int size); 
	void push(T value) ;
	bool isFull() ;
	bool isEmpty() ;
	 T pop() ;
	 T top() ;

};
template<typename T>
myStack<T>::myStack(int size) : Stack<T>(size) {}

template<typename T>
void myStack<T>::push(T value)  {
	if (isFull()) {
		cout << "Stack is  Full" << endl;
	}
	else {
		Stack<T>::arr[Stack<T>::currentSize++] = value;
	}
}
template<typename T>
bool myStack<T>::isFull()  {
	return Stack<T>::maxSize == Stack<T>::currentSize;
}
template<typename T>
bool myStack<T>::isEmpty()  {
	return Stack<T>::currentSize == 0;
}
template<typename T>
T myStack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return T();
	}
	return Stack<T>::arr[--Stack<T>::currentSize];
}
template<typename T>
T myStack<T>::top() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return T();
	}
	return Stack<T>::arr[Stack<T>::currentSize-1];
}




