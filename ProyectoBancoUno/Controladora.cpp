#include "Controladora.h"
#include"Vista.h"


Controladora::Controladora() { 
	arbolClientes = new BST<Cliente>;
	colaClientes = new ColaPrioridad<Cliente>;

}

void Controladora::control1() {
	Vista::presentacionInicial();
	cargaCli();
	try {
		int opcion;
		do {
			opcion = Vista::menu();
			switch (opcion) {
			case 1:
				encolarTodos();
				break;
			case 2:
				encalarUno();
				break;
			case 3:
				atender5();
				break;
			case 4:
				mostrarSig();
				break;
			case 5:
				simulacion();
				break;
			case 6:
				agregarNuevo();
				break;
			case 7:
				control2();
				break;
			default:
				int aux = 0;
				cout << "Debe digitar un numero del 1 al 7" << endl;
				Validacion::validaInt(aux);
			}
		} while (opcion != 7);
	}
	catch (const char* excepcion) {
		cout << excepcion << endl;
	}
	catch (...) {
		cout << "Hubo un problema inesperado. " << endl;
	}
}

void Controladora::cargaCli() {
	Vista::cargaCliente(arbolClientes);
	system("pause");
}

void Controladora::encolarTodos() {

	cout << "Encolando todos los clientes..." << endl;
	Sleep(1500);
	arbolClientes->encolar(colaClientes);
	cout << "Clientes encolados exitosamente..." << endl;
	system("pause");
}

void Controladora::encalarUno() {
	cout << "Encolar un cliente" << endl;
	string id;
	cout << "Digite la cedula del cliente que desea encolar" << endl;
	cin.ignore();
	id = Validacion::validaString();
	arbolClientes->encolarUno(colaClientes, id);
	system("pause");
}

void Controladora::atender5() {
	cout << "Atender los siguientes 5 clientes" << endl;
	Vista::atenderCincoClientes(colaClientes);
	system("pause");
}

void Controladora::mostrarSig() {
	cout << "Mostrar el siguiente cliente a ser atendido" << endl;
	Vista::verSiguienteCLiente(colaClientes);
	system("pause");
}

void Controladora::simulacion() {
	cout << "Simulacion de atencion de clientes" << endl;
	Vista::simulacionAtencionClientes(colaClientes);
	system("pause");
}

void Controladora::agregarNuevo() {
	Cliente* cli = nullptr;
	cout << "------------------Agregar un nuevo cliente------------------" << endl;
	cli = Vista::crearCliente();
	arbolClientes->insert(cli);
	system("pause");
}

void Controladora::control2() {
	Vista::salir();
}


Controladora::~Controladora() {
	delete arbolClientes;
	delete colaClientes;
}



