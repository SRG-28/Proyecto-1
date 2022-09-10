#include "Validacion.h"


string Validacion::validaString()
{
	string s;
	getline(cin, s);
	cin.clear();
	return s;
}

int Validacion::validaInt(int c)
{
	while (!(cin >> c)) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Error,el valor digitado no es un numero\n";
	}
	return c;
}

