#include <iostream>

using namespace std;

template<class T>
struct Node{
	T data;
	Node* next;
	Node(){ next = NULL; };
	Node( const T& _data ){ data = _data; next = NULL; };
};

template<class T>
class List{
	public:
		List(){ head = NULL; };
		
		Node<T>* insert( const T& _data, const int& pos );
		Node<T>* insert( const T&  _data, const Node<T>* pos );		// insert after node pos
		void del( const int& pos );
		void del( const Node<T>* pos );
		const T& operator[]( int i );
		const int size();
		void inverse();
		void print();
	private:
		Node<T>* head;
};

int main(){
	List<int> l;
	l.insert(5, 0);
	l.insert(4, 0);
	l.insert(3, 1);
	l.insert(2, 0);	
	l.insert(1, 0);	
	l.insert(0, 0);	
	
	cout << "List: ";
	l.print();
	
	l.inverse();
	cout << "List inverse: ";
	l.print();
	
	cout << "List size: ";
	cout << l.size();
	
	return 0;
}

template<class T>
Node<T>* List<T>::insert( const T& _data, const int& pos ){
	Node<T>* newNode = new Node<T>(_data);
	if ( head == NULL ){
		head = newNode;
	}
	else if ( pos == 0 ){
		newNode->next = head;
		head = newNode;
	}
	else{
		Node<T>* tmp = head;
		for ( int i = 1; i < pos-1; tmp = tmp->next, i++ );
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	return newNode;
}

template<class T>
Node<T>* List<T>::insert( const T& _data, const Node<T>* pos ){
	Node<T>* newNode = new Node<T>(_data);
	newNode->next = pos->next;
	pos->next = newNode;
}

template<class T>
void List<T>::del( const int& pos ){
	if ( pos == 0 ){
		delete head;
		head = NULL;
	}
	else{
		Node<T>* tmp = head;
		for ( int i = 1; i < pos-1; tmp = tmp->next, i++ );
		Node<T>* delNode = tmp->next;
		tmp->next = delNode->next;
		delete delNode;
		delNode = NULL;
	}
}

template<class T>
void List<T>::del( const Node<T>* pos ){
	if ( pos != NULL ){
//	??? address prev node		
	}
}

template<class T>
void List<T>::inverse(){
	Node<T>* prev = NULL;
	Node<T>* current = head;
	Node<T>* tmp;
	
	while ( current != NULL ){
		tmp = current->next;
		current->next = prev;
		prev = current;
		current = tmp;
	}
	
	head = prev;
}

template<class T>
void List<T>::print(){
	for (Node<T>* tmp = head; tmp != NULL; cout << tmp->data << " ", tmp = tmp->next );
	cout << endl;
}

template<class T>
const T& List<T>::operator[]( int i ){
	Node<T>* tmp = head;
	for ( int j = 0; j < i; tmp = tmp->next, j++ );
	return tmp->data;
}

template<class T>
const int List<T>::size(){
	if ( head == NULL ){
		return 0;
	}
	else{
		Node<T>* tmp = head;
		int c = 0;
		for ( ; tmp != NULL; c++, tmp = tmp->next );
		return c;
	}
}
