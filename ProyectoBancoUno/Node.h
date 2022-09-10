#pragma once
#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
template <class T>
class Node {

private:
	T* data;
	Node<T>* left;
	Node<T>* right;
public:
	Node(T* data = nullptr, Node<T>* left = nullptr, Node<T>* right = nullptr) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	virtual ~Node() {

	}
	T* getData() const {
		return data;
	}
	void setData(T* data) {
		this->data = data;
	}

	Node* getLeft() const {
		return left;
	}
	void setLeft(Node* left) {
		this->left = left;
	}

	Node* getRight() const {
		return right;
	}
	void setRight(Node* right) {
		this->right = right;
	}

};