#include "Vista.h"
#include <Windows.h>
#include "Cliente.h"


void Vista::presentacionInicial() {
	cout << "--------------Bienvenidos------------------" << endl;
	cout << "----------A NUESTRA APLICACION-------------" << endl;
	cout << "-------------------------------------------" << endl;
	Sleep(1500);
	system("cls");
}


int Vista::menu() {
	int opcion;
	int aux = 0;
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "-----------MENU PROCESAMIENTO-------------" << endl;
	cout << "------------------------------------------" << endl;
	cout << "    1- Encolar todos los clientes" << endl;
	cout << "    2- Encolar un cliente" << endl;
	cout << "    3- Atender los siguientes 5 clientes" << endl;
	cout << "    4- Mostrar el siguiente cliente a ser atendido" << endl;
	cout << "    5- Simulacion de atencion de clientes" << endl;
	cout << "    6- Agregar un cliente nuevo" << endl;
	cout << "    7- Salir                              " << endl;
	cout << "------------------------------------------" << endl;
	cout << "     Digite la opcion..: ";
	opcion = Validacion::validaInt(aux);
	system("cls");
	return opcion;
}


void Vista::cargaCliente(BST<Cliente>* arbol) {
	cout << "------Bienvenido al programa de carga de datos de Clientes------" << endl;
	cout << " Archivos:  ClientesBancoUno.csv" << endl;
	Cliente* cli = nullptr;
	string linea = "";
	string dato = "";
	fstream infile("ClientesBancoUno.csv", ios::in);
	vector <string> datos_csv;
	if (infile.is_open()) {
		while (getline(infile, linea)) {
			stringstream sl(linea);
			while (getline(sl, dato, ',')) {
				datos_csv.push_back(dato);
			}
		}
		for (int unsigned i = 0; i < datos_csv.size(); i++) {
			if (i % 6 == 0) {
				cli = new Cliente(datos_csv[i], datos_csv[i + 1], datos_csv[i + 2], datos_csv[i + 3], datos_csv[i + 4], datos_csv[i + 5], 0);
				cli->calcuPorcent();
				arbol->insert(cli);
			}
		}
		infile.close();
	}
	else {
		cout << "Error al abrir el archivo para lectura" << endl;
	}
	cout << " Registros encontrados:  "<<arbol->size() << endl;
	//Sleep(1500);
}

Cliente* Vista::crearCliente() {
	string id, nom, nino, embarazo, adultoMayor, categoria;
	cout << "-------------------Vamos a crear un nuevo cliente------------------" << endl;
	cout << " Digite el nombre del cliente: ";
	cin.ignore();
	nom = Validacion::validaString();
	cout << " Digite el id: ";
	id = Validacion::validaString();
	cout << " Ingrese -> Yes <- si el cliente ingresa con un nino y -> No <- si el cliente no ingresa con un nino" << endl;
	cout << " Ingresa con un nino: ";
	nino = Validacion::validaString();
	if (nino == "Yes" || nino == "No") {
		cout << "***Dato ingresado correctamente***" << endl;
	}
	else {
		while (!(nino == "Yes" || nino == "No")) {
			cout << " Ingrese -> Yes <- si el cliente ingresa con un nino y -> No <- si el cliente no ingresa con un nino" << endl;
			cout << " Ingresa con un nino: ";
			nino = Validacion::validaString();
		}
		cout << "***Dato ingresado correctamente***" << endl;
	}
	cout << " Ingrese -> Yes <- si el cliente ingresa embarazada y -> No <- si el cliente no ingresa embarazada" << endl;
	cout << " Esta embarazada: ";
	embarazo = Validacion::validaString();
	if (embarazo == "Yes" || embarazo == "No") {
		cout << "***Dato ingresado correctamente***" << endl;
	}
	else {
		while (!(embarazo == "Yes" || embarazo == "No")) {
			cout << " Ingrese -> Yes <- si el cliente ingresa embarazada y -> No <- si el cliente no ingresa embarazada" << endl;
			cout << " Esta embarazada: ";
			embarazo = Validacion::validaString();
		}
		cout << "***Dato ingresado correctamente***" << endl;
	}
	cout << " Ingrese -> Yes <- si el cliente es un adulto mayor y -> No <- si el cliente no es un adulto mayor" << endl;
	cout << " Es adulto mayor: ";
	adultoMayor = Validacion::validaString();
	if (adultoMayor == "Yes" || adultoMayor == "No") {
		cout << "***Dato ingresado correctamente***" << endl;
	}
	else {
		while (!(adultoMayor == "Yes" || adultoMayor == "No")) {
			cout << " Ingrese -> Yes <- si el cliente es un adulto mayor y -> No <- si el cliente no es un adulto mayor" << endl;
			cout << " Es adulto mayor: ";
			adultoMayor = Validacion::validaString();
		}
		cout << "***Dato ingresado correctamente***" << endl;
	} 
	cout << " 1 = Categoria 1 (premium) ,  2 = Categoria 2 (oro) , 3 = Categoria 3 (normal)" << endl;
	categoria = Validacion::validaString();
	if (categoria == "1" || categoria == "2" || categoria == "3") {
		cout << "***Categoria ingresada correctamente***" << endl;
	}
	else {
		while (categoria > "3") {
			cout << " Ingrese -> 1 <- para Categoria 1 (premium) , Ingrese -> 2 <- para Categoria 2 (oro) , Ingrese -> 3 <- para Categoria 3 (normal)";
			cout << " Digite la categoria:" << endl;
			categoria = Validacion::validaString();
		}
		cout << "***Dato ingresado correctamente***" << endl;
	}
	Cliente* cli1 = new Cliente(nom, id, nino, embarazo, adultoMayor, categoria);
	cli1->calcuPorcent();
	despedida(cli1);
	return cli1;
}


void Vista::despedida(Cliente* cli) {
	ofstream MiArchivo("ClientesBancoUno.csv", ios::app); 
	if (MiArchivo.is_open()) {
			MiArchivo << cli->getNombre() << ",";
			MiArchivo << cli->getId() << ",";
			MiArchivo << cli->getNino() << ",";
			MiArchivo << cli->getEmbarazo() << ",";
			MiArchivo << cli->getAdultoMayor() << ",";
			MiArchivo << cli->getCategoria() << "\n";
		MiArchivo.close();
	}
	else cout << "No se abrio correctamente el archivo para escritura!" << endl;
	cout << "------------------------------------" << endl;
}

void Vista::salir(){
	cout << "------------------------------------------------" << endl;
	cout << "-----------------MUCHAS GRACIAS-----------------" << endl;
	cout << "--------POR UTILIZAR NUESTRA APLICACION---------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Archivo actualizado: ClientesBancoUno.csv" << endl;
	cout << "------------------------------------------------" << endl;

}

void Vista::atenderCincoClientes(ColaPrioridad<Cliente> *p) {
	cout << "------------Atencion de los siguientes 5 clientes---------------" << endl;
	if (p->isEmpty()) {
		cout << "Cola vacia" << endl;
	}
	else {
		for (int i = 0; i < 5; i++) {
			cout << *p->remove() << endl;
		}
	}
}

void Vista::verSiguienteCLiente(ColaPrioridad<Cliente> *p) {
	cout << "-----------------Siguiente cliente en la cola-------------------" << endl;
	if (p->isEmpty()) {
		cout << "Cola vacia" << endl;
	}
	else {
		cout << *p->peek() << endl;
	}
}

void Vista::simulacionAtencionClientes(ColaPrioridad<Cliente> *p) {
	cout << "-----------------Simulacion de atencion de de clientes-------------------" << endl;
	cout << "------------------Atendiendo a todos los clientes---------------------" << endl;
	while (!p->isEmpty()) {
		cout << *p->remove() << endl;
		//Sleep(1000);
	}
	cout << "Cola vacia" << endl;
}
