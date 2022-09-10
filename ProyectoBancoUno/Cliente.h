#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Cliente;
class Cliente {
private:
	string nombre;
	string id;
	string nino;
	string embarazo;
	string adultoMayor;
	string categoria;
	int porcentajeInfluencia;
public:
	Cliente(string = "", string = "", string = "", string = "", string = "", string = "", int = 0);
	Cliente(const Cliente&);
	void setNombre(string);
	void setId(string);
	void setNino(string);
	void setEmbarazo(string);
	void setAdultoMayor(string);
	void setCategoria(string);
	int getPorcentajeInfluencia() const;
	void setPorcentajeInfluencia(int porcentajeInfluencia);
	string getNombre();
	string getId();
	string getNino();
	string getEmbarazo();
	string getAdultoMayor();
	string getCategoria();
	Cliente& operator=(const Cliente&);
	friend ostream& operator << (ostream&, Cliente&);
	string toString();
	void calcuPorcent();
	virtual ~Cliente();
	operator int const ();
};

