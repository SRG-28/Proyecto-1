#pragma once
#include "Lista.h"
template <class T>
class ColaPrioridad {
private:
	bool compara(T& obj_a, T& obj_b);
	bool tipo;
	int getHijoIz(int);
	Lista<T>* contenedor;
	void MaxHeapify(int);
	void MinHeapify(int);
	void Intercambio(int, int);
	void CrearHeap(Lista<T>*);
	int getPadre(int);
	int getHijoDer(int);
	void SiftUp();
	void SiftUpMenor();
	T* comparaHipifyMayor(int);
	bool eliminar();
public:

	ColaPrioridad(bool = true);
	ColaPrioridad(const ColaPrioridad<T>& cl);
	ColaPrioridad(const Lista<T>& ls, bool);
	~ColaPrioridad();
	bool isEmpty();
	bool insertar(T*&);
	T* peek();
	T* remove();

};

template<class T>
ColaPrioridad<T>::ColaPrioridad(bool m)
{
	this->contenedor = new Lista<T>();
	this->tipo = m;

}

template<class T>
ColaPrioridad<T>::ColaPrioridad(const ColaPrioridad<T>& cl) {
	this->tipo = cl.tipo;
	this->contenedor = new Lista<T>(*cl.contenedor);
}

template<class T>
ColaPrioridad<T>::ColaPrioridad(const Lista<T>& ls, bool ti)
{
	this->contenedor = new Lista<T>(ls);
	this->tipo = ti;
	this->CrearHeap(contenedor);

}

template<class T>
ColaPrioridad<T>::~ColaPrioridad()
{
}


template<class T>
bool ColaPrioridad<T>::isEmpty()
{
	return (this->contenedor->empty());
}

template<class T>
bool ColaPrioridad<T>::insertar(T*& obj)
{
	this->contenedor->insertar(obj);
	if (contenedor->getCantidad() > 0) {
		if (tipo == true) {
			this->SiftUp();
		}
		else {
			this->SiftUpMenor();
		}
	}
	return true;
}

template<class T>
bool ColaPrioridad<T>::eliminar()
{
	bool m = this->contenedor->eliminar();
	if (m == true) {
		int n = ((contenedor->getCantidad() - 1) / 2);
		for (int i = n; i >= 0; i--) {
			if (this->tipo == true) {
				this->MaxHeapify(i);
			}
			else {
				this->MinHeapify(i);
			}
		}
		return true;
	}
	return false;

}

template<class T>
T* ColaPrioridad<T>::peek()
{
	return contenedor->elemento();
}

template<class T>
T* ColaPrioridad<T>::remove()
{
	T* objeto = new T(*this->contenedor->getFront()->getObjetoPtr());
	this->eliminar();
	return objeto;
}

template<class T>
bool ColaPrioridad<T>::compara(T& obj_a, T& obj_b)
{
	return  (obj_a > obj_b) ? true : false;
}

template<class T>
void ColaPrioridad<T>::MaxHeapify(int i)
{
	int izq = this->getHijoIz(i);
	int der = this->getHijoDer(i);
	T* obj = nullptr;
	T* obj2 = nullptr;
	T* father = nullptr;
	T* tmp = nullptr;
	int mayor = 0;
	if (izq == -1 && der == -1) {
		return;
	}
	obj = this->comparaHipifyMayor(izq);
	obj2 = this->comparaHipifyMayor(der);
	father = this->comparaHipifyMayor(i);
	if (obj == nullptr && obj2 == nullptr) {
		return;
	}
	if (obj != nullptr) {
		if (*obj > *father) {
			mayor = izq;
			tmp = obj;
		}
		else {
			mayor = i;
			tmp = father;
		}
	}
	if (obj2 != nullptr) {
		if (*obj2 > *tmp) {
			mayor = der;
			tmp = obj2;
		}
	}

	if (mayor != i) {
		this->Intercambio(mayor, i);
		this->MaxHeapify(mayor);
	}

}

template<class T>
void ColaPrioridad<T>::MinHeapify(int i)
{
	int izq = this->getHijoIz(i);
	int der = this->getHijoDer(i);
	int menor = 0;
	T* obj = nullptr;
	T* obj2 = nullptr;
	T* father = nullptr;
	T* tmp = nullptr;
	if (izq == -1 && der == -1) {
		return;
	}
	obj = this->comparaHipifyMayor(izq);
	obj2 = this->comparaHipifyMayor(der);
	father = this->comparaHipifyMayor(i);
	if (obj == nullptr && obj2 == nullptr) {
		return;
	}
	if (obj != nullptr) {
		if (*obj < *father && izq != -1) {
			menor = izq;
			tmp = obj;
		}
		else {
			menor = i;
			tmp = father;
		}
	}
	if (obj2 != nullptr) {
		if (*obj2 < *tmp && der != -1) {
			menor = der;
			tmp = obj2;
		}
	}

	if (menor != i) {
		this->Intercambio(menor, i);
		this->MinHeapify(menor);
	}

}

template<class T>
int ColaPrioridad<T>::getHijoIz(int i)
{

	Nodo<T>* actual;
	actual = contenedor->getFront();
	int contador = 0;
	int ayudante = ((i * 2) + 1);
	while (actual != nullptr) {

		if (contador == ayudante) {
			return ayudante;
		}
		contador++;
		actual = actual->getSiguiente();
	}
	return -1;
}

template<class T>
void ColaPrioridad<T>::CrearHeap(Lista<T>* ls)
{
	for (int i = (contenedor->getCantidad() / 2) - 1; i >= 0; i--) {
		if (this->tipo == true) {
			this->MaxHeapify(i);

		}
		else {
			this->MinHeapify(i);
		}
	}
}

template<class T>
int ColaPrioridad<T>::getPadre(int i)
{
	Nodo<T>* actual;
	actual = contenedor->getFront();
	int contador = 0;
	int ayudante = ((i - 1) / 2);
	while (actual != nullptr) {

		if (contador == ayudante) {
			return ayudante;
		}
		contador++;
		actual = actual->getSiguiente();
	}
	return -1;
}



template<class T>
int ColaPrioridad<T>::getHijoDer(int i)
{

	Nodo<T>* actual;
	actual = contenedor->getFront();
	int contador = 0;
	int ayudante = ((i * 2) + 2);
	while (actual != nullptr) {

		if (contador == ayudante) {
			return ayudante;
		}
		contador++;
		actual = actual->getSiguiente();
	}
	return -1;
}

template<class T>
void ColaPrioridad<T>::SiftUp()
{
	Nodo<T>* aux = contenedor->getBack();
	int contador = contenedor->getCantidad();
	int contador2 = contador - 1;
	while (aux && contador2 >= 0) {
		if (!compara(*aux->getObjetoPtr(), *aux->getAnterior()->getObjetoPtr())) {
			return;
		}
		else {
			this->Intercambio(contador, contador2);
		}
		aux = aux->getAnterior();
		contador--;
		contador2--;
	}

}
template<class T>
void ColaPrioridad<T>::SiftUpMenor()
{
	Nodo<T>* aux = contenedor->getBack();
	int contador = contenedor->getCantidad();
	int contador2 = contador - 1;
	while (aux && contador2 >= 0) {
		if (!compara(*aux->getObjetoPtr(), *aux->getAnterior()->getObjetoPtr())) {
			this->Intercambio(contador, contador2);
		}
		else {
			return;
		}
		aux = aux->getAnterior();
		contador--;
		contador2--;
	}

}
template<class T>
T* ColaPrioridad<T>::comparaHipifyMayor(int m)
{
	return contenedor->buscarElemento(m);

}
template<class T>
void ColaPrioridad<T>::Intercambio(int mayor, int i)
{
	T* aux = nullptr;
	T* aux2 = nullptr;
	T* temporal = nullptr;
	Nodo<T>* ayudante = nullptr;
	Nodo<T>* actual;
	actual = contenedor->getFront();
	int contador = 0;
	int contador2 = 0;
	while (actual != nullptr) {
		if (mayor < i) {
			if (contador == mayor) {
				aux = actual->getObjetoPtr();
				ayudante = actual;
			}
			if (contador2 == i) {
				aux2 = actual->getObjetoPtr();
				actual->setObjetoPtr(aux);
				ayudante->setObjetoPtr(aux2);
			}
		}
		else {
			if (contador == i) {
				aux = actual->getObjetoPtr();
				ayudante = actual;
			}
			if (contador2 == mayor) {
				aux2 = actual->getObjetoPtr();
				actual->setObjetoPtr(aux);
				ayudante->setObjetoPtr(aux2);
			}
		}
		actual = actual->getSiguiente();
		contador2++;
		contador++;
	}

}
