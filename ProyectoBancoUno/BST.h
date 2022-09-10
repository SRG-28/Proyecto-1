#pragma once
#include "Node.h"
#include "ColaPrioritaria.h"
template<class T>

class BST {
private:
	Node<T>* root;
	int quantity;

	Node<T>* makeEmpty(Node<T>* t) {
		if (t == nullptr)
			return nullptr;
		{
			makeEmpty(t->getLeft());
			makeEmpty(t->getRight());
			delete t;
		}
		return nullptr;
	}

	Node<T>* insert(T* x, Node<T>* t)
	{
		if (t == nullptr)
		{
			t = new Node<T>;
			t->setData(x);
			t->setLeft(nullptr);
			t->setRight(nullptr);
			quantity += 1;
		}
		else if (x < t->getData())
			t->setLeft(insert(x, t->getLeft()));
		else if (x > t->getData())
			t->setRight(insert(x, t->getRight()));

		return t;
	}

	Node<T>* findMin(Node<T>* t)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->getLeft() == nullptr)
			return t;
		else
			return findMin(t->getLeft());
	}

	Node<T>* findMax(Node<T>* t) {
		if (t == nullptr)
			return nullptr;
		else if (t->getRight() == nullptr)
			return t;
		else
			return findMax(t->getRight());
	}

	Node<T>* remove(int x, Node<T>* t) {
		Node<T>* temp;
		if (t == nullptr)
			return nullptr;
		else if (x < t->getData())
			t->setLeft(remove(x, t->getLeft()));
		else if (x > t->getData())
			t->setRight(remove(x, t->getRight()));
		else if (t->getLeft() && t->getRight())
		{
			temp = findMin(t->getRight());
			t->setData(temp->getData());
			t->setRight(remove(t->getData(), t->getRight()));

		}
		else
		{
			temp = t;
			if (t->getLeft() == nullptr)
				t = t->getRight();
			else if (t->getRight() == nullptr)
				t = t->getLeft();
			delete temp;
			quantity -= 1;
		}

		return t;
	}

	void inorder(Node<T>* t) {
		if (t == nullptr)
			return;
		inorder(t->getLeft());
		cout << *t->getData() << " ";
		inorder(t->getRight());
	}

	Node<T>* find(Node<T>* t, T x) {
		if (t == nullptr)
			return nullptr;
		else if (x < t->getData())
			return find(t->getLeft(), x);
		else if (x > t->getData())
			return find(t->getRight(), x);
		else
			return t;
	}

	void inorderEncolar(Node<T>* t, ColaPrioridad<T>* cola) {
		if (t == nullptr)
			return;
		inorderEncolar(t->getLeft(), cola);
		T* objeto = t->getData();
		cola->insertar(objeto);
		inorderEncolar(t->getRight(), cola);
	}

	void inorderUno(Node<T>* t, ColaPrioridad<T>* cola, string id) {
		if (t == nullptr)
			return;
		inorderUno(t->getLeft(), cola, id);
		Cliente* objeto = t->getData();
		if (objeto->getId() == id) {
			cola->insertar(objeto);
			cout << "Cedula encontrada y cliente encolado exitosamente.." << endl;
		}
		inorderUno(t->getRight(), cola, id);
	}

public:
	BST() {
		root = nullptr;
		quantity = 0;
	}

	~BST() {
		root = makeEmpty(root);
		cout << "Arbol destruido" << endl;
	}

	void insert(T* x) {
		root = insert(x, root);
	}

	void remove(T x) {
		root = remove(x, root);
	}

	void display() {
		inorder(root);
		cout << endl;
	}

	void search(T x) {
		root = find(root, x);
	}
	void encolar(ColaPrioridad<T>* cola) {
		inorderEncolar(root, cola);
		cout << endl;
	}

	void encolarUno(ColaPrioridad<T>* cola, string id) {
		inorderUno(root, cola, id); 
		cout << endl;
	}


	int size() {
		return quantity;
	}

};


