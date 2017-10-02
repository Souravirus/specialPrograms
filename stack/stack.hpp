#include <bits/stdc++.h>
#include "../linked_list/ll.hpp"
using namespace std;

template<class T>
struct stackmp{
	ll_node<T> *top;
	int capacity; // number of elements the stack can contain
	int size; // number of elements in the stack

	stackmp(int cap) : capacity(cap),size(0) {}

	/* Description: function will add an item to the stack
	*  Complexity:  O(1)
	*/
	void push(T new_data){
		if(size == capacity){
			cout << "Stack is full! Cannot push new element" << endl;
			return;
		}
		ll_node<T> *new_node = create_node(new_data);
		ll_node<T> *temp_node = this->top;
		new_node->next = temp_node;
		this->top = new_node;
		size++;
	}

	/* Description: Function will items in the stack.
	*  Complexity:  O(n)
	*/
	void print(){
		ll_node<T> *temp_node = this->top;
		if(size == 0){
			cout << "Stack is empty" << endl;
			return;
		}
		cout << "Printing stack:" << endl;
		for(int i=0;i<this->size;i++){
			cout << temp_node->data << ' ';
			temp_node = temp_node->next;
		}
		cout << endl;
	}

	/* Description: Function will remove an item from the stack. The item is removed (popped)
	*	        in opposite order than pushed.
	*  Complexity:  O(1)
	*/
	T pop(){
		if(size == 0){
			cout << "Stack is empty, can't pop" << endl;
			return '\0';
		}
		T data = this->top->data;
		this->top = this->top->next;
		size--;
		return data;
	}

	/* Description: Function will return the item at the top of the stack.
	*  Complexity:  O(1)
	*/
	T peek(){
		return this->top->data;
	}
};

template<class T>
/* Description: Function will return the size of the stack
*  Complexity:  O(1)
*/
int get_size(stackmp<T> *s){
	return s->size;
}

template<class T>
/* Description: Function will return the capacity of the stack
*  Complexity:  O(1)
*/
int get_capacity(stackmp<T> *s){
	return s->capacity;
}

