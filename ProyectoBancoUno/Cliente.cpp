#include "Cliente.h"
Cliente::Cliente(string nombre, string id, string nino, string embarazo, string adultoMayor, string categoria, int porcentaje) :
	id(id), nombre(nombre), nino(nino), embarazo(embarazo), adultoMayor(adultoMayor), categoria(categoria), porcentajeInfluencia(porcentaje) {
}

Cliente::Cliente(const Cliente& cli) {
	this->id = cli.id;
	this->nombre = cli.nombre;
	this->nino = cli.nino;
	this->embarazo = cli.embarazo;
	this->adultoMayor = cli.adultoMayor;
	this->categoria = cli.categoria;
	this->porcentajeInfluencia = cli.porcentajeInfluencia;
}

void Cliente::setNombre(string id) {
	this->id = id;
}

void Cliente::setId(string nombre) {
	this->nombre = nombre;
}

void Cliente::setNino(string nino) {
	this->nino = nino;
}

void Cliente::setEmbarazo(string embarazo) {
	this->embarazo = embarazo;
}

void Cliente::setAdultoMayor(string adultoMayor) {
	this->adultoMayor = adultoMayor;
}

void Cliente::setCategoria(string categoria) {
	this->categoria = categoria;
}

string Cliente::getNombre() {
	return nombre;
}

string Cliente::getId() {
	return id;
}

string Cliente::getNino() {
	return nino;
}

string Cliente::getEmbarazo() {
	return embarazo;
}

string Cliente::getAdultoMayor() {
	return adultoMayor;
}

string Cliente::getCategoria() {
	return categoria;
}

Cliente& Cliente::operator=(const Cliente& cli) {
	if (this != &cli) {
		this->nombre = cli.nombre;
		this->id = cli.id;
		this->nino = cli.nino;
		this->embarazo = cli.embarazo;
		this->adultoMayor = cli.adultoMayor;
		this->categoria = cli.categoria;
		this->porcentajeInfluencia = cli.porcentajeInfluencia;
	}
	return *this;
}

ostream& operator << (ostream& out, Cliente& cli) { 
	return out
		<< "-------------------------Datos del cliente-------------------------" << endl << endl
		<< "Nombre: " << cli.getNombre() << endl
		<< "Cedula: " << cli.getId() << endl
		<< "Ingresa con un nino: " << cli.getNino() << endl
		<< "Esta embarazada: " << cli.getEmbarazo() << endl
		<< "Es adulto mayor: " << cli.getAdultoMayor() << endl
		<< "Categoria: " << cli.getCategoria() << endl
		<< "Porcentaje de influencia: " << cli.getPorcentajeInfluencia() << endl;
}

string Cliente::toString() {
	stringstream s;
	s << "-------------------------Datos del cliente-------------------------" << endl << endl;
	s << "Nombre: " << getNombre() << endl;
	s << "Cedula: " << getId() << endl;
	s << "Ingresa con un nino: " << getNino() << endl;
	s << "Esta embarazada: " << getEmbarazo() << endl;
	s << "Es adulto mayor: " << getAdultoMayor() << endl;
	s << "Categoria: " << getCategoria() << endl;
	s << "Porcentaje de influencia: " << getPorcentajeInfluencia() << endl;

	return s.str();
}

void Cliente::calcuPorcent() {
	int porcentaje = 0;
	string valorEsperado = "Yes";
	string cate1 = "1";
	string cate2 = "2";
	string cate3 = "3";
	if (valorEsperado.find(getNino()) != string::npos) {
		setPorcentajeInfluencia(20);
	}
	if (valorEsperado.find(getEmbarazo()) != string::npos) {
		setPorcentajeInfluencia(25);
	}
	if (valorEsperado.find(getAdultoMayor()) != string::npos) {
		setPorcentajeInfluencia(35);
	}
	if (cate1.find(getCategoria()) != string::npos) {
		setPorcentajeInfluencia(20);
	}
	if (cate2.find(getCategoria()) != string::npos) {
		setPorcentajeInfluencia(10);
	}
	if (cate3.find(getCategoria()) != string::npos) {
		setPorcentajeInfluencia(0);
	}
}

Cliente::~Cliente() {}

int Cliente::getPorcentajeInfluencia() const {
	return porcentajeInfluencia;
}

void Cliente::setPorcentajeInfluencia(int porcentajeInfluencia) {
	Cliente::porcentajeInfluencia += porcentajeInfluencia;
}

Cliente::operator int const() {
	return porcentajeInfluencia;
}