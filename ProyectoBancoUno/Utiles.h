#pragma once
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

class Utiles {
public:
	static double convertirDouble(string n) {

		stringstream r(n);
		double d;
		r >> d;
		return d;
	}
	static int convertirInt(string n) {

		stringstream r(n);
		int d;
		r >> d;
		return d;
	}

	static string convertirString(int n) {


		string Result;

		stringstream convert;

		convert << n;

		return Result = convert.str();
	}
	static string convertirSChar(char n) {

		string s;
		stringstream r(n);
		r << s;
		return s;
	}



};