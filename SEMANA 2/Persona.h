#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class CPersona{
private:
	string nombre;
	int edad;
	int dni;
	char sexo;
	double peso;
	double altura;

public:
	//CONSTRUCTOR CON VALORES POR DEFECTO
	CPersona(){
		nombre = " ";
		edad = 0;
		dni = 0;
		sexo = 'H';
		peso = 0.0;
		altura = 0.0;
	}

	//SEGUNDO CONSTRUCTOR - SOBRECARGA DE CONSTRUCTORES
	CPersona(string nombre, int _edad, char sexo) {
		this->nombre = nombre;
		edad = _edad;
		this->sexo = sexo;
		generarDNI(); //CREAMOS LA FUNCION LUEGO
		peso = 0.0;
		altura = 0.0;
	}

	//TERCER CONSTRUCTOR - SOBRECARGA DE CONSTRUCTORES
	CPersona(string nombre, int edad, char sexo, double peso, double altura) {
		this->nombre = nombre;
		this->edad   = edad;
		this->sexo   = sexo;
		this->peso   = peso;
		this->altura = altura;
		generarDNI(); //CREAMOS LA FUNCION LUEGO
	}

	//DESTRUCTOR
	~CPersona(){}

	//-------METODOS GET-------
	string getNombre(){ return nombre; }
	int	   getEdad() { return edad; }
	char   getSexo() { return sexo; }
	double getPeso() { return peso; }
	double getAltura() { return altura; }

	//-------METODOS SET-------
	void setNombre(string nombre) { this->nombre = nombre; }
	void setEdad(int edad) { this->edad = edad; }
	void setSexo(char sexo) { this->sexo = sexo; }
	void setPeso(double peso) { this->peso = peso; }
	void setAltura(double altura) { this->altura = altura; }

	//-------METODOS O FUNCIONES-------
	int calcularIMC() {
		double pesoIdeal;

		pesoIdeal = peso / (pow(altura, 2)); // altura * altura

		if (pesoIdeal < 20) {
			return -1;
		}
		else {
			if (pesoIdeal >= 20 && pesoIdeal <= 25) {
				return 0;
			}
			else {
				return 1;
			}
		}
	}

	bool esMayorDeEdad() {
		if (edad >= 18) {
			return true;
		}
		else {
			return false;
		}
	}

	void comprobarSexo(char sexo) {
		if (sexo != 'H' && sexo != 'M') {
			this->sexo = 'H';
			cout << "Las opciones para ingresar son: H: Hombre; M: Mujer" << endl;
		}
		else {
			cout << "Se completo de manera exitosa" << endl;
		}
	}

	void devolverInfo() {
		cout << "INFORMACION DE LA PERSONA" << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Edad  : " << edad << endl;
		cout << "Sexo  : " << sexo << endl;
		cout << "Peso  : " << peso << endl;
		cout << "Altura: " << altura << endl;
		cout << "DNI: " << dni << endl;
	}

	void generarDNI() {
		dni = rand() % 99999999 + 9999999;
	}

};