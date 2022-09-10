#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Cliente.h"
#include "BST.h"
#include "ColaPrioritaria.h"
#include "Validacion.h"
using namespace std;

class Vista {
public:
	static void presentacionInicial();
	static int menu();
	static void cargaCliente(BST<Cliente>*);
	static Cliente* crearCliente();
	static void despedida(Cliente*);
	static void salir();
	static void atenderCincoClientes(ColaPrioridad<Cliente>*);
	static void verSiguienteCLiente(ColaPrioridad<Cliente>*);
	static void simulacionAtencionClientes(ColaPrioridad<Cliente>*);
};

