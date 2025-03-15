#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node{
	public:
		Node(){ left = NULL; right = NULL; };
		Node( const T _data ){ data = _data; left = NULL; right = NULL; };
		T data;
		Node<T>* left;
		Node<T>* right;
};

template <class T>
class binary_search_tree{
	public:
		binary_search_tree(){ root = NULL; };
		
		void insert( const T& _data );
		
		Node<T>* getRoot(){ return root; };
		
		bool find( const T& key );
		
		void get( Node<T>* _node, vector<T>* arr_sorted );
	private:
		Node<T>* root;
};

template <class T>
void binary_search_tree<T>::insert( const T& _data ){
	Node<T>* newNode = new Node<T>( _data );
	
	if ( root == NULL ){
		root = newNode;
	}
	else{
		Node<T>* tmp = root;
		while( newNode != NULL ){
			if ( tmp->data > newNode->data ){
				if ( tmp->left == NULL ){
					tmp->left = newNode;
					newNode = NULL;
				}
				else{
					tmp = tmp->left;
				}
			}
			else{
				if ( tmp->right == NULL ){
					tmp->right = newNode;
					newNode = NULL;
				}
				else{
					tmp = tmp->right;
				}
			}
		}
	}
}

template <class T>
bool binary_search_tree<T>::find( const T& key ){
	bool flag = false;
	Node<T>* tmp = root;
	while ( !flag && tmp != NULL ){
		if ( tmp->data == key ){
			flag = true;
		}
		else if ( tmp->data < key ){
			tmp = tmp->right;
		}
		else{
			tmp = tmp->left;
		}
	}
	return flag;
}
		
template <class T>
void binary_search_tree<T>::get( Node<T>* _node, vector<T>* arr_sorted ){
	if ( _node != NULL ){
		get( _node->left, arr_sorted );
		arr_sorted->push_back(_node->data);
		get( _node->right, arr_sorted );
	}
}

int main(){
	int a[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, -3 };
	binary_search_tree<int> t;
	for ( int i = 0; i < 10; t.insert(a[i]), i++ );
	
	vector<int> v;
	t.get( t.getRoot(), &v );
	
	cout << "Sorted: ";
	for ( int i = 0; i < v.size(); cout << v[i] << " ", i++ );
	cout << endl;
	cout << "Find 6: " << t.find(6) << endl;
	cout << "Find: 12: " << t.find(12) << endl;
		
	return 0;
}
