#include "BST.hpp"

//--------------------------
// Mètodes privats auxiliars
//--------------------------

template <typename T>
void BST<T>::clear(Item *node) {
	if (node != NULL) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) {
	if (node == NULL) {
		node = new Item(d, NULL, NULL);
	} else if (d < node->data) {
		node->left = insert(node->left, d);
	} else {
		node->right = insert(node->right, d);
	} 
	return node;
}

template <typename T>
typename BST<T>::Item* BST<T>::remove(Item *node, const T& d) {
	if (node == NULL) {
		return NULL;
	} else if (d > node->data) {
		node->right = remove(node->right, d);
	} else if (d < node->data) {
		node->left = remove(node->left, d);
	} else if (node->left != NULL and node->right != NULL) {
		// Node has two children
		Item *tmp = node->right;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}
		node->data = tmp->data;
		node->right = remove(node->right, node->data);
	} else {
		// Node has at most one child
		Item *tmp = node;
		if (node->left == NULL) {
			node = node->right;
		} else if (node->right == NULL) {
			node = node->left;
		}
		delete tmp;
	}
	return node;
}

template <typename T>
void BST<T>::setValue(Item *node, const T& d, const T& value) {
	Item *temp = find(node, d); // ?? No existeix mètode find que rebi aquests tipus de paràmetre
	if (temp != NULL) {
		temp->data = value;
	} else {
		cerr << "Error: Node not found!" << endl;
	}
}

template <typename T>
typename BST<T>::Item* BST<T>::find(Item *pitem, const T &element) const{
	if(pitem != NULL and not (pitem->data == element)){
		if(pitem->left != NULL){
			pitem = find(pitem->left, element);
			// HI: pitem apunta a un l'element del subarbre esquerrà, que sigui igual a T
		}
		if(pitem->right != NULL){
			pitem = find(pitem->right, element);
			// HI: pitem apunta a un l'element del subarbre dretà, que sigui igual a T
		}
	}
	return pitem;
}

//-------------
// Constructors
//-------------

template <typename T>
BST<T>::BST() {
	root = NULL;
}


//-------------
// Destructor
//-------------

template <typename T>
BST<T>::~BST() { 
	clear(root); 
}


//-------------
// Modificadors
//-------------

template <typename T>
void BST<T>::insert(const T& d) { 
	root = insert(root, d); 
}

template <typename T>
void BST<T>::remove(const T& d) { 
	root = remove(root, d); 
}

template <typename T>
void BST<T>::setValue(const T& d, const T& value) { 
	setValue(root, d, value); 
}


//-----------
// Consultors
//-----------

template <typename T>
pair<bool, T> BST<T>::find(const T& d) const {
	pair<bool, T> aux;
	aux.first = false;
	Item *pitem = root; // Punter auxiliar, que apunta a l'arrel de l'arbre de cerca
	pitem = find(pitem, d);
	if(pitem != NULL and pitem->data == d){
		aux.first = true;
		aux.second = pitem->data;
	}
	return aux;
}
