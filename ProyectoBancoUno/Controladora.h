#pragma once
#include "Cliente.h"
#include <Windows.h>
#include "BST.h"
#include "ColaPrioritaria.h"
#include "Validacion.h"
class Controladora {
private:
	BST<Cliente>* arbolClientes;
	ColaPrioridad<Cliente>* colaClientes;

public:
	Controladora();
	virtual ~Controladora();
	void control1();
	void control2();
	void cargaCli();
	void encolarTodos();
	void encalarUno();
	void atender5();
	void mostrarSig();
	void simulacion();
	void agregarNuevo();
};

